#ifndef SEGMENTRINGER_H
#define SEGMENTRINGER_H

#import "Ringer.h"
#include <TM1637.h>


class Display : public Ringer {
  public:
    Display(int clockPin, int dataPin);
    void begin() override;
    void activate() override;
    void deactivate() override;
    void update() override;
    void display(String msg) override;
  private:
    TM1637 tm;
};

#endif
