#include "box.h"

Box::Box(){
    pBoard = NULL;
    pLumino = NULL;
    pPos = NULL;
    pMotor = NULL;
    pLamp = NULL;
    pScreen = NULL;
    pinLumino = pinPos = pinMotor = pinLamp = pinScreen = 0;
}

Box::Box(Board* pB, int t, int portLumino, int portPos, int portMotor, int portLamp, int addScreen){
    pBoard = new Board;
    pBoard = pB;
    pLumino = new AnalogSensorLuminosity(t);
    pPos = new AnalogSensorPosition(t);
    pMotor = new AnalogActuatorMotor(t);
    pLamp = new IntelligentAnalogActuatorLamp(t);
    pScreen = new I2CActuatorScreen;
    pinLumino = portLumino;
    pinPos = portPos;
    pinMotor = portMotor;
    pinLamp = portLamp;
    pinScreen = addScreen;
    pBoard->pin(portLumino,*pLumino);
    pBoard->pin(portPos,*pPos);
    pBoard->pin(portMotor,*pMotor);
    pBoard->pin(portLamp,*pLamp);
    pBoard->i2c(addScreen,*pScreen);
}

ostream& operator<<(ostream& os, const Box& b){
    os << "Vous avez les capteurs : ";
    if(b.pLumino != NULL) os << "Un <AnalogLuminosity> connercte a pin " << b.pinLumino << ", ";
    if(b.pPos != NULL) os << "Un <AnalogPosition> connercte a pin " << b.pinPos << endl;
    os << "Vous avez les actionneurs : ";
    if(b.pMotor != NULL) os << "Un <AnalogMotor> connercte a pin " << b.pinMotor << ", ";
    if(b.pLamp != NULL) os << "Un <AnalogLamp> connercte a pin " << b.pinLamp << endl;
    os << "Vous avez les afficheurs : ";
    if(b.pScreen != NULL) os << "Un <Screen> connecte a add " << b.pinScreen << endl;
    return os;
}
