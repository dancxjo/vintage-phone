#include "Magnet.h"

Magnet::Magnet(int pin) : pin(pin), activated(false) {}

void Magnet::begin() {
  pinMode(pin, OUTPUT);
  deactivate(); 
}

void Magnet::activate() {
  digitalWrite(pin, HIGH);
  Serial.println("MAGNET ON");
}

void Magnet::deactivate() {
  digitalWrite(pin, LOW);
  Serial.println("MAGNET OFF");
}

void Magnet::pulse(int onInterval, int offInterval) {
  activate();
  delay(onInterval);
  deactivate();
  delay(offInterval);
}
