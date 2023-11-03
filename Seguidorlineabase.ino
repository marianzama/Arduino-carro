
static int PinIN1 = //falta saber que pines vamos a utilizar
static int PinIN2 = //falta saber que pines vamos a utilizar
static int PinIN3 = //falta saber que pines vamos a utilizar
static int PinIN4 = //falta saber que pines vamos a utilizar
static int Pin_sensor1 = //falta saber que pines vamos a utilizar
static int Pin_sensor2 = //falta saber que pines vamos a utilizar
static int Pin_sensor3 = //falta saber que pines vamos a utilizar

void setup() {
  Serial.begin(9600);               //iniciamos las comunicaciones con el puerto serie para el monitor serie
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
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
    MotorAdelante();    
  }
  
  if (value1 == HIGH & value2== HIGH & value3==HIGH) 
  {
    Serial.println("detenido");
    MotorStop();    
  }
 
   if (value1 == HIGH && value2 == LOW) // Si el sensor izuierdo detecta una zona oscura    
    {
     Serial.println("izquierda");
     MotorIzquierda();
    } 
    
   if (value2 == HIGH && value1 == LOW) // Si el sensor derecho detecta una zona oscura  
    { 
     Serial.println("derecha"); 
     MotorDerecha();
    }
 
  delay(20);                             // Hacemos una pausa en milisegundos, de forma que leemos el sensor cada dicho tiempo
}
  
  void MotorIzquierda()
  {
  digitalWrite (PinIN1, HIGH);            // Motor Izquierdo atras
  digitalWrite (PinIN2, LOW);  
  digitalWrite (PinIN3, HIGH);            // Motor Derecho adelante
  digitalWrite (PinIN4, LOW); 
  }

  void MotorDerecha()
  {
  digitalWrite (PinIN1, LOW);             // Motor Izquierdo adelante
  digitalWrite (PinIN2, HIGH);  
  digitalWrite (PinIN3, LOW);             // Motor Derecho atras
  digitalWrite (PinIN4, HIGH);
  }

  void MotorAdelante()
  {
  digitalWrite (PinIN1, LOW);             // Motor Izquierdo adelante
  digitalWrite (PinIN2, HIGH); 
  digitalWrite (PinIN3, HIGH);            // Motor Derecho adelante
  digitalWrite (PinIN4, LOW); 
  }

  void MotorStop()
  {
  digitalWrite (PinIN1, LOW);             // Motor Izquierdo detenido
  digitalWrite (PinIN2, LOW);
  digitalWrite (PinIN3, LOW);             // Motor Derecho detenido 
  digitalWrite (PinIN4, LOW);
  
  }
