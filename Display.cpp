#include "Display.h"

Display::Display(int clockPin, int dataPin) : tm(clockPin, dataPin) {}

void Display::begin() {
  tm.begin();
  tm.setBrightness(4);
  tm.clearScreen();
}

void Display::activate() {
  display("RING");
}

void Display::deactivate() {
}

void Display::update() {
  if (!(millis() % 2000)) {
    tm.clearScreen();
  }
}

void Display::display(String msg) {
  tm.display(msg);
}
