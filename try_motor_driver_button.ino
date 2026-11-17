#include <Stepper.h>
#define STEPS 2048
Stepper moteur(STEPS,8,10,9,11);
const int button =12;
void setup() {
  pinMode(button,INPUT_PULLUP);
  moteur.setSpeed(10);
  // put your setup code here, to run once:

}

void loop() {
  if(digitalRead(button)==LOW){
    moteur.step(500);
    delay(1000);
  }
  
     

  
   
  

  // put your main code here, to run repeatedly:

}
