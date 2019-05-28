# Slave
Please READ main.cpp ʘ‿ʘ

## Command List :
### Set Up
```
hft.init(); 
//^^ Wake up hfCore [essential]
airt.init(); 
//^^ Wake up relay [essential]
hft.setupServo(PC_8); 
//^^ gives a period to servo @ hfCore [essential], PC_8 can be any pin that gives a PWM
```

### Hf Core

ʘ‿ʘ **O indicates front :** ʘ‿ʘ
```
hft.charge(true); //<- Stop at O------------| . Moving direction is backward.
hft.homing(true); //<- Stop at O-------|----- .  Moving direction is forward.
hft.vsc(0); //<- Pull the trigger (Crossbow). Do not change the 0 since it is position.
hft.servoMove(); //<- Servo turn anticlockwise 180 degree (Fire the hole)
```

### Air Core [Shit Mode]
ʘ‿ʘ **make sure the circuit is correctly arranged.** ʘ‿ʘ

* basic movements:
```
airt.openC(); //<- Open (horizonal movement)
airt.closeC(); //<- Close (horizonal movement)
airt.moveUp(); //<- Move Up (vertical movement)
airt.moveDown(); //<- Move Down (vertical movement)
```
* preset movements:
```
airt.fss(2);
//^^ run the fullSequence of task. little bit buggy. 2 is the time interval between movement
airt.prepareS(0.1);
//^^ open. <- prepare to pick up. 0.01 is the time interval between movement
airt.holdS(2);
//^^ close,moveup,open,close. <- for picking up shit and hold the position. 2 is the time interval between movement
airt.aimS(2);
//^^ open,movedown,close. <- for prepare to shoot. 2 is the time interval between movement
```

* **auto path -> fullSequence**
* **semi auto path -> open -> hold -> aim**

### Air Core [George Mode]
ʘ‿ʘ **make sure the circuit is correctly arranged.** ʘ‿ʘ

* basic movements:
```
airt.georgeRelease(); //<- Release (horizonal movement)
airt.georgeHold(); //<- Hold (horizonal movement)
airt.georgeMoveUp(); //<- Move Up (vertical movement)
airt.georgeMoveDown(); //<- Move Down (vertical movement)
```
* preset movements:
```
airt.toggleGeorgeHold();
//^^ toggle hold and release
airt.toggleGeorgeMove();
//^^ toggle up and down
```


### For Serial Debug :
```
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

```

## Readme.md written by max
```
░░░░░░░░░░░░░░░░░▄▄▄▄▄▄
░░░░░░░░░░░░░▄▄▀▀░░░░░░▀▄
░░░░░░░░░░░▄▀░░░░░░░░░░▄▄▌░▄██▀▄
░░░░░░░▀▄▄▀░░░░░░░░░░░░▄▄███▀▀▌▐
░░░░░░▐▄▀███▄░░▄█▄▄░░▄▀▒▒▒▒▀▀▄▐░▌
░░░░░▄▌▀▄▐▀▒▀▄▀▀▒▒▒▀▀▄▀▄▒▒▒▒▒▒▀▄▌▀
░░░░▐░▌▐▄▌▒▒▒▄▀▀▄▒▒▒▐▄▒▒▒▒▒▒▒▒▒▒▐▀
░░░░▐▄▐▐▒▒▒▒▒▒▒▐░▌▒▒▒▌▀▄▀▀▄▒▒▒▒▒▒▌
░░░░▐▄▄▌▒▒▒▌▒▄▀▀▄▀▄▒▒▌▌░░░▐▄▒▒▒▒▒▐
░░░░▐▌▒▒▒▒▐▒▄▀░░░█░▀▄▐░▌░░▐█▐▒▒▀▄▐
░░░░░▌▒▒▒▒▐▀▄░░░▄█░░░▀▐▄▄███░▌▒▐▐▐
░░░░▐▒▒▒▒▒▌░█▄▄███▌░░░▐████▀▌▐▒▒▌▀
░░░░▐▒▒▒▒▒▌░████▌█▌░░░░█▀█▀░▌▐▒▒▐
░░░░▐█▒▒▒▒▌░▐░▀▀░▐░░░▀░░▀░░░░░▀▌▐
░░░░▐█▌▒▒▒▐░░░░░░▐▄▄▀▄▀░░░░░░░▄▀▌
▄▀▄░░██▄▒▒▒▌░░░░░░▐▄▀░░░░░░░▄▀▒█
▀▄▐▌░▐█▀▄▒▒▀▄░▄▄▄▄░░░▄▄▀▀▀██▒▒█
░▐██░░██░▀▄▐░▀▌░░░▀█▀▌░░░▐▀▐▄▀
░░██▌▐█▌░▐░▀▀▌▌░░▄░▌░▌▄░░▌▐﻿
```