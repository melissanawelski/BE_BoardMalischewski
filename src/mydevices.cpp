
#include "mydevices.h"

using namespace std;

int luminosite_environnement = 200;
int luminosite_led = 0;

//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int t):Device(),val(t),temps(d){
  alea=10;
}

void AnalogSensorTemperature::run(){
  while(1){
    alea=10-alea;
    if(ptrmem!=NULL)
      *ptrmem=val+alea;
    sleep(temps);
  }
}


//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):Device(),temps(d){
  alea=2;
  val=luminosite_environnement + luminosite_led;
}

void AnalogSensorLuminosity::run(){
  while(1){
    alea=2-alea;
    if(ptrmem!=NULL){
      //cout<<"[LOG]luminosit_env: " << luminosite_environnement << endl;
      //cout<<"[LOG]luminosit_led: " << luminosite_led << endl;
      //cout<<"[LOG]alea: " << alea << endl;
      //sleep(1);
      *ptrmem = luminosite_environnement + luminosite_led + alea;
    }
    else{
      cout<<"ptrmem == null"<<endl;
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

//classe IntelligentDigitalActuatorLED
IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void IntelligentDigitalActuatorLED::run(){
  while(1){
    
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW){
      cout << "((((eteintIntelligent))))\n";
    }
    else{
      luminosite_led=50;
      cout << "((((allumeIntelligent))))\n";
    }
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

//classe ExternalDigitalSensorButton
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t) : Device(),stateb(LOW),temps(t){}

void ExternalDigitalSensorButton::run(){
  while(1){
    int alea = 1;
    if(ifstream("fileName")){// le fichier existe
      stateb=1; // le bouton est on
    }
    if (stateb==LOW){
      cout << "((((relache))))\n";
      stateb=stateb+alea;
    }
    else {
      cout << "((((appui))))\n";
      sleep(temps);
    }
  }  
}

//classe IrSensor
IrSensor::IrSensor(int t) : Device(), stateIR(LOW), temps(t){};

void IrSensor::run(){
  while(1){
    if(ptrmem!=NULL){
      stateIR=*ptrmem;
    }
    if (stateIR==LOW){
      cout << "((((nobody))))\n";
    }
    else{
      luminosite_led=50;
      cout << "((((peoplehere))))\n";
    }
    sleep(temps); 
  }
}

//classe simulant le module RTC de façon grossière, donne l'heure, date jour etc
RTC::RTC(int t) :  Device(), state(LOW), temps(t){};

int RTC::read_current_datetime(){
  int jour = -1;
  if(ptrmem!=NULL){
    state=*ptrmem;
  }

  if (state==LOW){
    cout << "L'horloge est deconnectee ou n'a plus de pile";
  }
  else{
    //simule l'envoie de data du module RTC et la lecture par l'arduino
    // date / heure actuelle basée sur le système actuel
    time_t tmm = time(0);
    // convertir en forme de chaîne
    char* dt = ctime(&tmm);
    // convertir en tm struct pour UTC
    tm *g = gmtime(&tmm);
    dt = asctime(g);
    cout << "La date et l'heure UTC sont:"<< dt << endl;

    if(g->tm_hour < 8 or g->tm_hour>21){
      jour = 0;
    }
    else{
      jour = 1;
    }
  }
  return jour;
}

