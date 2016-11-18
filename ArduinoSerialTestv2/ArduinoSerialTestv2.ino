const int INTERVAL = 5000; 

int val1 = 0;
int val2 = 0;
int val3 = 0;

//initializing button pins 
int buttonPin1 = 13;
int buttonPin2 = ; 
int buttonPin3 = ;

//boolean if the button is pressed 
bool isPressed1 = false;
bool isPressed2 = false;
bool isPressed3 = false;

//keep track of previous and current states
bool button1PreviousState = HIGH; 
bool button1CurrentState; 

bool button2PreviousState = HIGH; 
bool button2CurrentState;

bool button3PreviousState = HIGH; 
bool button3CurrentState;

unsigned long button1Time = 0;
unsigned long button2Time = 0;
unsigned long button3Time = 0;

//keeps track of the first time a button was pressed
long previousTime = 0;

//integer array tracks the buttons pressed 
int[] buttonsPressed = {0, 0, 0, 0}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //identify button pins as inputs 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT); 
  pinMode(buttonPin3, INPUT); 
  
  //TO DO: Identify output 
}

void loop() {
//   long currentTime = millis(); 
//   if ((currentTime - previousTime) > INTERVAL){ 
//     //then send information somehow?
//     Serial.write(something);
//   } 
  
//   buttonsPressed = checkButtons(); 
  
  
//   if ((button1CurrentState == LOW) && (button1PreviousState == HIGH)){ 
//     Serial.println("FIRST TIME");
//     Serial.println(millis());
    
//     output1 = true;
    
//     unsigned long firstTime = millis(); 
//     checkIfHeld(button1CurrentState, button1PreviousState, firstTime);
//     button1PreviousState = LOW; 
//     delay(500);
//   }
  buttonMessages = checkButtons(buttonPin1, buttonPin2, buttonPin3);

}


bool[] checkButtons(button1, button2, button3){
  curTime = millis();
  button1State = !digitalRead(button1);
  button2State = !digitalRead(button2);
  button3State = !digitalRead(button3);
  
  bool output1 = false;
  bool output2 = false;
  bool output3 = false;
  
  if(!isPressed1 && button1State == LOW){
    isPressed1 = true;
    button1Time = curTime;
    output1 = true;
  }
  else if(button1State == HIGH){
    isPressed1 = false;
  }
  else if(isPressed1 && (curTime - button1Time > INTERVAL)){
    button1Time = curTime;
    output1 = true;
  }
  
  if(!isPressed2 && button2State == LOW){
    isPressed2 = true;
    button2Time = curTime;
    output2 = true;
  }
  else if(button2State == HIGH){
    isPressed2 = false;
  }
  else if(isPressed2 && (curTime - button2Time > INTERVAL)){
    button2Time = curTime;
    output2 = true;
  }
  
  if(!isPressed3 && button3State == LOW){
    isPressed3 = true;
    button3Time = curTime;
    output3 = true;
  }
  else if(button3State == HIGH){
    isPressed3 = false;
  }
  else if(isPressed3 && (curTime - button3Time > INTERVAL)){
    button3Time = curTime;
    output3 = true;
  }
  
  return [output1, output2, output3];
  
}