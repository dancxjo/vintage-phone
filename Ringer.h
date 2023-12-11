#ifndef RINGER_H
#define RINGER_H

#include <Arduino.h>

enum class RingerState {
  OFF,
  RESTING,
  RINGING
};

class Ringer {
  public:
    virtual void begin() = 0;
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual void update() = 0;
    virtual void display(String msg) = 0;
};

#endif
