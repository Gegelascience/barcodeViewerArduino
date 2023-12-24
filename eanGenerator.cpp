#include "eanGenerator.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Arduino.h>
#include <avr/pgmspace.h>



EanGenerator::EanGenerator(int screenWidth, int screenHeight) {
  screenDriver = Adafruit_SSD1306(screenWidth,screenHeight);
  
}

void EanGenerator::setupDisplay(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0) {
  screenDriver.begin(switchvcc, i2caddr);

}

void EanGenerator::showBarcode(String ean){
  String barcode = calculateBarcode(ean);

  screenDriver.clearDisplay();

  screenDriver.setTextSize(1);      // Normal 1:1 pixel scale
  screenDriver.setTextColor(SSD1306_WHITE); // Draw white text
  screenDriver.setCursor(0, 0);     // Start at top-left corner
  screenDriver.cp437(true);         // Use full 256 char 'Code Page 437' font

  for(int16_t i=0; i<ean.length(); i++) {
    screenDriver.write(ean[i]);
  }

  screenDriver.drawLine(0,20,0, 40, WHITE);

  for (unsigned int i=0;i<barcode.length();i++){
    if (int(barcode[i]) == '1') {
      screenDriver.drawLine(i,20,i, 40, WHITE);
    } else {
      screenDriver.drawLine(i,20,i, 40, BLACK);
    }
  }
  

  /*screenDriver.clearDisplay();
  screenDriver.setCursor(0, 20);
  for(int16_t j=0; j<barcode.length(); j++) {
    screenDriver.write(barcode[j]);
  }*/

  screenDriver.display();


  //

}


