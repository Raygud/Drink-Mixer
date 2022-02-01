
const int buttonPin = 2;     // the number of the pushbutton pin
const int Gin =  13;      // the number of the Gin pin
const int Mixer =  12;      // the number of the Mixer pin

bool Clicked = false;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the Gin/Mixer pins as an output:
  pinMode(Gin, OUTPUT);
  pinMode(Mixer, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // Switch Clicked state:
    Clicked = !Clicked;
  } else {
    Serial.write("hello");
  }
  if (Clicked == true) {
    digitalWrite(Gin, HIGH);
    delay(20000);
    digitalWrite(Gin, LOW);
    delay(500);
     digitalWrite(Mixer, HIGH);
    delay(60000);
    digitalWrite(Mixer, LOW);
    delay(500);
     Clicked = !Clicked;
}
else {
    // turn both pumps off:
    digitalWrite(Gin, LOW);
    digitalWrite(Mixer, LOW);
  }}
