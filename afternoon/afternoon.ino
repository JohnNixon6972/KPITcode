#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1);
long duration;
int distance, l, r, f;
int US_M_trigPin = A2, US_M_echoPin = A3;
int US_L_trigPin = A0, US_L_echoPin = A1;
int US_R_trigPin = A4, US_R_echoPin = A5;
int m12 = 7;
int mb1 = 6;
int mb2 = 5;
int m11 = 4;
int enal = 3;
int enar = 9;
int enab = 11;
int buzzer = 2;
bool isdriving;
int SPEED = 100; //h4ighest  = 255 range == 1 < 255
void setup()
{
    Serial.begin(9600);
    mySerial.begin(9600);
    while(!Serial)
    {   
      ;   
    }
       
    pinMode(US_L_trigPin, OUTPUT);
    pinMode(US_L_echoPin, INPUT);
    pinMode(US_M_trigPin, OUTPUT);
    pinMode(US_M_echoPin, INPUT);
    pinMode(US_R_trigPin, OUTPUT);
    pinMode(US_R_echoPin, INPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(m12, OUTPUT);
    pinMode(mb1, OUTPUT);
    pinMode(mb2, OUTPUT);
    pinMode(m11, OUTPUT);
    pinMode(enal, OUTPUT);
    pinMode(enar, OUTPUT);
    pinMode(enab, OUTPUT);
    analogWrite(enar, SPEED);
    analogWrite(enal, SPEED);
    analogWrite(enab, SPEED);
    
    
       
    isdriving = true;
}

void loop()
{

    if ((f >= 80) && (r >= 150) && (l >= 150))
        drive();

    else if (f > 40)
    {

        if ((r > 100) && (r > l) && (l > 40))
            moveright();

        else if ((l > 100) && (l > r) && (r > 40))
            moveleft();
        else
            stopcar();
    }
    else
        stopcar();

    getdistances();

    delay(100);
}
//delay(100);

void getdistances()
{
    sonar(US_M_trigPin, US_M_echoPin);
    f = distance;
    sonar(US_L_trigPin, US_L_echoPin);
    l = distance;
    sonar(US_R_trigPin, US_R_echoPin);
    r = distance;
    Serial.print("L:");
    mySerial.print("L:");
    Serial.println(l);
    delayMicroseconds(1);
    Serial.print("F:");
    Serial.println(f);
    delayMicroseconds(1);
    Serial.print("R:");
    Serial.println(r);
    delayMicroseconds(1);
}

void stopcar()
{
    digitalWrite(m11, LOW);
    digitalWrite(m12, LOW);
    digitalWrite(mb1, LOW);
    digitalWrite(mb2, LOW);
    digitalWrite(buzzer, HIGH);
}

void drive()
{

    analogWrite(enal, 100);
    analogWrite(enar, 100);

    digitalWrite(m11, HIGH);
    digitalWrite(m12, HIGH);
    digitalWrite(mb1, HIGH);
    digitalWrite(mb2, HIGH);
    digitalWrite(buzzer, LOW);
}

void moveleft()
{
    digitalWrite(m11, LOW);
    digitalWrite(m12, HIGH);
    digitalWrite(mb1, HIGH);
    digitalWrite(mb2, HIGH);
    digitalWrite(buzzer, LOW);
}

void moveright()
{
    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    digitalWrite(mb1, HIGH);
    digitalWrite(mb2, HIGH);
    digitalWrite(buzzer, LOW);
}

void sonar(int trigPin, int echoPin)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
}