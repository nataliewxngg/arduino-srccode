// C++ code
//

//vars
//int a=8;int b=9;int c=3;int d=4;int e=5;int f=7;int g=6; //pin #s corresponded to 7SEG tags

int button=13;

int value=0; //1 or 0, state of button presses
int previousValue=0; //saves the previous state of button presses for checking later

int displayNum=0; //num to display on the 7SEG

int delayTime=100;


//setup
void setup()
{
  int segments;
  pinMode(segments,OUTPUT); //sets all pins to OUTPUT
  
  pinMode(button,INPUT);
  
  Serial.begin(9600);
}

void clearAll(){
  int i;
  for(i=3;i<10;i++){
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
  delay(delayTime);
}

void loop()
{
  value=digitalRead(button);
  Serial.println(value);
  
  if (value!=previousValue){ 
    //if the button is held, this statement is False (skips block)
    
    if (value==1){
      displayNum++; //to update the 7SEG display later
    }
    else{ 
      //if value goes from 1 to 0, this else block will be operated 
      //but will affect nothing as there are no operations
    }
  }
  
  previousValue=value; //updates previousValue to value, for the next loop!
    
  switch(displayNum) //takes in displayNum as an argument and operates the following cases according to the num
  {
    //note:(c,d,e,g,f,a,b)
    
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
    displayNum=0; //starts with 0
    break;
  } 
}
