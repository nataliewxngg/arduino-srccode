// C++ code
//

//vars
//int a=8;int b=9;int c=3;int d=4;int e=5;int f=7;int g=6; //pin #s corresponded to 7SEG tags
int delayTime=1000;

//setup
void setup()
{
  int segments;
  pinMode(segments,OUTPUT); //set all pins to OUTPUT
  
  Serial.begin(9600);
}

void clearAll(){
  int i;
  for(i=3;i<10;i++){ //sets every pin # from 3 to 9 to LOW (turns off)
  	digitalWrite(i,LOW); 
  }
}

void printLetter(int three,int four,int five,int six,int seven,int eight,int nine){ //arguments are pin #s corresponded to 7SEG tags (c,d,e,g,f,a,b)
  
  clearAll(); 
  int arr[]={three,four,five,six,seven,eight,nine}; //sorts pin #s into list for index checking later
    
  int count;
  for(count=0;count<7;count++){
    if(arr[count]==1){ 
      //checks in array to determine which 7SEG tags
      //if argument==0, it'll NOT turn on that segment but will if argument==1

      digitalWrite(count+3,HIGH); //turns on the segment (+3 because pins start at 3 and end at 9, FOR LOOP STARTS AT 0 AND ENDS AT 7 (for easier access of the argument array))
    }
  }
  delay(delayTime);
}

void loop()
{
  //note:(c,d,e,g,f,a,b)
  
  printLetter(1,0,1,0,1,1,1); //n
  printLetter(1,0,1,1,1,1,1); //a
  printLetter(0,1,1,1,1,0,0); //t
  printLetter(1,0,1,1,1,1,1); //a
  printLetter(0,1,1,0,1,0,0); //l
  printLetter(0,0,1,0,1,0,0); //i
  printLetter(0,1,1,1,1,1,0); //e
}

/*
void letterE(){
  digitalWrite(a,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  
  delay(letterDelay);
}


void loop()
{
  clearAll();
  number0();

  clearAll();
  number1();

  clearAll();
  number2();
    
  clearAll();
  number3();
    
  clearAll();
  number4();

  clearAll();
  number5();
   
  clearAll();
  number6();

  clearAll();
  number7();

  clearAll();
  number8();
        
  clearAll();
  number9();
}
*/
