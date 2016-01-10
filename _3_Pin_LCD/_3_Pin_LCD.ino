// Robo India Tutorial on using 16X2 LCD with 3 Pin interface. 
// www.roboindia.com


#include <Wire.h>
#include <LiquidCrystal_SR.h>

// Defining LCD and Pins for interfacing.
LiquidCrystal_SR lcd(6, 5, 9); // Pin 6 - Data Enable/ SER, Pin 5 - Clock/SCL, Pin 9 -SCK


void setup(){
  lcd.begin(16,2);               // Initializing LCD
  lcd.home ();                   // Setting Cursor at Home i.e. 0,0
  
}

void loop(){
  
  lcd.print("  House STARK");       // Print Something on LCD
  delay(2000);                  // Waiting for a while
  lcd.clear();                  // Clearing LCD      
  lcd.print("Winter is Coming");  
   
  lcd.setCursor(0, 1);          // Setting cursor to column first and second row.
  delay(2000);
lcd.clear(); 
  lcd.print("Game of Thrones");
  delay(2000);
  lcd.clear();                  

  
}
