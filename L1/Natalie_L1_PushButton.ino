// C++ code
//

int pushButton = 2;

void setup()
{
  Serial.begin(9600); //enable serial monitor
  
  pinMode(pushButton, INPUT);
}

void loop()
{
  int sensorValue = digitalRead(pushButton); 
  Serial.println(sensorValue);
  //0 default
  
  delay(1);
}