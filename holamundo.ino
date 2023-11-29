#include <Servo.h>

#define LE 2
#define MID 4
#define RIG 10
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
void ultra(){
  
}
void linea(){
  Serial.println("Seguidor de linea");
  while(true){
    int sr=digitalRead(RIG);
    int sm=digitalRead(MID);
    int sl=digitalRead(LE);
    if(sr == HIGH && sm == HIGH && sl == HIGH){
        Motorpausa();
        Motoradelante(125);
    }
    if(sm == LOW){
      if(sr == HIGH && sl == HIGH){
        Motoradelante(125);
      }
      if(sr ==HIGH && sl == LOW){
        Motorizq(125); 
      }
      if(sr == LOW && sl == HIGH){
        Motorder(125);
      }
     } 
   }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LE,INPUT);
  pinMode(MID,INPUT);
  pinMode(RIG,INPUT);
  pinMode(EC,INPUT);
  pinMode(TR,OUTPUT);
  pinMode(ML1,OUTPUT);
  pinMode(ML2,OUTPUT);
  pinMode(MLPWM,OUTPUT);
  pinMode(MR1,OUTPUT);
  pinMode(MR2,OUTPUT);
  pinMode(MRPWM,OUTPUT);
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,LOW);
  S1.attach(pinS);
  S1.write(90);
  delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  //line
//  Serial.print("LE: ");
//  Serial.print(digitalRead(LE));
//  Serial.print("   ");
//  Serial.print("MID: ");
//  Serial.print(digitalRead(MID));
//  Serial.print("   ");
//  Serial.print("RIG: ");
//  Serial.println(digitalRead(RIG));
//  //ultrasen
//  digitalWrite(TR,LOW);
//  delay(10);
//  digitalWrite(TR,HIGH);
//  delay(10);
//  digitalWrite(TR,LOW);
//  float d=pulseIn(EC,HIGH);
//  float distance=d*0.034/2;
//  Serial.print("DISTANCE: ");
//  Serial.print("   ");
//  Serial.println(distance);
  linea();
}