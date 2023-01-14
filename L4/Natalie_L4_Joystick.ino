// C++ code
//

//imports the module and create the servo object
#include <Servo.h>  
Servo myservo;  

//vars
int potpin = A0;  
int servoPin=9

int potValue; //value of potentiometer    

void setup() {
  pinMode(potpin,INPUT);
  pinMode(9,OUTPUT);
  
  myservo.attach(servoPin); //attaches servo to servo object
}

void loop() {
  potValue = analogRead(potpin);            
  potValue = map(val, 0, 1023, 0, 180); 
  //read the value inputted from the potentiometer,
  //change the max and min from 0-1023 to 0-180
  
  myservo.write(potValue); //output the servo position based off of potentiometer value inputted                 
  
  delay(15);                           
}