#include "mbed.h"
#include "Relay.h"

class airCore
{
public:
	airCore(bool debug, PinName pin1, PinName pin2, PinName pin3, PinName pin4, PinName pin5, PinName pin6);

	void setAirCoreDebug(bool inp);
	bool getAirCoreDebug(void);

	void openC(void);
	void closeC(void);
	void toggleC(void);

	void moveUp(void);
	void moveDown(void);
	void toggleMove(void);

	void init(void);

	void fss(float time);
	void prepare(float time);
	void hold(float time);
	void aim(float time);

	void georgeMoveUp(void);
	void georgeMoveDown(void);
	void toggleGeorgeMove(void);

	void georgeHold(void);
	void georgeRelease(void);
	void toggleGeorgeHold(void);

private:
	bool airCoreDebug;
	bool lock;
	bool rotationalState;
	bool linearState;

	bool georgeLock;
	bool georgeMoveState;
	bool georgeHoldeState;

	Relay *rotationalC;
	Relay *linearC;
	Relay *george;
};
