#include "witch4atk.h"



witch4atk::witch4atk()
{
	sprite.setOrigin(32, 32);
	sprite1.setOrigin(1728, 972);
	sprite2.setOrigin(1728, 972);
	sprite.setPosition(1280, 720);
	sprite1.setPosition(1280, 720);
	sprite2.setPosition(1280, 720);
}
void witch4atk::fire()
{
	if (count3 < 540) this->count3 += 1;
	if (count3 == 0 || count3 == 90 || count3 == 180)
	{
		justdoit = false;
		for (int i = 0; i < 30; i++)
		{
			angle[i] = rand_gen_ptp(10, 12) *i;
		}
		atkSF.play();
	}
	if (count3 == 540) count3 = 0;
}
void witch4atk::update()
{
	sprite.move(v * cos(myangle*(180 / 3.14)), v * sin(myangle * (180 / 3.14)));
}
void witch4atk::passive(Vector2f pos, Vector2f Wpos)
{
	dis = sqrt(pow(pos.x - Wpos.x, 2) + pow(pos.y - Wpos.y, 2));
	if (dis <= 300) vP = 0.5;
	else vP = 0.2;
	if (count < 60) this->count += 1;
	if (count == 60)
	{
		count = 0;
		gen = rand_gen_ptp(1, 100);
		if (gen > 80) reverse = true;
		else if (gen > 60) reverse = false;
	}
	if (!reverse)
		sprite2.rotate(vP);
	else
		sprite2.rotate(-vP);
}
void witch4atk::active(int hp, int mh)
{
	if (hp <= 0.5*mh && !lock)
	{	
		count2 = 90;
		state = true;
		sprite1.setRotation(rand_gen_0(360));
		lock = true;
		atkSF.play();
	}
	if (state)
	{
		sprite1.rotate(2);
		if (count2 != 0) this->count2 -= 1;
		if (count2 == 0) { state = false;}
	}
}