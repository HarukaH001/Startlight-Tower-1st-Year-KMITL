#include "explosion.h"



explosion::explosion()
{
	sprite.setPosition(0,0);
	sprite.setOrigin(250, 250);
	sprite.setTextureRect(IntRect(0,0,500,500));
	sprite.setColor(Color(255,255,255,0));
}

void explosion::start(Vector2f pos)
{
	sprite.setPosition(pos);
	sprite.setColor(Color(255, 255, 255, 255));
	state = 1;
	counter = 280;
	i = 0;

}
void explosion::explode()
{
	if (state == 1 && counter != 0)
	{
		this->counter -= 1;
		if (counter >= 120 && counter % 40 == 0)
		{
			sprite.setColor(Color(rand_gen_ptp(128, 255), rand_gen_ptp(128, 255), rand_gen_ptp(128, 255), 255));
			sprite.rotate(rand_gen_0(360));
			sprite.setTextureRect(IntRect(500*i,0,500,500));
			this->i += 1;
		}
		else if (counter >= 20 && counter % 20 == 0)
		{
			sprite.setColor(Color(rand_gen_ptp(128, 255), rand_gen_ptp(128, 255), rand_gen_ptp(128, 255), 255));
			sprite.rotate(rand_gen_0(360));
		}
		else if (counter < 20)
		{
			sprite.setTextureRect(IntRect(500 * 4, 0, 500, 500));
		}

	}
	else if (state == 1 && counter == 0)
	{
		state = 0;
		sprite.setColor(Color(255, 255, 255, 0));
	}
}