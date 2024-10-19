#include <AFMotor.h>
#include <Servo.h>


Servo servo2;
Servo servo;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
    servo.attach(9);
  servo2.attach(10);
}

void loop() {
delay(1500);
autonomo(1001);
}

void autonomo(int check){
if(check >= 1000){
servo2.write(0);
motor1.setSpeed(0);
 motor2.setSpeed(0);
 motor3.setSpeed(0);
 motor4.setSpeed(0);
 motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);

delay(3500);
motor1.setSpeed(150);
 motor2.setSpeed(150);
 motor3.setSpeed(150);
 motor4.setSpeed(175);

ldDir();
delay(1500);

forwards();
delay(850);

ldDir();
delay(600);
Stop();
delay(1000);
motor1.setSpeed(150);
 motor2.setSpeed(150);
 motor3.setSpeed(150);
 motor4.setSpeed(175);
//solta o blc
servo2.write(90);


ldEsq();
servo2.write(0);
delay(550);
forwards();]





delay(200);
//solta o outro
servo2.write(90);

ldEsq();
delay(800);

forwards();
delay(200);



Stop();
return;

}
   else if(check != 1){return;}
}

void Stop(){
 motor1.setSpeed(0);
 motor2.setSpeed(0);
 motor3.setSpeed(0);
 motor4.setSpeed(0);
 }

 void backward(){
 motor1.run(BACKWARD);
 motor2.run(BACKWARD); 
 motor3.run(BACKWARD);
 motor4.run(BACKWARD);
 }

 void ldDir(){
 motor2.run(FORWARD);
 motor1.run(BACKWARD);
 motor4.run(FORWARD);
 motor3.run(BACKWARD);
 }

 void ldEsq(){
 motor1.run(FORWARD);
 motor2.run(BACKWARD); 
 motor3.run(FORWARD);
 motor4.run(BACKWARD);
 }
 void forwards(){
 motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);
 }
