//Programa: Display LCD 16x2 e modulo I2C
//Autor: Arduino e Cia

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
String sWord = "espada";

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);
 
void setup()
{
  Serial.begin(9600);
 lcd.init();
}
 
void loop()
{
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print(".");
  delay(700);
  lcd.clear();
  lcd.print("..");
  delay(700);
  lcd.clear();
  lcd.print("...");
  delay(700);
  lcd.clear();

  String received = Serial.readStringUntil('\n');

   if (received.startsWith("  Palavra: ")) {
    sWord = received.substring(8);
     Serial.println("Palavra: ");
     Serial.print(sWord);
     lcd.print(sWord);
    }

  delay(5000);
  lcd.clear();  
}
