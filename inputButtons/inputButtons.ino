void setup(){ 
  Serial.begin(9600)  
}

void loop(){ 
  
}const int leftButton = 5;
const int rightButton = 6;
const int rotateButton = 7;
void setup(){
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(rotateButton, INPUT);
  Serial.begin(9600);	
}

void loop(){
	val leftButt = digitalRead(leftButton)	
    //incorporate filtering/debouncing
  if (leftButt == HIGH){ 
      Serial.print("1")  
  }
  
  if(digitalRead(rightButton) == HIGH){
    	Serial.print('1');
  }
  else{
    	Serial.print('0');
  }
     
  if(digitalRead(rotateButton) == HIGH){
    	Serial.print('1');
  }
  else{
    	Serial.print('0');
  }
  
}
