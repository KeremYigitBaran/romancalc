#ifndef ROMAN_MATH_H
#define ROMAN_MATH_H

extern const int INVALID_ROMAN_NUMERAL;

int romanToInt(const char* Roman);
int romanSumInt(const char* Augend, const char* Addend);
char* romanSum(const char* Augend, const char* Addend);
char* intToRoman(int Value);
char* romanSubtract(const char* Menuend, const char* Subtrahend);

#endif
