int port = 12;
int state = 0;
int oldButton = 1;
int newButton;


void setup() {
  // put your setup code here, to run once:
  pinMode (port, INPUT);
  Serial.begin (9600);
  pinMode (2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

newButton = digitalRead (port);

if (oldButton == 0 && newButton ==1) {
  if (state == 0){
    digitalWrite (2, HIGH);
    state = 1;
    }
    else {
      digitalWrite (2, LOW);
      state = 0;
      }
  }
oldButton = newButton;
delay (100);  
}

        
