#pragma once
#include "entity.h"
#include "rng.h"
class witch1atk : public entity, rng
{
public:
	//sfx
	Sound atkSF;
	/////////////witch attack////////////////////
	//normal attack : charge and fire
	int normal_dmg = 25;
	int counter1_1 = 120;
	int bul = 7;
	int bul_count = 0;
	int charge_state = 0;
	float velocity = 5;
	Vector2f lockPos;
	bool lock = false;
	bool go = false;
	bool del = false;
	float cosh = 0;
	float sinh = 0;
	float COORD_angel = 0;
	int order = -1;
	//////////////////////////////////////////////////////
	//Ultimate Defense
	int passive_dmg = 20;
	int counter2_1 = 0;
	bool state2 = false;
	int hit_counter = 0;
	int gen = 0;
	//////////////////////////////////////////////////////
	witch1atk();
	void attack();
	void first(Vector2f pos, Vector2f Wpos, size_t i, int order);
	void second();
};

