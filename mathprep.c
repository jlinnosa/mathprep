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

int main(int argc, char *argv[])
{
	int x, y, result, answer;

	printf("mathprep\n\n");
	init_randomness();

	for(;;)
	{
		x = random_int(1,8);
		y = random_int(1,3);
		result = x + y;
		printf("%i + %i = ",x,y);
		if(!scanf("%i",&answer))
			break;
		printf( (result==answer) ? "Correct!\n\n" : "Wrong...\n\n" );
	}
	exit(0);
}
