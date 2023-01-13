// C++ code
//

int piezo=13;

int shortSpeed=200;
int longSpeed=500;
int rest=200;

void setup()
{
  pinMode(piezo, OUTPUT);
}

//function for 3 repeated short tones
void threeShort(){
  
  int i; //initialize var for for loop
  for (i=0;i<3;i++){ 
    tone(piezo,500);
    delay(shortSpeed); 
    
    noTone(piezo);
    delay(rest);
  }
}

void loop()
{
  
  threeShort(); 
  
  int i;
  for (i=0;i<3;i++){ //three long
  	tone(piezo,500);
    delay(longSpeed);
    
    noTone(piezo);
    delay(rest); 
  }
  
  threeShort();
  
  noTone(13); 
  delay(3000); //pulse for 3000ms
}