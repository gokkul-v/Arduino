#include <Wire.h>

#include <RealTimeClockDS1307.h>

#include <RTClib.h>

#include <DateTimeStrings.h>

#include <DateTime.h>

#include <Time.h>

#include <DS1307RTC.h>

// DS1307_Serial_Easy (C)2010 Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//
// A quick demo of how to use my DS1307-library to 
// quickly send time and date information over a serial link
//
// I assume you know how to connect the DS1307.
// DS1307:  SDA pin   -> Arduino Digital 20
//          SCL pin   -> Arduino Digital 21

// I changed these to digital I/O 2 and 3

//#include <DS1307.h>

// Init the DS1307
DS1307RTC(2, 3);

void setup()
{
  // Set the clock to run-mode
  rtc.halt(false);
  
  // Setup Serial connection
  Serial.begin(9600);

  // The following lines can be commented out to use the values already stored in the DS1307
  rtc.setDOW(MONDAY);        // Set Day-of-Week to SUNDAY
  rtc.setTime(1, 8, 00);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(8, 8, 2011);   // Set the date to October 3th, 2010
}

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
  delay (1000);
}
