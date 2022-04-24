int Xpin=A0;
int Ypin=A1;
int Spin=2;
int up=3;
int right=4;
int down=5;
int left=6;
int Xval;
int Yval;
int Sval; 

int delayT (int voltage) {
  voltage = voltage / 100;

  if (voltage == 10){
    int delayTime = 25;
    return delayTime;
  }

  if (voltage == 9){
    int delayTime = 50;
    return delayTime;
  }

  if (voltage == 8){
    int delayTime = 100;
    return delayTime;
  }

  if (voltage == 7){
    int delayTime = 200;
    return delayTime;
  }

  if (voltage == 6){
    int delayTime = 300;
    return delayTime;
  }          
  
  if (voltage == 5){
    int delayTime = 300;
    return delayTime;
  }
  if (voltage == 4){
    int delayTime = 200;
    return delayTime;
  }
  if (voltage == 3){
    int delayTime = 100;
    return delayTime;
  }
  if (voltage == 2){
    int delayTime = 50;
    return delayTime;
  }
  if (voltage == 1){
    int delayTime = 25;
    return delayTime;
  }

  if (voltage == 0){
    int delayTime = 25;
    return delayTime;
  }

  Serial.println (voltage);
          
}

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode (Xpin, INPUT);
pinMode (Ypin, INPUT);
pinMode (Spin, INPUT);
pinMode (up, OUTPUT);
pinMode (right, OUTPUT);
pinMode (down, OUTPUT);
pinMode (left, OUTPUT); 
digitalWrite (Spin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead (Xpin);
  Yval = analogRead (Ypin);
  Sval = digitalRead (Spin);
  delay (0);

  Serial.print ("X= ");
  Serial.print (Xval);
  Serial.print (" Y= ");
  Serial.print (Yval);
  Serial.print (" SW = ");
  Serial.println (Sval);

  if (Xval >= 540){
    digitalWrite (right, HIGH);
    delay (delayT(Xval));
    digitalWrite (right, LOW);
    delay (delayT(Xval));
  }
  else{
    digitalWrite (right, LOW);
  }

  if (Xval <= 480){
    digitalWrite (left, HIGH);
    delay (delayT(Xval));
    digitalWrite (left, LOW);
    delay (delayT(Xval));
  }
  else{
    digitalWrite (left, LOW);
  }
  
  if (Yval >= 530){
    digitalWrite (down, HIGH);
    delay (delayT(Yval));
    digitalWrite (down, LOW);
    delay (delayT(Yval));
  }
  else{
    digitalWrite (down, LOW);
  }

  if (Yval <= 470){
    digitalWrite (up, HIGH);
    delay (delayT(Yval));
    digitalWrite (up, LOW);
    delay (delayT(Yval));
  }
  else{
    digitalWrite (up,LOW);
  }

  if (Sval ==0){
    digitalWrite (down, HIGH);
    digitalWrite (right, HIGH);
    digitalWrite (down, HIGH);
    digitalWrite (left, HIGH);
  }

  
}
