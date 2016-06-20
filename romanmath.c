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
	default:
		value = 0;
		break;
	};

	return value;
}

int romanToInt( const char* Roman)
{
	int value = 0;
	int previousSymbolValue = 0;

	for (int index = strlen(Roman)-1; index >=0; --index)
	{
		int symbolValue = romanSymbolToInt(Roman[index]);
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
