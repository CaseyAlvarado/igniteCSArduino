int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int curval = 0;
int prevval = 0;
bool isPressed1 = false;
bool isPressed2 = false;
bool isPressed3 = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  val1 = digitalRead(3);
  val2 = digitalRead(5);
//  val3 = digitalRead(10);
//  uint8_t scale_val = map(curval,0,1023,2,255);
  if (curval != prevval) {
    Serial.write(scale_val);
  }
  prevval = curval;
  curval = analogRead(A0);
  if (val1 == 1) {
    if (isPressed1 == false) {
     Serial.write('l'); 
     isPressed1 = true;
    }
  }  // put your main code here, to run repeatedly: 
  else {
    isPressed1 = false;
  }

  if (val2 == 1) {
    if (isPressed2 == false) {
      Serial.write('r');
      isPressed2 = true;
    }
  }
  else {
    isPressed2 = false;
  }

  if (val3 == 1) {
    if (isPressed3 == false) {
      Serial.write('u');
      isPressed3 = true;
    }
  }
  else {
    isPressed3 = false;
  }
  delay(5);
  Serial.println('a');
}

