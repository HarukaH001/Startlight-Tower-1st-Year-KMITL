#pragma once
#ifndef player_inti
#define player_inti
#include "entity.h"
#include "rng.h"

	class player: public entity , rng
	{
	public:
		//sfx
		Sound evasion;
		Sound magic;
		//parameters
		//weapon check
		int weapon_class;
		int weapon_rank;
		//hp
		int life_state = 0; // 1 = still alive , 0 = dead
		int item_maxhp = 0;
		int floor_maxhp = 0;
		int max_hp = 0;
		int base_mh = 100;
		int hp = 0;
		//atk
		int floor_atk = 0;
		int item_atk_string = 0;
		int item_atk_counter = 0;
		int item_atk_const = 0;
		int weapon_atk = 0;
		int base_atk = 5;
		int atk = 0;
		//reduce
		int item_reduce_const = 0;
		int base_reduce = 0;
		int reduce = 0;
		//armor
		int armor_state = 0; // 1 = on , 0 = off
		int armor = 0;
		//hit check
		int hit_counter = 0;
		//weapon & item pick check
		int gen = 0;
		int argument_1 = 0;
		int argument_2 = 0;
		int argument_3 = 0;
		//movement
		int blockleft = 0, blockright = 0;
		int blockup = 0, blockdown = 0;
		int d_blockleft = 0, d_blockright = 0;
		int d_blockup = 0, d_blockdown = 0;
		float xcoord, ycoord, accel;
		int dash_state = 0, dash_count = 0;
		int magic_state = 0, magic_count = 0;
		int magic_duration = 0;
		Vector2f magic_position;
		int charX, charY, mouseX, mouseY;
		int char_stepCount, counter;
		float COORD_angel;
		sf::Vector2f mousePosition;
		sf::Vector2f charPosition;
		player();
		int pickup(int arg1, int arg2, int arg3);
		void update(sf::Vector2f charPos, sf::Vector2f mouseCoord);
		void init(int c, int r);
		void status(int c, int r);
	};

#endif