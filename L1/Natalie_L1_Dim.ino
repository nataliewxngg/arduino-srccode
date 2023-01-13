// C++ code
//

int led=9;
int brightness=0;
int fadeAmount=5;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  analogWrite(led,brightness); //brightness var changes
  
  brightness=brightness+fadeAmount; //fades in/out by a value of 5 each time
  
  if (brightness<=0||brightness>=255){ 
    fadeAmount=-fadeAmount;
    
    //changes fade from in->out (or out->in) by reversing signs
    //eg. if 255 is reaches, fade will be -5, resulting in a brightness of (255 + (-5)) 
  }
  
  delay(30); //adjust to change fading speed
}