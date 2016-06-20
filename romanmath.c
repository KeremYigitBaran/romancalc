#include "romanmath.h"
#include <string.h>
#include <stdbool.h>


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
		repeatCountAllowed = 3;
		break;
	case 5:
	case 50:
	case 500:
		repeatCountAllowed = 1;
		break;
	case 1000:
		repeatCountAllowed = 4;
		break;
	default: 
		repeatCountAllowed = 0;
	}

	return repeatCountAllowed;
}

bool isAllowedSubtractiveForValue(possibleSubtractve, symbolValue)
{
	bool isAllowed = false;

	switch (symbolValue)
	{
	case 5:
	case 10:
		isAllowed = (possibleSubtractve == 1);
		break;
	case 50:
	case 100:
		isAllowed = (possibleSubtractve == 10);
		break;
	case 500:
	case 1000:
		isAllowed = (possibleSubtractve == 100);
		break;
	case 1:
	default:
		isAllowed = false;
	}

	return isAllowed;
}
int romanToInt( const char* Roman)
{
	int value = INVALID_ROMAN_NUMERAL;
	int previousSymbolValue = 0;
	int largestSymbolValue = 0;
	int repeatCount = 0;

	
	for (int index = strlen(Roman)-1; index >=0; --index)
	{
		int symbolValue = romanSymbolToInt(Roman[index]);
		if (symbolValue == INVALID_ROMAN_NUMERAL)
		{
			value = INVALID_ROMAN_NUMERAL;
			break;
		}

		if (symbolValue == previousSymbolValue)
		{
			++repeatCount;
			if (repeatCount > romanAllowedSymbolRepeat(symbolValue))
			{
				value = INVALID_ROMAN_NUMERAL;
				break;
			}
		}
		else
		{
			repeatCount = 1;
		}

		if (isAllowedSubtractiveForValue(symbolValue, previousSymbolValue))
		{
			value -= symbolValue;
		}
		else
		{
			if (symbolValue < largestSymbolValue)
			{
				value = INVALID_ROMAN_NUMERAL;
				break;
			}
			largestSymbolValue = symbolValue;
			value += symbolValue;
		}

		previousSymbolValue = symbolValue;
	}

	return value;
}

int romanSumInt(const char* AddendA, const char* AddendB)
{
	int addendA = romanToInt(AddendA);
	int addendB = romanToInt(AddendB);
	if (addendA == INVALID_ROMAN_NUMERAL || addendB == INVALID_ROMAN_NUMERAL)
	{
		return INVALID_ROMAN_NUMERAL;
	}
	return addendA + addendB;
}

char* intToRoman(int Value)
{
	if (1 == Value)
	{
		return strdup("I");
	}
	else
	{
		return strdup("II");
	}
}