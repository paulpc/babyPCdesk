/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
  const int analogOutWhite = 12;
  const int analogOutRed = 11;
  const int analogOutGreen = 10;
  const int analogOutBlue = 9;
  const int analogOutYellow = 8;
  const int buttonPin = 7;     // the number of the pushbutton pin
  int buttonState = 0;         // variable for reading the pushbutton status

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
// the loop routine runs over and over again forever:
int sensorValue = 0;

void loop() {
  // read the input on analog pin 1:
    sensorValue += analogRead(A7);
  if (sensorValue > 0) {
    Serial.println("motion detected at some point");
    // continuous beeps for motion - if adam is there, turn on the lights
    Serial.println(sensorValue);
    //analogWrite(analogOutWhite, sensorValue);
   // turn the LED on (HIGH is the voltage level)
   // delay(100);                       // wait for a second
    //analogWrite(analogOutBlue, sensorValue);
   // turn the LED on (HIGH is the voltage level)
   // delay(100);                       // wait for a second
   // analogWrite(analogOutGreen, sensorValue);
  // analogWrite(analogOutWhite, 0);
   // turn the LED on (HIGH is the voltage level)
   // delay(100);                       // wait for a second
    analogWrite(analogOutRed, 10);
  //  analogWrite(analogOutBlue, 0);
   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
  // analogWrite(analogOutGreen, 0);
    // turn the LED off by making the voltage LOW
                           // wait for a second
    analogWrite(analogOutRed, 0);
    delay(100);
    sensorValue -= 200; // should probably have a 7 second interval between movements just in case
    }
   int buttonValue = digitalRead(buttonPin);
  if (buttonValue == HIGH) {
    if (buttonState == LOW) {
      Serial.println("button pressed - ON");
      buttonState = HIGH;
      analogWrite(analogOutWhite, 255);
  }
  else {
    Serial.println("button pressed - OFF");
    analogWrite(analogOutWhite, 0);
    buttonState = LOW;
  }
  }
  
  delay(1);        // delay in between reads for stability
}
