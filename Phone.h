#ifndef PHONE_H
#define PHONE_H

#include <Bounce2.h>
#include "Dial.h"
#include "Ringer.h"

class Phone
{
  public:
    Phone(int hookPin, int pulsePin, int offNormalPin, int ringerPin);
    void begin();
    void update();
    bool isOnHook();
    void report(String msg);
    void receiveDigit(int digit);

  private:
    const int hookPin;
    const int pulsePin;
    const int offNormalPin;

    Bounce2::Button hook;
    Dial dial;
    Ringer* ringer;

    void handleInput();
    bool handleEvent(String command);

    bool wasHungUp();
    bool wasPickedUp();

    void reset();
};

#endif // PHONE_H
