#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define rouge 3
#define vert 2
MFRC522 rfid(SS_PIN, RST_PIN);
Servo porte;

void setup() {
  pinMode(vert,OUTPUT);
  pinMode(rouge,OUTPUT);
  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  Serial.println("Approchez une carte...");

  porte.attach(8);
  porte.write(0); // Porte fermée au démarrage
  digitalWrite(vert,LOW);
  digitalWrite(rouge,HIGH);
  
}

void loop() {

  // Vérifie si une nouvelle carte est présente
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  // Vérifie si la carte peut être lue
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println("Carte detectee !");

  // Ouvrir la porte
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  porte.write(0);
  delay(3000);

  // Fermer la porte
  porte.write(95);
  delay(1000);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  // Arrête la communication avec la carte
  rfid.PICC_HaltA();

  Serial.println("Approchez une autre carte...");
}