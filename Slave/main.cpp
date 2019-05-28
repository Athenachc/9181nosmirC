//hf core v.5
//air core v.2

////////////////////////////////////////
#include "mbed.h"
#include "hfCore.h"
#include "string.h"
#include "airCore.h"
////////////////////////////////////////

//pin need to change later.
//airCore airt(true, PC_9,PC_8,PB_8,PC_6); //<- for STM32F103RB (TEST ONLY) 

airCore airt(true, PC_2,PC_3,PC_0,PA_4,PB_0,PC_5); //<- for STM32F446RE

////////////////////////////////////////

//ONLY enable ONE! Parameter order: (Debug mode onoff, normal speed, turbo speed)
//Turbo Time interval fixed to 0.475s in hfCore.cpp

//hfCore hft(true,0.3,0.4); //Safe speed

hfCore hft(true,0.3,0.95);  //Fastest speed. use CAREFULLY. the Speed is between -0.95 to 0.95.

////////////////////////////////////////

/* MAX 26/5/2019
COMMAND LIST:

//////////////Set Up////////////////////
hft.init(); //<- Wake up hfCore [essential]
airt.init(); //<- Wake up relay [essential]
hft.setupServo(PC_8); //<- gives a period to servo @ hfCore [essential], PC_8 can be any pin that gives a PWM


/////////////Hf Core////////////////////
** O indicates front :

hft.charge(true); //<- Stop at O------------| . Moving direction is backward.
hft.homing(true); //<- Stop at O-------|----- .  Moving direction is forward.
hft.vsc(0); //<- Pull the trigger (Crossbow). Do not change the 0 since it is position.
hft.servoMove(); // Servo turn anticlockwise 180 degree (Fire the hole)


//////////////Air Core//////////////////
make sure the circuit is correctly arranged.

*basic movements:

airt.openC(); //<- Open (horizonal movement)
airt.closeC(); //<- Close (horizonal movement)
airt.moveUp(); //<- Move Up (vertical movement)
airt.moveDown(); //<- Move Down (vertical movement)

*preset movements:

airt.fullSequence(2); //<- run the fullSequence of task. little bit buggy. 2 is the time interval between movement
airt.hold(2); //<- close,moveup,open,close. <- for picking up shit and hold the position. 2 is the time interval between movement
airt.aim(2); //<- open,movedown,close. <- for prepare to shoot. 2 is the time interval between movement

auto path -> fullSequence
semi auto path -> open -> hold -> aim  

////////////////////////////////////////


*/


////////////////////////////////////////
/*
    Charging -> VSC -> sand -> Homing -> Shoot
     C->V->A->H->F
*/

//TX, RX
Serial usbDebug(USBTX, USBRX); // <- Serial Testing
//Serial  Gsam(PC_10, PC_11); //not used
Serial  Gsam(PA_0, PA_1);  // <- this is for the fully functional program

char temp; // get the input

////////////////////////////////////////

void inputInterrupter(char inp){
    switch(inp) {
        case 'H':
            hft.homing(true); //Stop at -------|-----
            break;
        case 'C':
            hft.charge(true); //Stop at ------------|
            break;
        case 'F':
            printf("Fire!!!\n"); 
            hft.servoMove(); // Servo turn anticlockwise 180 degree (Fire the hole)
            break;
        case 'V':
            printf("VSC!!!\n");
            hft.vsc(0); // Pull the trigger
            break;
        case 'A':
            airt.fss(2); //auto clipping
            break;
        case 'O':
            airt.prepareS(0.01); //(clip the shit part1)
            break;
        case 'U':
            airt.holdS(2); //pick the shit up (clip the shit part2)
            break;
        case 'M':
            airt.aimS(2); //prepare to shoot (clip the shit part3)
            break;
        case 'P':
            airt.georgeMoveUp(); //move up george
            break;
        case 'B':
            airt.georgeMoveDown(); //move down george
            break;
        case 'L':
            airt.toggleGeorgeHold(); // hold and release george.
            break;
    }
}


void rxInterrupt() {
        while(Gsam.readable()){
            temp = Gsam.getc();
            //Gsam.printf("%c",temp);
            printf("[uArt]Input:%c\n",temp);
            inputInterrupter(temp);
        }      
}


void usbInterrupt() {
        if(usbDebug.readable()){
            temp = usbDebug.getc();
            //Gsam.printf("%c",temp);
            printf("[USB]Input:%c\n",temp);
            inputInterrupter(temp);
        }      
}

///////////////////////////////////////

int main() {
    
    //Gsam.baud(115200); //for changing the baud. not used.
    printf("ST32 Ready\n");
    wait(1);
    
    hft.init(); //hfCore wake
    airt.init(); //airCore wake
    hft.setupServo(PC_8); //servo@hfCore wake
    
    Gsam.attach(&rxInterrupt, Serial::RxIrq); // PS4 side interrupt
    usbDebug.attach(&usbInterrupt, Serial::RxIrq); //PC side interrupt
    while(1) {
        wait(1); 
    }
}
