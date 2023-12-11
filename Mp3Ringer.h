#ifndef MP3RINGER_H
#define MP3RINGER_H

#import "Ringer.h"
#include "DFRobotDFPlayerMini.h"


class Mp3Ringer : public Ringer {
  public:
    Mp3Ringer();
    void begin() override;
    void activate() override;
    void deactivate() override;
    void update() override;
    void display(String msg) override;
  private:
    DFRobotDFPlayerMini dfp1;

};

#endif
