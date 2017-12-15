/*
  AnalogReadSerial

  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
  const int redLed = 7;
  const int yellowLed = 9;
  const int blueLed = 10;
  const int greenLed = 11;
  const int whiteLed = 12;

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

  int redFlash = 3;         
  int yellowFlash = 3;
  int blueFlash =  3;
  int greenFlash = 3;
  int whiteFlash = 3; 

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
  // initializing the LEDs
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueButtonPin, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);

  // flash all lights once
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(blueLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(whiteLed, HIGH);
  delay(1000);
  digitalWrite(redLed, 0);
  digitalWrite(yellowLed, 0);
  digitalWrite(blueLed, 0);
  digitalWrite(greenLed, 0);
  digitalWrite(whiteLed, 0);
}
// the loop routine runs over and over again forever:
void loop() {

  // red lights
  
  int redBV = digitalRead(redButtonPin);
  if (redBV == HIGH) {
    if (redState == LOW) {
      Serial.println("red button pressed - ON");
      redState = HIGH;
      digitalWrite(redLed, HIGH);
      redFlash -= 1;
  }
  else {
    Serial.println("red button pressed - OFF");
    digitalWrite(redLed, 0);
    redState = LOW;
    if (redFlash == 0) {
      for (int i =0; i < 5; i++) {
        digitalWrite(redLed, HIGH);
        delay(250);
        digitalWrite(redLed, LOW);
        delay(500);
      }
      redFlash = 3;
    }
  }
  delay(500);
  }

  // yellow lights
  int yellowBV = digitalRead(yellowButtonPin);
  if (yellowBV == HIGH) {
    if (yellowState == LOW) {
      Serial.println("yellow button pressed - ON");
      yellowState = HIGH;
      digitalWrite(yellowLed, HIGH);
      yellowFlash -= 1;
    } 
    else {
      Serial.println("yellow button pressed - OFF");
      digitalWrite(yellowLed, 0);
      yellowState = LOW;
      if (yellowFlash == 0) {
        for (int i =0; i < 5; i++) {
          digitalWrite(yellowLed, HIGH);
          delay(250);
          digitalWrite(yellowLed, LOW);
          delay(500);
        }
        yellowFlash = 3;
      }
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
      digitalWrite(blueLed, HIGH);
      blueFlash -= 1;
    } 
    else {
      Serial.println("blue button pressed - OFF");
      digitalWrite(blueLed, 0);
      blueState = LOW;
      if (blueFlash == 0) {
        for (int i =0; i < 5; i++) {
          digitalWrite(blueLed, HIGH);
          delay(250);
          digitalWrite(blueLed, LOW);
          delay(500);
        }
      blueFlash = 3;
    }
    }
    delay(500);
  }

    // white lights
  int whiteBV = digitalRead(whiteButtonPin);
  if (whiteBV == HIGH) {
    if (whiteState == LOW) {
      Serial.println("white button pressed - ON");
      whiteState = HIGH;
      digitalWrite(whiteLed, HIGH);
      whiteFlash -= 1;
    } 
    else {
      Serial.println("white button pressed - OFF");
      digitalWrite(whiteLed, 0);
      whiteState = LOW;
      if (whiteFlash == 0) {
        for (int i =0; i < 5; i++) {
          digitalWrite(whiteLed, HIGH);
          delay(250);
          digitalWrite(whiteLed, LOW);
          delay(500);
        }
        whiteFlash = 3;
      }
    }
    delay(500);
  }

  // green lights
  int greenBV = digitalRead(greenButtonPin);
  if (greenBV == HIGH) {
    if (greenState == LOW) {
      Serial.println("green button pressed - ON");
      greenState = HIGH;
      digitalWrite(greenLed, HIGH);
      greenFlash -= 1;

    } 
    else {
      Serial.println("green button pressed - OFF");
      digitalWrite(greenLed, 0);
      greenState = LOW;
      if (greenFlash == 0) {
        for (int i =0; i < 5; i++) {
          digitalWrite(greenLed, HIGH);
          delay(250);
          digitalWrite(greenLed, LOW);
          delay(500);
        }
        greenFlash = 3;
      }
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
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(yellowLed, HIGH);
    delay(500);
    digitalWrite(blueLed, HIGH);
    delay(500);
    digitalWrite(greenLed, HIGH);
    delay(500);
    digitalWrite(whiteLed, HIGH);
    delay(500);

    //all flash x 5
    for (int tp = 0; tp < 10; tp++) {      
      digitalWrite(redLed, 0);
      digitalWrite(yellowLed, 0);
      digitalWrite(blueLed, 0);
      digitalWrite(greenLed, 0);
      digitalWrite(whiteLed, 0);
      delay(500);
      digitalWrite(redLed, HIGH);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(blueLed, HIGH);
      digitalWrite(greenLed, HIGH);
      digitalWrite(whiteLed, HIGH);
      delay(250);
    }
    
    // now turn them back off
    digitalWrite(redLed, 0);
    delay(500);
    digitalWrite(yellowLed, 0);
    delay(500);
    digitalWrite(blueLed, 0);
    delay(500);
    digitalWrite(greenLed, 0);
    delay(500);
    digitalWrite(whiteLed, 0);
    Serial.println("Party time is over");
    // resetting the counters
      int redFlash = 3;         
      int yellowFlash = 3;
      int blueFlash =  3;
      int greenFlash = 3;
      int whiteFlash = 3; 
  }
  delay(1);        // delay in between reads for stability
}
