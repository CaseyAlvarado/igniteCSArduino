// the last time the output pin was toggled
unsigned long LEFTLastDebounceTime = 0; 
unsigned long debounceDelay = 50; //debounce time, min time you want between presses 

int LEFTButtonState; 
int LEFTLastButtonState = LOW;
int RIGHTButtonState; 
int RIGHTLastButtonState = LOW; 
int ROTATEButtonState;
int ROTATELastButtonState = LOW; 

const int leftButton = 5;
const int rightButton = 6;
const int rotateButton = 7;

void setup(){
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(rotateButton, INPUT);
  Serial.begin(9600);	
}

void loop(){
  //debouncing for LEFT button input only 
  //read pin 
  int LEFTButtonReading  = digitalRead(leftButton); 
  
  //if the new button reading does not equal the old button reading, then record time 
  if (LEFTButtonReading != LEFTLastButtonState){ 
    LEFTLastDebounceTime = millis(); 
  } 
  
  //if the time between presses is less than the debounce delay 
  //and the current button state is not the same as the new button 
  //reading, then set new button state 
  if ((millis() - LEFTLastDebounceTime) > debounceDelay){ 
    //then this is actual content 
    
    if (LEFTButtonReading != LEFTButtonState) { 
      LEFTButtonState = LEFTButtonReading; 
    }  
  } 
  //transfer current button reading to last button state for future
  //checks 
  LEFTLastButtonState = LEFTButtonReading;
  
   //incorporate filtering/debouncing
  if (leftButton == HIGH){ 
      Serial.print("1"); 
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
