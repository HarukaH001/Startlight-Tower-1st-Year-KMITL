#include "entity.h"

class enemy_atk : public entity
{
public:
	//starter weapon : wooden sword :: 0,0
	int weapon_class = 0;	//input of which weapon class picked
	int weapon_rank = 0;	//input of which weapon rank of its class picked
							//var
	int base_atkSpeed = 1920;
	int charX, charY, enemyX, enemyY;
	float delaycounter = 0;
	float scounter = 0;
	float velocity;
	float scosX, scosY;
	float sCOORD_angel;
	float distant = 0;
	float currentDis = 0;
	enemy_atk();
	void attack(sf::Vector2f charPos, sf::Vector2f enemyPos); //attack when lmouse pressed
	void update(int w_class, int w_rank); //add the stats of the class and rank demanded to player stats
};
