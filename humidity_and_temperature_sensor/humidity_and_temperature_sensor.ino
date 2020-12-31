#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 9, d5 = 8, d6 = 7, d7 = 6; LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include "DHT.h"// include the the dht sensor library

#define DHT_pin A4// give a name to the sensor pin and A0

dht DHT;//initialize the sensor

void setup(){

lcd.begin(16, 2);//initialize the senso

Serial.begin(9600);// start the Serial communication

delay(500);//Delay to let system boot

Serial.println("DHT11 Humidity & temperature Sensor\n\n");

delay(1000);//Wait before accessing Sensor

}



void loop(){

DHT.read11(DHT_pin);//Read the Sensor pin

Serial.print("humidity = ");//print the humidity in the Serial Monitor

Serial.print(DHT.humidity);

Serial.print("% ");

Serial.print("temperature = ");

Serial.print(DHT.temperature); //to print temperature on the Serial monitor

Serial.println("C ");

lcd.setCursor(0,0);

lcd.print("humidity=");//to print humidity on the lcd

lcd.print(DHT.humidity);

lcd.print("% ");

lcd.setCursor(0,2);

lcd.print("temp = ");//to print temperature on the lcd

lcd.print(DHT.temperature);

lcd.println("C ");

delay(3000);//Wait 3 seconds before accessing sensor again.

}
