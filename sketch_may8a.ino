#include <LiquidCrystal.h>

const int rs = 2;
const int en = 3;
const int d4 = 6;
const int d5 = 7;
const int d6 = 8;
const int d7 = 9;

int tempInput = A0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  Serial.begin(9600);
  delay(500); 
  lcd.begin(16, 2);
  delay(100);  
}

void loop() {
  float voltage = analogRead(tempInput) * (5.0 / 1023.0);
  float temp = voltage * 100;
  
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  
    lcd.setCursor(0, 2);

  lcd.print(temp, 1);  
  lcd.print(" C ");   
  
  Serial.print("Temperature: ");
  Serial.println(temp);
  
  delay(1000);
}