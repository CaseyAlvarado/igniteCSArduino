const int INTERVAL = 5000; 

int val1 = 0;
int val2 = 0;
int val3 = 0;

//initializing button pins 
int buttonPin1 = 5;
int buttonPin2 = 6; 
int buttonPin3 = 7;

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
int buttonsPressed[] = {0, 0, 0, 0};

int buttonMessages[3]; 

void setup() {
  Serial.begin(9600);
  //identify button pins as inputs 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT); 
  pinMode(buttonPin3, INPUT); 
  
}

void loop() {
  checkButtons(buttonPin1, buttonPin2, buttonPin3);

  if(buttonMessages[0]){ // this is the left button
    Serial.println('l');
  }
  if(buttonMessages[1]){ // this is the middle button
    Serial.println('u');
  }
  if(buttonMessages[2]){ // this is the right button
    Serial.println('r');
  }

}


void checkButtons(int button1, int button2, int button3){
  unsigned long curTime = millis();
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);
  int button3State = digitalRead(button3);
  
  bool output1 = false;
  bool output2 = false;
  bool output3 = false;
  
  if(!isPressed1 && button1State == HIGH){
    isPressed1 = true;
    output1 = true;
  }
  else if(button1State == LOW){
    isPressed1 = false;
  }
  else if(isPressed1 && (curTime - button1Time > INTERVAL)){
    output1 = true;
  }
  button1Time = curTime;
  
  if(!isPressed2 && button2State == HIGH){
    isPressed2 = true;
    output2 = true;
  }
  else if(button2State == LOW){
    isPressed2 = false;
  }
  else if(isPressed2 && (curTime - button2Time > INTERVAL)){
    output2 = true;
  }
  button2Time = curTime;
  
  if(!isPressed3 && button3State == HIGH){
    isPressed3 = true;
    output3 = true;
  }
  else if(button3State == LOW){
    isPressed3 = false;
  }
  else if(isPressed3 && (curTime - button3Time > INTERVAL)){
    output3 = true;
  }
  button3Time = curTime;
  
  buttonMessages[0] = output1; 
  buttonMessages[1] = output2;
  buttonMessages[2] = output3;
  
}
