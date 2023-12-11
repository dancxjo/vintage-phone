#include "Dial.h"
#include "Ringer.h"

Dial::Dial(int pulsePin, int offNormalPin, Callback receiveDigit, Phone *phone)
  : pulsePin(pulsePin), offNormalPin(offNormalPin), onEmit(receiveDigit), phone(phone) {
}

void Dial::begin()
{
  pulse.attach(pulsePin, INPUT_PULLUP);
  pulse.interval(5);
  pulse.setPressedState(HIGH);

  offNormal.attach(offNormalPin, INPUT_PULLUP);
  offNormal.interval(5);
  offNormal.setPressedState(LOW);
}

void Dial::update()
{
  pulse.update();
  offNormal.update();

  if (offNormal.fell())
  {
    pulseCount = 0;
  } else if (offNormal.rose()) {
    emitDigit();
  } else if (pulse.rose())
  {
    pulseCount++;
  }
}

void Dial::clear() {
  number = "";
}

void Dial::emitDigit() {
  int digit = (pulseCount) % 10;
  pulseCount = 0;

  if (phone) {
    (phone->*onEmit)(digit);
  }
  number = number + digit;
  if (number.length() == 10) {
    emitNumber();
  }
}

void Dial::emitNumber() {
  Serial.println(number);
  clear();
}
