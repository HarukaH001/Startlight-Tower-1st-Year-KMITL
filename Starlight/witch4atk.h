#pragma once
#include "entity.h"
#include "rng.h"
class witch4atk : public entity,rng
{
public:
	//sfx
	Sound atkSF;
	//parameter
	int passive_dmg = 140;
	int active_dmg = 220;
	int normal_dmg = 100;
	float angle[30];
	float myangle = 0;
	float v = 1.5;
	float vP = 0;
	float dis = 0;
	int count = 0;
	int count2 = 0;
	int count3 = 0;
	int gen = 0;
	bool reverse = false;
	bool state = false;
	bool justdoit = false;
	bool del = false;
	bool lock = false;
	witch4atk();
	void fire();
	void update();
	void passive(Vector2f pos, Vector2f Wpos);
	void active(int hp, int mh);
};

