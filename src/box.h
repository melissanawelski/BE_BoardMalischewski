#include "core_simulation.h"
#include "mydevices.h"

class Box{
private:
    //Board
    Board* pBoard;
    // Captures
    AnalogSensorTemperature* pTemp; 
    AnalogSensorLuminosity* pLumino;
    AnalogSensorPosition* pPos;
    ExternalDigitalSensorButton* pButton;
    DigitalSensorIR* pIR;
    DigitalSensorRTC* pRTC;
    // Actionneurs
    DigitalActuatorLED *pLed;
    AnalogActuatorMotor* pMotor;
    IntelligentAnalogActuatorLamp* pLamp;
    AnalogActuatorChauffClim* pChauffClim;
    I2CActuatorScreen* pScreen1;
    I2CActuatorScreen* pScreen2;
    // Numero de pin
    int pinTemp, pinLumino, pinPos, pinButton, pinIR, pinRTC, pinLed, pinMotor, pinLamp, pinChauffClim, addrScreen1, addrScreen2;

public:
    Box();
    Box(Board* pB,int t,int portLumino,int portPos,int portButton,int portLed,int portMotor,int portLamp,int adScreen); // module regulation luminosity
    Box(Board* pB,int t,int portTemp, int portChaffClim,int adScreen); // module regulation temperature
    Box(Board* pB,int t,int portIR,int portRTC); // module detection presence et jour/nuit
    ~Box();
    friend ostream& operator<< (ostream& os, const Box& b);
};
