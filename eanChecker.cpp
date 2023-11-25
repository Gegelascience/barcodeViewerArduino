#include "eanChecker.h"

#include <Arduino.h>
#include <ctype.h>

bool isCorrectEan(String possibleEan) {
  int eanLength = possibleEan.length();
  
  if(eanLength != 8 && eanLength != 13){
    return false;
  }

  for (unsigned int i=0;i<eanLength;i++) {
    if (!isdigit(possibleEan.charAt(i))){
      return false;
    }
  }
  String eanDigitCheckLess = possibleEan.substring(0,eanLength-1);

  char digitToCheck = calculateDigitCheck(eanDigitCheckLess);

 
  if (digitToCheck == possibleEan.charAt(eanLength-1)){
    return true;
  } else {
    return false;
  }  

}

char calculateDigitCheck(String eanDigitCheckLess) {
  int baseLength = eanDigitCheckLess.length();
  int factor = 3;
  unsigned int somme = 0;

  for (int i=baseLength-1;i>-1;i--) {
    somme += String(eanDigitCheckLess.charAt(i)).toInt() * factor;
    factor = 4 - factor;
  }

  return String((10 - (somme % 10))%10).charAt(0);

}
