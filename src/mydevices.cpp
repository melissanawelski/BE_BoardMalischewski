
#include "mydevices.h"

using namespace std;

int temperature_environnement = 18;
int position_rideau = 10;
int luminosite_environnement = 200;
int luminosite_externe = 200;
int luminosite_rideau = luminosite_externe * position_rideau / 100;
int luminosite_led = 0;
int luminosite_lampe = 0;


// classe exception
LampException::LampException(int l){
  lel=l;
}
int LampException::getLevel(){
  return lel;
}

//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d):Device(),temps(d){
  val = temperature_environnement;
}

void AnalogSensorTemperature::run(){
  while(1){
    if(ptrmem!=NULL)
      *ptrmem = temperature_environnement;
    sleep(temps);
  }
}

//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):Device(),temps(d){
  val=luminosite_environnement + luminosite_led + luminosite_lampe + luminosite_rideau;
}

void AnalogSensorLuminosity::run(){
  while(1){
    if(ptrmem!=NULL){
      //cout<<"[LOG]luminosit_env: " << luminosite_environnement << endl;
      //cout<<"[LOG]luminosit_led: " << luminosite_led << endl;
      //cout<<"[LOG]alea: " << alea << endl;
      //sleep(1);
      luminosite_rideau = luminosite_externe * position_rideau / 100;
      *ptrmem = luminosite_environnement + luminosite_led + luminosite_lampe + luminosite_rideau;
    }
    sleep(temps);
  }
}

// classe AnalogSensorPosition
AnalogSensorPosition::AnalogSensorPosition(int d):Device(),temps(d){
  val=position_rideau;
}

void AnalogSensorPosition::run(){
  while(1){
    if(ptrmem!=NULL)
      *ptrmem = position_rideau;
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
      cout << "((((eteintLed))))\n";
    
    if(state==HIGH)
      cout << "((((allumeLed))))\n";
    sleep(temps);
    }
}

// classe IntelligentDigitalActuatorLED
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

// classe AnalogActuatorMoteur
AnalogActuatorMotor::AnalogActuatorMotor(int t):Device(),input(0),temps(t){
}

void AnalogActuatorMotor::checkRange(int in){
    if(in<0||in>100)
    throw InputException();
}

void AnalogActuatorMotor::run(){
  while(1){
    if(ptrmem!=NULL)
      input=*ptrmem;
    try{
      checkRange(input);
      //luminosite_rideau = luminosite_externe*position_rideau/100;
      if (input==0){
        cout << "((((eteintMoteur))))\n";
      }
      else if(position_rideau == input){
        cout << "((((eteintMoteur))))\n";
        //luminosite_rideau = luminosite_externe*input/100;
      }
      else if(input > position_rideau){
        cout << "((((allumeMoteur en mode Ascension))))\n";
        position_rideau++;
      }
      else if(input < position_rideau){
        cout << "((((allumeMoteur en mode Descente))))\n";
        position_rideau--;
      }
    }
    catch(InputException e){
      cout<<"[Position Exception: input illegal (Rappel input doit etre 0-100)]\n";
    }
    sleep(temps);
  }
}

// classe IntelligentAnalogActuatorLamp
IntelligentAnalogActuatorLamp::IntelligentAnalogActuatorLamp(int t):Device(),level(0),temps(t){
}

void IntelligentAnalogActuatorLamp::checkLevel(int l){
  if(l<0||l>4)
    throw LampException(l);
}

void IntelligentAnalogActuatorLamp::run(){
  while(1){
    if(ptrmem!=NULL)
      level=*ptrmem;
    try{
      checkLevel(level);
      switch (level){
        case 1:
          luminosite_lampe = 50;
          cout << "((((allumeLampe a niveau 1))))\n";
        break;
        case 2:
        luminosite_lampe = 100;
        cout << "((((allumeLampe a niveau 2))))\n";
        break;
        case 3:
        luminosite_lampe = 150;
        cout << "((((allumeLampe a niveau 3))))\n";
        break;
        case 4:
        luminosite_lampe = 200;
        cout << "((((allumeLampe a niveau 4))))\n";
        break;
        default:
        luminosite_lampe = 0;
        cout << "((((eteintLampe))))\n";
      }
    }
    catch(LampException e){
      cout <<"[Lampe Exception : niveau "<< e.getLevel() << " excede le domaine de niveau (0-4)]\n";
    }
    sleep(temps);
  }
}

// classe AnalogActuatorChauffClim
AnalogActuatorChauffClim::AnalogActuatorChauffClim(int t):Device(),input(0),temps(t){
}

void AnalogActuatorChauffClim::checkFigure(int in){
    if(in!=0 && (in<20||in>25))
    throw InputException();
}

void AnalogActuatorChauffClim::run(){
  while(1){
    if(ptrmem!=NULL)
      input=*ptrmem;
    try{
      checkFigure(input);
      if (input==0){
        cout << "((((eteintChauffClim))))\n";
      }
      else if(temperature_environnement == input){
        cout << "((((allumeChauffClim en mode Temperature Constante))))\n";
      }
      else if(input > temperature_environnement){
        cout << "((((allumeChauffClim en mode Chauffage))))\n";
        temperature_environnement++;
      }
      else if(input < temperature_environnement){
        cout << "((((allumeChauffClim en mode Refroidissement))))\n";
        temperature_environnement--;
      }
    }
    catch(InputException e){
      cout<<"[Position Exception: input illegal (Rappel input doit etre 0-100)]\n";
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
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t) : Device(),stateb(LOW),temps(t){

}

void ExternalDigitalSensorButton::run(){
  while(1){
    if(ptrmem!=NULL){
      if(ifstream("on.txt")){// le fichier existe
        stateb=1; // le bouton est on
      }
      else{
        stateb=0;
      }
      *ptrmem = stateb;
    }
    sleep(temps);
  }  
}