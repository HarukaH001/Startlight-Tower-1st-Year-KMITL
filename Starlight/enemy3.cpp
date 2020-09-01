#include "enemy3.h"
//class enemy_atk eneatk;

enemy3::enemy3()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setFillColor(sf::Color::Blue);
	sprite.setOrigin(32, 32);
	sprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
	sprite.setColor(sf::Color(0, 0, 200));
}

void enemy3::drop()
{
	//which
	gen = rand_gen_ptp(1, 100);
	if (gen <= 15) argument_1 = 2;
	else if (gen <= 45) argument_1 = 1;
	else argument_1 = 0;
	//arg 2 & 3
	if (argument_1 == 1)
	{
		//order
		gen = rand_gen_ptp(1, 100);
		if (gen <= 28) argument_2 = 0;
		else if (gen <= 46) argument_2 = 1;
		else if (gen <= 63) argument_2 = 2;
		else if (gen <= 78) argument_2 = 3;
		else if (gen <= 85) argument_2 = 4;
		else if (gen <= 90) argument_2 = 5;
		else if (gen <= 95) argument_2 = 6;
		else argument_2 = 7;
	}
	if (argument_1 == 2)
	{
		//class
		gen = rand_gen_ptp(1, 100);
		if (gen <= 25) argument_2 = 0;
		else if (gen <= 50) argument_2 = 1;
		else if (gen <= 68) argument_2 = 2;
		else if (gen <= 86) argument_2 = 3;
		else argument_2 = 4;
		//rank
		gen = rand_gen_ptp(1, 100);
		if (gen <= 50) argument_3 = 0;
		else if (gen <= 75) argument_3 = 1;
		else if (gen <= 90) argument_3 = 2;
		else if (gen <= 97) argument_3 = 3;
		else argument_3 = 4;
	}
}

void enemy3::update(sf::Vector2u windowSize)  /////need random weapon, armor, and etc. 
{
	rect.setPosition(rand_gen_ptp(632, 1928), rand_gen_ptp(56, 1383));
	weapon_class = rand_gen_0(2); weapon_rank = rand_gen_0(2);
	weapon_atk = weapon_atkDmg[weapon_class][weapon_rank];
	atk = floor_atk + weapon_atk / 2;
	max_hp = floor_maxhp;
	hp = max_hp;
	life_state = 1;
	armor_state = rand_gen_0(1);
	if (armor_state == 1) armor = 5;
	reduce = rand_gen_0(1);
}

void enemy3::update2()
{
	sprite.setPosition(rect.getPosition());
}

void enemy3::updateMovement(sf::Vector2f charPos, sf::Vector2f enemyPos, sf::Vector2u windowSize)
{
	charX = (int)charPos.x;
	charY = (int)charPos.y;
	enemyX = (int)enemyPos.x;
	enemyY = (int)enemyPos.y;
	xcoord = 0; ycoord = 0;
	currentDis = (float)sqrt(pow(charX - enemyX, 2) + pow(charY - enemyY, 2));
	if (this->counter == 16)
	{
		direction = rand_gen_0(8); this->counter = 0;
		if (currentDis <= 500)
		{
			if (enemyX < charX && enemyY < charY) { if (direction == 1 || direction == 4 || direction == 5 || direction == 6 || direction == 7) direction = 0; }
			else if (enemyX < charX && enemyY > charY) { if (direction == 1 || direction == 2 || direction == 5 || direction == 6 || direction == 8) direction = 0; }
			else if (enemyX > charX && enemyY < charY) { if (direction == 3 || direction == 4 || direction == 5 || direction == 7 || direction == 8) direction = 0; }
			else if (enemyX > charX && enemyY > charY) { if (direction == 2 || direction == 3 || direction == 6 || direction == 7 || direction == 8) direction = 0; }
		}
	}
	if (currentDis <= 500)
	{
		if (enemyX == charX && enemyY < charY) { direction = 2; }
		else if (enemyX == charX && enemyY > charY) { direction = 4; }
		else if (enemyX < charX && enemyY == charY) { direction = 3; }
		else if (enemyX > charX && enemyY == charY) { direction = 1; }
	}
	if (enemy_stepCount == 1) enemy_stepCount = 2;
	if (enemy_stepCount != 1) this->stepCounter += 1;
	if (stepCounter % 30 == 0) enemy_stepCount = 0; else if (this->stepCounter % 15 == 0) enemy_stepCount = 2;
	if (currentDis <= weapon_range[weapon_class][weapon_rank])
	{
		direction = 0;
	}
	if (direction == 1 && blockleft != 1) { xcoord = -accel; sprite.setTextureRect(sf::IntRect(0 + (enemy_stepCount) * 64, 64, 64, 64)); } //left
	if (direction == 2 && blockdown != 1) { ycoord = accel; sprite.setTextureRect(sf::IntRect(0 + (enemy_stepCount) * 64, 0, 64, 64)); }  //down
	if (direction == 3 && blockright != 1) { xcoord = accel; sprite.setTextureRect(sf::IntRect(0 + (enemy_stepCount) * 64, 128, 64, 64)); }  //right
	if (direction == 4 && blockup != 1) { ycoord = -accel; sprite.setTextureRect(sf::IntRect(0 + (enemy_stepCount) * 64, 192, 64, 64)); } //up
	if (direction == 5 && blockleft != 1 && blockup != 1) { xcoord = -accel; ycoord = -accel; sprite.setTextureRect(sf::IntRect(192 + (enemy_stepCount) * 64, 64, 64, 64)); } //left + up
	if (direction == 6 && blockleft != 1 && blockdown != 1) { ycoord = accel; ycoord = accel; sprite.setTextureRect(sf::IntRect(192 + (enemy_stepCount) * 64, 0, 64, 64)); }  //left + down
	if (direction == 7 && blockright != 1 && blockup != 1) { xcoord = accel; ycoord = -accel; sprite.setTextureRect(sf::IntRect(192 + (enemy_stepCount) * 64, 192, 64, 64)); }  //right + up
	if (direction == 8 && blockright != 1 && blockdown != 1) { ycoord = -accel; ycoord = accel; sprite.setTextureRect(sf::IntRect(192 + (enemy_stepCount) * 64, 128, 64, 64)); } //right + down
	rect.move(xcoord, ycoord);
	this->counter += 1;
}

int enemy3::getClass()
{
	return weapon_class;
}

int enemy3::getRank()
{
	return weapon_rank;
}

