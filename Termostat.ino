// include the library code:
#include <LiquidCrystal.h>
#include "DHT.h"

// set the DHT Pin
#define DHTPIN 8

// initialising the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define DHTTYPE DHT11
// define obj dht(pin, tip)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //Setting the nb of columns and lines of LCD: 
  lcd.begin(16, 2);
  dht.begin();
  
  // Printing values on LCD
  lcd.print("Temp:  Humidity:");
}

void loop() {
  delay(500);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // read humidity
  float h = dht.readHumidity();
  //read temperature in Fahrenheit
  float f = dht.readTemperature(true);
  //magically changing the temperature to degrees
  float degC = (f-32)/(9.0/5.0);

  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
    return;
  }

  lcd.print(degC);
  lcd.setCursor(7,1);
  lcd.print(h);  
}
