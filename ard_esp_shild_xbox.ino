#include <AFMotor.h>
#include <Servo.h>

int lateral;
int axial;
int yaw1;
int rightFront;
int leftFront;
int rightBack;
int leftBack;
int Gat2;

Servo servo;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // Inicializa a serial
  Serial.begin(9600);
  servo.attach(A0);
}

void Reciver(){
String received = Serial.readStringUntil('\n');
    
rightFront = axial - lateral + yaw1;
leftFront = axial + lateral - yaw1;
rightBack = axial + lateral + yaw1;
leftBack = axial - lateral - yaw1; 

    // Verifica e armazena a variável correspondente
    if (received.startsWith("  Axial: ")) {
      axial = received.substring(8).toInt(); // Extrai o valor e converte para inteiro
     // Serial.print("  Axial: ");
     // Serial.print(axial);
    }
    if (received.startsWith("  Later: ")) {
      lateral = received.substring(8).toInt(); // Extrai o valor e converte para inteiro
     // Serial.print("  Lateral: ");
     // Serial.print(lateral);
    }
    if (received.startsWith("  Yaw1: ")) {
      yaw1 = received.substring(8).toInt(); // Extrai o valor e converte para inteiro
     // Serial.print("  Yaw1: ");
     // Serial.print(yaw1);
    }
    if (received.startsWith("  Gat2: ")) {
      Gat2 = received.substring(8).toInt(); // Extrai o valor e converte para inteiro
      servo.write(map(Gat2, 0, 1023, 0, 180));
    }
Serial.print(leftFront / 2);
Serial.print('\t');
Serial.print(rightFront / 2);
Serial.print('\t');
Serial.print(leftBack / 2);
Serial.print('\t');
Serial.print(rightBack / 2);
Serial.println('\t');

 power();
 direction();

}

void power(){
if(rightFront < 0){
    motor2.setSpeed(rightFront * -1);  
  } else {
    motor2.setSpeed(rightFront);
  }
  if(leftFront < 0){
    motor3.setSpeed(leftFront * -1);  
  } else{
    motor3.setSpeed(leftFront);
  }
  if(leftBack < 0){
    motor4.setSpeed(leftBack * -1);
  }else{
    motor4.setSpeed(leftBack);  
  }
  if(rightBack < 0){
    motor1.setSpeed(rightBack * -1);  
  } else{
    motor1.setSpeed(rightBack);
  }  
}

void direction(){
  if(leftFront > 0){
motor3.run(BACKWARD);
} else{
  motor3.run(FORWARD);
}

if(leftBack > 0){
motor4.run(BACKWARD);
} else{
  motor4.run(FORWARD);
}

if(rightFront > 0){
motor2.run(BACKWARD);
} else{
  motor2.run(FORWARD);
}

if(rightBack > 0){
motor1.run(BACKWARD);
} else{
  motor1.run(FORWARD);
}

}


void loop() {

  if (Serial.available()) {
  Reciver();
  }
}