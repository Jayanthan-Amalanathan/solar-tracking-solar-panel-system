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

//
#include <LiquidCrystal.h>

#include <DHT.h>

#include "DHT.h"

#define DHTPIN A4     // what pin we're connected to

#define DHTTYPE DHT11   // we are using the DHT11 sensor

LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
// servo connections
// name.attacht(pin);
  horizontal.attach(3); 
  vertical.attach(4);

  //
  for (int DigitalPin = 7; DigitalPin <= 9; DigitalPin++) 
 {
  pinMode(DigitalPin, OUTPUT);
 }
  lcd.begin(16,2);  //16 by 2 character display
  
dht.begin();

}

void loop() 
 // Reading temperature or humidity takes about 250 milliseconds!
{  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Read temperature as Celsius (the default){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);  //printing temperarture to the LCD display


  lcd.print("'C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);  //printing humidity to the LCD display
  lcd.print("%");

 {
 // 
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
}
