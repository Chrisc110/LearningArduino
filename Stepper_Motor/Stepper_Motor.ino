#include <Stepper.h>
int stepsPerRev=2048;
int motSpeed=10;
int buttonPin = 3;
int newButton;
int oldButton = 1;
int state = 0;

Stepper myStepper(stepsPerRev,8,10,9,11);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper.setSpeed(motSpeed);
pinMode (buttonPin, INPUT);
digitalWrite (buttonPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
newButton = digitalRead(buttonPin);
  if (oldButton == 0 && newButton == 1){
    if (state == 0){
      state = 1;
    }
    else{
      state = 0;
    }
  }
  if (state == 1){
    myStepper.step(1);
    Serial.println("right");
  }
  else{
    myStepper.step (-1);
    Serial.println("left");
  }
  
oldButton = newButton;
}
