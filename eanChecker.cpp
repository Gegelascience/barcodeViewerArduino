#include "eanChecker.h"

#include <Arduino.h>
#include <ctype.h>

bool isCorrectEan(String possibleEan) {
  
  if(possibleEan.length() != 8 && possibleEan.length() != 13){
    return false;
  }

  for (unsigned int i=0;i<possibleEan.length();i++) {
    if (!isdigit(possibleEan.charAt(i))){
      return false;
    }
  }

  
  String eanDigitCheckLess = possibleEan.substring(0,possibleEan.length()-1);

  int factor = 3;
  unsigned int somme = 0;


  for (int i=eanDigitCheckLess.length()-1;i>-1;i--) {
    somme += String(eanDigitCheckLess.charAt(i)).toInt() * factor;
    factor = 4 - factor;
  }


  char digitToCheck = String((10 - (somme % 10))%10).charAt(0);




  if (digitToCheck == possibleEan.charAt(possibleEan.length()-1)){
    return true;
  } else {
    return false;
  }  

}

char calculateDigitCheck(String eanDigitCheckLess) {
  
  int factor = 3;
  unsigned int somme = 0;


  for (int i=eanDigitCheckLess.length()-1;i>-1;i--) {
    somme += String(eanDigitCheckLess.charAt(i)).toInt() * factor;
    factor = 4 - factor;
  }

  return String((10 - (somme % 10))%10).charAt(0);

}
