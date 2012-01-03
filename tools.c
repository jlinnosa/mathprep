#include <assert.h>
#include <sys/time.h>
#include <stdlib.h>

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
	int range = (max + 1) - min;
	return rand() % range + min;
}
