int m12 = 7;
int mb1 = 6;
int mb2 = 5;
int m11 = 4;
int ena1 = 3;
int ena2 = 11;
int SPEED = 255;

void setup() {
  // put your setup code here, to run once:
 pinMode(m12,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  pinMode(m11,OUTPUT);
  pinMode(ena1,OUTPUT);
  pinMode(ena2,OUTPUT);
  analogWrite(ena1,SPEED);
  analogWrite(ena2,SPEED);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(m11,HIGH);
    digitalWrite(m12,HIGH);
    digitalWrite(mb1,HIGH);
    digitalWrite(mb2,HIGH);
}
