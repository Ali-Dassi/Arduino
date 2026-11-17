#include <Servo.h>
#define Sound_D0 3
#define Sound_A0 A0
Servo myservo ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sound_D0,INPUT);
  myservo.attach(2);

}

void loop() {
  int sound_In =analogRead(Sound_A0);//0-1023
  Serial.println(sound_In);
  int seuil=digitalRead(Sound_D0);
  if (sound_In <66){
    Serial.println("oui");

  }
  else{
    Serial.println("non");
  }
  myservo.write(sound_In);
  // put your main code here, to run repeatedly:
  delay(1000);
}