String EanGenerator::calculateBarcode(String ean) {
  String barcode = String("101");

  if(ean.length() == 13) {
    String firstPart = ean.substring(1,7);
    String secondPart = ean.substring(7);
    long prefix = ean.substring(0,1).toInt();
    

    for (unsigned int i=0;i<firstPart.length();i++){
      if( gettingSet(i,prefix) == 'A') {

        if (firstPart.substring(i,i+1) == "0") {
          barcode.concat(F("0001101"));
        } else if (firstPart.substring(i,i+1) == "1") {
          barcode.concat(F("0011001"));
        } else if (firstPart.substring(i,i+1) == "2") {
          barcode.concat(F("0010011"));
        } else if (firstPart.substring(i,i+1) == "3") {
          barcode.concat(F("0111101"));
        } else if (firstPart.substring(i,i+1) == "4") {
          barcode.concat(F("0100011"));
        } else if (firstPart.substring(i,i+1) == "5") {
          barcode.concat(F("0110001"));
        } else if (firstPart.substring(i,i+1) == "6") {
          barcode.concat(F("0101111"));
        } else if (firstPart.substring(i,i+1) == "7") {
          barcode.concat(F("0111011"));
        } else if (firstPart.substring(i,i+1) == "8") {
          barcode.concat(F("0110111"));
        } else if (firstPart.substring(i,i+1) == "9") {
          barcode.concat(F("0001011"));
        }



      } else {

        if (firstPart.substring(i,i+1) == "0") {
          barcode.concat(F("0100111"));
        } else if (firstPart.substring(i,i+1) == "1") {
          barcode.concat(F("0110011"));
        } else if (firstPart.substring(i,i+1) == "2") {
          barcode.concat(F("0011011"));
        } else if (firstPart.substring(i,i+1) == "3") {
          barcode.concat(F("0100001"));
        } else if (firstPart.substring(i,i+1) == "4") {
          barcode.concat(F("0011101"));
        } else if (firstPart.substring(i,i+1) == "5") {
          barcode.concat(F("0111001"));
        } else if (firstPart.substring(i,i+1) == "6") {
          barcode.concat(F("0000101"));
        } else if (firstPart.substring(i,i+1) == "7") {
          barcode.concat(F("0010001"));
        } else if (firstPart.substring(i,i+1) == "8") {
          barcode.concat(F("0001001"));
        } else if (firstPart.substring(i,i+1) == "9") {
          barcode.concat(F("0010111"));
        }

      }
      
    }

    barcode.concat("01010");

    for (unsigned int i=0;i<secondPart.length();i++){


      if (secondPart.substring(i,i+1) == "0") {
        barcode.concat(F("1110010"));
      } else if (secondPart.substring(i,i+1) == "1") {
        barcode.concat(F("1100110"));
      } else if (secondPart.substring(i,i+1) == "2") {
        barcode.concat(F("1101100"));
      } else if (secondPart.substring(i,i+1) == "3") {
        barcode.concat(F("1000010"));
      } else if (secondPart.substring(i,i+1) == "4") {
        barcode.concat(F("1011100"));
      } else if (secondPart.substring(i,i+1) == "5") {
        barcode.concat(F("1001110"));
      } else if (secondPart.substring(i,i+1) == "6") {
        barcode.concat(F("1010000"));
      } else if (secondPart.substring(i,i+1) == "7") {
        barcode.concat(F("1000100"));
      } else if (secondPart.substring(i,i+1) == "8") {
        barcode.concat(F("1001000"));
      } else if (secondPart.substring(i,i+1) == "9") {
        barcode.concat(F("1110100"));
      }

    }

    barcode.concat("101");


  } else {
    String firstPart = ean.substring(0,4);
    String secondPart = ean.substring(4);

    for (unsigned int i=0;i<firstPart.length();i++){
      if (firstPart.substring(i,i+1) == "0") {
          barcode.concat(F("0001101"));
        } else if (firstPart.substring(i,i+1) == "1") {
          barcode.concat(F("0011001"));
        } else if (firstPart.substring(i,i+1) == "2") {
          barcode.concat(F("0010011"));
        } else if (firstPart.substring(i,i+1) == "3") {
          barcode.concat(F("0111101"));
        } else if (firstPart.substring(i,i+1) == "4") {
          barcode.concat(F("0100011"));
        } else if (firstPart.substring(i,i+1) == "5") {
          barcode.concat(F("0110001"));
        } else if (firstPart.substring(i,i+1) == "6") {
          barcode.concat(F("0101111"));
        } else if (firstPart.substring(i,i+1) == "7") {
          barcode.concat(F("0111011"));
        } else if (firstPart.substring(i,i+1) == "8") {
          barcode.concat(F("0110111"));
        } else if (firstPart.substring(i,i+1) == "9") {
          barcode.concat(F("0001011"));
        }
    }


    barcode.concat("01010");

    for (unsigned int i=0;i<secondPart.length();i++){
      if (secondPart.substring(i,i+1) == "0") {
        barcode.concat(F("1110010"));
      } else if (secondPart.substring(i,i+1) == "1") {
        barcode.concat(F("1100110"));
      } else if (secondPart.substring(i,i+1) == "2") {
        barcode.concat(F("1101100"));
      } else if (secondPart.substring(i,i+1) == "3") {
        barcode.concat(F("1000010"));
      } else if (secondPart.substring(i,i+1) == "4") {
        barcode.concat(F("1011100"));
      } else if (secondPart.substring(i,i+1) == "5") {
        barcode.concat(F("1001110"));
      } else if (secondPart.substring(i,i+1) == "6") {
        barcode.concat(F("1010000"));
      } else if (secondPart.substring(i,i+1) == "7") {
        barcode.concat(F("1000100"));
      } else if (secondPart.substring(i,i+1) == "8") {
        barcode.concat(F("1001000"));
      } else if (secondPart.substring(i,i+1) == "9") {
        barcode.concat(F("1110100"));
      }
    }

    barcode.concat("101");

  }

  return barcode;

}

char gettingSet(unsigned int index,long prefix) {
  if (index == 0 || prefix == 0) {
    return 'A';
  } else if (prefix == 1){
    if (index == 1 || index == 3) {
      return 'A';
    } else {
      return 'B';
    }

  } else if (prefix == 2){
    if (index == 1 || index == 4) {
      return 'A';
    } else {
      return 'B';
    }

  } else if (prefix == 3){
    if (index == 1 || index == 5) {
      return 'A';
    } else {
      return 'B';
    }

  } else if (prefix == 4){
    if (index == 2 || index == 3) {
      return 'A';
    } else {
      return 'B';
    }

  } else if (prefix == 5){
    if (index == 4 || index == 3) {
      return 'A';
    } else {
      return 'B';
    }

  } else if (prefix == 6){
    if (index == 4 || index == 5) {
      return 'A';
    } else {
      return 'B';
    }

  } else if (prefix == 7){
    if (index == 4 || index == 2) {
      return 'A';
    } else {
      return 'B';
    }


  } else if (prefix == 8){
    if (index == 5 || index == 2) {
      return 'A';
    } else {
      return 'B';
    }

  } else {
    if (index == 5 || index == 3) {
      return 'A';
    } else {
      return 'B';
    }
  }


}