#pragma once
#include "entity.h"
#include "rng.h"
class witch : public entity , rng
{
public:
	//hp
	int life_state = 0; // 1 = still alive , 0 = dead
	int floor_maxhp = 0;
	int max_hp = 0;
	int hp = 0;
	//drop
	int gen = 0;
	int argument_1 = 0;
	int argument_2 = 0;
	int argument_3 = 0;
	witch();
	void drop();
	void init(int floor);
	void update(int floor, Vector2f pos);
};

