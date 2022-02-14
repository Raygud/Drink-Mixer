# Arduino Gin&Tonic Mixer
____
## Issues: 
 1. Pumping carbonated drinks is not a good idea! about half of the expected volum comes out and it comes out uncarbonated since the liquid and carbon get seperated in the small tube(dont know if the size of the tube makes any difference..)

2. Bigger pumps are needed, puming at 6 volts took 2min 40 seconds too fill the glass! bumping up the voltage too 9v(Stressings the pump) took 1min 20 seconds yilded a rather impressive 50% decrease in time.

> > note: make sure your tubes are going too the right location, had an unfortunate experience with a rather powerful mix! 

 ## constants won't change. They're used here to set pin numbers:

```

const int Mixer =  13;             // the number of the Mixer pin
const int Gin =  12;              // the number of the Gin pin
const int ReadyLed =  9;         // Indicates the machine is ready too pour
const int WorkingLed =  8;      // Indicates the machine is currently pouring
const int buttonPin = 2;            // the number of the pushbutton pin
```
_____

## Variables will change while program is running

```
Button setup:
   bool Clicked = false; // Says that the button is currently NOT pressed
   int buttonState = 0;         // variable for reading the pushbutton status, will change too 1 if pressed(bool)
```
____

## Initial setup on start up, this code will run once when the program initionaly stars running.

```
void setup() {

   Serial.begin(9600);// opens serial port, sets data rate to 9600 bps(Realy only used for testing)
   
   OUTPUT // Voltage will be set to the corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH and 0V for LOW
   
   pinMode(Gin, OUTPUT); 
   pinMode(Mixer, OUTPUT);
   
  // initialize the Gin/Mixer pins as an output:
   pinMode(ReadyLed, OUTPUT);
   pinMode(WorkingLed, OUTPUT);
   
  // initialize the pushbutton pin as an input:
  
   pinMode(buttonPin, INPUT); // Pins are actualy set as INPUT by default, but im keeping this in for clarity.
   
   digitalWrite(ReadyLed, HIGH); // Turns on ReadyLed too indicate that the machine is ready too pour.
   
   // as unintuitive as it might sound setting the Mixer && Gin pins to HIGH will turn the relays of so here we are just making sure the pumps are turned of.
   
   digitalWrite(Mixer, HIGH);
   digitalWrite(Gin, HIGH);
}
```

____

```

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  digitalWrite(Gin, HIGH);
    digitalWrite(Mixer, HIGH);
      
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // Switch Clicked state:
    Clicked = !Clicked;
  } else {
    Serial.write("hello");
  }
  if (Clicked == true) {
     digitalWrite(WorkingLed, HIGH);
     digitalWrite(ReadyLed, LOW);
     digitalWrite(Gin, LOW);
     delay(2000);
     digitalWrite(Gin, HIGH);
     digitalWrite(Mixer, LOW);
     delay(2000);
     digitalWrite(Gin, HIGH);
     digitalWrite(Mixer, HIGH);
     digitalWrite(WorkingLed, LOW);
     digitalWrite(ReadyLed, HIGH);
     delay(1000);
     
     Clicked = !Clicked;
}
else {
    // turn both pumps off:
    digitalWrite(Gin, HIGH);
    digitalWrite(Mixer, HIGH);
  }}

```

