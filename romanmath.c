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
	if (strcmp(Roman, "I") == 0)
	{
		return romanSymbolToInt('I');
	}
	else if (strcmp(Roman, "II") == 0)
	{
		return romanSymbolToInt('I') + romanSymbolToInt('I');
	}
	else if (strcmp(Roman, "III") == 0)
	{
		return romanSymbolToInt('I') + romanSymbolToInt('I') + romanSymbolToInt('I');
	}
	else if (strcmp(Roman, "IV") == 0)
	{
		return romanSymbolToInt('V') - romanSymbolToInt('I');
	}
	else if (strcmp(Roman, "V") == 0)
	{
		return romanSymbolToInt('V');
	}
	else if (strcmp(Roman, "VI") == 0)
	{
		return romanSymbolToInt('V') + romanSymbolToInt('I');
	}
	else if (strcmp(Roman, "VII") == 0)
	{
		return romanSymbolToInt('V') + romanSymbolToInt('I') + romanSymbolToInt('I');
	}
	else if (strcmp(Roman, "VIII") == 0)
	{
		return romanSymbolToInt('V') + romanSymbolToInt('I') + romanSymbolToInt('I') + romanSymbolToInt('I');
	}
	else if (strcmp(Roman, "IX") == 0)
	{
		return romanSymbolToInt('X') - romanSymbolToInt('I');
	}
	else
	{
		return romanSymbolToInt('X');
	}
}
