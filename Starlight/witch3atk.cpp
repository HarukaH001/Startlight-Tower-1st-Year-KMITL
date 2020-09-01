#include "witch3atk.h"



witch3atk::witch3atk()
{
	sprite.setOrigin(32, 64); // wind
	sprite1.setOrigin(128, 128); //gale
	sprite2.setOrigin(256, 256); //vortex
	sprite3.setOrigin(32, 32); //pillar
}

void witch3atk::attack(int hp, int mh)
{
	//global counter I
	if (counter1_1 != 0) this->counter1_1 -= 1;
	//normal attack : wind cutter
	if (counter1_1 == 0)
	{
		state = true;
	}
	else state = false;
	//random attack : gale
	if (1)
	{
		sprite1.setPosition(rand_gen_ptp(632, 1928), rand_gen_ptp(56, 1383));
	}
	//ultimate defense
	if (hp <= 0.5*mh)
	{
		if (!lock2)
		{
			vortex = true;
			lock2 = true;
		}
	}
	//global counter II
	if (counter1_1 == 0) counter1_1 = 120;
}

void witch3atk::first(Vector2f pos, Vector2f Wpos)
{
		if (!lock)
		{
			sprite.setPosition(Wpos.x, Wpos.y - 64);
			go = true;
			lock = true;
			atkSF.play();			
		}
		if (go)
		{
			dis = sqrt(pow(pos.x - Wpos.x, 2) + pow(pos.y - Wpos.y, 2));
			if (counter1_2 != 0) this->counter1_2 -= 1;
			if (counter1_2 == 0)
			{
				track = false;
				velocity = 6;
			}
			if (track)
			{
				COORD_angel = atan((pos.y - sprite.getPosition().y) / (pos.x - sprite.getPosition().x));
				if (pos.x > sprite.getPosition().x)
				{
					sprite.setRotation(COORD_angel*(180 / 3.14));
					cosh = cos(COORD_angel);
					sinh = sin(COORD_angel);
				}
				else if (pos.x < sprite.getPosition().x)
				{
					sprite.setRotation(180 + COORD_angel * (180 / 3.14));
					cosh = -cos(COORD_angel);
					sinh = -sin(COORD_angel);
				}
			}
			if (dis <= 512)
			{
				track = false;
			}
			sprite.move(velocity * cosh, velocity * sinh);
		}
}

void witch3atk::second()
{
	sprite1.setPosition(rand_gen_ptp(632, 1928), rand_gen_ptp(56, 1383));
}

void witch3atk::third()
{

}

