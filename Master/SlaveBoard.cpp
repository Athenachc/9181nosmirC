#include "SlaveBoard.h"

SlaveBoard::SlaveBoard(PinName tx, PinName rx) : Serial(tx, rx){}

void SlaveBoard::homing()
{
    putc('H');
}

void SlaveBoard::readyPosition()
{
    putc('R');
}

void SlaveBoard::fire()
{
    putc('F');
}

void SlaveBoard::estop()
{
    putc('E');
}

void SlaveBoard::vesc()
{
    putc('V');
}

void SlaveBoard::charge()
{
    putc('C');
}

void SlaveBoard::grasp()
{
    putc('A');    
}

