//version 3.0 28/5/2019
//state : not tested 
//v3.0 george , toggle FEATURE AND prepare()
//v2.0 lock 

#include "airCore.h"
//              Charge, Release 


//construstor
airCore::airCore(bool debug, PinName pin1, PinName pin2, PinName pin3, PinName pin4, PinName pin5, PinName pin6) {
	airCoreDebug = debug;
	rotationalC = new Relay(pin1, pin2);
	linearC = new Relay(pin3, pin4);
	lock = true;

	george = new Relay(pin5, pin6);
	georgeLock = true;
}


//set flag
void airCore::setAirCoreDebug(bool inp) {
	airCoreDebug = inp;
	if (inp) {
		printf("[airCore]debug:ON\n");
	}
	else {
		printf("[airCore]debug:OFF\n");
	}
}

bool airCore::getAirCoreDebug(void) {
	return airCoreDebug;
}

//shit==========================================================
//basic movements
void airCore::openC(void) {
	linearC->offRelease();
	wait(0.1);
	linearC->onCharge();
	wait(0.1);

	linearState = true;

	if (airCoreDebug) {
		printf("[airCore]OpenC\n");
	}

}

void airCore::closeC(void) {
	linearC->offCharge();
	wait(0.1);
	linearC->onRelease();
	wait(0.1);

	linearState = false;

	if (airCoreDebug) {
		printf("[airCore]CloseC\n");
	}
}

void airCore::toggleC(void) {
	if (linearState) {
		closeC();
	}
	else {
		openC();
	}
}


void airCore::moveUp(void) {
	rotationalC->offRelease();
	wait(0.1);
	rotationalC->onCharge();
	wait(0.1);

	rotationalState = true;

	if (airCoreDebug) {
		printf("[airCore]Move up\n");
	}
}

void airCore::moveDown(void) {
	rotationalC->offCharge();
	wait(0.1);
	rotationalC->onRelease();
	wait(0.1);

	rotationalState = false;

	if (airCoreDebug) {
		printf("[airCore]Move down\n");
	}
}

void airCore::toggleMove(void) {
	if (linearState) {
		moveDown();
	}
	else {
		moveUp();
	}
}


//pro. s** movements
void airCore::init(void) {
	if (airCoreDebug) {
		printf("[airCore]init: start\n");
	}

	moveDown();
	closeC();

	if (airCoreDebug) {
		printf("[airCore]init: end\n");
	}

	lock = false;
}

////////////////////////////////////////////Path Auto
void airCore::fss(float time) {
	if (lock) {

		printf("[airCore]ERROR:some else is running\n");

	}
	else {
		lock = true;

		if (airCoreDebug) {
			printf("[airCore]fullSequenceShit: start\n");
		}

		////////////////////////
		//hold s*** and move up
		openC(); // init
		wait(time / 2);


		////////////////////////
		closeC(); // hold the shit
		wait(time * 2);
		moveUp(); //rise the shit
		wait(time);

		//open and close
		openC();
		wait(time / 2);
		closeC();
		wait(time / 2);

		/////////////////////////
		openC();
		wait(time * 2);
		//back to ready
		moveDown();
		wait(time);
		closeC(); //back to init

		if (airCoreDebug) {
			printf("[airCore]fullSequence: end\n");
		}

		lock = false;

	}
}

////////////////////////////////////////////Path Semi-Auto
void airCore::prepare(float time) {
	if (lock) {

		printf("[airCore]ERROR:some else is running\n");

	}
	else {
		lock = true;

		openC();
		wait(time);

		lock = false;
	}
}

void airCore::hold(float time) {
	if (lock) {

		printf("[airCore]ERROR:some else is running\n");

	}
	else {
		lock = true;

		closeC(); // hold the shit
		wait(time * 2);
		moveUp(); //rise the shit
		wait(time);

		openC();
		wait(time / 2);
		closeC();
		wait(time / 2);

		lock = false;
	}
}

void airCore::aim(float time) {

	if (lock) {

		printf("[airCore]ERROR:some else is running\n");

	}
	else {
		lock = true;

		openC();
		wait(time * 2);
		moveDown(); //back to ready
		wait(time);
		closeC(); //back to init

		lock = false;
	}
}

//george========================================================================
//basic movement
void airCore::georgeMoveUp(void) {
	if (georgeLock) {

		printf("[airCore]George said:some else is running\n");

	}
	else {
		georgeLock = true;

		george->onCharge();
		wait(0.1);

		georgeMoveState = true;

		georgeLock = false;
	}

}

void airCore::georgeMoveDown(void) {
	if (georgeLock) {

		printf("[airCore]George said:some else is running\n");

	}
	else {
		georgeLock = true;

		george->offCharge();
		wait(0.1);

		georgeMoveState = false;

		georgeLock = false;
	}

}

void airCore::toggleGeorgeMove(void) { //toggle up and down

	if (georgeHoldeState) {
		georgeMoveDown();
	}
	else {
		georgeMoveUp();
	}

}

void airCore::georgeHold(void) {
	if (georgeLock) {

		printf("[airCore]George said:some else is running\n");

	}
	else {
		georgeLock = true;

		george->onRelease();
		wait(0.1);

		georgeHoldeState = true;

		georgeLock = false;
	}

}

void airCore::georgeRelease(void) {
	if (georgeLock) {

		printf("[airCore]George said:some else is running\n");

	}
	else {
		georgeLock = true;

		george->offRelease();
		wait(0.1);

		georgeHoldeState = false;

		georgeLock = false;
	}

}

void airCore::toggleGeorgeHold(void) { //toggle hold and release

	if (georgeHoldeState) {
		georgeRelease();
	}
	else {
		georgeHold();
	}

}

