#define pinSensorD 11
#define pinSensorE 12

#define pinMotorE1 2 
#define pinMotorE2 3 
#define pinMotorD1 4
#define pinMotorD2 5
#define pwm_MD 6
#define pwm_ME 9
#define velocidade 120            // aumenta a velocidade o robô por PWM velocidade maxima 255


void setup() {
  // put your setup code here, to run once:
  pinMode(pinSensorD, INPUT);
  pinMode(pinSensorE, INPUT);

  pinMode(pinMotorD1, OUTPUT);
  pinMode(pinMotorD2, OUTPUT);
  pinMode(pinMotorE1, OUTPUT);
  pinMode(pinMotorE2, OUTPUT);
  pinMode(pwm_MD, OUTPUT);
  pinMode(pwm_ME, OUTPUT);

  analogWrite(pwm_MD, velocidade);
  analogWrite(pwm_ME, velocidade);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bool estadoD = digitalRead(pinSensorD);               // para inverter a cor da linha retirar a exclamação
  bool estadoE = digitalRead(pinSensorE);

  if (estadoD && estadoE) {                             // Avanço do Robô
     digitalWrite(pinMotorD2, LOW); 
     digitalWrite(pinMotorD1, HIGH);
     digitalWrite(pinMotorE1, LOW);
     digitalWrite(pinMotorE2, HIGH);
  }

  if (!estadoD && !estadoE) {                           // caso encontre um cruzamento o robô para aguarda 3s e avaça novamente
     digitalWrite(pinMotorD1, LOW);
     digitalWrite(pinMotorD2, LOW);
     digitalWrite(pinMotorE1, LOW);
     digitalWrite(pinMotorE2, LOW);
     delay(3000);
     digitalWrite(pinMotorD2, LOW); 
     digitalWrite(pinMotorD1, HIGH);
     digitalWrite(pinMotorE1, LOW);
     digitalWrite(pinMotorE2, HIGH);
     delay(2000);
     
  }

  if (!estadoD && estadoE) {                        // caso encontre uma curva para esquerda inverte os motores para realiza-la
     digitalWrite(pinMotorE1, LOW);
     digitalWrite(pinMotorE2, HIGH);
     digitalWrite(pinMotorD1, LOW);
     digitalWrite(pinMotorD2, HIGH);
  }

  if (estadoD && !estadoE) {                        // caso encontre uma curva para direita inverte os motores para realiza-la
     digitalWrite(pinMotorD2, LOW);
     digitalWrite(pinMotorD1, HIGH);
     digitalWrite(pinMotorE2, LOW);
     digitalWrite(pinMotorE1, HIGH);
  }
  
}
