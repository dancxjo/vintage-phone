#ifndef SOLENOIDRINGER_H
#define SOLENOIDRINGER_H

#import "Ringer.h"
#import "Magnet.h"

class SolenoidRinger : public Ringer {
  public:
    SolenoidRinger(int pin);
    ~SolenoidRinger();
    void begin() override;
    void activate() override;
    void deactivate() override;
    void update() override;
    void display(String msg) override;

  private:
    Magnet magnet; 
    bool isActivated;
    bool isPulsing;
    unsigned long lastCycleStarted;
};

#endif
