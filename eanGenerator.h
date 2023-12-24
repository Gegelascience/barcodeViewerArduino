#ifndef EANGENERATOR_H
#define EANGENERATOR_H

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


char gettingSet(unsigned int index,long prefix);

class EanGenerator {
  private:
  Adafruit_SSD1306 screenDriver;
  String calculateBarcode(String ean);

  public:
  EanGenerator(int screenWidth, int screenHeight);
  void setupDisplay(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0);
  void showBarcode(String ean);

};

#endif