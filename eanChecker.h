#ifndef EANCHECKER_H
#define EANCHECKER_H

#include <Arduino.h>

bool isCorrectEan(String possibleEan);

char calculateDigitCheck(String eanDigitCheckLess);

#endif