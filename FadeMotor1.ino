/*
 Fade
 
 This example shows how to fade pulse width modulation control 
 of a motor on pin 5
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int motorPin = 5;           // the pin that the motor is attached to
int motorSpeed = 0;    // how bright the motor is
int fadeAmount = 5;    // how many points to fade the motor by

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 5 to be an output:
  pinMode(motorPin, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the motorSpeed of pin 5:
  analogWrite(motorPin, motorSpeed);    

  // change the motorSpeed for next time through the loop:
  motorSpeed = motorSpeed + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (motorSpeed == 0 || motorSpeed == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}

