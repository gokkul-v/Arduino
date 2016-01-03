#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // sets the interfacing pins
int Contrast=125;


void setup()
{
 analogWrite(6,Contrast);
 lcd.begin(16, 2);  // initializes the 16x2 LCD
}

void loop()
{
  lcd.setCursor(0,1);           //sets the cursor at row 0 column 0
  lcd.print("Winter is Coming"); // prints 16x2 LCD MODULE
  lcd.setCursor(3,0);           //sets the cursor at row 1 column 2
  lcd.print("HOUSE STARK");     // prints HELLO WORLD
}

