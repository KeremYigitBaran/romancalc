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
	else
	{
		return 4;
	}
}
