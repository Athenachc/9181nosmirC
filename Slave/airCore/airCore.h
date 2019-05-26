#include "mbed.h"
#include "Relay.h"

class airCore
{ 
public:
    airCore(bool debug, PinName pin1, PinName pin2, PinName pin3, PinName pin4);

    void setAirCoreDebug(bool inp);
    bool getAirCoreDebug(void);
    
    void openC(void);
    void closeC(void);
    void moveUp(void);
    void moveDown(void);
    
    void init(void);
    
    void fullSequence(float time);
    void hold(float time);
    void aim(float time);
    
private: 
    bool airCoreDebug;
    
    Relay *rotationalC;
    Relay *linearC;
};
