#include <FastIO.h>
#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>

//#include <SoftI2CMaster.h>

#include <Wire.h>
#include <Time.h>
#define DS1307_I2C_ADDRESS 0x68
#include <DS1307RTC.h>
LiquidCrystal_SR lcd(6, 5, 9);
//SoftwareWire(A4,A5);
int i;
void sysout() {
  i++;
  lcd.clear();
  lcd.print(i);
}
void setup() {
  lcd.begin(16,2);               // Initializing LCD
  lcd.home ();
  // put your setup code here, to run once:
Serial.begin(9600);
while(!Serial);
delay(200);
Serial.print("Please Wait");

}

void loop() {
  lcd.print("in void loop()");
  delay(1000);
//  lcd.clear();
//  lcd.print("1");
sysout();
delay(1000);
lcd.print("hi");
sysout();
  tmElements_t tm;
  // put your main code here, to run repeatedly:
if(RTC.read(tm))
//Serial.print("No RTC");
//else
Serial.print("RTC running");
return;
sysout();
//delay(1000);
//lcd.clear();
//lcd.print("end of void loop()");
//delay(1000);
//lcd.clear();
}
