#include "box.h"

Box::Box(){
    pBoard = NULL;
    pTemp = NULL;
    pLumino = NULL;
    pPos = NULL;
    pButton = NULL;
    pLed = NULL;
    pMotor = NULL;
    pLamp = NULL;
    pScreen1 = NULL;
    pScreen2 = NULL;
    pinTemp = pinLumino = pinPos = pinButton = pinLed = pinMotor = pinLamp = addrScreen1 = addrScreen2 = 0;
}

Box::Box(Board* pB,int t,
    int portTemp,int portLumino,int portPos,
    int portButton,int portLed,int portMotor,
    int portLamp,int adScreen1,int adScreen2){
    pBoard = new Board;
    pBoard = pB;
    pTemp = new AnalogSensorTemperature(t);
    pLumino = new AnalogSensorLuminosity(t);
    pPos = new AnalogSensorPosition(t);
    pButton = new ExternalDigitalSensorButton (t);
    pLed = new DigitalActuatorLED(t);
    pMotor = new AnalogActuatorMotor(t);
    pLamp = new IntelligentAnalogActuatorLamp(t);
    pScreen1 = new I2CActuatorScreen;
    pScreen2 = new I2CActuatorScreen;
    pinTemp = portTemp;
    pinLumino = portLumino;
    pinPos = portPos;
    pinButton = portButton;
    pinLed = portLed;
    pinMotor = portMotor;
    pinLamp = portLamp;
    addrScreen1 = adScreen1;
    addrScreen2 = adScreen2;
    pBoard->pin(pinTemp,*pTemp);
    pBoard->pin(pinLumino,*pLumino);
    pBoard->pin(pinPos,*pPos);
    pBoard->pin(pinButton,*pButton);
    pBoard->pin(pinLed,*pLed);
    pBoard->pin(pinMotor,*pMotor);
    pBoard->pin(pinLamp,*pLamp);
    pBoard->i2c(addrScreen1,*pScreen1);
    pBoard->i2c(addrScreen2,*pScreen2);
}

ostream& operator<<(ostream& os, const Box& b){
    os << "------------------------------------------------------------------------" << endl;
    os << "Vous avez les capteurs : " << endl;
    if(b.pTemp != NULL) os << "Un <AnalogTemperature> connercte a pin " << b.pinTemp << ", ";
    if(b.pLumino != NULL) os << "Un <AnalogLuminosity> connercte a pin " << b.pinLumino << ", ";
    if(b.pPos != NULL) os << "Un <AnalogPosition> connercte a pin " << b.pinPos << endl;
    os << "Vous avez les interactions : " << endl;
    if(b.pButton != NULL) os << "Un <ExternaButton> connercte a pin " << b.pinButton << endl;
    os << "Vous avez les actionneurs : " << endl;
    if(b.pLed != NULL) os << "Un <DigitalLed> connercte a pin " << b.pinLed << ", ";
    if(b.pMotor != NULL) os << "Un <AnalogMotor> connercte a pin " << b.pinMotor << ", ";
    if(b.pLamp != NULL) os << "Un <AnalogLamp> connercte a pin " << b.pinLamp << endl;
    os << "Vous avez les afficheurs : " << endl;
    if(b.pScreen1 != NULL) os << "Un <Screen> connecte a addr " << b.addrScreen1 << ", ";
    if(b.pScreen2 != NULL) os << "Un <Screen> connecte a addr " << b.addrScreen2 << endl;
    os << "------------------------------------------------------------------------" << endl;
    return os;
}
