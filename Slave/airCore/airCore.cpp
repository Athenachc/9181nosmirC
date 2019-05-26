//version 1 23/5/2019

#include "airCore.h"
//              Charge, Release 


//construstor
airCore::airCore(bool debug, PinName pin1, PinName pin2, PinName pin3, PinName pin4){
    airCoreDebug = debug;
    rotationalC = new Relay(pin1, pin2);
    linearC = new Relay(pin3,pin4);
}


//set flag
void airCore::setAirCoreDebug(bool inp){
    airCoreDebug = inp; 
    if (inp){
        printf("[airCore]debug:ON\n");
    }else{
        printf("[airCore]debug:OFF\n");
    }
}

bool airCore::getAirCoreDebug(void){
    return airCoreDebug;
}


//basic movements
void airCore::openC(void){
    linearC->offRelease();
    wait(0.1);
    linearC->onCharge();
    wait(0.1);
    
    if (airCoreDebug){
        printf("[airCore]OpenC\n");
    }
}

void airCore::closeC(void){
    linearC->offCharge();
    wait(0.1);
    linearC->onRelease();
    wait(0.1);
    
    if (airCoreDebug){
        printf("[airCore]CloseC\n");
    }
}

void airCore::moveUp(void){
    rotationalC->offRelease();
    wait(0.1);
    rotationalC->onCharge();
    wait(0.1);
    
    if (airCoreDebug){
        printf("[airCore]Move up\n");
    }
}

void airCore::moveDown(void){
    rotationalC->offCharge();
    wait(0.1);
    rotationalC->onRelease();
    wait(0.1);
    
    if (airCoreDebug){
        printf("[airCore]Move down\n");
    }
}


//pro. s** movements
void airCore::init(void){
    if (airCoreDebug){
        printf("[airCore]init: start\n");
    }
    
    moveDown();
    closeC();
    
    if (airCoreDebug){
        printf("[airCore]init: end\n");
    }
}

void airCore::fullSequence(float time){
    
    if (airCoreDebug){
        printf("[airCore]fullSequence: start\n");
    }
        
    ////////////////////////
    //hold s*** and move up
    openC(); // init
    wait(time/2);
    
    
    ////////////////////////
    closeC(); // hold the shit
    wait(time*2);
    moveUp(); //rise the shit
    wait(time);
        
    //open and close
    openC(); 
    wait(time/2);
    closeC();
    wait(time/2);
    
    /////////////////////////
    openC();
    wait(time*2);
    //back to ready
    moveDown();
    wait(time);
    closeC(); //back to init
    
    if (airCoreDebug){
        printf("[airCore]fullSequence: end\n");
    }
}

void airCore::hold(float time){
    
    closeC(); // hold the shit
    wait(time*2);
    moveUp(); //rise the shit
    wait(time);

    openC(); 
    wait(time/2);
    closeC();
    wait(time/2);
}

void airCore::aim(float time){
        
    openC();
    wait(time*2);
    moveDown(); //back to ready
    wait(time);
    closeC(); //back to init
}