#include "romanmath.h"
#include <string.h>

int romanSymbolToInt( const char RomanSymbol )
{
	int value = 0;

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
		value = 0;
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
		repeatCountAllowed = 2;
		break;
	case 1000:
		repeatCountAllowed = 4;
		break;
	default: 
		repeatCountAllowed = 0;
	}

	return repeatCountAllowed;
}

int romanToInt( const char* Roman)
{
	int value = 0;
	int previousSymbolValue = 0;
	int repeatCount = 0;

	for (int index = strlen(Roman)-1; index >=0; --index)
	{
		int symbolValue = romanSymbolToInt(Roman[index]);
		if (symbolValue == 0)
		{
			value = 0;
			break;
		}
		
		if (symbolValue == previousSymbolValue)
		{
			++repeatCount;
			if (repeatCount > romanAllowedSymbolRepeat(symbolValue))
			{
				value = 0;
				break;
			}
		}
		else
		{
			repeatCount = 1;
		}

		if (symbolValue < previousSymbolValue)
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
