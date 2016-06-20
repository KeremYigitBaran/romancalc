#include "romanmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	int mainResult = 0;

	if (argc != 4)
	{
		mainResult = 1;
	}
	else
	{
		char* result = 0;

		if (strcmp(argv[2], "+") == 0 )
		{
			result = romanSum(argv[1], argv[3]);
		}
		else if (strcmp(argv[2], "-") == 0)
		{
			result = romanSubtract(argv[1], argv[3]);
		}
		else
		{
			mainResult = 2;
		}

		if (result)
		{
			printf("%s\n", result);
			free(result);
		}
		else
		{
			mainResult = 3;
		}
	}

    return mainResult;
}
