#pragma once
#include "entity.h"
#include "rng.h"
class explosion : public entity , rng
{
public:
	int counter = 0;
	int state = 0;
	int i = 0;
	explosion();
	void start(Vector2f pos);
	void explode();
};

