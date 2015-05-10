/*
 Control of motor on/off with momentary button on digital pin 2  
  */
  int buttonPin = 2; //define knob pin as analog input A2
  int motorPin = 5;  //define motor pin to be PWM output pin 5
  boolean buttonState = false;//buttonState is state of button
  int motorSpeed = 0;//motorSpeed is the speed scaled to 255
  
 void setup() {
    // declare the motorPin as an OUTPUT:
    pinMode(motorPin, OUTPUT);
    //declare button pin as input
    pinMode(buttonPin, INPUT);  
 }

void loop() {
    buttonState = digitalRead(buttonPin); //read button state
    if(buttonState){
      motorSpeed = 255;
    }
    else{
      motorSpeed = 0;
    }
    analogWrite(motorPin,motorSpeed); //set motor speed based on knob position
}
