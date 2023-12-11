#include <Arduino.h>
#include "Dial.h"
#include "Phone.h"
#include "Mp3Ringer.h"
#include "SolenoidRinger.h"
#include "Display.h"

Phone::Phone(int hookPin, int pulsePin, int offNormalPin, int ringerPin) : hookPin(hookPin),
  pulsePin(pulsePin),
  offNormalPin(offNormalPin),
  hook(),
  ringer(new Display(21, 23)),
  dial(pulsePin, offNormalPin, &Phone::receiveDigit, this)
{
}

void Phone::begin()
{
  hook.attach(hookPin, INPUT_PULLUP);
  hook.interval(5);
  hook.setPressedState(LOW);

  dial.begin();
  ringer->begin();

}

void Phone::reset() {
  while (true);
}

bool Phone::handleEvent(String command) {
  Serial.println(command);

  if (command == "INCOMING") {
    if (!isOnHook()) {
      report("BUSY");
    } else {
      ringer->activate();
    }
    return true;
  } else if (command == "ENDED") {
    ringer->deactivate();
    report("STOP");
    return true;
  } else if (command == "HALT") {
    report("HALT");
    while (true);
    return true;
  }
  return false;
}


void Phone::handleInput() {
  if (Serial.available()) {
    String command = Serial.readString();
    command.toUpperCase();
    command.trim();
    bool handled = handleEvent(command);
    if (!handled) {
      report("ERR ");
    }
  }
}

bool Phone::wasHungUp() {
  return hook.rose();
}

bool Phone::wasPickedUp() {
  return hook.fell();
}

void Phone::update()
{
  handleInput();
  hook.update();

  if (wasHungUp()) {
    report("ONHK");
    dial.clear();
  }

  if (wasPickedUp()) {
    report("OFFH");
    ringer->deactivate();
  }

  if (!isOnHook()) {
    dial.update();
  }

  ringer->update();
}

bool Phone::isOnHook()
{
  bool pressed = hook.read();
  return pressed;
}

void Phone::report(String msg) {
  Serial.println(msg);
  ringer->display(msg);
}

void Phone::receiveDigit(int digit) {
  String msg = "DGT";
  msg += digit;
  report(msg);
}
