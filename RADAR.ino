
#include <Arduino.h>
#include "TM1637Display.h"
#include "pitch.h"

#define CLK 30    //Digital pin for clk
#define DIO 31    //Digital pin for dio
#define ECHO 40    //Digital pin for echo
#define TRIG 41    //Digital pin for trig

TM1637Display display(CLK, DIO);

long distance;
long time;


void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT); 
}

void loop() {


  digitalWrite(TRIG,LOW); 
  delayMicroseconds(5);
  
  digitalWrite(TRIG, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  
  time=pulseIn(ECHO, HIGH); 
  
  distance= int(0.017*time); 

  display.setBrightness(0x0f);

display.showNumberDec(distance, false);  



delay(1000);

	}
  
  


