#include <Arduino.h>

void setup();
void loop();
void rpm_fun();
#line 1 "src/test.ino"

 volatile byte half_revolutions;
 unsigned int rpm;
 unsigned long timeold;

 void setup()
 {
   Serial.begin(9600);
   attachInterrupt(digitalPinToInterrupt(2), rpm_fun, RISING);
   half_revolutions = 0;
   rpm = 0;
   timeold = 0;
 }
 void loop()
 {
   if (half_revolutions >= 20) { 
     //Update RPM every 20 counts, increase this for better RPM resolution,
     //decrease for faster update
     rpm = 30*1000/(millis() - timeold)*half_revolutions;
     timeold = millis();
     half_revolutions = 0;
     Serial.println(rpm,DEC);
   }
 }
 void rpm_fun()
 {
   half_revolutions++;
   //Each rotation, this interrupt function is run twice
 }