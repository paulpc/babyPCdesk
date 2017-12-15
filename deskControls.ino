/*
  AnalogReadSerial

  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
  const int analogOutRed = 7;
  const int analogOutYellow = 9;
  const int analogOutBlue = 10;
  const int analogOutGreen = 11;
  const int analogOutWhite = 12;

  const int redButtonPin = 2;     // the number of the pushbutton pin
  const int yellowButtonPin = 3;     // the number of the pushbutton pin
  const int blueButtonPin = 4;     // the number of the pushbutton pin
  const int greenButtonPin = 5;     // the number of the pushbutton pin
  const int whiteButtonPin = 6;     // the number of the pushbutton pin
  const int flashButtonPin = 8;     // the number of the pushbutton pin
  
  
  int redState = 0;         // variable for reading the pushbutton status
  int yellowState = 0;         // variable for reading the pushbutton status
  int blueState = 0;         // variable for reading the pushbutton status
  int greenState = 0;         // variable for reading the pushbutton status
  int whiteState = 0;         // variable for reading the pushbutton status

  int brightness = HIGH;
  // the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(redButtonPin, INPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(whiteButtonPin, INPUT);
  pinMode(flashButtonPin, INPUT);
  // flash all lights once
  pinMode(analogOutRed, OUTPUT);
  pinMode(analogOutYellow, OUTPUT);
  pinMode(blueButtonPin, OUTPUT);
  pinMode(analogOutBlue, OUTPUT);
  pinMode(analogOutGreen, OUTPUT);
  pinMode(analogOutWhite, OUTPUT);

  digitalWrite(analogOutRed, brightness);
  digitalWrite(analogOutYellow, brightness);
  digitalWrite(analogOutBlue, brightness);
  digitalWrite(analogOutGreen, brightness);
  digitalWrite(analogOutWhite, brightness);
  delay(1000);
  digitalWrite(analogOutRed, 0);
  digitalWrite(analogOutYellow, 0);
  digitalWrite(analogOutBlue, 0);
  digitalWrite(analogOutGreen, 0);
  digitalWrite(analogOutWhite, 0);
}
// the loop routine runs over and over again forever:
void loop() {

  // red lights
  
  int redBV = digitalRead(redButtonPin);

  if (redBV == HIGH) {
    if (redState == LOW) {
      Serial.println("red button pressed - ON");
      redState = HIGH;
      digitalWrite(analogOutRed, brightness);
  }
  else {
    Serial.println("red button pressed - OFF");
    digitalWrite(analogOutRed, 0);
    redState = LOW;
  }
  delay(500);
  }

  // yellow lights
  int yellowBV = digitalRead(yellowButtonPin);
  
    if (yellowBV == HIGH) {
      if (yellowState == LOW) {
        Serial.println("yellow button pressed - ON");
        yellowState = HIGH;
        digitalWrite(analogOutYellow, brightness);
      } 
      else {
        Serial.println("yellow button pressed - OFF");
        digitalWrite(analogOutYellow, 0);
        yellowState = LOW;
      }
     delay(500);
    }

  // blue lights
  int blueBV = digitalRead(blueButtonPin);
  
    if (blueBV == HIGH) {
       delay(100);
      if (blueState == LOW) {
        Serial.println("blue button pressed - ON");
        blueState = HIGH;
        digitalWrite(analogOutBlue, brightness);
      } 
      else {
        Serial.println("blue button pressed - OFF");
        digitalWrite(analogOutBlue, 0);
        blueState = LOW;
      }
      delay(500);
    }

    // white lights
    int whiteBV = digitalRead(whiteButtonPin);
    
      if (whiteBV == HIGH) {
        if (whiteState == LOW) {
          Serial.println("white button pressed - ON");
          whiteState = HIGH;
          digitalWrite(analogOutWhite, brightness);
        } 
        else {
          Serial.println("white button pressed - OFF");
          digitalWrite(analogOutWhite, 0);
          whiteState = LOW;
        }
        delay(500);
      }

    // green lights
    int greenBV = digitalRead(greenButtonPin);
  
    if (greenBV == HIGH) {
      if (greenState == LOW) {
        Serial.println("green button pressed - ON");
        greenState = HIGH;
        digitalWrite(analogOutGreen, brightness);
      } 
      else {
        Serial.println("green button pressed - OFF");
        digitalWrite(analogOutGreen, 0);
        greenState = LOW;
      }
      delay(500);
    }

  // flashing pattern: red on + off, yellow on + off, blue on + off , green on + off, white on + off 
  // red on, wait, yellow on, wait, blue on, wait, green on, wait, white on, wait (all on at this point)
  // all flash x 3
  // red off, wait, yellow off, wait, blue off wait, green off, wait, white off (all off at this point)
  int flashBV = digitalRead(flashButtonPin);
  if (flashBV == HIGH) {
    Serial.println("Flash button pressed; party time");

    digitalWrite(analogOutRed, brightness);
    delay(500);
    digitalWrite(analogOutYellow, brightness);
    delay(500);
    digitalWrite(analogOutBlue, brightness);
    delay(500);
    digitalWrite(analogOutGreen, brightness);
    delay(500);
    digitalWrite(analogOutWhite, brightness);
    delay(500);
    //all flash x 3
    for (int tp = 0; tp < 5; tp++) {      
      digitalWrite(analogOutRed, 0);
      digitalWrite(analogOutYellow, 0);
      digitalWrite(analogOutBlue, 0);
      digitalWrite(analogOutGreen, 0);
      digitalWrite(analogOutWhite, 0);
      delay(1000);
      digitalWrite(analogOutRed, brightness);
      digitalWrite(analogOutYellow, brightness);
      digitalWrite(analogOutBlue, brightness);
      digitalWrite(analogOutGreen, brightness);
      digitalWrite(analogOutWhite, brightness);
      delay(500);
    }
    // now turn them back off
    digitalWrite(analogOutRed, 0);
    delay(500);
    digitalWrite(analogOutYellow, 0);
    delay(500);
    digitalWrite(analogOutBlue, 0);
    delay(500);
    digitalWrite(analogOutGreen, 0);
    delay(500);
    digitalWrite(analogOutWhite, 0);
    Serial.println("Party time is over");

  }
  delay(1);        // delay in between reads for stability
}
