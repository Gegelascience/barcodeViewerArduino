#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <AUnit.h>

#include "eanGenerator.h"
#include "eanChecker.h"


#define OLED_WIDTH 128
#define OLED_HEIGHT 64

#define SWITCHCAPVCC 0x02
#define OLED_ADDR 0x3C


// switch between production and test mode
#define UNIT_TEST_MODE 1

// aunit consume too much sRAM on arduino uno R3 
#if UNIT_TEST_MODE
test(correct) {
  assertEqual(isCorrectEan(F("3666154117284")), true);
}
#endif

const EanGenerator generator = EanGenerator(OLED_WIDTH,OLED_HEIGHT);

void setup() {

  #if ! defined(EPOXY_DUINO)
    delay(1000); // wait for stability on some boards to prevent garbage Serial
  #endif

  //Serial.begin(115200);
  Serial.begin(9600);
  
  generator.setupDisplay(SWITCHCAPVCC, OLED_ADDR);
  
  #if !UNIT_TEST_MODE
      if (isCorrectEan(F("3666154117284"))) {
        generator.showBarcode(F("3666154117284"));
        Serial.println(F("Success"));
      } else {
        Serial.println(F("Bad EAN"));
      }
  #endif
  

}

void loop() {
  
  #if UNIT_TEST_MODE
    aunit::TestRunner::run();
  #endif
  

}