#include "Mp3Ringer.h"

Mp3Ringer::Mp3Ringer() {}

void Mp3Ringer::begin() {
  Serial1.begin(9600);
  dfp1.begin(Serial1, true, true);
  dfp1.volume(24);
}

void Mp3Ringer::activate() {
  dfp1.play(1);
}

void Mp3Ringer::deactivate() {
  dfp1.stop();
}

void Mp3Ringer::display(String msg) {
}

void Mp3Ringer::update() {
}
