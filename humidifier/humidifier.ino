#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_SR.h>

// Defining LCD and Pins for interfacing.
LiquidCrystal_SR lcd(6, 5, 9); // Pin 6 - Data Enable/ SER, Pin 5 - Clock/SCL, Pin 9 -SCK


#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

<<<<<<< HEAD
int Hu=25;
int Te=37;
/* humidifier - red LED
 *  xhaust - blueee LED
 */
int humidifier_on()
{
  digitalWrite(13, HIGH);
}

int humidifier_off()
{
  digitalWrite(13, LOW);
}
int exhaust_on()
{
  digitalWrite(12, HIGH);
}
int exhaust_off()
{
  digitalWrite(12, LOW);
=======
float H = 30.0;
float T = 37.5;

void humidifier_on()
{
  pinMode(13, HIGH);
}

void humidifier_off()
{
  pinMode(13, LOW);
}
void exhaust_on()
{
  pinMode(14, HIGH);
}
void exhaust_off()
{
  pinMode(14, LOW);
>>>>>>> origin/master
}
void setup() {
  lcd.begin(16, 2);              // Initializing LCD
  lcd.home ();                   // Setting Cursor at Home i.e. 0,0
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
<<<<<<< HEAD
//  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    lcd.print("Failed to read from DHT sensor!");
    return;
  }
  lcd.setCursor ( 0, 0 ); 
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" %");
  lcd.setCursor ( 0, 1 ); 
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" *C ");

  if(t>=Te)
  {
    humidifier_on();
  }
  else
  {
    humidifier_off();
  }

  if (h>=Hu)
  {
    exhaust_on();
  }
  else
  {
    exhaust_off();
  }
=======
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.print("Failed to read from DHT sensor!");
    return;
  }
lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" %\t");
  lcd.print("Temperature: ");
  lcd.print(t);
  lcd.print(" *C ");

  if (t >= T)
    humidifier_on();
  else
    humidifier_off();

  if (h >= H)
    exhaust_on();
  else
    exhaust_off();

>>>>>>> origin/master



}
