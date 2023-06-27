#include "SoftwareSerial.h"
#include "SuperMotor.h"

//TX - RX
SoftwareSerial bluetooth(8, 12);

SuperMotor motorDireito(3, 2, 6);
SuperMotor motorEsquerdo(5, 7, 4);

void setup(){
    Serial.begin(9600);
    bluetooth.begin(9600);

    motorDireito.enable();
    motorEsquerdo.enable();
}

void loop(){

    switch(bluetooth.read()){
      case 'F':
            motorDireito.frente();
            motorEsquerdo.frente();
      break;

      case 'B':
            motorDireito.tras();
            motorEsquerdo.tras();
      break;

      case 'R':
            motorDireito.frente();
            motorEsquerdo.tras();
      break;

      case 'L':
            motorDireito.tras();
            motorEsquerdo.frente();
      break;

      case '0':
             motorDireito.parar();
            motorEsquerdo.parar();
      break;
    }
    
  
}