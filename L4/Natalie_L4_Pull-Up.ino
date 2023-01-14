// C++ code
//

int buttonPin=2;
int ledPin=13;

void setup()
{
  pinMode(buttonPin,INPUT_PULLUP); //configures the internal pull-up resistor to the pushbutton input
  pinMode(ledPin,OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
  int sensorValue = digitalRead(buttonPin); 
  Serial.println(sensorValue); 
  //collects input from button and displays it (1 <- default or 0?)
  
  //if button displays default (1), then turn off LED
  if (sensorValue == HIGH) { 
    digitalWrite(13,LOW);
 
  }
  
  //if button doesn't display default (1), then turn on LED
  else {
    digitalWrite(13,HIGH);
  }
  
}