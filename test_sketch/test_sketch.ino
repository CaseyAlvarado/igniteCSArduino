void setup(){ 
  Serial.begin(9600); 
  Serial.print("r");
  Serial.print("l");  
  
} 

void loop(){ 
  Serial.println("l"); 
  delay(500); 
  Serial.println("r"); 
  delay(500); 
  
} 
