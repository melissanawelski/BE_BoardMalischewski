#include "core_simulation.h"
#include "mydevices.h"

class Box{
private:
    Board* pBoard;
    AnalogSensorTemperature* pTemp; 
    AnalogSensorLuminosity* pLumino;
    AnalogSensorPosition* pPos;
    ExternalDigitalSensorButton* pButton;
    DigitalActuatorLED *pLed;
    AnalogActuatorMotor* pMotor;
    IntelligentAnalogActuatorLamp* pLamp;
    I2CActuatorScreen* pScreen1;
    I2CActuatorScreen* pScreen2;
    int pinTemp, pinLumino, pinPos, pinButton, pinLed, pinMotor, pinLamp, addrScreen1, addrScreen2;

public:
    Box();
    Box(Board* pB,int t,int portTemp,int portLumino,int portPos,int portButton,int portLed,int portMotor,int portLamp,int adScreen1,int adScreen2);
    friend ostream& operator<< (ostream& os, const Box& b);
};
