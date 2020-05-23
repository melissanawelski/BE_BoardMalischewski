#include "core_simulation.h"
#include "mydevices.h"

class Box{
private:
    Board* pBoard;
    AnalogSensorLuminosity* pLumino;
    AnalogSensorPosition* pPos;
    AnalogActuatorMotor* pMotor;
    IntelligentAnalogActuatorLamp* pLamp;
    I2CActuatorScreen* pScreen;
    int pinLumino, pinPos, pinMotor, pinLamp, pinScreen;

public:
    Box();
    Box(Board* pB, int t, int portLumino, int portPos, int portMotor, int portLamp, int addScreen);
    friend ostream& operator<< (ostream& os, const Box& b);
};
