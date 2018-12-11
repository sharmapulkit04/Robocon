# define fdir1 50
# define fbrk1 46 //B
# define fpwm1 4
# define fdir2 51
# define fbrk2 47  //A
# define fpwm2 5
# define bdir1 52  
# define bbrk1 48   //C
# define bpwm1 6
# define bdir2 53
# define bpwm2 7
# define bbrk2 49  // D
# define gnd1 22 
# define gnd2 23
# define gnd3 24
# define gnd4 25
# define gnd5 26

const int junctionPulse0=18; //A
const int junctionPulse1=19; //B
const int junctionPulse2=20; //C
const int junctionPulse3=21;  //D
const int analogPin0 =A0;  //A front
const int analogPin1 =A1;  //B left
const int analogPin2=A2;   //C back
const int analogPin3=A3; //D  right
const int motorSpeed=200;
const int Kp=3;
int sw0=1,sw1=0,sw2=0,sw3=0; //code switches 
int readVal0,readVal1,readVal2,readVal3, positionVal0,positionVal1,positionVal2,positionVal3;

void setup() {

  pinMode(gnd1,OUTPUT);
  pinMode(gnd2,OUTPUT);
  pinMode(gnd3,OUTPUT);
  pinMode(gnd4,OUTPUT);
  pinMode(gnd5,OUTPUT);
  
  
  pinMode(junctionPulse0,INPUT);
  pinMode(junctionPulse1,INPUT);
 pinMode(junctionPulse2,INPUT);
  pinMode(junctionPulse3,INPUT);
 
  attachInterrupt(digitalPinToInterrupt(junctionPulse0), brk0, RISING);
  attachInterrupt(digitalPinToInterrupt(junctionPulse1), brk1, RISING);
  attachInterrupt(digitalPinToInterrupt(junctionPulse2), brk0, RISING);
  attachInterrupt(digitalPinToInterrupt(junctionPulse3), brk1, RISING);
  

for(byte i=4;i<=7;i++){
    
    pinMode(i,OUTPUT);
    
    } 
  
  
  for(byte i=46;i<=53;i++){
    
    pinMode(i,OUTPUT);
    
    }

 digitalWrite(50,LOW);// forward 
 digitalWrite(53,LOW);
 digitalWrite(51,LOW); //left 
 digitalWrite(52,LOW);
  digitalWrite(gnd1,LOW); 
 digitalWrite(gnd2,LOW);
digitalWrite(gnd3,LOW);
digitalWrite(gnd4,LOW);
digitalWrite(gnd5,LOW);
 
  

 
}

void loop() {





  readVal0 = analogRead(analogPin0);    // Read value from analog pin
  readVal1=  analogRead(analogPin1);
   readVal2 = analogRead(analogPin1);    // Read value from analog pin
  readVal3=  analogRead(analogPin2);
  
  // Convert voltage level into line position value
  positionVal0 = ((float)readVal0/921)*70;
  positionVal1 = ((float)readVal1/921)*70;
positionVal2 = ((float)readVal0/921)*70;
  positionVal3 = ((float)readVal1/921)*70;

 
 if(sw0){
  digitalWrite(fdir1,LOW);// forward 
 digitalWrite(bdir2,LOW);
   digitalWrite(fbrk1,LOW);
   digitalWrite(bbrk2,LOW);
   int error = Kp*(positionVal0-35);
  int leftMotorSpeed=motorSpeed - error;
  int rightMotorSpeed=motorSpeed + error;
  
move(leftMotorSpeed,rightMotorSpeed,fpwm1,bpwm2);

}


if(sw1){
  digitalWrite(fdir2,LOW);// left  
 digitalWrite(bdir1,LOW);
  
  digitalWrite(fbrk2,LOW);
  digitalWrite(bbrk1,LOW);
   int error = positionVal1-35;
  int leftMotorSpeed=motorSpeed - error;
  int rightMotorSpeed=motorSpeed + error;
  

move(leftMotorSpeed,rightMotorSpeed,fpwm2,bpwm1);

}

if(sw2){
  digitalWrite(50,HIGH);// backward 
 digitalWrite(53,HIGH);
  
  digitalWrite(fbrk1,LOW);
  digitalWrite(bbrk2,LOW);
   int error = positionVal1-35;
  int leftMotorSpeed=motorSpeed - error;
  int rightMotorSpeed=motorSpeed + error;
  

move(leftMotorSpeed,rightMotorSpeed,fpwm2,bpwm1);

}

if(sw3){
  digitalWrite(50,HIGH);// right 
 digitalWrite(53,HIGH);
  
  digitalWrite(fbrk2,LOW);
 digitalWrite(bbrk1,LOW);
   int error = positionVal1-35;
  int leftMotorSpeed=motorSpeed - error;
  int rightMotorSpeed=motorSpeed + error;
  

move(leftMotorSpeed,rightMotorSpeed,fpwm2,bpwm1);

}

if(positionVal0<5&&positionVal1<5){
  brk0();
  brk1();
  
  }

}


void move(int leftMotor,int rightMotor,int pwm1 ,int pwm2 ) {
  
  if(leftMotor>0&&rightMotor>0){
  analogWrite(pwm1,rightMotor);
  analogWrite(pwm2,leftMotor);
    
  }
  if(rightMotor<0){
  analogWrite(pwm1,0);
  analogWrite(pwm2,leftMotor);
  
  }
  if(leftMotor<0){
  analogWrite(pwm1,rightMotor);
  analogWrite(pwm2,0);
  }
  
  
}

void brk0(){
  delay(500);
  if(positionVal0>5&&positionVal2>5&&(positionVal1>5||positionVal3>5)){
  digitalWrite(fbrk1,LOW);
  digitalWrite(bbrk2,LOW);
 }
else{   
  digitalWrite(fbrk1,HIGH);
  digitalWrite(bbrk2,HIGH);
  delay(50);
  if(positionVal1>5){
    sw0=0;
    sw1=1;
    sw2=0;
    sw3=0;
    
    }
  if(positionVal3>5){
    sw0=0;
    sw1=0;
    sw2=0;
    sw3=1;
    
    }
  
   }
  
   
}
  void brk1(){
 delay(500);
  if(positionVal1>5&&positionVal3>5&&(positionVal0>5||positionVal2>5)){
  digitalWrite(fbrk2,HIGH);
  digitalWrite(bbrk1,HIGH);
    
 }
else{   
  digitalWrite(fbrk2,HIGH);
  digitalWrite(bbrk1,HIGH);
  delay(50);
  if(positionVal0>5){
    sw0=1;
    sw1=0;
    sw2=0;
    sw3=0;
    
    }
  if(positionVal2>5){
    sw0=0;
    sw1=0;
    sw2=1;
    sw3=0;
    
    }
  
  
  }
  }
