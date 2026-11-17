float duration ;
int distance ;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);// put your setup code here, to run once:
  pinMode(13,INPUT);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  
   
}

void loop() {
  digitalWrite(12,LOW);
  delay(200);
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);

  duration = pulseIn(13,HIGH);
  distance = duration * 0.034 /2;
  if (distance <20){
    digitalWrite(2,HIGH);
    digitalWrite(8,HIGH);
    

  }
  else {
    digitalWrite(2,LOW);
    digitalWrite(8,LOW);

}
   
  if (distance<50){
    if (distance>20) {
      digitalWrite(4,HIGH);}
    else {
      digitalWrite(4,LOW);

    }

  }
  else{
    digitalWrite(4,LOW);

  } 
  if (distance > 50){
     
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
   
   
  // put your main code here, to run repeatedly:

}
