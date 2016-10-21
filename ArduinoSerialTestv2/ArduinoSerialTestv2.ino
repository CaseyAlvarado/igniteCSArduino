int val1 = 0;
int val2 = 0;
int val3 = 0;
bool isPressed1 = false;
bool isPressed2 = false;
bool isPressed3 = false;

//keep track of previous and current states
bool previousState = HIGH; 
bool currentState; 

//keeps track of the first time a button was pressed
unsigned long firstTimePressed = 0; 

int buttonPin = 7; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  pinMode(5, INPUT);
//  pinMode(6, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  val1 = digitalRead(buttonPin);
  currentState = !val1; 
  
  
  if ((currentState == LOW) && (previousState == HIGH)){ 
    Serial.print("FIRST TIME");
    Serial.println(millis());
    firstTimePressed = millis(); 
    previousState = LOW; 
    delay(200);
  } 
  Serial.println(firstTimePressed);
  //how long has this been held for? 
  long timeHeld = millis() - firstTimePressed; 
  Serial.println(timeHeld);
  //if the amount of time held for it greater than some value to counteract noise 
  //the value of 50 can be experimented with 
  if ((timeHeld > 50) && (firstTimePressed !=0)){ 
    if (currentState == HIGH && previousState ==LOW){ 
      Serial.print("releasing state, held for");
      Serial.print(timeHeld);
      Serial.println(timeHeld/1000); 
      previousState = currentState;
    } 

  }
  delay(200);
//  
  
//  val2 = digitalRead(5);
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

