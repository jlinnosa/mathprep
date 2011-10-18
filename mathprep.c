#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void init_randomness()
{
	struct timeval t;
	gettimeofday(&t,0);
	srand(t.tv_usec);
	return;
}

int random_int(int min, int max)
{
	int range = max - min;
	return rand()%range + min;
}

int ask(int x, int y)
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

int main(int argc, char *argv[])
{
	int x, y, prev_x, prev_y;

	printf("mathprep\n\n");
	init_randomness();

	x = y = 0;

	for(;;)
	{
		prev_x = x;
		prev_y = y;

		do
		{
			x = random_int(1,8);
			y = random_int(1,3);
		} while (x==prev_x && y==prev_y);

		if(!ask(x,y))
			break;
	}
	
	exit(0);
}
