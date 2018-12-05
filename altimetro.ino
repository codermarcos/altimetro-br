#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_BMP085.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SoftwareSerial bt(9, 10);
Adafruit_BMP085 bmp180;

void setup() {  
  bt.begin(9600); 
  lcd.begin(16, 2);
  if (!bmp180.begin())
  {
    lcd.print("ERRO: sensor");
    while (1) {}
  }
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(bmp180.readPressure());    
  
  bt.print("\t");
  bt.print(String(bmp180.readPressure()));
  
  lcd.setCursor(0, 1);
  lcd.print(bmp180.readAltitude());
  
  bt.print("\t");
  bt.print(String(bmp180.readAltitude()));  
  
  delay(1000);
  lcd.clear();
  bt.print("\n");  
}
