#pragma once
#include "entity.h"
#include "rng.h"
class witch2atk : public entity, rng
{
public:
	//sfx
	Sound atkSF;
	/////////////witch attack////////////////////
	//normal attack : charge and fire
	int normal_dmg = 0;
	int base = 35;
	int counter1_1 = 90;
	int bul = 0;
	int bul_count = 0;
	int charge_state = 0;
	float velocity = 10;
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
	Vector2f WavePos;
	float accel = 4;
	int passive_dmg = 30;
	int counter2_1 = 0;
	bool state2 = false;
	int hit_counter = 0;
	int gen = 0;
	//////////////////////////////////////////////////////
	witch2atk();
	void attack(int hp, int mh);
	void first(Vector2f pos, Vector2f Wpos, int charge);
	void second();
};

