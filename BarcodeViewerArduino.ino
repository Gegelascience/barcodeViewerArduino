#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include "exempleWrapper.h"

#define OLED_WIDTH 128
#define OLED_HEIGHT 64

#define SWITCHCAPVCC 0x02
#define OLED_ADDR 0x3C

ExempleWrapper test = ExempleWrapper(OLED_WIDTH,OLED_HEIGHT);

void setup() {
  test.setupDisplay(SWITCHCAPVCC, OLED_ADDR);
}

void loop() {

  test.setExemple();

}