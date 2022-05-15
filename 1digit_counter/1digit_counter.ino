/* 1 Digit counter
 *  Show numbers from 0 to 9 on a sevent segments display,
 *  numbers increase every time the button is pushed
 */

#define LED_A 2
#define LED_B 3
#define LED_C 4
#define LED_D 5
#define LED_E 6
#define LED_F 7
#define LED_G 8

#define BUTTON 9

int LEDS[7] = {LED_A,LED_B,LED_C,LED_D,LED_E,LED_F,LED_G};
int num = 9;
int buttonState = 1;
bool buttonStateChanged = false;

bool numberMap[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {0,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1} // 9
};

void setup() {
  Serial.begin(9600);
  for (int i=0; i<7; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  
  if (mySwitch()) {
    num = (num+1) % 10;
    drawNum(num);
  }
}

bool mySwitch() {
  Serial.println(num);
  buttonState = digitalRead(BUTTON);
  if (buttonState == LOW) {
    buttonStateChanged = true;
  }

  if (buttonState == HIGH && buttonStateChanged) {
    buttonStateChanged = false;
    return true;
  }
  return false; 
}

void drawNum(int num) {
  for (int i=0; i<7; i++) {
    if (numberMap[num][i] == 1) {
      digitalWrite(LEDS[i], HIGH);
    }
    else {
      digitalWrite(LEDS[i], LOW);
    }
  }
}
