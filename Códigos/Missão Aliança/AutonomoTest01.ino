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
int delays[] = {100 /*0*/, 1000/*1*/, 2500/*2*/, 500/*3*/, 5/*4*/}; //se pa q assim fica mais facil de mudar dps
motor1.setSpeed(0);
 motor2.setSpeed(0);
 motor3.setSpeed(0);
 motor4.setSpeed(0);
 motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);

delay(delays[0]);
motor1.setSpeed(120);
 motor2.setSpeed(120);
 motor3.setSpeed(120);
 motor4.setSpeed(120);

ldDir();
delay(delays[1]);

forwards();
delay(delays[3]);

ldDir();
delay(delays[3]);
//solta o blc
servo2.write(90);

ldEsq();
servo2.write(0);
delay(delays[1]);
forwards();
delay(delays[0]);
//solta o outro
servo2.write(90);
backward();
delay(delays[0]);

ldEsq();
delay(delays[1]);
backward();
delay(delays[0]);
//solta o conector magnetico

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


