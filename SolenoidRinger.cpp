#include <Arduino.h>
#include "SolenoidRinger.h"

SolenoidRinger::SolenoidRinger(int pin) : magnet(pin), isActivated(false) {}
SolenoidRinger::~SolenoidRinger() {
  magnet.deactivate();
}

void SolenoidRinger::begin() {
  magnet.begin();
  isActivated = false;
}

void SolenoidRinger::activate() {
  isActivated = true;
  isPulsing = true;
  lastCycleStarted = millis();
  Serial.println("RINGING");
}

void SolenoidRinger::deactivate() {
  isActivated = false;
  isPulsing = false;
  Serial.println("STOPPED");
}

void SolenoidRinger::update() {
  if (isActivated) {
    if (isPulsing) {
      magnet.pulse(24, 24);
    }

    auto timeSinceBeginning = millis() - lastCycleStarted;
    bool isReadyToSwitch = timeSinceBeginning > (isActivated ? 2000 : 4000);

    if (isReadyToSwitch) {
      isPulsing = !isPulsing;
      lastCycleStarted = millis();
    }
  }
}

void SolenoidRinger::display(String msg) {
}
