int val1 = 0;
int val2 = 0;
int val3 = 0;
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

//keeps track of the first time a button was pressed
//unsigned long firstTimePressed = 0; 

int buttonPin = 9; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  pinMode(5, INPUT);
//  pinMode(6, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  val1 = digitalRead(buttonPin);
  Serial.println("what is val?");
  Serial.println(val1);
  button1CurrentState = !val1;
  
  if ((button1CurrentState == LOW) && (button1PreviousState == HIGH)){ 
    Serial.println("FIRST TIME");
    Serial.println(millis());
    unsigned long firstTime = millis(); 
    checkIfHeld(button1CurrentState, button1PreviousState, firstTime);
    button1PreviousState = LOW; 
    delay(500);
  }
  
//  if ((currentState == LOW) && (previousState == HIGH)){ 
//    Serial.println("FIRST TIME");
//    Serial.println(millis());
//    firstTimePressed = millis(); 
//    checkIfHeld(button1CurrentState, button1PreviousState);
//    previousState = LOW; 
//    delay(500);
//  } 
 //if button is pressed, go into loop? 
 
   
  
//  val2 = digitalRead(5);
// 
//  
//  val3 = digitalRead(10);
//  if (val1 == 1) {
//    if (isPressed1 == false) {
//     Serial.write('l'); 
//     isPressed1 = true;
//    }
//  }  // put your main code here, to run repeatedly: 
//  else {
//    isPressed1 = false;
//  }
//
//  if (val2 == 1) {
//    if (isPressed2 == false) {
//      Serial.write('r');
//      isPressed2 = true;
//    }
//  }
//  else {
//    isPressed2 = false;
//  }
//
//  if (val3 == 1) {
//    if (isPressed3 == false) {
//      Serial.write('u');
//      isPressed3 = true;
//    }
//  }
//  else {
//    isPressed3 = false;
//  }
//  delay(5);
////  Serial.println('a');
}

void checkIfHeld(int buttonCurrentState, int buttonPreviousState, unsigned long firstTimePressed){ 
//  Serial.println(firstTimePressed);
//  //how long has this been held for? 
//  long timeHeld = millis() - firstTimePressed; 
//  Serial.println(timeHeld);
//  //if the amount of time held for it greater than some value to counteract noise 
//  //the value of 50 can be experimented with 
//  if ((timeHeld > 100) && (firstTimePressed !=0)){ 
//    if (currentState == HIGH && previousState ==LOW){ 
//      Serial.println("releasing state, held for");
//      Serial.println(timeHeld); 
//      Serial.println("how long was it held for?");
//      Serial.println(timeHeld/1000);
//      previousState = currentState;
//      delay(500);
//      
//      //return either a letter up above and print up above or print u, l, or r here 
//      //want it to happen real time, so probably here is a good idea 
//    } 
//  }
//  delay(500); 
  
}
