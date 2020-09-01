#pragma once
#include "entity.h"
#include "rng.h"

class item : public entity, rng
{
public:
	//texture
	int item_texture[8][4] = {		{ 0,	0,		64,		64 },
									{ 0,	64,		64,		64 },
									{ 0,	128,	64,		64 },
									{ 0,	192,	64,		64 },
									{ 0,	256,	64,		64 },
									{ 0,	320,	64,		64 },
									{ 0,	384,	64,		64 } ,
									{ 0,	448,	64,		64 } };
	int item2_texture[5][5][4] = {  {{ 64 * 1,	64 * 0,	64,		64 },{ 64 * 2,	64 * 0,	64,		64 },{ 64 * 3,	64 * 0,	64,		64 },{ 64 * 4,	64 * 0,	64,		64 },{ 64 * 5,	64 * 0,	64,		64 } },
									{{ 64 * 1,	64 * 1,	64,		64 },{ 64 * 2,	64 * 1,	64,		64 },{ 64 * 3,	64 * 1,	64,		64 },{ 64 * 4,	64 * 1,	64,		64 },{ 64 * 5,	64 * 1,	64,		64 } },
									{{ 64 * 1,	64 * 2,	64,		64 },{ 64 * 2,	64 * 2,	64,		64 },{ 64 * 3,	64 * 2,	64,		64 },{ 64 * 4,	64 * 2,	64,		64 },{ 64 * 5,	64 * 2,	64,		64 } },
									{{ 64 * 1,	64 * 3,	64,		64 },{ 64 * 2,	64 * 3,	64,		64 },{ 64 * 3,	64 * 3,	64,		64 },{ 64 * 4,	64 * 3,	64,		64 },{ 64 * 5,	64 * 3,	64,		64 } },
									{{ 64 * 1,	64 * 4,	64,		64 },{ 64 * 2,	64 * 4,	64,		64 },{ 64 * 3,	64 * 4,	64,		64 },{ 64 * 4,	64 * 4,	64,		64 },{ 64 * 5,	64 * 4,	64,		64 } }
};
	int argument_2 = 0;
	int argument_3 = 0;
	int which = 0;
	int state = 0;
	item();
	void drop();
	void update2(Vector2f Epos);
	void update(int whic, int argu2, int argu3);
	/* use update() to get the rand parameter from enemy and update.
	if argument 1 = weapon draw the weapon of class = argument 2 and rank = argument 3 at the Epos before erasing.
	then, in main loop, check the collision. if true, use pickup() from player class and send parameter to it using pickup().
	same argument as update.  and then, erase the array if state return from pickup = 0.
	if argument 1 = item draw the item of order = argument 2 and void = argument 3 at the Epos before erasing.
	then, in main loop, check the collision. if true,  use pickup() from player class and send parameter to it using pickup().
	same argument as update. and then, erase the array if state return from pickup = 0.
	//pickup\\ (player class)
	1. check if argument 1 = weapon
		1.1 if true - check if key E is pressed
			1.1.1 if true - update(argument 2, argument 3)
				1.1.2 return 0
		1.2 if false - return 1
	2. check if argument 1 = item
		2.1 if true
			2.1.1 if(argument 2 = 0) - (bomb) radius bomb, return 2
			2.1.2 if(argument 2 = 1) - (shield) open armor_state set rand 150-160% of max_hp, return 0
			2.1.3 if(argument 2 = 2) - (flint'n steel) add 20% string atkdmg, start timer 10s, return 0 (add 10 if 20% < 10)
			2.1.4 if(argument 2 = 3) - (cross) hp +50% of max_hp, return 0
			2.1.5 if(argument 2 = 4) - (green gem) hp = max_hp, return 0
			2.1.6 if(argument 2 = 5) - (yellow gem) +20% max_hp, hp=max_hp, return 0
			2.1.7 if(argument 2 = 6) - (red gem) atk + :rand 1-40 = + rand 2-10 :: 41-50 = + rand 11-15, return 0
			2.1.8 if(argument 2 = 7) - (blue gem) reduce + :rand 1-40 = + rand 1-5 :: 41-46 = + rand 6-10 :: 47-50 = +rand 11-15, return 0
	//drop\\(enemy class)
	-drop rate-
	weapon	15%
	item	30%
	non		55%
	-weapon rate-
	class >>	0 = 25% //sword
				1 = 25% //axe
				2 = 18% //spear
				3 = 18% //bow
				4 = 14% //staff
	rank >>		0 = 50%	//worst
				1 = 25%	//	|
				2 = 15%	//	|
				3 = 7%	//	V
				4 = 3%	//best
	-item rate-
	order >>	0 = 28%
				1 = 18%
				2 = 17%
				3 = 15%
				4 = 7%
				5 = 5%
				6 = 5%
				7 = 5%
	end <<
	0. argument 1 = weapon,item,non :: argument 2 = class,order :: argument 3 = rank,void
	1. which = :rand 1-15 = 2 (weapon) :: rand 16-45 = 1 (item) :: rand 46-100 = 0 (non)
	2. if which = 2 (weapon)
		2.1 class = :rand 1-25 = 0 (sword) :: rand 26-50 = 1 (axe) :: rand 51-68 = 2 (spear) :: rand 69-86 = 3 (bow) :: rand 87-100 = 4 (staff)
		2.2 rank = :rand 1-50 = 0 :: rand 51-75 = 1 :: rand 76-90 = 2 :: rand 91-97 = 3 :: rand 98-100 = 4
	3. if which = 1 (item)
		3.1 order = :rand 1-28 = 0 :: rand 29-46 = 1 :: rand 47-63 = 2 :: rand 64-78 = 3 :: rand 79-85 = 4 :: rand 86-90 = 5 :: rand 91-95 = 6 :: rand 96-100 = 7 
	*/
};

