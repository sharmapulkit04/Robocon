void setup() {
  pinMode(48,OUTPUT);
  pinMode(50,OUTPUT);
  pinMode(52,OUTPUT);
}

void loop() {
  
  digitalWrite(48,LOW);
  digitalWrite(50,HIGH);
  delay(10000);
  
  digitalWrite(52,HIGH);
  delay(1000);
  digitalWrite(52,LOW);
  
  digitalWrite(48,HIGH);
  digitalWrite(50,HIGH);
  delay(10000);
  
  digitalWrite(52,HIGH);
  delay(1000);
  digitalWrite(52,LOW); 
  
  }
