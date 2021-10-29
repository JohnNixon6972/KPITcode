
int m11 = 5;
int m12 = 4;
int m21 = 7;
int m22 = 8;
long L_duration,M_duration,R_duration;
int L_distance,M_distance,R_distance;
int US_M_trigPin= 3 ,US_M_echoPin= 2;
int US_L_trigPin= 10,US_L_echoPin= 12;
int US_R_trigPin = 11,US_R_echoPin = 13;

void setup() 
{
 Serial.begin(9600);
pinMode( m11 , OUTPUT);
pinMode( m12 , OUTPUT);
pinMode( m21 , OUTPUT);
pinMode( m22 , OUTPUT);
pinMode(US_L_trigPin,OUTPUT);
pinMode(US_L_echoPin,INPUT);
pinMode(US_M_trigPin,OUTPUT);
pinMode(US_M_echoPin,INPUT);
pinMode(US_R_trigPin,OUTPUT);
pinMode(US_R_echoPin,INPUT);
Serial.begin(9600);

}

void loop() 
{
  // Clears the trigPin condition
  digitalWrite(US_L_trigPin, LOW);
  digitalWrite(US_M_trigPin, LOW);
  digitalWrite(US_R_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(US_L_trigPin, HIGH);
  digitalWrite(US_M_trigPin, HIGH);
  digitalWrite(US_R_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_L_trigPin, LOW);
  digitalWrite(US_M_trigPin, LOW);
  digitalWrite(US_R_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  L_duration = pulseIn(US_L_echoPin, HIGH);
  M_duration = pulseIn(US_M_echoPin, HIGH);
  R_duration = pulseIn(US_R_echoPin, HIGH);
    // Calculating the distance
  L_distance = L_duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  M_distance = M_duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  R_distance = R_duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
  Serial.print("L_Distance: ");
  Serial.print(L_distance);
  Serial.println(" cm");
  Serial.print("M_Distance: ");
  Serial.print(M_distance);
  Serial.println(" cm");
  Serial.print("R_Distance: ");
  Serial.print(R_distance);
  Serial.println(" cm");
  
  //if ( distance > 50)
  //{
  //  digitalWrite( m11 , HIGH);
  //  digitalWrite( m12 , LOW);
  //  digitalWrite( m21 , HIGH);            // FORWARD DIRECTION
  //  digitalWrite( m22 , LOW);
  //}
  //else if ( distance < 50)
  //{
  //  digitalWrite( m11 , LOW);
  //  digitalWrite( m12 , HIGH);               // RIGHT DIRECTION
  //  digitalWrite( m21 , HIGH);
  //  digitalWrite( m22 , LOW);
  //  delay(300);
  //  }
}
