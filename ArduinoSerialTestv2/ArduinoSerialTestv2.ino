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
  // put your setup code here, to run once:
  Serial.begin(9600);
  //identify button pins as inputs 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT); 
  pinMode(buttonPin3, INPUT); 
  
  //TO DO: Identify output 
}

void loop() {
  checkButtons(buttonPin1, buttonPin2, buttonPin3);
  if(buttonMessages[0]){
    Serial.println('l');
  }
  if(buttonMessages[1]){
    Serial.println('r');
  }
  if(buttonMessages[2]){
    Serial.println('u');
  }
}


void checkButtons(int button1, int button2, int button3){
  unsigned long curTime = millis();
  int button1State = !digitalRead(button1);
  int button2State = !digitalRead(button2);
  int button3State = !digitalRead(button3);
  
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
  
  buttonMessages[0] = output1; 
  buttonMessages[1] = output2;
  buttonMessages[2] = output3;
  
}
