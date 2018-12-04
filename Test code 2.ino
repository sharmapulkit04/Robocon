



void setup() {

 pinMode(4,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(50,OUTPUT);
 pinMode(51,OUTPUT);
 pinMode(52,OUTPUT);
 pinMode(53,OUTPUT);

 pinMode(47,OUTPUT);
 pinMode(48,OUTPUT); 
 pinMode(46,OUTPUT);
 pinMode(49,OUTPUT); 

 analogWrite(4,60);
analogWrite(7,60); 
delay(3000);

digitalWrite(46,HIGH);
digitalWrite(49,HIGH);
delay(1000);
digitalWrite(50,HIGH);
digitalWrite(53,HIGH);
delay(100);
digitalWrite(46,LOW);
digitalWrite(49,LOW);
delay(3000);
digitalWrite(46,HIGH);
digitalWrite(49,HIGH);


analogWrite(5,60);
analogWrite(6,60); 
delay(3000);

digitalWrite(47,HIGH);
digitalWrite(48,HIGH);
delay(1000);
digitalWrite(51,HIGH);
digitalWrite(52,HIGH);
delay(100);
digitalWrite(47,LOW);
digitalWrite(48,LOW);
delay(3000);
digitalWrite(47,HIGH);
digitalWrite(48,HIGH);

 
 }

void loop() {
   




}
