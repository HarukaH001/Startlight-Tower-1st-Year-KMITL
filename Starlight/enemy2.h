#pragma once
#ifndef enemy2_inti
#define enemy2_inti
#include "entity.h"
#include "rng.h"

class enemy2 : public entity, rng
{
public:
	//hp
	int life_state = 0; // 1 = still alive , 0 = dead
	int floor_maxhp = 0;
	int max_hp = 0;
	int hp = 0;
	//atk
	int floor_atk = 0;
	int weapon_atk = 0;
	int atk = 0;
	//reduce
	int reduce = 0;
	//armor
	int armor_state = 0; // 1 = on , 0 = off
	int armor = 0;
	//weapon check
	int weapon_class;
	int weapon_rank;
	//drop
	int gen = 0;
	int argument_1 = 0;
	int argument_2 = 0;
	int argument_3 = 0;
	//movement
	int blockleft = 0, blockright = 0;
	int blockup = 0, blockdown = 0;
	int xcoord, ycoord;
	int accel = 1; // movespeed
	int charX, charY, enemyX, enemyY;
	int enemy_stepCount, counter = 0;
	int stepCounter;
	int direction = 0;
	float COORD_angel;
	int weapon_rand_count = 0;
	float currentDis;
	enemy2();
	void drop();
	void update(sf::Vector2u windowSize);
	void update2();
	void updateMovement(sf::Vector2f charPos, sf::Vector2f enemyPos, sf::Vector2u windowSize);
	int getClass();
	int getRank();
};

#endif