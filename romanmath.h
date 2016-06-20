#ifndef ROMAN_MATH_H
#define ROMAN_MATH_H

extern const int INVALID_ROMAN_NUMERAL;

int romanToInt(const char* Roman);
int romanSumInt(const char* AddendA, const char* AddendB);
char* romanSum(const char* AddendA, const char* AddendB);
char* intToRoman(int Value);

#endif
