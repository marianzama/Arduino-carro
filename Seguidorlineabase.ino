
static int Pin1 = //falta saber que pines vamos a utilizar
static int Pin2 = //falta saber que pines vamos a utilizar
static int Pin3 = //falta saber que pines vamos a utilizar
static int Pin4 = //falta saber que pines vamos a utilizar
static int Pin5 = //falta saber que pines vamos a utilizar
static int Pin6 = //falta saber que pines vamos a utilizar
static int Pin_sensor1 = //falta saber que pines vamos a utilizar
static int Pin_sensor2 = //falta saber que pines vamos a utilizar
static int Pin_sensor3 = //falta saber que pines vamos a utilizar

void setup() {
  Serial.begin(9600);               //iniciamos las comunicaciones con el puerto serie para el monitor serie
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
  pinMode(Pin6, OUTPUT);
  pinMode(Pin_sensor1, INPUT);       //definimos el pin que vamos a utilizar como entrada para el sensor izquierdo
  pinMode(Pin_sensor2, INPUT);       //definimos el pin que vamos a utilizar como entrada para el sensor derecho
  pinMode(Pin_sensor3, INPUT);       //definimos el pin que vamos a utilizar como entrada para el sensor de en medio

}

void loop() {
  
  int value1 = 0;                        // Variable temporal que usaremos para recoger la señal del sensor izquierdo
  int value2 = 0;                        // Variable temporal que usaremos para recoger la señal del sensor derecho
  int value3 = 0;
  value1 = digitalRead(Pin_sensor1);     // lectura digital de pin del sensor1
  value2 = digitalRead(Pin_sensor2);     // lectura digital de pin del sensor2
  value1 = digitalRead(Pin_sensor3);     // lectura digital de pin del sensor3


  if (value1 == LOW & value2== LOW & value3==LOW) 
  {
    Serial.println("adelante");
    MotorAdelanteAA();    
  }
  
  if (value1 == HIGH & value2== HIGH & value3==HIGH) 
  {
    Serial.println("detenido");
    MotorStopAA();    
  }
 
   if (value1 == HIGH && value2 == LOW && value3==LOw) // Si el sensor izuierdo detecta una zona oscura    
    {
     Serial.println("izquierda");
     MotorIzquierdaAA();
    } 
    
   if (value2 == HIGH && value1 == LOW && value3==LOw) // Si el sensor derecho detecta una zona oscura  
    { 
     Serial.println("derecha"); 
     MotorDerechaAA();
    }
  if (value3==HIGH && value1 == LOW && value2== LOW){
    Serial.println("adelante")
    MotorAdelanteAA();
    }
  delay(20);                             // Hacemos una pausa en milisegundos, de forma que leemos el sensor cada dicho tiempo
}
  
  void MotorIzquierdaAA()
  {
  digitalWrite (Pin1, HIGH);            // Motor Izquierdo atras
  digitalWrite (Pin2, LOW);  
  digitalWrite (Pin3, HIGH);            // Motor Derecho adelante
  digitalWrite (Pin4, LOW); 
  digitalWrite(Pin5, HIGH);
  digitalWrite(Pin6,LOW);
  }

  void MotorDerechaAA()
  {
  digitalWrite (Pin1, LOW);             // Motor Izquierdo adelante
  digitalWrite (Pin2, HIGH);  
  digitalWrite (Pin3, LOW);             // Motor Derecho atras
  digitalWrite (Pin4, HIGH);
  digitalWrite(Pin5, LOW);
  digitalWrite(Pin6, HIGH);
  }

  void MotorAdelanteAA()
  {
  digitalWrite (Pin1, LOW);             // Motor Izquierdo adelante
  digitalWrite (Pin2, HIGH); 
  digitalWrite (Pin3, HIGH);            // Motor Derecho adelante
  digitalWrite (Pin4, LOW); 
  digitalWrite(Pin5, LOW);
  digitalWrite(Pin6, HIGH);
  } //checar bien esta función 

  void MotorStopAA()
  {
  digitalWrite (Pin1, LOW);             // Motor Izquierdo detenido
  digitalWrite (Pin2, LOW);
  digitalWrite (Pin3, LOW);             // Motor Derecho detenido 
  digitalWrite (Pin4, LOW);
  digitalWrite(Pin5, LOW);
  digitalWrite(Pin6,LOW);
  }
