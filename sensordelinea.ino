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
int sr;
int sm;
int sl;
int cont;
int flag;
// quisiera declararle mi amor pero apenas se declarar variables
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
  if (d>15){
    Motoradelante(125);
  }
  if(d<=15){
    S1.write(10);
    Motorpausa();
    if (d>7){
      delay(1000);
      Motorder(125);
      delay(1000);
      Motoradelante(125);
      S1.write(90);
    }if (d<=7){
      S1.write(170);
      if (d>7){
        delay(1000);
        Motorizq(125);
        delay(1000);
        Motoradelante(125);
        S1.write(90);
      }else{
        delay(1000);
        Motorrever(125);
        S1.write(90);
      }
    }
  }
          
} 
void linea(){
  while(true){
    sr=digitalRead(RIG);sm=digitalRead(MID);sl=digitalRead(LE);
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
void lineatras(){
  while(true){
    sr=digitalRead(RIG);sm=digitalRead(MID);sl=digitalRead(LE);
    if(sr == HIGH && sm == HIGH && sl == HIGH){
        Motorpausa();
        Motorrever(125);
    }
    if(sm == LOW){
      if(sr == HIGH && sl == HIGH){
        Motorrever(125);
      }
      
   }
  }
}
//aca inicia el grid
void adelante1(){
  sr=digitalRead(RIG);sm=digitalRead(MID);sl=digitalRead(LE);
  cont=0;
  if(sm == 1){
    Motoradelante(125/1.2);
    cont=1;
  }
  if (sr==0 || sm==0 || sl==0){
    cont=0;
    Motorpausa();
    delay(1000);
    if (cont==0){
      Motorpausa();
    }else{
      Motoradelante(125/1.2);
    }
  }
}

//aca termina el grid
void setup() {
  Serial.begin(9600);
  pinMode(LE,INPUT);pinMode(MID,INPUT);pinMode(RIG,INPUT);
  pinMode(EC,INPUT);pinMode(TR,OUTPUT);
  pinMode(ML1,OUTPUT);pinMode(ML2,OUTPUT);pinMode(MLPWM,OUTPUT);
  pinMode(MR1,OUTPUT);pinMode(MR2,OUTPUT);pinMode(MRPWM,OUTPUT);
  digitalWrite(ML1,LOW);digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);digitalWrite(MR2,LOW);
  S1.attach(pinS);S1.write(90);
  delay(1000);
}
void loop() {
  //linea();
  //lineatras();
  ultra();
  //adelante1();
  //blue();
  //grid1();
  //grid2();
  //grid3();
  //grid4();
  //grid5();
  //grid6();
  //grid7();
  //grid8();
  //grid9();
  //grid10();
  //grid11();
  //grid12();
  //grid13();
  //grid14();
  //grid15();
  //grid16();
  // sr=digitalRead(RIG);sm=digitalRead(MID);sl=digitalRead(LE);
  // Serial.println(sr);
  // Serial.println(sm);
  // Serial.println(sl);
//  long t; 
//  long d; 
//
//  digitalWrite(TR, HIGH);
//  delayMicroseconds(10);         
//  digitalWrite(TR, LOW);
//  
//  t = pulseIn(EC, HIGH); 
//  d = t/59;             
//  
//  Serial.print("Distancia: ");
//  Serial.print(d);
//  Serial.print("cm");
//  Serial.println();
//  delay(100); 
}
