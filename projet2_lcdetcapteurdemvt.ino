#include <Wire.h>
#include <LiquidCrystal.h>
#define mvt 8 
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  
  pinMode(mvt,INPUT);


}

void loop() {
  int mv=digitalRead(mvt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("bonjour <3");
  // put your main code here, to run repeatedly:
  if (mv== HIGH){
    lcd.setCursor(1,1);
    lcd.print("objet detecté");
     
  }
  else{
    lcd.setCursor(1,1);
    lcd.print("safe");
    

  }
  delay(1000);

}
