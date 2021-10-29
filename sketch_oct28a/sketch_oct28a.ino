int m12 = 7;
int mb1 = 6;
int mb2 = 5;
int m11 = 4;
int enal = 3;
int enar = 9;
int enab = 11;

void setup() {
  // put your setup code here, to run once:
   pinMode(m12, OUTPUT);
    pinMode(mb1, OUTPUT);
    pinMode(mb2, OUTPUT);
    pinMode(m11, OUTPUT);
    pinMode(enal, OUTPUT);
    pinMode(enar, OUTPUT);
    pinMode(enab, OUTPUT);
    analogWrite(enal, 100);
    analogWrite(enar, 100);
    analogWrite(enab , 100);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(m11, HIGH);
    digitalWrite(m12, HIGH);
    digitalWrite(mb1, HIGH);
    digitalWrite(mb2, HIGH);
    

}
