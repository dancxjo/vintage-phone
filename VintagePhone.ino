#include "Phone.h"

const int pulsePin = 14;
const int offNormalPin = 12;
const int hookPin = 13;
const int ringerPin = 2;
const int ringerClockPin = 23;

Phone phone = Phone(hookPin, pulsePin, offNormalPin, ringerPin);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("READY?");
  phone.begin();
  Serial.println("OKAY!");
}

void loop() {
  phone.update();
}
