#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <assert.h>
#include "ui.h"

#define BUFFSIZE 100

#define OP_ADD 1
#define OP_SUB 2

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
	int x, y, op, prev_x, prev_y, prev_op, result;
	char operator, *str;

	printf("mathprep\n\n");
	init_randomness();

	x = y = op = 0;
	if ((str = malloc(BUFFSIZE)) == NULL)
		exit(EXIT_FAILURE);

	for (;;) {
		prev_x = x;
		prev_y = y;
		prev_op = op;

		do {
			x = random_int(1, 8);
			y = random_int(1, 3);
			op = random_int(1, 2);
		} while (x == prev_x && y == prev_y && op == prev_op);

		switch (op) {
		case OP_ADD:
			operator = '+';
			result = x + y;
			break;
		case OP_SUB:
			operator = '-';
			result = x - y;
			break;
		default:
			/* this should not happen :) */
			assert(0);
		};

		snprintf(str, BUFFSIZE, "%i %c %i", x, operator, y);
		if (!ask(str, result))
			break;
	}

	free(str);
	exit(EXIT_SUCCESS);
}
