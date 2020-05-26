#include "box.h"

Box::Box(){
    pBoard = NULL;
    pTemp = NULL;
    pLumino = NULL;
    pPos = NULL;
    pButton = NULL;
    pIR = NULL;
    pRTC = NULL;
    pLed = NULL;
    pMotor = NULL;
    pLamp = NULL;
    pChauffClim = NULL;
    pScreen1 = NULL;
    pScreen2 = NULL;
    pinTemp = pinLumino = pinPos = pinButton = pinIR = pinLed = pinRTC = pinMotor = pinLamp = pinChauffClim = addrScreen1 = addrScreen2 = -1;
}

Box::Box(Board* pB,int t,int portLumino,int portPos,int portButton,int portLed,int portMotor,int portLamp,int adScreen){
    pBoard = new Board;
    pBoard = pB;
    pLumino = new AnalogSensorLuminosity(t);
    pPos = new AnalogSensorPosition(t);
    pButton = new ExternalDigitalSensorButton (t);
    pLed = new DigitalActuatorLED(t);
    pMotor = new AnalogActuatorMotor(t);
    pLamp = new IntelligentAnalogActuatorLamp(t);
    pTemp = NULL;
    pRTC = NULL;
    pIR = NULL;
    pChauffClim = NULL;
    pScreen2 = NULL;
    pScreen1 = new I2CActuatorScreen;
    pinLumino = portLumino;
    pinPos = portPos;
    pinButton = portButton;
    pinLed = portLed;
    pinMotor = portMotor;
    pinLamp = portLamp;
    addrScreen1 = adScreen;
    pBoard->pin(pinLumino,*pLumino);
    pBoard->pin(pinPos,*pPos);
    pBoard->pin(pinButton,*pButton);
    pBoard->pin(pinLed,*pLed);
    pBoard->pin(pinMotor,*pMotor);
    pBoard->pin(pinLamp,*pLamp);
    pBoard->i2c(addrScreen1,*pScreen1);
}

Box::Box(Board* pB,int t,int portTemp,int portChaffClim,int adScreen){
    pBoard = new Board;
    pBoard = pB;
    pTemp = new AnalogSensorTemperature(t);
    pChauffClim = new AnalogActuatorChauffClim(t);
    pScreen2 = new I2CActuatorScreen;
    pLumino = NULL;
    pPos = NULL;
    pButton = NULL;
    pIR = NULL;
    pRTC = NULL;
    pLed = NULL;
    pMotor = NULL;
    pLamp = NULL;
    pScreen1 = NULL;
    pinTemp = portTemp;
    pinChauffClim = portChaffClim;
    addrScreen2 = adScreen;
    pBoard->pin(pinTemp,*pTemp);
    pBoard->pin(pinChauffClim,*pChauffClim);
    pBoard->i2c(addrScreen2,*pScreen2);
}

Box::Box(Board* pB,int t,int portIR,int portRTC){
    pBoard = new Board;
    pBoard = pB; 
    pIR = new DigitalSensorIR(t);
    pRTC = new DigitalSensorRTC(t);
    pTemp = NULL;
    pLumino = NULL;
    pPos = NULL;
    pButton = NULL;
    pLed = NULL;
    pMotor = NULL;
    pLamp = NULL;
    pChauffClim = NULL;
    pScreen1 = NULL;
    pScreen2 = NULL;
    pinIR = portIR;
    pinRTC = portRTC;
    pBoard->pin(pinIR,*pIR);
    pBoard->pin(pinRTC,*pRTC);
}

Box::~Box(){
    if(pTemp != NULL){
        delete[] pTemp;
        pTemp=NULL;
    }
    if(pLumino != NULL){
        delete[] pLumino;
        pLumino=NULL;
    }
    if(pPos != NULL){
        delete[] pPos;
        pPos=NULL;
    }
    if(pIR != NULL){
        delete[] pIR;
        pIR=NULL;
    }
    if(pRTC != NULL){
        delete[] pRTC;
        pRTC=NULL;
    }
    if(pButton != NULL){
        delete[] pButton;
        pButton=NULL;
    }
    if(pLed != NULL){
        delete[] pLed;
        pLed=NULL;
    }
    if(pMotor != NULL){
        delete[] pMotor;
        pMotor=NULL;
    }
    if(pLamp != NULL){
        delete[] pLamp;
        pLamp=NULL;
    }
    if(pChauffClim != NULL){
        delete[] pChauffClim;
        pChauffClim=NULL;
    }
    if(pScreen1 != NULL){
        delete[] pScreen1;
        pScreen1=NULL;
    }
    if(pScreen2 != NULL){
        delete[] pScreen2;
        pScreen2=NULL;
    }           
}

ostream& operator<<(ostream& os, const Box& b){
    os << "------------------------------------------------------------------------" << endl;
    os << "Vous avez les capteurs : " << endl;
    if(b.pTemp != NULL) os << "Un <AnalogTemperature> connercte a pin " << b.pinTemp << endl;
    if(b.pLumino != NULL) os << "Un <AnalogLuminosity> connercte a pin " << b.pinLumino << endl;
    if(b.pPos != NULL) os << "Un <AnalogPosition> connercte a pin " << b.pinPos << endl;
    if(b.pIR != NULL) os << "Un <DigitalIR> connecte a pin " << b.pinIR << endl;
    if(b.pRTC != NULL) os << "Un <DigitalRTC> connecte a pin " << b.pinRTC << endl;
    os << "Vous avez les interactions : " << endl;
    if(b.pButton != NULL) os << "Un <ExternaButton> connercte a pin " << b.pinButton << endl;
    os << "Vous avez les actionneurs : " << endl;
    if(b.pLed != NULL) os << "Un <DigitalLed> connercte a pin " << b.pinLed << endl;
    if(b.pMotor != NULL) os << "Un <AnalogMotor> connercte a pin " << b.pinMotor << endl;
    if(b.pLamp != NULL) os << "Un <AnalogLamp> connercte a pin " << b.pinLamp << endl;
    if(b.pChauffClim != NULL) os << "Un <AnalogChauffClim> connecte a pin " << b.pinChauffClim << endl;
    os << "Vous avez les afficheurs : " << endl;
    if(b.pScreen1 != NULL) os << "Un <Screen> connecte a addr " << b.addrScreen1 << endl;
    if(b.pScreen2 != NULL) os << "Un <Screen> connecte a addr " << b.addrScreen2 << endl;
    os << "------------------------------------------------------------------------" << endl;
    return os;
}
