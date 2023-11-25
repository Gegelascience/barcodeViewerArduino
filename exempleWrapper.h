#ifndef EXEMPLEWRAPPER_H
#define EXEMPLEWRAPPER_H

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

class ExempleWrapper {
  private:
  Adafruit_SSD1306 screenDriver;

  public:
  ExempleWrapper(int screenWidth, int screenHeight);
  void setupDisplay(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0);
  void setExemple();

};

#endif