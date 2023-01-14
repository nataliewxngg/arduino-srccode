// C++ code
//

//vars
int buttonPin=2;
int ledPin=13;

int buttonState; //check for button press
int lastButtonState = LOW; //previous check for button press, saved

int ledState=HIGH;
  
long debounceDelay=50; 
long lastDebounceTime=0;

void setup()
{
  pinMode(buttonPin, INPUT); 
  pinMode(ledPin, OUTPUT); 
  
  digitalWrite(ledPin,ledState); //set initial LED state (HIGH, as var was initialized HIGH in vars)
}

void loop()
{
  int sensorValue = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState){ 
    //if the button is held, this statement is False (skips block)
    lastDebounceTime = millis(); //resets debounce timer
  }
  
  if((millis() - lastDebounceTime) > debounceDelay){
    //for stable current state
    
    if (sensorValue != buttonState){ 
      buttonState = sensorValue;
      //if the button state changes, 
      //set the state of the button to the sensorValue
      
      if (buttonState == HIGH){
        //enables the LED if the state of the button is HIGH
        ledState = !ledState;
      }
    }
  }
  
  digitalWrite(13, ledState); //updates state of the led (LOW or HIGH depending on the previous block of code)
  
  //saves the button state
  lastButtonState = sensorValue;
}