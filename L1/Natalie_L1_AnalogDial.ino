// C++ code
//

int potPin=A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(potPin);
  Serial.println(sensorValue);
  //min:0 max:1023
  
  delay(1);
}