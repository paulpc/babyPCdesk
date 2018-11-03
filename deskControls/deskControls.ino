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

  // reading state
  int redBV = digitalRead(redButtonPin);
  int flashBV = digitalRead(flashButtonPin);
  int yellowBV = digitalRead(yellowButtonPin);
  int blueBV = digitalRead(blueButtonPin);
  int whiteBV = digitalRead(whiteButtonPin);
  int greenBV = digitalRead(greenButtonPin);

  // red lights
  if (redBV == HIGH) {
    if (flashBV == HIGH){
      //   red and flash pressed, first party time
      // R - R  - Y  - Y - B - B - R - W - G - G - W - R
      digitalWrite(redLed, HIGH);
      delay(500);
      digitalWrite(redLed, LOW);
      delay(1000);
      digitalWrite(redLed, HIGH);
      delay(500);
      digitalWrite(redLed, LOW);
      delay(1000);
      digitalWrite(yellowLed, HIGH);
      delay(500);
      digitalWrite(yellowLed, LOW);
      delay(1000);
      digitalWrite(yellowLed, HIGH);
      delay(500);
      digitalWrite(yellowLed, LOW);
      delay(1000);
      digitalWrite(blueLed, HIGH);
      delay(500);
      digitalWrite(blueLed, LOW);
      delay(1000);
      digitalWrite(blueLed, HIGH);
      delay(500);
      digitalWrite(blueLed, LOW);
      delay(1000);
      digitalWrite(redLed, HIGH);
      delay(500);
      digitalWrite(redLed, LOW);
      delay(1000);
      digitalWrite(whiteLed, HIGH);
      delay(500);
      digitalWrite(whiteLed, LOW);
      delay(1000);
      digitalWrite(greenLed, HIGH);
      delay(500);
      digitalWrite(greenLed, LOW);
      delay(1000);
      digitalWrite(redLed, HIGH);
      delay(500);
      digitalWrite(redLed, LOW);
      delay(1000);
      digitalWrite(whiteLed, HIGH);
      delay(500);
      digitalWrite(whiteLed, LOW);
      delay(1000);
      digitalWrite(greenLed, HIGH);
      delay(500);
      digitalWrite(greenLed, LOW);
      delay(1000);
    }
    else {
      if (redState == LOW) {
        Serial.println("red button pressed - ON");
        redState = HIGH;
        digitalWrite(redLed, HIGH);
      }
      else {
        Serial.println("red button pressed - OFF");
        digitalWrite(redLed, 0);
        redState = LOW;
      }
    }
  }

  // yellow lights
  if (yellowBV == HIGH) {
    if (flashBV == HIGH){
      // yellow and flash pressed, first party time
      // R Y B G W - R Y B G W g2 - R Y G B W g3 - r g b g w -g4
      digitalWrite(redLed, HIGH);
      delay(200);
      digitalWrite(redLed, LOW);
      delay(200);
      digitalWrite(yellowLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, LOW);
      delay(200);
      digitalWrite(blueLed, HIGH);
      delay(200);
      digitalWrite(blueLed, LOW);
      delay(200);
      digitalWrite(greenLed, HIGH);
      delay(200);
      digitalWrite(greenLed, LOW);
      delay(200);
      digitalWrite(whiteLed, HIGH);
      delay(200);
      digitalWrite(whiteLed, LOW);
      delay(500);

      digitalWrite(redLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, HIGH);
      delay(200);
      digitalWrite(redLed, LOW);
      delay(200);
      digitalWrite(blueLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, LOW);
      delay(200);
      digitalWrite(greenLed, HIGH);
      delay(200);
      digitalWrite(blueLed, LOW);
      delay(200);
      digitalWrite(whiteLed, HIGH);
      delay(200);
      digitalWrite(greenLed, LOW);
      delay(200);
      digitalWrite(whiteLed, LOW);
      delay(500);

      digitalWrite(redLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, HIGH);
      delay(200);
      digitalWrite(blueLed, HIGH);
      delay(200);
      digitalWrite(redLed, LOW);
      delay(200);
      digitalWrite(greenLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, LOW);
      delay(200);
      digitalWrite(whiteLed, HIGH);
      delay(200);
      digitalWrite(blueLed, LOW);
      delay(200);
      digitalWrite(greenLed, LOW);
      delay(200);
      digitalWrite(whiteLed, LOW);
      delay(500);
      
      digitalWrite(redLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, HIGH);
      delay(200);
      digitalWrite(blueLed, HIGH);
      delay(200);
      digitalWrite(greenLed, HIGH);
      delay(200);
      digitalWrite(redLed, LOW);
      delay(200);
      digitalWrite(whiteLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, LOW);
      delay(200);
      digitalWrite(blueLed, LOW);
      delay(200);
      digitalWrite(greenLed, LOW);
      delay(200);
      digitalWrite(whiteLed, LOW);

    }
    else {
    if (yellowState == LOW) {
      Serial.println("yellow button pressed - ON");
      yellowState = HIGH;
      digitalWrite(yellowLed, HIGH);
    } 
    else {
      Serial.println("yellow button pressed - OFF");
      digitalWrite(yellowLed, 0);
      yellowState = LOW;
      }
    }
    }
 

  // blue lights
  if (blueBV == HIGH) {
    if (flashBV == HIGH) {
      // blue and flash pressed, first party time
      // R r Y y B b G g W w  - R Y B G W g2 - R Y G B W g3 - r g b g w -g4
      digitalWrite(redLed, HIGH);
      delay(600);
      digitalWrite(redLed, LOW);
      delay(400);
      digitalWrite(redLed, HIGH);
      delay(200);
      digitalWrite(redLed, LOW);
      delay(400);
      digitalWrite(redLed, HIGH);
      delay(600);
      digitalWrite(redLed, LOW);
      delay(400);
      digitalWrite(redLed, HIGH);
      delay(200);
      digitalWrite(redLed, LOW);
      delay(400);
      digitalWrite(yellowLed, HIGH);
      delay(600);
      digitalWrite(yellowLed, LOW);
      delay(400);
      digitalWrite(yellowLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, LOW);
      delay(400);
      digitalWrite(yellowLed, HIGH);
      delay(600);
      digitalWrite(yellowLed, LOW);
      delay(400);
      digitalWrite(yellowLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, LOW);
      delay(400);
      digitalWrite(whiteLed, HIGH);
      delay(600);
      digitalWrite(whiteLed, LOW);
      delay(400);
      digitalWrite(whiteLed, HIGH);
      delay(200);
      digitalWrite(whiteLed, LOW);
      delay(400);
      digitalWrite(whiteLed, HIGH);
      delay(600);
      digitalWrite(whiteLed, LOW);
      delay(400);
      digitalWrite(whiteLed, HIGH);
      delay(200);
      digitalWrite(whiteLed, LOW);
      delay(400);
      digitalWrite(greenLed, HIGH);
      delay(600);
      digitalWrite(greenLed, LOW);
      delay(400);
      digitalWrite(greenLed, HIGH);
      delay(200);
      digitalWrite(greenLed, LOW);
      delay(400);
      digitalWrite(greenLed, HIGH);
      delay(600);
      digitalWrite(greenLed, LOW);
      delay(400);
      digitalWrite(greenLed, HIGH);
      delay(200);
      digitalWrite(greenLed, LOW);
      delay(400);
      digitalWrite(blueLed, HIGH);
      delay(600);
      digitalWrite(blueLed, LOW);
      delay(400);
      digitalWrite(blueLed, HIGH);
      delay(200);
      digitalWrite(blueLed, LOW);
      delay(400);
      digitalWrite(blueLed, HIGH);
      delay(600);
      digitalWrite(blueLed, LOW);
      delay(400);
      digitalWrite(blueLed, HIGH);
      delay(200);
      digitalWrite(blueLed, HIGH);
      delay(400);
      digitalWrite(yellowLed, HIGH);
      delay(200);
      digitalWrite(yellowLed, LOW);
      delay(400);
      digitalWrite(redLed, HIGH);
      delay(200);
      digitalWrite(redLed, LOW);
      delay(400);
    }
    else {
     if (blueState == LOW) {
      Serial.println("blue button pressed - ON");
      blueState = HIGH;
      digitalWrite(blueLed, HIGH);
    } 
    else {
      Serial.println("blue button pressed - OFF");
      digitalWrite(blueLed, 0);
      blueState = LOW;
    }
    }
  }

    // white lights
  if (whiteBV == HIGH) {
    if (flashBV == HIGH){
      digitalWrite(redLed, HIGH);
    delay(1000);
    digitalWrite(yellowLed, HIGH);
    delay(1000);
    digitalWrite(blueLed, HIGH);
    delay(1000);
    digitalWrite(greenLed, HIGH);
    delay(1000);
    digitalWrite(whiteLed, HIGH);
    delay(1000);
    
    // now turn them back off
    digitalWrite(redLed, 0);
    delay(1000);
    digitalWrite(yellowLed, 0);
    delay(1000);
    digitalWrite(blueLed, 0);
    delay(1000);
    digitalWrite(greenLed, 0);
    delay(1000);
    digitalWrite(whiteLed, 0);

    // left to right to left
    digitalWrite(redLed, HIGH);
    delay(1000);
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(1000);
    digitalWrite(yellowLed, LOW);
    digitalWrite(blueLed, HIGH);
    delay(1000);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(1000);
    digitalWrite(greenLed, LOW);
    digitalWrite(whiteLed, HIGH);
    delay(1000);
    digitalWrite(whiteLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(1000);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, HIGH);
    delay(1000);
    digitalWrite(blueLed, LOW);
    digitalWrite(yellowLed, HIGH);
    delay(1000);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    delay(1000);
    digitalWrite(redLed, LOW);
    }
    else {
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
      }
    }
  }

  // green lights
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
        for (int i = 0; i < 10; i++) {
          digitalWrite(greenLed, HIGH);
          delay(250);
          digitalWrite(greenLed, LOW);
          delay(500);
        }
        greenFlash = 3;
      }
    }    
  }

  // flashing pattern: red on + off, yellow on + off, blue on + off , green on + off, white on + off 
  // red on, wait, yellow on, wait, blue on, wait, green on, wait, white on, wait (all on at this point)
  // all flash
  // red off, wait, yellow off, wait, blue off wait, green off, wait, white off (all off at this point)
  if (flashBV == HIGH) {
    
    // Serial.println("Flash button pressed; party time");
    
     
    // Serial.println("Party time is over");

    // resetting the counters
      int redFlash = 3;         
      int yellowFlash = 3;
      int blueFlash =  3;
      int greenFlash = 3;
      int whiteFlash = 3; 
  }
  delay(200);        // delay in between reads for stability
}
