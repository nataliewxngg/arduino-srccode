// C++ code
//

//vars
//int a=8;int b=9;int c=3;int d=4;int e=5;int f=7;int g=6; //pin #s corresponded to 7SEG tags
int delayTime=100;

//setup
void setup()
{
  int segments;
  pinMode(segments,OUTPUT); //set all pins to OUTPUT
  
  pinMode(A0,INPUT);
  
  Serial.begin(9600);
}

void clearAll(){
  int i;
  for(i=3;i<10;i++){ //sets every pin # from 3 to 9 to LOW (turns off)
    digitalWrite(i,LOW);
  }
}

void printNum(int three,int four,int five,int six,int seven,int eight,int nine){ //arguments are pin #s corresponded to 7SEG tags (c,d,e,g,f,a,b)
  
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
  delay(delayTime); //this can be removed for PCs with higher performance (will barely affect performance on a high-end computer)
}

void loop()
{
  int sensorValue = analogRead(A0);
  int mappedValue = map(sensorValue, 0, 1023, 0, 9); //changes min and max of potentiometer from 0-1023 to 0-9
  
  Serial.println(mappedValue); //for developer - verify the values of the potentiometer
  
  switch(mappedValue)
  //takes in mappedValue as an argument and operates the following cases according to the num
  {
    
    case 0:
    printNum(1,1,1,0,1,1,1); //0
    break;

	case 1:
    printNum(1,0,0,0,0,0,1); //1
    break;

	case 2:
    printNum(0,1,1,1,0,1,1); //2
    break;
    
	case 3:
    printNum(1,1,0,1,0,1,1); //3
    break;
    
    case 4:
    printNum(1,0,0,1,1,0,1); //4
    break;

    case 5:
    printNum(1,1,0,1,1,1,0); //5
    break;
    
    case 6:
    printNum(1,1,1,1,1,1,0); //6
    break;

    case 7:
    printNum(1,0,0,0,0,1,1); //7
    break;

    case 8:
    printNum(1,1,1,1,1,1,1); //8
    break;
        
    case 9:
    printNum(1,1,0,1,1,1,1); //9
    break;

 	default: 
    mappedValue=0; //starts with 0
    break;
    
  }
}
