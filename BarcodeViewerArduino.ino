#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include "eanGenerator.h"
#include "eanChecker.h"

#include "exempleWrapper.h"

#define OLED_WIDTH 128
#define OLED_HEIGHT 64

#define SWITCHCAPVCC 0x02
#define OLED_ADDR 0x3C

EanGenerator test = EanGenerator(OLED_WIDTH,OLED_HEIGHT);
//ExempleWrapper test = ExempleWrapper(OLED_WIDTH,OLED_HEIGHT);

void setup() {
  //Serial.begin(115200);
  Serial.begin(9600);
  test.setupDisplay(SWITCHCAPVCC, OLED_ADDR);
  
  //Serial.println(String(isCorrectEan(String("3666154117284"))).c_str());

  if (isCorrectEan(F("3666154117284"))) {
    test.showBarcode(F("3666154117284"));
    Serial.println(F("Success"));
  } else {
    Serial.println(F("Bad EAN"));
  }
  
  
  //test.setExemple();
  

}

void loop() {
  

  
  //Serial.println("Success");

}