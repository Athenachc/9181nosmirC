#include "library/robot.h"

class Motor {
    public:
        void init();
        void update(int motor1, int motor2, int motor3, int motor4);
        void manual();
        Motor();
};


