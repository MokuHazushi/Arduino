/*
 * Lights up 8 LEDs (one at a time)
 */

#define SER 2
#define LATCH 3
#define SRCLK 4

byte leds;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(SRCLK, OUTPUT);
}

  void loop() {
  for (int i=0; i<8; i++) {
    leds = 0;
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }
}

void updateShiftRegister() {
  digitalWrite(LATCH, LOW);
  shiftOut(SER, SRCLK, LSBFIRST, leds);
  digitalWrite(LATCH, HIGH);
}
