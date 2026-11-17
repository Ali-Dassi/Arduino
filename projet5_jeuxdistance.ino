#include <LiquidCrystal.h>
#define RED 9
#define GREEN 8
#define BLUE 10
#define TRIG 6
#define ECHO 7

long duree;
float distance;
int dis ;
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  // Initialise le LCD : 16 colonnes, 2 lignes
  lcd.begin(16, 2);
  
   
  // Afficher sur la deuxième ligne
  
}

void loop() {
  // Envoie une impulsion ultrason
  lcd.setCursor(0, 0);
  lcd.print("tu as 10 seconde");
  lcd.setCursor(0, 1);
  lcd.print("distance est ");
  dis=random(8,30); 
  lcd.print(String(dis));
    
  int i =random(0,225);
     
  analogWrite(RED,225-i);
  analogWrite(GREEN,i);
  analogWrite(BLUE,i);
    
  delay(10000);
  lcd.clear(); 
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  // Mesure le temps de retour
  duree = pulseIn(ECHO, HIGH);
  

  // Calcul de la distance en cm
  distance = duree * 0.034 / 2;

  lcd.setCursor(0, 0);
  lcd.print("distance est "); 
  lcd.print(String(dis));
  lcd.setCursor(0, 1);
  lcd.print("score = ");
  lcd.print(String(distance));
  if (distance+1 >dis){
    if (distance-1 <dis){
      lcd.print(" *A*");
    }
    else{
      lcd.print(" *B*");

    }
  }
  else{
    lcd.print(" *B*");
  }
  delay(10000);
  lcd.clear();}