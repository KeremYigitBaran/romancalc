#include "romanmath.h"
#include <string.h>

int romanToInt( const char* Roman)
{
	if (strcmp(Roman, "I") == 0)
	{
		return 1;
	}
	else if (strcmp(Roman, "II") == 0)
	{
		return 2;
	}
	else if (strcmp(Roman, "III") == 0)
	{
		return 3;
	}
	else if (strcmp(Roman, "IV") == 0)
	{
		return 4;
	}
	else if (strcmp(Roman, "V") == 0)
	{
		return 5;
	}
	else if (strcmp(Roman, "VI") == 0)
	{
		return 6;
	}
	else if (strcmp(Roman, "VII") == 0)
	{
		return 7;
	}
	else if (strcmp(Roman, "VIII") == 0)
	{
		return 8;
	}
	else if (strcmp(Roman, "IX") == 0)
	{
		return 9;
	}
	else
	{
		return 10;
	}
}
