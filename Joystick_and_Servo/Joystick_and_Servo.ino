#include <Servo.h>

int Xpin = A0;
int Ypin = A1;
int Spin = 2;
int Xval;
int Yval;
int Sval; 

int servoPin = 9;
int servoPos = 0;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode (Xpin, INPUT);
pinMode (Ypin, INPUT);
pinMode (Spin, INPUT);
digitalWrite (Spin, HIGH);
myServo.attach (servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead (Xpin);
  Yval = analogRead (Ypin);
  Sval = digitalRead (Spin);
  delay (25);

  Serial.print ("X= ");
  Serial.print (Xval);
  Serial.print (" Y= ");
  Serial.print (Yval);
  Serial.print (" SW = ");
  Serial.print (Sval);

  if (Xval < 275 && servoPos > 0) {
    servoPos = servoPos - 10;
    myServo.write (servoPos);
  }

  if (Xval > 725 && servoPos < 180) {
    servoPos = servoPos + 10;
    myServo.write (servoPos);
  }

  if (Sval == 0){
    servoPos = 0;
    myServo.write (servoPos);
  }

  Serial.print (" Servo = ");
  Serial.println (servoPos);
  
}
