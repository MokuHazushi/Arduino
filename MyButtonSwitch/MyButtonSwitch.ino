/*
 * Button switch
 * Press the button to switch the state of a LED (off->on->off)
 * 
 * Circuit:
 * +5V --------------------------------->
 *                     |
 *                     |   |
 *                     Button                   
 *      LED-------     |   |
 *       |       |         |
 *     220ohm    |   |---10Kohm
 *       |       |   |     |
 *      13       |   |     2
 *       |      GROUND     |
 * --------------------------------------
 * |                                    |
 * |         ARDUINO UNO R3             |
 */

 const int buttonPin = 2;
 const int ledPin = 13;

 int buttonState = 0;
 bool ledOn = false;
 bool buttonStateChanged = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    buttonStateChanged = true;
  }

  if (buttonState == LOW && buttonStateChanged) {
    ledOn = !ledOn;
    buttonStateChanged = false;
  }

  if (ledOn) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
