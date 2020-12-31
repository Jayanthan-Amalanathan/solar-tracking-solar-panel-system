#include <Servo.h> // include Servo library 

Servo horizontal; // horizontal servo
int servoh = 90;     // stand horizontal servo

Servo vertical;   // vertical servo 
int servov = 90;     // stand vertical servo

// LDR pin connections
//  name  = analogpin;
int ldrlt = 0; //LDR top left
int ldrrt = 1; //LDR top rigt
int ldrld = 2; //LDR down left
int ldrrd = 3 ; //ldr down rigt


#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 9, d5 = 8, d6 = 7, d7 = 6; LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include "DHT.h"// include the the dht sensor library

#define DHT_pin A4// give a name to the sensor pin and A0

dht DHT;//initialize the sensor



void setup()
{
  lcd.begin(16, 2);//initialize the senso


  Serial.begin(9600);

  delay(500);//Delay to let system boot
// servo connections
// name.attacht(pin);
  horizontal.attach(3); 
  vertical.attach(4);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");

  delay(1000);//Wait before accessing Sensor

}

void loop() 
{
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  int dtime = analogRead(4)/20; // read potentiometers  
  int tol = analogRead(5)/4;
  
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt

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
    
  if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle
  {
  if (avt > avd)
  {
    servov = --servov;
     if (servov > 180) 
     { 
      servov = 180;
     }
  }
  else if (avt < avd)
  {
    servov= ++servov;
    if (servov < 0)
  {
    servov = 0;
  }
  }
  vertical.write(servov);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
  if (avl > avr)
  {
    servoh = --servoh;
    if (servoh < 0)
    {
    servoh = 0;
    }
  }
  else if (avl < avr)
  {
    servoh = ++servoh;
     if (servoh > 180)
     {
     servoh = 180;
     }
  }
  else if (avl = avr)
  {
    // nothing
  }
  horizontal.write(servoh);
  }
   delay(dtime); 
}
