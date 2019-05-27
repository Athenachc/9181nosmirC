# Slave
Please READ main.cpp \ - / 

## Command List :
### Set Up
```
hft.init(); //<- Wake up hfCore [essential]
airt.init(); //<- Wake up relay [essential]
hft.setupServo(PC_8); //<- gives a period to servo @ hfCore [essential], PC_8 can be any pin that gives a PWM
```

### Hf Core

**O indicates front :**
```
hft.charge(true); //<- Stop at O------------| . Moving direction is backward.
hft.homing(true); //<- Stop at O-------|----- .  Moving direction is forward.
hft.vsc(0); //<- Pull the trigger (Crossbow). Do not change the 0 since it is position.
hft.servoMove(); // Servo turn anticlockwise 180 degree (Fire the hole)
```

### Air Core
**make sure the circuit is correctly arranged.**

* basic movements:
```
airt.openC(); //<- Open (horizonal movement)
airt.closeC(); //<- Close (horizonal movement)
airt.moveUp(); //<- Move Up (vertical movement)
airt.moveDown(); //<- Move Down (vertical movement)
```
* preset movements:
```
airt.fullSequence(2); //<- run the fullSequence of task. little bit buggy. 2 is the time interval between movement
airt.hold(2); //<- close,moveup,open,close. <- for picking up shit and hold the position. 2 is the time interval between movement
airt.aim(2); //<- open,movedown,close. <- for prepare to shoot. 2 is the time interval between movement
```

* **auto path -> fullSequence**
* **semi auto path -> open -> hold -> aim**

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
            airt.fullSequence(2); //auto clipping
            break;
        case 'O':
            airt.openC(); //(clip the shit part1)
            break;
        case 'U':
            airt.hold(2); //pick the shit up (clip the shit part2)
            break;
        case 'M':
            airt.aim(2); //prepare to shoot (clip the shit part3)
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