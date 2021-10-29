#include <LiquidCrystal.h>
LiquidCrystal lcd(9,8,10,11,12,13);
#define trigPin1 A0
#define echoPin1 A1
#define trigPin2 A2
#define echoPin2 A3
#define trigPin3 A4
#define echoPin3 A5
int ALARM = 2;
int m11 = 5;
int m12 = 4;
int m21 = 6;
int m22 = 7;
long duration, distance, FIRSTSensor,SECONDSensor,THIRDSensor;
void setup()
{
lcd.begin(16,2);
Serial.begin (9600);
lcd.clear(); 
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(ALARM, OUTPUT);
pinMode(m11, OUTPUT);
pinMode(m12, OUTPUT);
pinMode(m21, OUTPUT);
pinMode(m22, OUTPUT);

digitalWrite(ALARM, LOW);
lcd.setCursor(0,0);lcd.print("Interfacing ");
lcd.setCursor(0,1);lcd.print("of Multiple ");
delay(3000);lcd.clear();  
lcd.setCursor(0,0);lcd.print("3 HC - SR04 ");
lcd.setCursor(0,1);lcd.print("Ultrasonic  ");
delay(3000);lcd.clear();
lcd.setCursor(0,0);lcd.print("SensorS With ");
lcd.setCursor(0,1);lcd.print("Arduino ");
delay(3000);lcd.clear();
}

void loop() 
{
/////////////////////////////////////////////////////// 
SonarSensor(trigPin1, echoPin1);
FIRSTSensor = distance;
SonarSensor(trigPin2, echoPin2);
SECONDSensor = distance;
SonarSensor(trigPin3, echoPin3);
THIRDSensor = distance;
/////////////////////////////////////////////////////////////
digitalWrite(ALARM, LOW);
//////////////////////////////////////////////////////////////////////////////////////
Serial.print("L:");Serial.println(FIRSTSensor); delayMicroseconds(10);
Serial.print("F:");Serial.println(SECONDSensor);delayMicroseconds(10);
Serial.print("R:");Serial.println(THIRDSensor); delayMicroseconds(10);
///////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,0);lcd.print("L:");lcd.setCursor(4,0);lcd.print(FIRSTSensor);
lcd.setCursor(9,0);lcd.print("F:");lcd.setCursor(12,0);lcd.print(SECONDSensor);
lcd.setCursor(0,1);lcd.print("R:");lcd.setCursor(4,1);lcd.print(THIRDSensor);
delay(500);lcd.clear();

if ((FIRSTSensor <= 70) || (SECONDSensor <= 70) || (THIRDSensor <= 70)){
    digitalWrite(ALARM, HIGH);
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
  }

if ((FIRSTSensor >= 100) & (SECONDSensor >= 100) & (THIRDSensor >= 100)){
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
  }
else if ((FIRSTSensor < 100) & (SECONDSensor >= 100) & (THIRDSensor >= 100)){
    digitalWrite(m11,LOW);
    digitalWrite(m12,LOW);
    digitalWrite(m21,HIGH);
    digitalWrite(m22,LOW);
  }
else if ((FIRSTSensor >= 100) & (SECONDSensor >= 100) & (THIRDSensor < 100)){
    digitalWrite(m11,HIGH);
    digitalWrite(m12,LOW);
    digitalWrite(m21,LOW);
    digitalWrite(m22,LOW);
  }
else if (SECONDSensor < 100){
    if ((FIRSTSensor > 100)& (FIRSTSensor >= THIRDSensor) ){
        digitalWrite(m11,HIGH);
        digitalWrite(m12,LOW);
        digitalWrite(m21,LOW);
        digitalWrite(m22,LOW);
      }
    else if ((THIRDSensor > 100) & (THIRDSensor >= FIRSTSensor)){
        digitalWrite(m11,LOW);
        digitalWrite(m12,LOW);
        digitalWrite(m21,HIGH);
        digitalWrite(m22,LOW);
      }
    else {
        digitalWrite(m11,LOW);
        digitalWrite(m12,LOW);
        digitalWrite(m21,LOW);
        digitalWrite(m22,LOW);
      }
  }
    

}
/////////////////////////////////////////////////////////////////////////////////
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
