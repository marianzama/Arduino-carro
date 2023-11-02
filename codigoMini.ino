  // Pines de los motores
    // Modificar si el giro de motores no es el adecuado
#define PIN_MOTOR_LEFT_1        6
#define PIN_MOTOR_LEFT_2        5
#define PIN_MOTOR_RIGHT_1       11
#define PIN_MOTOR_RIGHT_2       10

  // Pines de los sensores
    // Modificar segun se soldo la placa
#define PIN_SENSOR_LEFT         A4
#define PIN_SENSOR_MIDDLE       A3
#define PIN_SENSOR_RIGHT        A2
#define PIN_LINE_SENSOR_LEFT    A5
#define PIN_LINE_SENSOR_RIGHT   A1

  //Valores de referencia para los sensores de línea
#define L_LINE_REF_VALUE 200
#define R_LINE_REF_VALUE 200

  // Pines de otros componentes
#define PIN_RED_LED             13
#define PIN_START_MODULE        3
#define PIN_BUZZER              4
#define PIN_DIP_SW_1            7
#define PIN_DIP_SW_2            8
#define PIN_DIP_SW_3            9

  // Variables
bool sensor_left = false;
bool sensor_middle = false;
bool sensor_right = false;
bool line_sensor_left = 0;
bool line_sensor_right = 0;

  //Otras variables
int start_module_status = 0;
bool sw1_status = false;

void setup() {
  //Pines de los sensores de oponente - ENTRADAS
  pinMode(PIN_SENSOR_LEFT,INPUT);
  pinMode(PIN_SENSOR_MIDDLE,INPUT);
  pinMode(PIN_SENSOR_RIGHT,INPUT);
  //Pines de los sensores de linea - ENTRADAS
  pinMode(PIN_LINE_SENSOR_LEFT,INPUT);
  pinMode(PIN_LINE_SENSOR_RIGHT,INPUT);
  //Pines de los drivers de motores - SALIDAS
  pinMode(PIN_MOTOR_LEFT_1, OUTPUT);
  pinMode(PIN_MOTOR_LEFT_2, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_1, OUTPUT);
  pinMode(PIN_MOTOR_RIGHT_2, OUTPUT);
  //Otros dispositivos
  pinMode(PIN_RED_LED,OUTPUT);
  pinMode(PIN_START_MODULE,INPUT);
  pinMode(PIN_DIP_SW_1,INPUT);

  attachInterrupt(digitalPinToInterrupt(PIN_START_MODULE), end_match, FALLING);    // Interrupción que usaremos para detener el robot (control SONY y módulo de arranque).

  while(start_module_status == 0){
    start_module_status = digitalRead(PIN_START_MODULE);
    // para que inicie al mismo tiempo que otro robot
  }
}

void loop() {
  read_all_sensors();
  if(line_sensor_left or line_sensor_right){
      int reached_line_with_left = line_sensor_left;
      set_motors(-100,-100);
      delay(400);
      set_motors(-255,-255);
      while(line_sensor_left or line_sensor_right){
          read_all_sensors();
      }
      if(reached_line_with_left){
          set_motors(255,-255);
      }
      else{
          set_motors(-255,255);
      }
      delay(180);
  }

  else if(sensor_left == HIGH){
      set_motors(-255,255);
      delay(100);
  }
  else if(sensor_right == HIGH){
      set_motors(255,-255);
      delay(100);
  }
  else if(sensor_middle == HIGH) {
      set_motors(255,255);
  }
  else{
      sw1_status = digitalRead(PIN_DIP_SW_1);
      if (sw1_status == LOW){
          set_motors(127, 127);  
      }
      else {
          stop_movement();  
      }
  }

}

void read_all_sensors(){
    //Lectura de sensores de oponente.
    sensor_left = digitalRead(PIN_SENSOR_LEFT);
    sensor_middle = digitalRead(PIN_SENSOR_MIDDLE);
    sensor_right = digitalRead(PIN_SENSOR_RIGHT);
    
    //Lectura de sensor de linea izquierdo
    int temp_line_left = analogRead(PIN_LINE_SENSOR_LEFT);
    if (temp_line_left < L_LINE_REF_VALUE){
        line_sensor_left = 1;
    }
    else{
        line_sensor_left = 0;
    }
    
    //Lectura de sensor de linea derecho
    int temp_line_right = analogRead(PIN_LINE_SENSOR_RIGHT);
    if (temp_line_right < R_LINE_REF_VALUE){
        line_sensor_right = 1;
    }
    else{
        line_sensor_right = 0;
    }
}

void stop_movement(void){
    //Frenamos motor izquierdo
    digitalWrite(PIN_MOTOR_LEFT_1, HIGH);
    digitalWrite(PIN_MOTOR_LEFT_2, HIGH);
    //Frenamos motor derecho
    digitalWrite(PIN_MOTOR_RIGHT_1, HIGH);
    digitalWrite(PIN_MOTOR_RIGHT_2, HIGH);  
} 

void move_forward(unsigned int speed_val){
    if (speed_val > 255) speed_val = 255;
    //Motor Izquierdo
    analogWrite(PIN_MOTOR_LEFT_1, speed_val);
    digitalWrite(PIN_MOTOR_LEFT_2, LOW);
    //Motor Derecho
    analogWrite(PIN_MOTOR_RIGHT_1, speed_val);
    digitalWrite(PIN_MOTOR_RIGHT_2, LOW);
}

void move_backwards(unsigned int speed_val){
    if (speed_val > 255) speed_val = 255;
    //Motor Izquierdo
    analogWrite(PIN_MOTOR_LEFT_2, speed_val);
    digitalWrite(PIN_MOTOR_LEFT_1, LOW);
    //Motor Derecho
    analogWrite(PIN_MOTOR_RIGHT_2, speed_val);
    digitalWrite(PIN_MOTOR_RIGHT_1, LOW);
}

void set_motors(int16_t l_motor_value, int16_t r_motor_value){
    //-----Left Motor
    if(l_motor_value > 0){
        digitalWrite(PIN_MOTOR_LEFT_1, HIGH);
        analogWrite(PIN_MOTOR_LEFT_2, 255-l_motor_value);
    }
    else{
        digitalWrite(PIN_MOTOR_LEFT_2, HIGH);
        analogWrite(PIN_MOTOR_LEFT_1, 255+l_motor_value);
    }
    //-----Right Motor
    if(r_motor_value > 0){
        digitalWrite(PIN_MOTOR_RIGHT_1, HIGH);
        analogWrite(PIN_MOTOR_RIGHT_2, 255-r_motor_value);
    }
    else{
        digitalWrite(PIN_MOTOR_RIGHT_2, HIGH);
        analogWrite(PIN_MOTOR_RIGHT_1, 255+r_motor_value);
    }
}

void end_match(){
    stop_movement();
    while(1){
      digitalWrite(PIN_RED_LED,HIGH);
    }
}
