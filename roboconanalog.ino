# define fdir1 50
# define fbrk1 46
# define fpwm1 4
//# define fdir2 51
//# define fbrk2 47
//# define fpwm2 5
//# define bdir1 52
//# define bbrk1 48
//# define bpwm1 6
# define bdir2 53
# define bpwm2 7
# define bbrk2 49

const int junctionPulse=2;
const int analogPin =A0;

void setup() {
  
  Serial.begin(9600);
  pinMode(junctionPulse,INPUT);
  
 
  attachInterrupt(digitalPinToInterrupt(junctionPulse), brk, RISING);
  

for(byte i=4;i<=7;i++){
    
    pinMode(i,OUTPUT);
    
    } 
  
  
  for(byte i=46;i<=53;i++){
    
    pinMode(i,OUTPUT);
    
    }

 digitalWrite(50,HIGH);
 digitalWrite(53,HIGH);
  

 
}

void loop() {


 pinMode(fbrk1,LOW);
 pinMode(bbrk2,LOW);


int readVal,positionVal;
  readVal = analogRead(analogPin);    // Read value from analog pin

  // Convert voltage level into line position value
  positionVal = ((float)readVal/921)*70;

  // Line at left when 0 - 18, move left
  if(positionVal >= 45)
  moveLeft(positionVal);

  // Line at middle when 19 - 52, move forward
  else if(positionVal <= 45&&positionVal>=25)
  moveForward();

  // Line at right when 53 - 70, move right
  else if(positionVal <= 25)
  moveRight(positionVal);


}

void moveLeft(int pos) {
  analogWrite(fpwm1,60);
  analogWrite(bpwm2,60-2*(25-pos));
}


void moveRight(int pos) {
  analogWrite(fpwm1,60-2*(pos-45));
  analogWrite(bpwm2,60);
}


void moveForward() {
  analogWrite(fpwm1,60);
  analogWrite(bpwm2,60);
}


void brk(){
  
  digitalWrite(fbrk1,HIGH);
  digitalWrite(bbrk2,HIGH);
  
  
  }
