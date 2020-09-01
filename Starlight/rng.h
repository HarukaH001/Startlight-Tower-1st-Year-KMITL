#pragma once
#ifndef rng_inti
#define rng_inti


class rng
{
public:

	int random;
	int max;
	rng();
	int rand_gen_0(int max);
	int rand_gen_ptp(int min, int max);
};

#endif