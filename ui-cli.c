#include <stdlib.h>
#include <stdio.h>

/*
 * The text interface.
 */

int ask(int x, int y, char op)
{
	int answer, result;

	result=x+y;

	for(;;)
	{
		printf("%i + %i = ",x,y);
		if(!scanf("%i",&answer))
			return 0;
		if(result==answer)
		{
			printf("Oikein!\n\n");
			return 1;
		} else
		{
			printf("Ei ihan. Koita uudestaan!\n");
		}
	}
}
