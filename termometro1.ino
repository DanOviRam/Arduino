/* Termometro con lm35, LCD, y led RGB
*/
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int sensor=0;
const int ledRojo=9;
const int ledAzul=8;

long milivolts;
long temperatura;
int brillo;
int contrastPin = 6; //Pin que identifica el pin donde esta conectado el puerto de contraste del LCD
int contrastValue= 1; // Valor del contraste en la Pantalla (5-20)
void setup() {
  
  
  // put your setup code here, to run once:
  lcd.begin(16,2);
   //Seteo el pin "contrast" del LCS
  pinMode(contrastPin,OUTPUT); //El pin contrast (LCD) debe estar configurado como salida
  lcd.print("Temperatura ");
  pinMode(ledRojo,OUTPUT);
  pinMode(ledAzul,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  milivolts=(analogRead(sensor)*2500L)/1023;
  temperatura=milivolts/10;
  brillo=map(temperatura,0,100,0,255);
  brillo=constrain(brillo,0,255);
  analogWrite(ledRojo,brillo);
  analogWrite(ledAzul,255-brillo);
  Serial.print("Temperatura ");
  Serial.print(temperatura);
  Serial.println("grados ");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Temp ");
  lcd.print(temperatura);

 lcd.print(" grados");



  
}