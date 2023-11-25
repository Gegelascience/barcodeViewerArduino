#include "exempleWrapper.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Arduino.h>



ExempleWrapper::ExempleWrapper(int screenWidth, int screenHeight) {
  screenDriver = Adafruit_SSD1306(screenWidth,screenHeight);
  
}

void ExempleWrapper::setupDisplay(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0) {
  screenDriver.begin(switchvcc, i2caddr);
}

void ExempleWrapper::setExemple(){
  screenDriver.clearDisplay();
  screenDriver.drawLine(0,0,90, 30, WHITE);
  screenDriver.display();
  delay(2000);

  screenDriver.clearDisplay();
  screenDriver.drawRect(1, 1, screenDriver.width() - 2, screenDriver.height() - 2, WHITE);
  screenDriver.display();
  delay(2000);

  screenDriver.clearDisplay();
  screenDriver.drawCircle(63, 31, 20, WHITE);
  screenDriver.display();
  delay(2000);

  screenDriver.clearDisplay();
  screenDriver.drawTriangle(63, 0, 0, 63, 127, 63, WHITE);
  screenDriver.display();
  delay(2000);

  screenDriver.clearDisplay();
  screenDriver.drawRect(1, 1, screenDriver.width() - 2, screenDriver.height() - 2, WHITE);
  screenDriver.display();
  delay(2000);
  screenDriver.fillRect(10, 10, 107, 44, WHITE);
  screenDriver.display();
  delay(2000);
  screenDriver.drawRect(20, 20, 87, 24, BLACK);
  screenDriver.display();
  delay(2000);
}