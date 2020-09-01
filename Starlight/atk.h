#pragma once
#ifndef atk_inti
#define atk_inti
#include "entity.h"

class atk : public entity
{
public:
	//sfx
	Sound atkSF;
	//starter weapon : wooden sword :: 0,0
	int weapon_class = 0;	//input of which weapon class picked
	int weapon_rank = 0;	//input of which weapon rank of its class picked
	//var
	int base_atkSpeed = 1920;
	int charX, charY, mouseX, mouseY;
	float delaycounter = 0;
	float counter = 0;
	float velocity;
	float cosX, cosY;
	float COORD_angel;
	float distant = 0;
	sf::Vector2f mousePosition;
	sf::Vector2f charPosition;

	atk();
	void attack(sf::Vector2f charPos, sf::Vector2f mouseCoord); //attack when lmouse pressed
	void update(int w_class,int w_rank); //add the stats of the class and rank demanded to player stats
};

#endif