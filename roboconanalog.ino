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
const int motorSpeed=60
void setup() {
  
  
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
  int error = positionVal-35;
  int leftMotorSpeed=motorSpeed - error;
  int rightMotorSpeed=motorSpeed + error;;
 
move(leftMotorSpeed,rightMotorSpeed);

}




void move(int leftMotor,int rightMotor) {
  
  if(leftMotor>0&&rightMotor>0){
  analogWrite(fpwm1,leftMotor);
  analogWrite(bpwm2,rightMotor);
    
  }
  if(leftMotor<0){
  analogWrite(fpwm1,0);
  analogWrite(bpwm2,rightMotor);
  
  }
  if(rightMotor<0){
  analogWrite(fpwm1,leftMotor);
  analogWrite(bpwm2,0);
  }
  
  
}

void brk(){
  
  digitalWrite(fbrk1,HIGH);
  digitalWrite(bbrk2,HIGH);
  
  
  }
