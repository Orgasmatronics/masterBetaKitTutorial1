/*
  Knob control of motor speed.  Knob controls analog input on analog input A2, 
  which is a 10 bit signal, or scale of 0 to 1023.  
  Output is an 8 bit signal, or scale of 0 to 255.
  
  */
  int knobPin = A2; //define knob pin as analog input A2
  int motorPin = 5;  //define motor pin to be PWM output pin 5
  int knobPosition = 0;//knobPosition is the position scaled to 1023
  int motorSpeed = 0;//motorSpeed is the speed scaled to 255
  
 void setup() {
    // declare the motorPin as an OUTPUT:
    //pinMode(motorPin, OUTPUT);  
 }

void loop() {
    knobPosition = analogRead(knobPin); //read in the position of the knob
    motorSpeed = knobPosition/4;  //convert from 255 scaling to 1023 scaling
    analogWrite(motorPin,motorSpeed); //set motor speed based on knob position
}
