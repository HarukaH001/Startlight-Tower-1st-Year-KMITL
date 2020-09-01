#include "witch.h"



witch::witch()
{
	sprite.setOrigin(32,32);
	sprite.setPosition(1280, 356);
}

void witch::drop()
{
	//which
	gen = rand_gen_ptp(1, 100);
	if (gen <= 50) argument_1 = 2;
	else if (gen > 50) argument_1 = 1;
	//arg 2 & 3
	if (argument_1 == 1)
	{
		//order
		gen = rand_gen_ptp(1, 100);
		if (gen <= 40) argument_2 = 4;
		else if (gen <= 60) argument_2 = 5;
		else if (gen <= 80) argument_2 = 6;
		else argument_2 = 7;
	}
	if (argument_1 == 2)
	{
		//class
		gen = rand_gen_ptp(1, 100);
		if (gen <= 15) argument_2 = 0;
		else if (gen <= 30) argument_2 = 1;
		else if (gen <= 55) argument_2 = 2;
		else if (gen <= 80) argument_2 = 3;
		else argument_2 = 4;
		//rank
		gen = rand_gen_ptp(1, 100);
		if (gen <= 50) argument_3 = 2;
		else if (gen <= 80) argument_3 = 3;
		else argument_3 = 4;
	}
}

void witch::init(int floor)
{
	if (floor == 7) sprite.setTextureRect(IntRect(64,0,64,64));
	if (floor == 14) sprite.setTextureRect(IntRect(64 * 7,0,64,64));
	if (floor == 21) sprite.setTextureRect(IntRect(64 * 10,0,64,64));
	if (floor == 28) sprite.setTextureRect(IntRect(64,64 * 4, 64, 64));
	if (floor == 28) sprite.setPosition(1280,720);
	else sprite.setPosition(1280, 356);
	max_hp = floor_maxhp;
	hp = max_hp;
	life_state = 1;
}

void witch::update(int floor, Vector2f pos)
{
}