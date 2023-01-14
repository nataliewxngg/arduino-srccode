// C++ code
//

int buttonPin = 2;
int ledPin = 13;

int buttonPushCounter = 0; //accumulator for button pushes

//current and previous states of button
int buttonState = 0; 
int lastButtonState = 0;

void setup()
{
  pinMode(buttonPin,INPUT); //pushbutton
  pinMode(ledPin,OUTPUT); //led
  
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  
  if(buttonState!=lastButtonState){
    //if the button is held, this statement is False (skips block)
    
    if(buttonState==HIGH){
      buttonPushCounter++; 
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      
      //increment button push counter and display button pushes
    }
    else{
      Serial.println("off");
      //if the state of the button is LOW then display off in serial monitor
      
    }
    delay(50);
  }
  
  lastButtonState=buttonState; //updates button state for next loop
  
  if(buttonPushCounter%4==0){
    //after every 4 pushes...
    
    digitalWrite(13,HIGH); 
  }
  
  else{
    digitalWrite(13,LOW);
  }
  
}