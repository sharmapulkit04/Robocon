# define fdir1 50
# define fbrk1 46
# define fpwm1 2
# define fdir2 51
# define fbrk2 47
# define fpwm2 3
# define bdir1 52
# define bbrk1 48
# define bpwm1 4
# define bdir2 53
# define bpwm2 5
# define bbrk2 49

int s[8];

void setup() {

  for( byte i=0; i<=7;i++){
  s[i]=i+7;
  }

  
  // Setting pin 7 -14 as digital input pin
  for(byte i=7;i<=14;i++) {
    pinMode(i,INPUT);
  }

  for(byte i=2;i<=5;i++){
    
    pinMode(i,OUTPUT);
    
    } 
  
  
  for(byte i=46;i<=53;i++){
    
    pinMode(i,OUTPUT);
    
    }
  

 }

void loop() { 
  // keep moving forward
  if((digitalRead(s[3]) && digitalRead(s[4])))
  moveForward();
  
  else if(digitalRead(s[2])==HIGH&&digitalRead(s[1])==LOW)
  moveSlightlyRight();

  else if(digitalRead(s[1])==HIGH&&digitalRead(s[0])==LOW)
  moveRight();
  
  else if(digitalRead(s[0])==HIGH)
  moveExtremelyRight();

  else if(digitalRead(s[5])==HIGH&&digitalRead(s[6])==LOW)
  moveSlightlyLeft();

  else if(digitalRead(s[6])==HIGH&&digitalRead(s[7])==LOW)
  moveLeft();
  
  else if(digitalRead(s[7])==HIGH)
  moveExtremelyLeft();


  // If no line is detected, BREAK
  else
  brk();


}


void moveSlightlyLeft() {
  analogWrite(bpwm1,160);
  analogWrite(fpwm2,120);
}

void moveExtremelyLeft() {
  analogWrite(bpwm1,90);
  analogWrite(fpwm2,10);
}

void moveLeft() {
  analogWrite(bpwm1,120);
  analogWrite(fpwm2,50);
}

void moveSlightlyRight() {
  analogWrite(fpwm1,120);
  analogWrite(bpwm2,160);
}

void moveRight() {
  analogWrite(fpwm1,60);
  analogWrite(bpwm2,160);
}


void moveExtremelyRight() {
  analogWrite(fpwm1,10);
  analogWrite(bpwm2,90);
}

void moveForward() {
  analogWrite(fpwm1,200);
  analogWrite(bpwm2,200);
}

void brk(){
  
  digitalWrite(fbrk1,HIGH);
  digitalWrite(bbrk1,HIGH);
  
  
  }
