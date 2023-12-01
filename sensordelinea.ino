#define LE 2
#define MID 4
#define RIG 10
#define ML1 7
#define ML2 8
#define MLPWM 5
#define MR1 11
#define MR2 9
#define MRPWM 6
int sr;
int sm;
int sl;
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
void setup() {
  Serial.begin(9600);
  pinMode(LE,INPUT);pinMode(MID,INPUT);pinMode(RIG,INPUT);
  pinMode(ML1,OUTPUT);pinMode(ML2,OUTPUT);pinMode(MLPWM,OUTPUT);
  pinMode(MR1,OUTPUT);pinMode(MR2,OUTPUT);pinMode(MRPWM,OUTPUT);
  digitalWrite(ML1,LOW);digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);digitalWrite(MR2,LOW);
}
void loop() {
  //descomentar la funcion que quieras usar
  //linea();
  //lineatras();
}
