int vol;

void setup() {
  // put your setup code here, to run once:
pinMode (2, INPUT);
digitalWrite (2, HIGH);
Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
vol=digitalRead (2);
Serial.println (vol);

}
