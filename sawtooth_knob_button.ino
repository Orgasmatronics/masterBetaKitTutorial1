/*
saw tooth control of motor speed with knob controlling ramp time, stay at 
maximum power until reset by button, then ramp up again

This is actually a neat toy.  Ramp up as slow as you want, stay at max, 
then restart any time! Actually useful.
*/
  int buttonPin = 2; //define knob pin as analog input A2
  boolean buttonState = false;//buttonState is state of button
  int knobPin = A2; //define knob pin as analog input A2
  int motorPin = 5;  //define motor pin to be PWM output pin 5
  float knobPosition = 0.0;//knobPosition is the position scaled to 1023
  float motorSpeedMin = 55.0;//minimum motor speeed
  float motorSpeed = 0.0;//motorSpeed is the speed scaled to 255
  float rampTime = 5.0; //ramp time in seconds
  float rampTimeMax = 120.0; //2 minutes max
  float rampTimeMin = 1.0; //1 second minimum 
  float rampTimeRange; //
  float delayTime; //time between points in miliseconds
  float fadeAmount = 2.0;//note that 200/2 = 100, one 100th of total sweep
  
  
  void setup(){
    pinMode(motorPin,OUTPUT);
    motorSpeed = motorSpeedMin;//start at 55 to avoid dead zone of motor
    pinMode(buttonPin, INPUT);  
  }
  
  void loop(){
    rampTimeRange = rampTimeMax - rampTimeMin;//total range of times in s
    knobPosition = analogRead(knobPin);//read in knob position, from 0 to 1023 
    rampTime = rampTimeMin + (knobPosition*rampTimeRange/1023.0);//compute ramp time
    delayTime = rampTime*1000.0/100.0;//convert ramp time in s to delay time in ms
    motorSpeed = motorSpeed + fadeAmount;//increment motor speed by fadeAmount(1%)
    if(motorSpeed >= 255.0){  
      motorSpeed = 255.0;  //if max motor speed attained or exceeded, stay at max
    }
    buttonState = digitalRead(buttonPin); //read button state
    if(buttonState){
      motorSpeed = motorSpeedMin;
    }

    analogWrite(motorPin,motorSpeed); //output new motor speed
    delay(delayTime);//wait for delayTime number of miliseconds
  }
