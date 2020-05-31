
#include "mydevices.h"

using namespace std;

int temperature_environnement = 18;
int position_rideau = 15;
int luminosite_environnement = 200;
int luminosite_externe = 200;
int luminosite_rideau = luminosite_externe * position_rideau / 100;
int luminosite_led = 0;
int luminosite_lampe = 0;
int nb_humain = 1;


// classe exception
LampException::LampException(int l){
  lel=l;
}

int LampException::getLevel(){
  return lel;
}

// classe AnalogSensor
AnalogSensor::AnalogSensor(int d):Device(),temps(d){
  val = 0;
}

void AnalogSensor::run(){
  while(1){
    cout << "empty analogsensor\n";
    sleep(3);
  }
}

// classe DigitalSensor
DigitalSensor::DigitalSensor(int d): Device(),temps(d){
}

void DigitalSensor::run(){
  while(1){
    cout << "empty digitalsensor\n";
    sleep(3);
  }
}

// classe AnalogActuator
AnalogActuator::AnalogActuator(int t):Device(),input(0),temps(t){
}
void AnalogActuator::run(){
  while(1){
    cout << "empty analogactuator\n";
    sleep(3);
  }
}

// classe DigitalActuator
DigitalActuator::DigitalActuator(int d):Device(), state(LOW),temps(d){
}

void DigitalActuator::run(){
  while(1){
    cout << "empty digitalactuator\n";
    sleep(3);
  }
}


//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d):AnalogSensor(d){
  val = temperature_environnement; //valeur initiale
}

void AnalogSensorTemperature::run(){
  while(1){
    if(ptrmem!=NULL)
      *ptrmem = temperature_environnement; //lire la valeur de temperature et l ecrire a pin
    sleep(temps);
  }
}

//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):AnalogSensor(d){
  val=luminosite_environnement + luminosite_led + luminosite_lampe + luminosite_rideau; //valeur initiale
}

void AnalogSensorLuminosity::run(){
  while(1){
    if(ptrmem!=NULL){
      luminosite_rideau = luminosite_externe * position_rideau / 100;
      *ptrmem = luminosite_environnement + luminosite_led + luminosite_lampe + luminosite_rideau;// lire tous les luminosite et l ecrire a pin
    }
    sleep(temps);
  }
}

// classe AnalogSensorPosition
AnalogSensorPosition::AnalogSensorPosition(int d):AnalogSensor(d){
  val=position_rideau;//valeur initiale
}

void AnalogSensorPosition::run(){
  while(1){
    if(ptrmem!=NULL)
      *ptrmem = position_rideau; //lire la valeur de position du rideau et l ecrire a pin
    sleep(temps);
  }
}

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):DigitalActuator(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem; //lire la valeur ecrit a pin
    if (state==LOW)
      cout << "((((eteintLed))))\n"; 
    
    if(state==HIGH)
      cout << "((((allumeLed))))\n";
    sleep(temps);
    }
}

// classe IntelligentDigitalActuatorLED
IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):DigitalActuator(t){
}

void IntelligentDigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem; //lire la valeur ecrit a pin
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
AnalogActuatorMotor::AnalogActuatorMotor(int t):AnalogActuator(t){
}
// si les valeur n est pas dans la plage, lancer une exception
void AnalogActuatorMotor::checkRange(int in){
    if(in<0||in>100)
    throw InputException();
}

void AnalogActuatorMotor::run(){
  while(1){
    if(ptrmem!=NULL)
      input=*ptrmem; //lire la valeur ecrit a pin
    try{
      checkRange(input); //examine la valeur
      if (input==0){
        cout << "((((eteintMoteur))))\n";
      }
      else if(position_rideau == input){
        cout << "((((eteintMoteur))))\n";
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
IntelligentAnalogActuatorLamp::IntelligentAnalogActuatorLamp(int t):AnalogActuator(t){
}
// si les valeur n est pas dans la plage, lancer une exception
void IntelligentAnalogActuatorLamp::checkLevel(int l){
  if(l<0||l>4)
    throw LampException(l);
}

void IntelligentAnalogActuatorLamp::run(){
  while(1){
    if(ptrmem!=NULL)
      input=*ptrmem; //lire la valeur ecrit a pin
    try{
      checkLevel(input);
      switch (input){
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
AnalogActuatorChauffClim::AnalogActuatorChauffClim(int t):AnalogActuator(t){
}
// si les valeur n est pas dans la plage, lancer une exception
void AnalogActuatorChauffClim::checkFigure(int in){
    if(in!=0 && (in<20||in>25))
    throw InputException();
}

void AnalogActuatorChauffClim::run(){
  while(1){
    if(ptrmem!=NULL)
      input=*ptrmem; //lire la valur ecrit a pin
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
ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t) : DigitalSensor(t),stateb(LOW){

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
      *ptrmem = stateb; //ecrire la valeur a pin
    }
    sleep(temps);
  }  
}

//classe IrSensor
DigitalSensorIR::DigitalSensorIR(int t) : DigitalSensor(t), stateIR(LOW){

};

void DigitalSensorIR::run(){
  while(1){
    if(ptrmem!=NULL){
      if(nb_humain>0){
        stateIR = 1;
        cout << "((((peoplehere))))\n";
      }
      else{
        stateIR = 0;
        cout << "((((nobody))))\n";
      }
      *ptrmem = stateIR; // ecrire la valeur a pin
    }
    sleep(temps); 
  }
}

//classe simulant le module RTC de façon grossière, donne l'heure, date jour etc
DigitalSensorRTC::DigitalSensorRTC(int t) : DigitalSensor(t), jour(LOW){
};

void DigitalSensorRTC::run(){
  while(1){
    if(ptrmem!=NULL){
      //simule l'envoie de data du module RTC et la lecture par l'arduino
      // date / heure actuelle basée sur le système actuel
      time_t tmm = time(0);
      // convertir en forme de chaîne
      char* dt = ctime(&tmm);
      // convertir en tm struct pour UTC
      tm *g = gmtime(&tmm);
      dt = asctime(g);
      cout << "La date et l'heure UTC sont:"<< dt ;

      if(g->tm_hour < 8 or g->tm_hour>21){
        jour = 0;
      }
      else{
        jour = 1;
      }
      *ptrmem = jour;
    }
    sleep(temps);
  }
}  
