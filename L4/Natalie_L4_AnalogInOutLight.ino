// C++ code
//

//val
const int ledPin=9;
const int potPin=A0;

int sensorValue=0; //value inputted from potentiometer
int outputValue=0; //value to output on led

void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(potPin,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  sensorValue=analogRead(potPin);
  outputValue=map(sensorValue,0,1023,0,255); 
  //reads, thenchange max & min of potentiometer from 0-1023 to 0-255
  
  analogWrite(ledPin,outputValue); //output LED light by pot value
  
  //display info sensor and output info in the serial monitor
  Serial.print("sensor=");
  Serial.print(sensorValue);
  Serial.print("\t output=");
  Serial.println(outputValue);
}