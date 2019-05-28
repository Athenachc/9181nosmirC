# Slave
Please READ main.cpp ʘ‿ʘ

## Command List :
### Set Up

| Command | Usage |
| ------------- | ------------- |
| `hft.init();` | Wake up hfCore [essential] |
| `airt.init();` | Wake up relay [essential] |
| `hft.setupServo(PC_8);` | gives a period to servo @ hfCore [essential], PC_8 can be any pin that gives a PWM |


### Hf Core [HF + 拉弓 + Servo]

ʘ‿ʘ **O indicates front :** ʘ‿ʘ

| Command | Usage |
| ------------- | ------------- |
| `hft.charge(true);` | Stop at O------------E . Moving direction is backward. |
| `hft.homing(true);` | Stop at O-------E----- .  Moving direction is forward. |
| `hft.vsc(0);` | Pull the trigger (Crossbow). Do not change the 0 since it is position. |
| `hft.servoMove();` | Servo turn anticlockwise 180 degree (Fire the hole) |


### Air Core [Shit Mode 屎夾]
ʘ‿ʘ **make sure the circuit is correctly arranged.** ʘ‿ʘ

| Command | Usage |
| ------------- | ------------- |
| `airt.openC();` | Open (horizonal movement) |
| `airt.closeC();` | Close (horizonal movement) |
| `airt.moveUp();` | Move Up (vertical movement) |
| `airt.moveDown();` | Move Down (vertical movement) |
| `airt.toggleC();` | toggle openC and closeC. |
| `airt.toggleMove();` | toggle move up and down. |
| `airt.fss(2);` | run the fullSequence of task. little bit buggy. 2 is the time interval between movement |
| `airt.prepareS(0.1);` | open. <- prepare to pick up. 0.01 is the time interval between movement |
| `airt.holdS(2);` | close,moveup,open,close. <- for picking up shit and hold the position. 2 is the time interval between movement |
| `airt.aimS(2);` | open,movedown,close. <- for prepare to shoot. 2 is the time interval between movement |


* **auto : fullSequence**
* **semi-auto : prepareS -> holdS -> aimS**
* **manual : open->close->moveup->open->close->open->movedown->close**

### Air Core [George Mode 左治夾]
ʘ‿ʘ **make sure the circuit is correctly arranged.** ʘ‿ʘ

| Command | Usage |
| ------------- | ------------- |
| `airt.georgeRelease();` | Release (horizonal movement) |
| `airt.georgeHold();` | Hold (horizonal movement) |
| `airt.georgeMoveUp();` | Move Up (vertical movement) |
| `airt.georgeMoveDown();` | Move Down (vertical movement) |
| `airt.toggleGeorgeHold();` | toggle hold and release |
| `airt.toggleGeorgeMove();` | toggle up and down |



### For Serial Debug Ardino (9600baud):

| Command | Usage |
| ------------- | ------------- |
| `H` | Homing |
| `C` | Charge |
| `F` | Servo |
| `V` | 拉弓 |
| `L` | 開關左治夾 |
| `I` | 升降左治夾 |
| `X` | 開關屎夾 |
| `Y` | 升降屎夾 |


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