#include "DHT.h"
 float temp;
 float hum;
#define BLYNK_TEMPLATE_ID "TMPL23yynVv08"
#define BLYNK_TEMPLATE_NAME "temp"
#define BLYNK_AUTH_TOKEN "•••• - Tbwh"
#define type DHT11
#define pin 4

DHT sensor(pin,type);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
sensor.begin();
blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);

}

void loop() {
  // put your main code here, to run repeatedly:
temp=sensor.readTemperature();//read temperature true pour conv fer
hum=sensor.readHumidity();
blynk.virtualWrite(V0,temp);
blynk.virtualWrite(V1,temp);
Serial.println(temp);Serial.print(temp);Serial.print("C°");
Serial.println(hum);Serial.print(hum);Serial.print("%");


}
