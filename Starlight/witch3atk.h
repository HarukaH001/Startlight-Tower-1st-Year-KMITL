#pragma once
#include "entity.h"
#include "rng.h"
class witch3atk : public entity, rng
{
public:
	//sfx
	Sound atkSF;
	/////////////witch attack////////////////////
	//normal attack : charge and fire
	int normal_dmg = 80;
	int counter1_1 = 90;
	bool state = false;
	float velocity = 3;
	bool lock = false;
	bool go = false;
	bool del = false;
	float cosh = 0;
	float sinh = 0;
	float COORD_angel = 0;
	int counter1_2 = 90;
	bool track = true;
	float dis = 0;
	//////////////////////////////////////////////////////
	//passive attack : gale
	int size = 3;
	float accel = 4;
	int passive_dmg = 40;
	//////////////////////////////////////////////////////
	//ultimate defense : vortex and pillar
	bool vortex = false;
	int pillar_count = 0;
	int pillar_hp = 500;
	int pillar_mh = 500;
	bool del2 = false;
	bool lock2 = false;
	Vector2f pillar_pos;
	//////////////////////////////////////////////////////
	witch3atk();
	void attack(int hp, int mh);
	void first(Vector2f pos, Vector2f Wpos);
	void second();
	void third();
};

