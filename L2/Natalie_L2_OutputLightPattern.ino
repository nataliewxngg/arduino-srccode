// C++ code
//

int flow=100;

void setup()
{
  int led;
  pinMode(led,OUTPUT);
}

/*
void loop() //left to right lighting only
{
  int i;
  
  for (i=2;i<10;++i){
    digitalWrite(i,HIGH);
    delay(500);
    digitalWrite(i,LOW);
  }
}
*/

void loop() //continuous back and forth lighting
{
  int i;
  
  for (i=2;i<10;++i){ //increment i by 1 each time to increase int (pins 2-9)
    digitalWrite(i,HIGH);
    delay(flow); //adjustment for flow speed
    
    digitalWrite(i,LOW);
  }  
  
  for(i=8;i>2;--i){ //reduct i by 1 each time to decrease int (pins 8-3)
    digitalWrite(i,HIGH);
    delay(flow); //adjustment for flow speed
     
    digitalWrite(i,LOW);
  }
}