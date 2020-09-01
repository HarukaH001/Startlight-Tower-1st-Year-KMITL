#include "rng.h"
#include <time.h>
#include <windows.h>

rng::rng() {
	srand(time(NULL));
}

int rng::rand_gen_0(int max)
{
		random = rand()%(max+1);
		return random;
}

int rng::rand_gen_ptp(int min, int max)
{
	random = rand() % (max-min+1) + min;
	return random;
}