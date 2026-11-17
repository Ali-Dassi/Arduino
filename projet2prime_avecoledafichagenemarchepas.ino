#include <Wire.h>
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define Sound_D0 3
#define Sound_A0 A0
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);
Servo myservo ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sound_D0,INPUT);
  myservo.attach(2);
  display.begin(0x3C, true); // adresse I2C souvent 0x3C
  display.clearDisplay();
  display.setTextSize(2);
  display.invertDisplay(SH110X_WHITE);
  display.setCursor(10,10);
  display.print("bonjour");

}

void loop() {
  int sound_In =analogRead(Sound_A0);//0-1023
  Serial.println(sound_In);
  int seuil=digitalRead(Sound_D0);
  display.setCursor(10,20);
  display.print(sound_In);

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
