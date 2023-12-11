#ifndef DIAL_H
#define DIAL_H

#include <Bounce2.h>
#include "Ringer.h"

class Phone;
typedef void (Phone::*Callback)(int digit);

class Dial {
  public:
    Dial(int pulsePin, int offNormalPin, Callback receiveDigit, Phone *phone);
    void begin();
    void update();
    void clear();

  private:
    String number = "";

    const int pulsePin;
    const int offNormalPin;
    Ringer *ringer;
    Callback onEmit;
    Phone *phone;

    unsigned short pulseCount = 0;

    Bounce2::Button pulse;
    Bounce2::Button offNormal;

    void emitDigit();
    void emitNumber();
};


#endif // DIAL_H 
