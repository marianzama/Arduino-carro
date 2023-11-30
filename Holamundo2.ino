#include <SoftwareSerial.h>
SoftwareSerial BT(0,1); // RX, TX recorder que se cruzan
// Motor 1
#define ML1 7
#define ML2 8
#define MLPWM 5
#define MR1 11
#define MR2 9
#define MRPWM 6
void setup() {
 Serial.begin(9600);
 BT.begin(9600);
 pinMode(ML1,OUTPUT);
 pinMode(ML2,OUTPUT);
 pinMode(MLPWM,OUTPUT);
 pinMode(MR1,OUTPUT);
 pinMode(MR2,OUTPUT);
 pinMode(MRPWM,OUTPUT); 
}
void loop() {
  if (BT.available()){
    char dato=BT.read();
    switch(dato){
      case 'w':
        Motoradelante(125);
        break;
      case 's':
        Motorrever(125);
        break;
      case 'd':
        Motorder(125);
        break;
      case 'a':
        Motorizq(125);
        break;
      case 'p':
        Motorpausa();
        break;
    }    
  }
}
void Motoradelante(int VEL){
  analogWrite(MLPWM,VEL);
  analogWrite(MRPWM,VEL);
  digitalWrite(ML1,HIGH);
  digitalWrite(ML2,LOW);
  digitalWrite(MR1,HIGH);
  digitalWrite(MR2,LOW);
}
void Motorrever(int VEL){
  analogWrite(MLPWM,VEL);
  analogWrite(MRPWM,VEL);
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,HIGH);
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,HIGH);
}
void Motorpausa(){
  analogWrite(MLPWM,0);
  analogWrite(MRPWM,0);
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,LOW);
}
void Motorder(int VEL){
  analogWrite(MLPWM,VEL);
  analogWrite(MRPWM,VEL);
  digitalWrite(ML1,HIGH);
  digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,HIGH);
}
void Motorizq(int VEL){
  analogWrite(MLPWM,VEL);
  analogWrite(MRPWM,VEL);
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,HIGH);
  digitalWrite(MR1,HIGH);
  digitalWrite(MR2,LOW);
}
