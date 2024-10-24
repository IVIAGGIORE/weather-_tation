#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>
#define DHTPIN 4    
DHT dht(DHTPIN, DHT11);
// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
   Serial.begin(115200);
    dht.begin();
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
   float humidity    = dht.readHumidity();
  float temperature = dht.readTemperature();
 
  //print result to serial
  Serial.print("Humidity = ");
  Serial.print(humidity, 2);
  Serial.println(" %");
   
  Serial.print("Temperature = ");
  Serial.print(temperature, 2);
  Serial.println(" *C");
  delay(1000); 
  String humidityString = "Humidity =";
  humidityString.concat(String(humidity, 2));
  humidityString.concat("%");
  
  Serial.print(humidityString);
  String temperatureString = "t =";
  temperatureString.concat(String(temperature, 2));
  temperatureString.concat("C");
  
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print(humidityString);
  
  // clears the display to print new message
  //lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print(temperatureString);
  delay(5000);
  lcd.clear(); 
}
