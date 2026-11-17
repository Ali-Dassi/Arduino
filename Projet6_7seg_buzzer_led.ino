int seg[8]={2,3,4,5,6,7,8,9};
const int num[10][8]={
  {1,1,1,1,1,1,0,0},//0
  {0,1,1,0,0,0,0,0},//1
  {1,1,0,1,1,0,1,0},//2
  {1,1,1,1,0,0,1,0},//3
  {0,1,1,0,0,1,1,0},//4
  {1,0,1,1,0,1,1,0},//5
  {1,0,1,1,1,1,1,0},//6
  {1,1,1,0,0,0,0,0},//7
  {1,1,1,1,1,1,1,0},//8
  {1,1,1,1,0,1,1,0} //9
  };




void setup() {
  for (int i=0 ;( i<9) ; i++){
    pinMode(seg[i],OUTPUT);
    digitalWrite(seg[i],LOW);
  }
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);
  // put your setup code here, to run once:

}

void loop() {
  for (int j=0 ;( j<10) ; j++){
    for (int i=0 ;( i<8) ; i++){
      digitalWrite(seg[i],num[j][i]);
      
    }
    delay(1000); 
     if (j==9){
        digitalWrite(11,HIGH);
        digitalWrite(12,HIGH);
        delay(500);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);
      }
  }
  // put your main code here, to run repeatedly:

}
