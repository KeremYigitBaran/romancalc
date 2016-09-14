#include "romanmath.h"
#include <string.h>
#include <stdbool.h>

char *strdup(const char *s);

const int INVALID_ROMAN_NUMERAL = 0;

int romanSymbolToInt( const char RomanSymbol )
{
	int value = INVALID_ROMAN_NUMERAL;

	switch (RomanSymbol)
	{
	case 'I':
		value = 1;
		break;
	case 'V':
		value = 5;
		break;
	case 'X':
		value = 10;
		break;
	case 'L':
		value = 50;
		break;
	case 'C':
		value = 100;
		break;
	case 'D':
		value = 500;
		break;
	case 'M':
		value = 1000;
		break;
	default:
		value = INVALID_ROMAN_NUMERAL;
		break;
	};

	return value;
}

int romanAllowedSymbolRepeat(int value)
{
	int repeatCountAllowed = 0;
	switch(value)
	{
	case 1:
	case 10:
	case 100:
	case 1000:
		repeatCountAllowed = 3;
		break;
	case 5:
	case 50:
	case 500:
		repeatCountAllowed = 1;
		break;
	default: 
		repeatCountAllowed = 0;
	}

	return repeatCountAllowed;
}

bool isCurrentSymbolASubtractiveForThePreviousSymbol(int possibleSubtractve, int symbolValue)
{
	bool isASubtractiveValue = false;

	switch (symbolValue)
	{
	case 5:
	case 10:
		isASubtractiveValue = (possibleSubtractve == 1);
		break;
	case 50:
	case 100:
		isASubtractiveValue = (possibleSubtractve == 10);
		break;
	case 500:
	case 1000:
		isASubtractiveValue = (possibleSubtractve == 100);
		break;
	case 1:
	default:
		isASubtractiveValue = false;
	}

	return isASubtractiveValue;
}

static bool subtractivePreventsMoreUseOfBaseValue(int baseValue)
{
	bool isPrevented = true;

	switch (baseValue)
	{
	case 10:
	case 100:
	case 1000:
		isPrevented = false;
		break;
	case 1:
	case 5:
	case 50:
	case 500:
	default:
		isPrevented = true;
	}

	return isPrevented;
}


static int updateRepeatCount(int repeatCount, int symbolValue, int previousSymbolValue)
{
	if (symbolValue == previousSymbolValue)
	{
		++repeatCount;
	}
	else
	{
		repeatCount = 1;
	}

	return repeatCount;
}

bool isValidRomanNumber(const char* Roman)
{
	if (!Roman)
	{
		return false;
	}

	bool isValid = true;

	int previousSymbolValue = 0;
	int largestSymbolValue = 0;
	int repeatCount = 0;
	
	int index = 0;
	int RomanLength = strlen(Roman);
	for (index = RomanLength-1; index >= 0; --index)
	{
		int symbolValue = romanSymbolToInt(Roman[index]);
		if (symbolValue == INVALID_ROMAN_NUMERAL)
		{
			isValid = false;
			break;
		}

		repeatCount = updateRepeatCount(repeatCount, symbolValue, previousSymbolValue);
		if (repeatCount > romanAllowedSymbolRepeat(symbolValue))
		{
			isValid = false;
			break;
		}
	
		
		if (isCurrentSymbolASubtractiveForThePreviousSymbol(symbolValue, previousSymbolValue))
		{
			if( subtractivePreventsMoreUseOfBaseValue(previousSymbolValue))
			{
				largestSymbolValue = previousSymbolValue + 1;	
			}
		}
		else
		{
			if (symbolValue < largestSymbolValue)
			{
				isValid = false;
				break;
			}
			largestSymbolValue = symbolValue;
		}

		previousSymbolValue = symbolValue;
	}

	return isValid;
}

int romanToInt( const char* Roman)
{
	if (!isValidRomanNumber(Roman))
	{
		return INVALID_ROMAN_NUMERAL;
	}

	int value = INVALID_ROMAN_NUMERAL;
	int previousSymbolValue = 0;
	
	int index = 0;
	for (index = strlen(Roman)-1; index >=0; --index)
	{
		int symbolValue = romanSymbolToInt(Roman[index]);

		if (isCurrentSymbolASubtractiveForThePreviousSymbol(symbolValue, previousSymbolValue))
		{
			value -= symbolValue;
		}
		else
		{
			value += symbolValue;
		}

		previousSymbolValue = symbolValue;
	}

	return value;
}

int romanSumInt(const char* Augend, const char* Addend)
{
	int augend = romanToInt(Augend);
	int addend = romanToInt(Addend);
	if (INVALID_ROMAN_NUMERAL == augend || INVALID_ROMAN_NUMERAL == addend)
	{
		return INVALID_ROMAN_NUMERAL;
	}
	return augend + addend;
}

char* romanSum(const char* Augend, const char* Addend)
{
	int sum = romanSumInt(Augend, Addend);
	if (INVALID_ROMAN_NUMERAL == sum)
	{
		return 0;
	}

	return intToRoman(sum);
}

int romanSubtractInt(const char* Menuend, const char* Subtrahend)
{
	int menuend = romanToInt(Menuend);
	int subtrahend = romanToInt(Subtrahend);
	if (INVALID_ROMAN_NUMERAL == menuend || INVALID_ROMAN_NUMERAL == subtrahend || subtrahend > menuend)
	{
		return INVALID_ROMAN_NUMERAL;
	}

	return menuend - subtrahend;
}

char* romanSubtract(const char* Menuend, const char* Subtrahend)
{
	int difference = romanSubtractInt(Menuend, Subtrahend);
	if (INVALID_ROMAN_NUMERAL == difference)
	{
		return 0;
	}

	return intToRoman(difference);
}

char* intToRoman(int Value)
{
	if (Value >= 4000)
	{
		return 0;
	}

	char romanNumeral[64];
	memset(romanNumeral, 0, 64);

	int symbolValues[] =             {1000, 900,  500, 400,  100, 90,   50,  40,   10,   9,    5,   4,    1};
	const char* symbolsForValues[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int symbolValueCount = sizeof(symbolValues) / sizeof(symbolValues[0]);

	int index = 0;
	for (index = 0; index < symbolValueCount; ++index)
	{
		for (;Value >= symbolValues[index]; Value -= symbolValues[index])
		{
			strcat(romanNumeral, symbolsForValues[index]);
		}
	}

	return strdup(romanNumeral);
}

