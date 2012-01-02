#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <assert.h>
#include "ui.h"

#define BUFFSIZE 100

void init_randomness()
{
	struct timeval t;
	gettimeofday(&t, 0);
	srand(t.tv_usec);
	return;
}

int random_int(int min, int max)
{
	assert(max > min);
	int range = (max+1) - min;
	return rand() % range + min;
}


int main(int argc, char *argv[])
{
	int x, y, prev_x, prev_y, result;
	char *str;

	printf("mathprep\n\n");
	init_randomness();

	x = y = 0;
	if ((str = malloc(BUFFSIZE)) == NULL)
		exit(EXIT_FAILURE);

	for (;;) {
		prev_x = x;
		prev_y = y;

		do {
			x = random_int(1, 8);
			y = random_int(1, 3);
		} while (x == prev_x && y == prev_y);

		snprintf(str, BUFFSIZE, "%i + %i", x, y);
		result = x + y;
		if (!ask(str, result))
			break;
	}

	free(str);
	exit(EXIT_SUCCESS);
}
