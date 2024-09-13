#include <Encoder.h>
#define INT1 6
#define INT2 7
#define INT3 8
#define INT4 9

#define power 150

Encoder motorEsq(2, 3); //Pinos dos encoders
Encoder motorDir(4, 5); //Mesma coisa

// Parâmetros do robô
const float L = 0.3;  // Distância entre as rodas em metros (por exemplo)
const float raioRoda = 0.015;  // Raio da roda em metros (1,5 cm)
const float C = 2 * 3.14159 * raioRoda;  // Circunferência da roda

float deltaTheta;
long deltaPulsosEsquerda;
long deltaPulsosDireita;
long deltaP;

long posicaoEsquerda = 0;
long posicaoDireita = 0;

float atualX = 0;
float atualY = 0;
float novoX;
float novoY;

float angulo;

bool xBool;
bool yBool;



void setup() {
Serial.begin(115200);
analogWrite(10, power);
analogWrite(11, power);
pinMode(INT1, OUTPUT);
pinMode(INT2, OUTPUT);
pinMode(INT3, OUTPUT);
pinMode(INT4, OUTPUT);

}

void x(){
atualX = motorEsq.read() / motorDir.read();
if(atualX > novoX){
  while(novoX != atualX){
    xBool = true;
    atualX = motorEsq.read() / motorDir.read() / 20;
    atualX /= 720;
  while(angulo != 270){
   digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, LOW);
   digitalWrite(INT4, HIGH);
  deltaPulsosEsquerda = motorEsq.read() - posicaoEsquerda;
  deltaPulsosDireita = motorDir.read() - posicaoDireita;
  deltaP = deltaPulsosEsquerda - deltaPulsosDireita;

  // Atualizar as posições anteriores
  posicaoEsquerda = motorEsq.read();
  posicaoDireita = motorDir.read();
  
  // Converter a diferença de pulsos para o ângulo
  deltaTheta = (deltaP * C) / L;  // Em radianos
  angulo += deltaTheta * (180.0 / 3.14159);  // Converter para graus
  Serial.println(angulo);
  // Garantir que o ângulo esteja entre 0 e 360 graus
  if (angulo < 0) {
    angulo += 360;
  } else if (angulo >= 360) {
    angulo -= 360;
  }
  
 // sem ideia agora (girar para 270°)
  }  
   digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, HIGH);
   digitalWrite(INT4, LOW);
   Serial.println(x);
   if(novoX == atualX) {xBool = false;}
  }
}
else if(atualX < novoX){
while(novoX != atualX){
    xBool = true;
    atualX = motorEsq.read() / motorDir.read() / 20;
    atualX /= 720;
  while(angulo != 90){
   digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, LOW);
   digitalWrite(INT4, HIGH);
  deltaPulsosEsquerda = motorEsq.read() - posicaoEsquerda;
  deltaPulsosDireita = motorDir.read() - posicaoDireita;
  deltaP = deltaPulsosEsquerda - deltaPulsosDireita;

  // Atualizar as posições anteriores
  posicaoEsquerda = motorEsq.read();
  posicaoDireita = motorDir.read();
  
  // Converter a diferença de pulsos para o ângulo
  deltaTheta = (deltaP * C) / L;  // Em radianos
  angulo += deltaTheta * (180.0 / 3.14159);  // Converter para graus
  Serial.println(angulo);
  // Garantir que o ângulo esteja entre 0 e 360 graus
  if (angulo < 0) {
    angulo += 360;
  } else if (angulo >= 360) {
    angulo -= 360;
  }
  
 // sem ideia agora (girar para 90°)
  }  
   digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, HIGH);
   digitalWrite(INT4, LOW);
   Serial.println(x);
   if(novoX == atualX) {xBool = false;}
  }
 }
atualX = motorEsq.read() / motorDir.read() / 20;
atualX /= 720;
return;
}



void y(){
atualY = motorEsq.read() / motorDir.read();
if(atualY > novoY){
  while(novoY != atualY){
    yBool = true;
    atualY = motorEsq.read() / motorDir.read() / 16;
    atualY /= 720;
  while(angulo != 180){
digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, LOW);
   digitalWrite(INT4, HIGH);
  deltaPulsosEsquerda = motorEsq.read() - posicaoEsquerda;
  deltaPulsosDireita = motorDir.read() - posicaoDireita;
  deltaP = deltaPulsosEsquerda - deltaPulsosDireita;

  // Atualizar as posições anteriores
  posicaoEsquerda = motorEsq.read();
  posicaoDireita = motorDir.read();
  
  // Converter a diferença de pulsos para o ângulo
  deltaTheta = (deltaP * C) / L;  // Em radianos
  angulo += deltaTheta * (180.0 / 3.14159);  // Converter para graus
  Serial.println(angulo);
  // Garantir que o ângulo esteja entre 0 e 360 graus
  if (angulo < 0) {
    angulo += 360;
  } else if (angulo >= 360) {
    angulo -= 360;
  }
  
  }  
   digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, HIGH);
   digitalWrite(INT4, LOW);
   Serial.println(y);
   if(novoY == atualY) {yBool = false;}
  }
}
else if(atualY < novoY){
while(novoY != atualY){
    yBool = true;
    atualY = motorEsq.read() / motorDir.read() / 16;
    atualY /= 720;
  while(angulo != 0){
   digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, LOW);
   digitalWrite(INT4, HIGH);
  deltaPulsosEsquerda = motorEsq.read() - posicaoEsquerda;
  deltaPulsosDireita = motorDir.read() - posicaoDireita;
  deltaP = deltaPulsosEsquerda - deltaPulsosDireita;

  // Atualizar as posições anteriores
  posicaoEsquerda = motorEsq.read();
  posicaoDireita = motorDir.read();
  
  // Converter a diferença de pulsos para o ângulo
  deltaTheta = (deltaP * C) / L;  // Em radianos
  angulo += deltaTheta * (180.0 / 3.14159);  // Converter para graus
  Serial.println(angulo);
  // Garantir que o ângulo esteja entre 0 e 360 graus
  if (angulo < 0) {
    angulo += 360;
  } else if (angulo >= 360) {
    angulo -= 360;
  }
  
  }  
   digitalWrite(INT1, HIGH);
   digitalWrite(INT2, LOW);
   digitalWrite(INT3, HIGH);
   digitalWrite(INT4, LOW);
   Serial.println(y);
   if(novoY == atualY) {yBool = false;}
  }
 }
atualY = motorEsq.read() / motorDir.read() / 16;
atualY /= 720;
return;
}




void loop() {
x();
y();
}
