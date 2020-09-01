#include "witch1atk.h"



witch1atk::witch1atk()
{
	sprite.setOrigin(16, 16); // rock
	sprite1.setOrigin(32, 32); //block
}

void witch1atk::attack()
{
		//global counter I
		if (counter1_1 != 0) this->counter1_1 -= 1;
		//normal attack : charge and fire
		if (counter1_1 == 0 && bul_count < bul + 1 && charge_state == 0)
		{
			this->bul_count += 1; // trigger push back in main with if(size < bul_count && shoot_state == 0)
			if (bul_count == bul + 1)
			{
				charge_state = 1;
				counter1_1 = 29;
			}
		}
		if (counter1_1 % 30 == 0)
		{
			if (charge_state == 1)
			{
				////////////////////////////////
				if (order < 7) this->order += 1;
				if (order == 7) order = 0;
			}
		}
		//random attack : stone pillar
		if (1)
		{
			gen = rand_gen_ptp(1, 100);
			if (gen > 75)
			{
				sprite1.setPosition(rand_gen_ptp(632, 1928), rand_gen_ptp(56, 1383));
				state2 = true;
				hit_counter = 120;
			}
		}
		//global counter II
		if (counter1_1 == 0) counter1_1 = 120;
}

void witch1atk::first(Vector2f pos, Vector2f Wpos, size_t i, int order)
{
	if (order == i)
	{
		if (!lock)
		{
			lockPos = pos;
			go = true;
			lock = true;
			COORD_angel = atan((lockPos.y - sprite.getPosition().y) / (lockPos.x - sprite.getPosition().x));
			if (lockPos.x > sprite.getPosition().x)
			{
				cosh = cos(COORD_angel);
				sinh = sin(COORD_angel);
			}
			else if (lockPos.x < sprite.getPosition().x)
			{
				cosh = -cos(COORD_angel);
				sinh = -sin(COORD_angel);
			}
			atkSF.play();
		}
	}
	if (go)
	{
		sprite.move(velocity * cosh, velocity * sinh);
	}
}

void witch1atk::second()
{
	if (state2)
	{
		if (hit_counter != 0) this->hit_counter -= 1;
	}
}
