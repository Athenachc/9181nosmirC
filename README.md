# 9181nosmirC

## Master [Stable] [More Information...](https://github.com/vinesmsuic/9181nosmirC/tree/master/Master)

### PS4 button

![longliveGsam](https://user-images.githubusercontent.com/34955859/58477027-184f6280-8185-11e9-85eb-c7f96cf52cc8.png "fuc u")

| Button  | Usage |
| ------------- | ------------- |
| L1  | manual去auto  |
| R1  | auto去manual  |
| UP ↑ | toggle 升左治夾,落左治夾  |
| RIGHT → | toggle 夾緊左治夾,放鬆左治夾  |
| DOWN ↓ | toggle 升屎夾,落屎夾  |
| LEFT ← | toggle 夾緊屎夾,放鬆屎夾  |
| TRIANGLE △ | Crossbow Trigger  |
| CIRCLE ○ | Fire  |
| SQUARE □ | Homing  |
| CROSS ×  | Charge  |

### How to ↑↑↓↓←→←→AB

| Situation  | Flow |
| ------------- | ------------- |
| Shoot | ×△ (Shit) □○ |
| Shit | ↓  ↓←↓↓↓←↓ |
| George | ↑    → |

| Situation  | Flow(in Arduino) |
| ------------- | ------------- |
| Shoot | CV (Shit) HF |
| Shit | X  XYXXX   YX |
| George | I    L |

## Slave [Beta] [More Information...](https://github.com/vinesmsuic/9181nosmirC/tree/master/Slave)

* hfcore version 6.0 20/5/2019
* aircore version 3.0 28/5/2019

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

## FOR ON999 software debug person only, 
```
if you are ME or look for how to control the thing you may saftely ignore this part
```
## Debug 101 help yourself manul by on99 steve (such debug so wow) 
### Uart fucking thing
1. "check the connection(or existing) of 3 wire (it is 3 wireS , NOT 2 wires !!!!!!!!1!1!) \("__")/"
  ```
master  to    slave
TX      <-->  RX
RX      <-->  TX
GND     <-->  GND ( this one must check)
the UAart TX RX shoud be PA_0 and PA_1
use multimeter to connection is CONNECTED( do you know how to use multimeter?
  ```
  ![do you f-ing remnber the pin layout?](https://os.mbed.com/media/uploads/adustm/nucleo_f446re_morpho_left_2016_7_22.png)
1. check if the sender are really sending something out (and recivewer are reciveding)
  ```
you may refer to the slave USB conscole look for:
  ```
  `[uArt]Input:<uart sent char here>`
  
1. Find on99 steve(it is dangerous)
  ```
  well, this is a risky move
  ```
  ![how about try harder?](https://img1.daumcdn.net/thumb/R720x0.q80/?scode=mtistory&fname=http%3A%2F%2Fcfile29.uf.tistory.com%2Fimage%2F9975C43E5ADCB8211120E3)

### power borad fucking thing
 ```
  coming up soon
  ```
