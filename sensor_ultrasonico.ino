#include <Servo.h>
#define EC A4
#define TR A5
#define ML1 7
#define ML2 8
#define MLPWM 5
#define MR1 11
#define MR2 9
#define MRPWM 6
Servo S1;
#define pinS 3
void Motoradelante(float VEL){
  analogWrite(MLPWM,VEL);analogWrite(MRPWM,VEL);
  digitalWrite(ML1,HIGH);digitalWrite(ML2,LOW);
  digitalWrite(MR1,HIGH);digitalWrite(MR2,LOW);
}
void Motorrever(float VEL){
  analogWrite(MLPWM,VEL);analogWrite(MRPWM,VEL);
  digitalWrite(ML1,LOW);digitalWrite(ML2,HIGH);
  digitalWrite(MR1,LOW);digitalWrite(MR2,HIGH);
}
void Motorpausa(){
  analogWrite(MLPWM,0);analogWrite(MRPWM,0);
  digitalWrite(ML1,LOW);digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);digitalWrite(MR2,LOW);
}
void Motorder(float VEL){
  analogWrite(MLPWM,VEL);analogWrite(MRPWM,VEL);
  digitalWrite(ML1,HIGH);digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);digitalWrite(MR2,HIGH);
}
void Motorizq(float VEL){
  analogWrite(MLPWM,VEL);analogWrite(MRPWM,VEL);
  digitalWrite(ML1,LOW);digitalWrite(ML2,HIGH);
  digitalWrite(MR1,HIGH);digitalWrite(MR2,LOW);
}
void ultra(){
  digitalWrite(TR,LOW);delay(10);
  digitalWrite(TR,HIGH);delay(10);
  digitalWrite(TR,LOW);
  float di=pulseIn(EC,HIGH);
  float d=di*0.034/2;
  if(d>35){
    Motoradelante(125);
    S1.write(90);
    delay(1000);
  }
  if(d<=35){
    Motorpausa();
    S1.write(0);
    delay(1000);
    if(d<=35){
      S1.write(180);
      delay(1000);
      if(d<=35){
        Motorder(255);
        delay(300);
        S1.write(90);
      }else{
        Motorizq(255); 
        delay(300);
        S1.write(90); 
      }
    }
  }
}
void setup() {
  Serial.begin(9600);
  pinMode(EC,INPUT);pinMode(TR,OUTPUT);
  pinMode(ML1,OUTPUT);pinMode(ML2,OUTPUT);pinMode(MLPWM,OUTPUT);
  pinMode(MR1,OUTPUT);pinMode(MR2,OUTPUT);pinMode(MRPWM,OUTPUT);
  digitalWrite(ML1,LOW);digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);digitalWrite(MR2,LOW);
  S1.attach(pinS);S1.write(90);delay(1000);
}

void loop() {
  ultra();
}
