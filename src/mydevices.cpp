
#include "mydevices.h"

using namespace std;

int luminosite_environnement = 200;

//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int t):Device(),val(t),temps(d){
  alea=1;
}

void AnalogSensorTemperature::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=val+alea;
    sleep(temps);
  }
}

//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):Device(),temps(d){
  alea=2;
  val=luminosite_environnement;
}

void AnalogSensorLuminosity::run(){
  while(1){
    alea=2-alea;
    if(ptrmem!=NULL)
      *ptrmem=luminosite_environnement+alea;
    sleep(temps);
  }
}


IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void IntelligentDigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      luminosite_environnement-=50;
      cout << "((((eteintIntelligent))))\n";
    }
    else{
      luminosite_environnement+=50;
      cout << "((((allumeIntelligent))))\n";
    }
    sleep(temps);
    }
}

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((eteint))))\n";
    else
    cout << "((((allume))))\n";
    sleep(temps);
    }
}

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

void I2CActuatorScreen::run(){
  while(1){
    if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
      Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
      cout << "---screen :"<< buf << endl;
    }
    sleep(1);
    }
}





