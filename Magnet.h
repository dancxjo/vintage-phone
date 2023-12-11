#ifndef MAGNET_H
#define MAGNET_H

#include <Arduino.h>

class Magnet {
  public:
    Magnet(int pin);
    void begin();
    void activate();
    void deactivate();
    void pulse(int onInterval, int offInterval);
  private:
    const int pin;
    bool activated;
    int onInterval;
    int offInterval;
};

#endif
