#include "eanGenerator.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Arduino.h>

char *setA[] = {
  "0001101",
  "0011001",
  "0010011",
  "0111101",
  "0100011",
  "0110001",
  "0101111",
  "0111011",
  "0110111",
  "0001011"
};

char *setB[] = {
  "0100111",
  "0110011",
  "0011011",
  "0100001",
  "0011101",
  "0111001",
  "0000101",
  "0010001",
  "0001001",
  "0010111"
};

char *setC[] = {
  "1110010",
  "1100110",
  "1101100",
  "1000010",
  "1011100",
  "1001110",
  "1010000",
  "1000100",
  "1001000",
  "1110100"
};


EanGenerator::EanGenerator(int screenWidth, int screenHeight) {
  screenDriver = Adafruit_SSD1306(screenWidth,screenHeight);
  
}

void EanGenerator::setupDisplay(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0) {
  screenDriver.begin(switchvcc, i2caddr);

  Serial.println("tada");

  /*screenDriver.clearDisplay();
  screenDriver.drawLine(0,0,90, 30, WHITE);
  screenDriver.display();
  delay(2000);*/

  Serial.println("truc");
}

void EanGenerator::showBarcode(char ean[]){
  String eanStr = String(ean);
  String barcode = calculateBarcode(eanStr);

  Serial.println("show");
  //Serial.println(barcode);

  screenDriver.clearDisplay();

  /*for (unsigned int i=0;i<barcode.length();i++){
    Serial.println("coucou");
    if (int(barcode[i]) == 1) {
      screenDriver.drawLine(i,15,i, 40, WHITE);
    } else {
      screenDriver.drawLine(i,15,i, 40, BLACK);
    }
  }*/

  screenDriver.setTextSize(1);      // Normal 1:1 pixel scale
  screenDriver.setTextColor(SSD1306_WHITE); // Draw white text
  screenDriver.setCursor(0, 0);     // Start at top-left corner
  screenDriver.cp437(true);         // Use full 256 char 'Code Page 437' font

  for(int16_t i=0; i<eanStr.length(); i++) {
    screenDriver.write(eanStr[i]);
  }

  /*screenDriver.setCursor(0, 50);
  for(int16_t j=0; j<barcode.length(); j++) {
    Serial.println(barcode[j]);
    screenDriver.write(barcode[j]);
  }*/


  screenDriver.display();


  //delay(2000);

}

String EanGenerator::barcodeString(char ean[]) {
  String eanStr = String(ean);
  return calculateBarcode(eanStr);
}

String EanGenerator::calculateBarcode(String ean) {
  String barcode = String("101");
  unsigned int lenEan = ean.length();

  if(lenEan == 13) {
    String firstPart = ean.substring(1,7);
    String secondPart = ean.substring(7);
    long prefix = ean.substring(0,1).toInt();

    for (unsigned int i=0;i<firstPart.length();i++){
      unsigned int indexSet = firstPart.substring(i,i+1).toInt();
      char setToApply = gettingSet(i,prefix);
      if( setToApply == 'A') {
        barcode.concat(setA[indexSet]);
      } else {
        barcode.concat(setB[indexSet]);
      }
      
    }

    barcode.concat("01010");

    for (unsigned int i=0;i<secondPart.length();i++){
      unsigned int indexSet = secondPart.substring(i,i+1).toInt();
      barcode.concat(setC[indexSet]);
    }

    barcode.concat("101");


  } else {
    String firstPart = ean.substring(0,4);
    String secondPart = ean.substring(4);

    for (unsigned int i=0;i<firstPart.length();i++){
      unsigned int indexSet = firstPart.substring(i,i+1).toInt();
      barcode.concat(setA[indexSet]);
    }


    barcode.concat("01010");

    for (unsigned int i=0;i<secondPart.length();i++){
      unsigned int indexSet = secondPart.substring(i,i+1).toInt();
      barcode.concat(setC[indexSet]);
    }

    barcode.concat("101");

  }
  Serial.println(barcode);

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