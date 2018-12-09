# define fdir1 50
# define fbrk1 46
# define fpwm1 4
# define fdir2 51
# define fbrk2 47
# define fpwm2 5
# define bdir1 52
# define bbrk1 48
# define bpwm1 6
# define bdir2 53
# define bpwm2 7
# define bbrk2 49
#define gnd1 22
#define gnd2 23
#define gnd3 24
#define gnd4 25
#define gnd5 26

const int junctionPulse0=2;
const int junctionPulse1=3;
const int analogPin0 =A0;
const int analogPin1 =A1;
const int motorSpeed=200;
const int Kp=3;
void setup() {

  pinMode(gnd1,OUTPUT);
  pinMode(gnd2,OUTPUT);
  pinMode(gnd3,OUTPUT);
  pinMode(gnd4,OUTPUT);
  pinMode(gnd5,OUTPUT);
  
  
  pinMode(junctionPulse0,INPUT);
  pinMode(junctionPulse1,INPUT);
 
  attachInterrupt(digitalPinToInterrupt(junctionPulse0), brk0, RISING);
  attachInterrupt(digitalPinToInterrupt(junctionPulse1), brk1, RISING);
  

for(byte i=4;i<=7;i++){
    
    pinMode(i,OUTPUT);
    
    } 
  
  
  for(byte i=46;i<=53;i++){
    
    pinMode(i,OUTPUT);
    
    }

 digitalWrite(50,LOW);
 digitalWrite(53,LOW);
  digitalWrite(gnd1,LOW); 
 digitalWrite(gnd2,LOW);
digitalWrite(gnd3,LOW);
digitalWrite(gnd4,LOW);
digitalWrite(gnd5,LOW);
 
  

 
}

void loop() {

 Serial.begin(9600);
 pinMode(fbrk1,LOW);
 pinMode(bbrk2,LOW);
pinMode(fbrk2,LOW);
 pinMode(bbrk1,LOW);


int readVal0,readVal1, positionVal0,positionVal1;
  readVal0 = analogRead(analogPin0);    // Read value from analog pin
  readVal1=  analogRead(analogPin1);
  // Convert voltage level into line position value
  positionVal0 = ((float)readVal0/921)*70;
  positionVal1 = ((float)readVal1/921)*70;
  Serial.println(positionVal0);
  Serial.println(positionVal1);
  
 
 if(positionVal0>5){
   int error = Kp*(positionVal0-35);
  int leftMotorSpeed=motorSpeed - error;
  int rightMotorSpeed=motorSpeed + error;
  
move(leftMotorSpeed,rightMotorSpeed,fpwm1,bpwm2);

}


if(positionVal0<5&&positionVal0>5){
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
 
  digitalWrite(fbrk1,HIGH);
  digitalWrite(bbrk2,HIGH);
  }

  void brk1(){
  digitalWrite(fbrk2,HIGH);
  digitalWrite(bbrk1,HIGH);
    
    
    }
  
  

