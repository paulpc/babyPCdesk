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
  const int redButtonPin = 1;     // the number of the pushbutton pin
  const int yellowButtonPin = 2;     // the number of the pushbutton pin
  const int blueButtonPin = 3;     // the number of the pushbutton pin
  const int greenButtonPin = 4;     // the number of the pushbutton pin
  const int whiteButtonPin = 5;     // the number of the pushbutton pin
  const int flashButtonPin = 7;     // the number of the pushbutton pin
  
  
  int redState = 0;         // variable for reading the pushbutton status
  int yellowState = 0;         // variable for reading the pushbutton status
  int blueState = 0;         // variable for reading the pushbutton status
  int greenState = 0;         // variable for reading the pushbutton status
  int whiteState = 0;         // variable for reading the pushbutton status
  
  // the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(redButtonPin, INPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(redButtonPin, INPUT);
  pinMode(whiteButtonPin, INPUT);
  pinMode(flashButtonPin, INPUT);
  // flash all lights once
  analogWrite(analogOutRed, 255);
  analogWrite(analogOutYellow, 255);
  analogWrite(analogOutBlue, 255);
  analogWrite(analogOutGreen, 255);
  analogWrite(analogOutWhite, 255);
  delay(1000);
  analogWrite(analogOutRed, 0);
  analogWrite(analogOutYellow, 0);
  analogWrite(analogOutBlue, 0);
  analogWrite(analogOutGreen, 0);
  analogWrite(analogOutWhite, 0);
}
// the loop routine runs over and over again forever:
int sensorValue = 0;

void loop() {

  // red lights
  
  int redBV = digitalRead(redButtonPin);

  if (redBV == HIGH) {
    if (redState == LOW) {
      Serial.println("red button pressed - ON");
      redState = HIGH;
      analogWrite(analogOutRed, 255);
  }
  else {
    Serial.println("red button pressed - OFF");
    analogWrite(analogOutRed, 0);
    redState = LOW;
  }
  }

  // yellow lights
  int yellowBV = digitalRead(yellowButtonPin);
  
    if (yellowBV == HIGH) {
      if (yellowState == LOW) {
        Serial.println("yellow button pressed - ON");
        yellowState = HIGH;
        analogWrite(analogOutYellow, 255);
      } 
      else {
        Serial.println("yellow button pressed - OFF");
        analogWrite(analogOutYellow, 0);
        yellowState = LOW;
      }
    }

  // blue lights
  int blueBV = digitalRead(blueButtonPin);
  
    if (blueBV == HIGH) {
      if (blueState == LOW) {
        Serial.println("blue button pressed - ON");
        blueState = HIGH;
        analogWrite(analogOutBlue, 255);
      } 
      else {
        Serial.println("blue button pressed - OFF");
        analogWrite(analogOutBlue, 0);
        blueState = LOW;
      }
    }

    // white lights
    int whiteBV = digitalRead(whiteButtonPin);
    
      if (whiteBV == HIGH) {
        if (whiteState == LOW) {
          Serial.println("white button pressed - ON");
          whiteState = HIGH;
          analogWrite(analogOutWhite, 255);
        } 
        else {
          Serial.println("white button pressed - OFF");
          analogWrite(analogOutWhite, 0);
          whiteState = LOW;
        }
      }

    // green lights
    int greenBV = digitalRead(greenButtonPin);
  
    if (greenBV == HIGH) {
      if (greenState == LOW) {
        Serial.println("green button pressed - ON");
        greenState = HIGH;
        analogWrite(analogOutGreen, 255);
      } 
      else {
        Serial.println("green button pressed - OFF");
        analogWrite(analogOutGreen, 0);
        greenState = LOW;
      }
    }

  // flashing pattern: red on + off, yellow on + off, blue on + off , green on + off, white on + off 
  // red on, wait, yellow on, wait, blue on, wait, green on, wait, white on, wait (all on at this point)
  // all flash x 3
  // red off, wait, yellow off, wait, blue off wait, green off, wait, white off (all off at this point)
  int flashBV = digitalRead(flashButtonPin);
  if (flashBV == HIGH) {
    analogWrite(analogOutRed, 255);
    delay(500);
    analogWrite(analogOutYellow, 255);
    delay(500);
    analogWrite(analogOutBlue, 255);
    delay(500);
    analogWrite(analogOutGreen, 255);
    delay(500);
    analogWrite(analogOutWhite, 255);
    delay(500);
    //all flash x 3
    analogWrite(analogOutRed, 0);
    analogWrite(analogOutYellow, 0);
    analogWrite(analogOutBlue, 0);
    analogWrite(analogOutGreen, 0);
    analogWrite(analogOutWhite, 0);
    delay(1000);
    analogWrite(analogOutRed, 255);
    analogWrite(analogOutYellow, 255);
    analogWrite(analogOutBlue, 255);
    analogWrite(analogOutGreen, 255);
    analogWrite(analogOutWhite, 255);
    delay(500);
    analogWrite(analogOutRed, 0);
    analogWrite(analogOutYellow, 0);
    analogWrite(analogOutBlue, 0);
    analogWrite(analogOutGreen, 0);
    analogWrite(analogOutWhite, 0);
    delay(1000);
    analogWrite(analogOutRed, 255);
    analogWrite(analogOutYellow, 255);
    analogWrite(analogOutBlue, 255);
    analogWrite(analogOutGreen, 255);
    analogWrite(analogOutWhite, 255);
    delay(500); 
    analogWrite(analogOutRed, 0);
    analogWrite(analogOutYellow, 0);
    analogWrite(analogOutBlue, 0);
    analogWrite(analogOutGreen, 0);
    analogWrite(analogOutWhite, 0);
    delay(1000);
    analogWrite(analogOutRed, 255);
    analogWrite(analogOutYellow, 255);
    analogWrite(analogOutBlue, 255);
    analogWrite(analogOutGreen, 255);
    analogWrite(analogOutWhite, 255);
    delay(500);
    // now turn them back off
    analogWrite(analogOutRed, 0);
    delay(500);
    analogWrite(analogOutYellow, 0);
    delay(500);
    analogWrite(analogOutBlue, 0);
    delay(500);
    analogWrite(analogOutGreen, 0);
    delay(500);
    analogWrite(analogOutWhite, 0);
    delay(500);
  }
  delay(1);        // delay in between reads for stability
}
