int in1 = 7;
int in2 = 6;
int in3 = 5;
int in4 = 4;
int ena = 3;
int ena1 = 11;
int SPEED = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(ena1,OUTPUT);
  analogWrite(ena,SPEED);
  analogWrite(ena1,SPEED);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
