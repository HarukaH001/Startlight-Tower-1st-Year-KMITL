#include "witch2atk.h"



witch2atk::witch2atk()
{
	sprite.setOrigin(0, 32); // water spear
	sprite1.setOrigin(32, 32); //wave
}

void witch2atk::attack(int hp, int mh)
{
	//hp base bullet set
	if (hp > 0.75*mh) bul = 2;
	else if (hp > 0.5*mh) bul = 3;
	else if (hp > 0.25*mh) bul = 4;
	else bul = 5;
	normal_dmg = base * bul;
	//global counter I
	if (counter1_1 != 0) this->counter1_1 -= 1;
	//normal attack : charge and fire
	if (counter1_1 == 0 && bul_count < bul + 1 && charge_state == 0)
	{
		this->bul_count += 1; // trigger push back in main with if(size < bul_count && shoot_state == 0)
		if (bul_count == bul + 1)
		{
			charge_state = 1;
		}
	}
	//random attack : wave
	if (counter1_1 % 45 == 0)
	{
		gen = rand_gen_ptp(1, 100);
		if (gen > 60)
		{
			state2 = true;
		}
		else state2 = false;
	}
	else state2 = false;
	//global counter II
	if (counter1_1 == 0) counter1_1 = 120;
}

void witch2atk::first(Vector2f pos, Vector2f Wpos,int charge)
{
	if (charge)
	{
		if (!lock)
		{
			lockPos = pos;
			go = true;
			lock = true;
			COORD_angel = atan((lockPos.y - sprite.getPosition().y) / (lockPos.x - sprite.getPosition().x));
			if (lockPos.x > sprite.getPosition().x)
			{
				sprite.setRotation(COORD_angel*(180 / 3.14));
				cosh = cos(COORD_angel);
				sinh = sin(COORD_angel);
			}
			else if (lockPos.x < sprite.getPosition().x)
			{
				sprite.setRotation(180 + COORD_angel*(180 / 3.14));
				cosh = -cos(COORD_angel);
				sinh = -sin(COORD_angel);
			}
			atkSF.play();
		}
		if (go)
		{
			sprite.move(velocity * cosh, velocity * sinh);
		}
	}
}

void witch2atk::second()
{
}

