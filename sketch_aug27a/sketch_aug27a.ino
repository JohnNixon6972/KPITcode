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
int SPEED = 100; //h4ighest  = 255 range == 1 < 255
void setup()
{
    Serial.begin(9600);
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
    Serial.begin(9600);
}

void loop()
{
    sonar(US_M_trigPin, US_M_echoPin);
    f = distance;
    sonar(US_L_trigPin, US_L_echoPin);
    l = distance;
    sonar(US_R_trigPin, US_R_echoPin);
    r = distance;
    Serial.print("L:");
    Serial.println(l);
    delayMicroseconds(1);
    Serial.print("F:");
    Serial.println(f);
    delayMicroseconds(1);
    Serial.print("R:");
    Serial.println(r);
    delayMicroseconds(1);

    if ((l <= 80) || (r <= 80) || (f <= 80))
    {
        analogWrite(enal, 100);
        analogWrite(enar, 100);

        if ((l >= 45) & (f >= 45) & (r >= 45))
        {
            digitalWrite(m11, HIGH);
            digitalWrite(m12, HIGH);
            digitalWrite(mb1, HIGH);
            digitalWrite(mb2, HIGH);
            digitalWrite(buzzer, LOW);
        }
        else if ((l < 45) & (f >= 80) & (r >= 80))
        {
            digitalWrite(m11, HIGH);
            digitalWrite(m12, LOW);
            digitalWrite(mb1, HIGH);
            digitalWrite(mb2, HIGH);
            digitalWrite(buzzer, LOW);
        }
        else if ((l >= 80) & (f >= 80) & (r < 45))
        {
            digitalWrite(m11, LOW);
            digitalWrite(m12, HIGH);
            digitalWrite(mb1, HIGH);
            digitalWrite(mb2, HIGH);
            digitalWrite(buzzer, LOW);
        }
        else if (f < 45)
        {
            if ((l > 80) & (l >= r))
            {
                digitalWrite(m11, LOW);
                digitalWrite(m12, HIGH);
                digitalWrite(mb1, HIGH);
                digitalWrite(mb2, HIGH);
                digitalWrite(buzzer, LOW);
            }
            else if ((r > 80) & (r >= l))
            {
                digitalWrite(m11, HIGH);
                digitalWrite(m12, LOW);
                digitalWrite(mb1, HIGH);
                digitalWrite(mb2, HIGH);
                digitalWrite(buzzer, LOW);
            }
            else
            {
                digitalWrite(m11, LOW);
                digitalWrite(m12, LOW);
                digitalWrite(mb1, LOW);
                digitalWrite(mb2, LOW);
                digitalWrite(buzzer, HIGH);
            }
        }
    }
    else
    {
        analogWrite(enal, 255);
        analogWrite(enar, 255);
        digitalWrite(m11, HIGH);
        digitalWrite(m12, HIGH);
        digitalWrite(mb1, HIGH);
        digitalWrite(mb2, HIGH);
    }
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
