/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/


#include <Servo.h>

Servo myservoA;  // create servo object to control a servo
Servo myservoB;  // create servo object to control a servo
// twelve servo objects can be created on most boards

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
unsigned long previousMillis = 0;          
const long interval = 10000;   


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int posA = 0;    // variable to store the servo position
int posB = 0;    // variable to store the servo position

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
  myservoA.attach(9);  // attaches the servo on pin 9 to the servo object
  myservoB.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop() {
  // read the state of the pushbutton value:
  unsigned long currentMillis = millis();
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:

 if (buttonState == HIGH) {
  digitalWrite(ledPin, HIGH);
    for (posA = 0; posA <= 180; posA += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoA.write(posA);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (posA = 180; posA >= 0; posA -= 1) { // goes from 180 degrees to 0 degrees
    myservoA.write(posA);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    
 }
  if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;
      for (posB = 0; posB <= 180; posB += 1) { // goes from 0 degrees to 180 degrees
     // in steps of 1 degree
     myservoB.write(posB);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
   }
    for (posB = 180; posB >= 0; posB -= 1) { // goes from 180 degrees to 0 degrees
     myservoB.write(posB);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
    }
    }
  
   else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
