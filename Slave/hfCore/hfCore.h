//lib
#include "mbed.h"

class hfCore
{
    public:
        hfCore(bool debug);
        hfCore(bool debug,float hfSpeed,float hfTurboSpeed);
        hfCore(bool debug,float hfSpeed,float hfTurboSpeed, double turboPercentage, double length, double gearRatio);
        
        void homing(bool turbo);
        void charge(bool turbo);
        
        void init(void);
        
        //servo=================================================================
        void servoMove();
        void setupServo(PinName pin, double period = 0.020, double pulseWidth1 = 0.0005, double pulseWidth2 = 0.0025, double timeInterval = 1);
        void vsc(float pos);
        void brake(void);
        //oid brake(float inp);

    private:
    
        //debug mode
        void setHfCoreDebug(bool inp);
        bool getHfCoreDebug(void);
        
        //using Edge limit SW for EStop(if non edge senor is persent)
        void setEdgeLimitEStop(bool inp);
        bool getEdgeLimitEStop(void);
        
        void setMotorSpeed(float inp);
        float getMotorSpeed(void);
        
        void setMotorTurboSpeed(float inp);
        float getMotorTurboSpeed(void);
        
        void setHfTurboPercentage(double inp);
        double getHfTurboPercentage(void);
        
        void setTravelLength(double inp);
        double getTravelLength(void);
        
        void setGeartRatio(double inp);
        double getGeartRatio(void);
        
        //calHf time for turbo Time
        void calHfTurboTime();
        double getHfTurboTime(void);
        
        Timeout turboEnd;
        Ticker motorUpdater;
    
        //bebug mode flage
        bool hfCoreDebug;
        //using Edge limit SW for EStop(if non edge senor is persent)
        bool turboLock;
        bool lock;
        bool edgeLimitEStop;
        
        float motorSpeed;
        float motorTurboSpeed;
        bool motorMode;//true for Turbo, false for normal speed
        
        //travel Length of the hf
        double travelLength;
        double geartRatio;
        double hfTurboPercentage;
        double hfTurboTime;
        
        //acceleration and deceleration
        int acc;
        int dec;

        //stop hf motor
        bool isStop;
        
        void motorInitialization(void);
        
        void turboOff(void);
        void homingMotorUpdate(void);
        void chargeMotorUpdate(void);
        
        //servo=================================================================
        PwmOut *servo;
        PinName pin;
        bool rcServoDebug;
        double period;
        double pulseWidth1;
        double pulseWidth2;
        double timeInterval;
};
