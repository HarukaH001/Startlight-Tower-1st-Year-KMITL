#include "player.h"

player::player()
{
	//character setup
	sprite.setPosition(1280, 1368); //1368 bottom :: 56 top
	sprite.setOrigin(32, 32);
	// active magic setup 
	Nsprite.setPosition(1280, 1368); //1368 bottom :: 56 top
	Nsprite.setOrigin(250, 250);
	Nsprite.setColor(Color(255, 255, 255, 0));
	//weapon range assist
	circle.setRadius(80.f);
	circle.setOrigin(80,80);
	circle.setFillColor(Color(255,255,255,0));
	circle.setOutlineThickness(1);
	circle.setOutlineColor(Color(255,255,255,32));
	circle.setPosition(1280, 1368);
	//magic setup
	Ncircle.setRadius(250.f);
	Ncircle.setOrigin(250, 250);
	Ncircle.setFillColor(Color(255, 255, 255, 0));
	Ncircle.setOutlineThickness(2);
	Ncircle.setOutlineColor(Color(255, 0, 255, 32));
	Ncircle.setPosition(1280, 1368);
}

int player::pickup(int arg1, int arg2, int arg3)
{
	//pickup\\ (player class)
	/*1. check if argument 1 = weapon
		1.1 if true - check if key E is pressed
		1.1.1 if true - update(argument 2, argument 3)
		1.1.2 return 0
		1.2 if false - return 1
		2. check if argument 1 = item
		2.1 if true
		2.1.1 if (argument 2 = 0) - (bomb)radius bomb, return 2
		2.1.2 if (argument 2 = 1) - (shield)open armor_state set rand 150 - 160 % of max_hp, return 0
		2.1.3 if (argument 2 = 2) - (flint'n steel) add 20% string atkdmg, start timer 10s, return 0 (add 10 if 20% < 10)
			2.1.4 if (argument 2 = 3) - (cross)hp + 50 % of max_hp, return 0
			2.1.5 if (argument 2 = 4) - (green gem) hp = max_hp, return 0
			2.1.6 if (argument 2 = 5) - (yellow gem) + 20 % max_hp, hp = max_hp, return 0
			2.1.7 if (argument 2 = 6) - (red gem) atk + :rand 1 - 40 = +rand 2 - 10 :: 41 - 50 = +rand 11 - 15, return 0
			2.1.8 if (argument 2 = 7) - (blue gem) reduce + : rand 0 - 40 = +rand 1 - 5 :: 41 - 46 = +rand 6 - 10 :: 47 - 50 = +rand 11 - 15, return 0*/
	if (arg1 == 2 && Keyboard::isKeyPressed(Keyboard::E))
	{
		status(arg2, arg3);
		return 0;
	}
	else if (arg1 == 2) return 1;
	if (arg1 == 1)
	{
		if (arg2 == 0) return 2;
		if (arg2 == 1) { armor_state = 1; this->armor += rand_gen_ptp(0.2*base_mh, 0.4*base_mh); status(weapon_class, weapon_rank); return 0; }
		if (arg2 == 2) { if(0.2*atk < 10) item_atk_string = 10; else item_atk_string = 0.2*atk; item_atk_counter = 600; status(weapon_class, weapon_rank); return 0; }
		if (arg2 == 3) { hp += (0.5*max_hp); if (hp > max_hp) hp = max_hp; status(weapon_class, weapon_rank); return 0; }
		if (arg2 == 4) { hp = max_hp; return 0; }
		if (arg2 == 5) { item_maxhp += (0.2*base_mh); hp += (0.2*base_mh); status(weapon_class, weapon_rank); return 0; }
		if (arg2 == 6)
		{
			gen = rand_gen_ptp(1,50);
			if (gen <= 40)
			{
				gen = rand_gen_ptp(2, 10);
				item_atk_const += gen;
			}
			else if (gen <= 50)
			{
				gen = rand_gen_ptp(11,15);
				item_atk_const += gen;
			}
			status(weapon_class, weapon_rank);
			return 0;
		}
		if (arg2 == 7)
		{
			gen = rand_gen_ptp(1, 50);
			if (gen <= 40)
			{
				item_reduce_const += rand_gen_ptp(1, 5);
			}
			else if (gen <= 46)
			{
				item_reduce_const += rand_gen_ptp(6, 10);
			}
			else if (gen <= 50)
			{
				item_reduce_const += rand_gen_ptp(11, 15);
			}
			status(weapon_class, weapon_rank);
			return 0;
		}
	}
}

void player::update(sf::Vector2f charPos, sf::Vector2f mouseCoord){
	//update pickup circle
	circle.setPosition(charPos);
	//update magic circle ready alert
	Ncircle.setPosition(charPos);
	//char movement
	xcoord = 0; ycoord = 0;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::V))) { item_atk_const += 100; status(weapon_class, weapon_rank); } ////HACK
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F)) && this->magic_state == 0) // warp gate magic
	{
		if (magic.getStatus() == magic.Stopped) magic.play();
		this->magic_state = 1; this->magic_count = 2700; this->magic_duration = 280;
		magic_position = charPos;
		Nsprite.setPosition(magic_position);
		Ncircle.setOutlineColor(Color(255, 0, 255, 0));
		Nsprite.setColor(Color(255,255,255,255));
	}
	if (magic_duration != 0)
	{
		if (magic_duration % 40 == 0)
		{
			Nsprite.setColor(Color(rand_gen_ptp(128, 255), rand_gen_ptp(128, 255), rand_gen_ptp(128, 255), 255));
			Nsprite.rotate(rand_gen_0(360));
		}
		this->magic_duration -= 1;
	}
	if (magic_duration == 0 && magic_state == 1)
	{
		Nsprite.setColor(Color(255, 255, 255, 0));
	}
	if (magic_count != 0 && magic_state == 1)
	{
		this->magic_count -= 1;
	}
	if (magic_count == 0)
	{
		this->magic_state = 0;
		Ncircle.setOutlineColor(Color(255, 0, 255, 32));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && this->dash_state == 0)
	{
		evasion.play();
		accel = 30; this->dash_state = 1; this->dash_count = 60;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && d_blockleft != 1)
		{
			xcoord = -accel;
		} //left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && d_blockdown != 1)
		{
			ycoord = accel;
		}  //down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && d_blockright != 1)
		{
			xcoord = accel;
		}  //right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && d_blockup != 1)
		{
			ycoord = -accel;
		} //up
		sprite.setPosition(charPos.x +xcoord, charPos.y +ycoord);
		xcoord = 0; ycoord = 0;
	} //dash
	else accel = 1.7;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && blockleft != 1)
	{ 
		xcoord = -accel; 
	} //left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && blockdown != 1)
	{
		ycoord = accel;
	}  //down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && blockright != 1)
	{ 
		xcoord = accel;
	}  //right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && blockup != 1)
	{ 
		ycoord = -accel; 
	} //up
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		char_stepCount = 1;  this->counter = 0;
	}
	else
	{
	if (char_stepCount == 1) char_stepCount = 2;
	if (char_stepCount != 1) this->counter += 1;
	if (counter % 30 == 0) char_stepCount = 0; else if (this->counter % 15 == 0) char_stepCount = 2;
	}
	if (this->dash_state == 1)  this->dash_count -= 1;  if (this->dash_count == 0) this->dash_state = 0;
	sprite.move(xcoord, ycoord);

	//char rotation
	charPosition = sprite.getPosition();
	mousePosition = mouseCoord;
	charX = (int)charPosition.x;	mouseX = mousePosition.x;
	charY = (int)charPosition.y;	mouseY = mousePosition.y;
	COORD_angel = (180 / 3.14)*(atan(((float)mouseY - (float)charY) / ((float)mouseX - (float)charX)));
	//spritePlayer.setTextureRect(sf::IntRect(0, 0, 64, 64));
	if (mouseX > charX && mouseY < charY) { //Q4
		if (COORD_angel > -30) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 128, 64, 64)); }//E
		if (COORD_angel <= -30 && COORD_angel >= -60) { sprite.setTextureRect(sf::IntRect(192 + (char_stepCount) * 64, 192, 64, 64)); }//NE
		if (COORD_angel < -60) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 192, 64, 64)); }//N
	}
	if (mouseX < charX && mouseY < charY) { //Q3
		if (COORD_angel > 60) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 192, 64, 64)); }//N
		if (COORD_angel >= 30 && COORD_angel <= 60) { sprite.setTextureRect(sf::IntRect(192 + (char_stepCount) * 64, 64, 64, 64)); }//NW
		if (COORD_angel < 30) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 64, 64, 64)); }//W
	}
	if (mouseX < charX && mouseY > charY) { //Q2
		if (COORD_angel > -30) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 64, 64, 64)); }//W
		if (COORD_angel <= -30 && COORD_angel >= -60) { sprite.setTextureRect(sf::IntRect(192 + (char_stepCount) * 64, 0, 64, 64)); }//SW
		if (COORD_angel < -60) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 0, 64, 64)); }//S
	}
	if (mouseX > charX && mouseY > charY) { //Q1
		if (COORD_angel > 60) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 0, 64, 64)); }//S
		if (COORD_angel >= 30 && COORD_angel <= 60) { sprite.setTextureRect(sf::IntRect(192 + (char_stepCount) * 64, 128, 64, 64)); }//SE
		if (COORD_angel < 30) { sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 128, 64, 64)); }//E
	}
	if (mouseX == charX && mouseY < charY) { //Q3
		sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 192, 64, 64));//N
	}
	if (mouseX == charX && mouseY > charY) { //Q3
		sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 0, 64, 64));//S
	}
	if (mouseX < charX && mouseY == charY) { //Q3
		sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 64, 64, 64)); //W
	}
	if (mouseX > charX && mouseY == charY) { //Q3
		sprite.setTextureRect(sf::IntRect(0 + (char_stepCount) * 64, 128, 64, 64));//E
	}
	//return to play area
	//non corner
	if (charX < 632 && charY >= 60 && charY <= 1385) sprite.setPosition(632, charY);
	if (charX > 1960 && charY >= 60 && charY <= 1385) sprite.setPosition(1960, charY);
	if (charY < 60 && charX >= 632 && charX <= 1960) sprite.setPosition(charX, 60);
	if (charY > 1385 && charX >= 632 && charX <= 1960) sprite.setPosition(charX, 1385);
	//corner
	if (charX < 632 && charY < 60) sprite.setPosition(632, 60);
	if (charX > 1960 && charY < 60) sprite.setPosition(1960, 60);
	if (charX < 632 && charY > 1385) sprite.setPosition(632, 1385);
	if (charX > 1960 && charY > 1385) sprite.setPosition(1960, 1385);
	if (charY < 60 && charX < 632) sprite.setPosition(632, 60);
	if (charY > 1385 && charX < 632) sprite.setPosition(632, 1385);
	if (charY < 60 && charX > 1960) sprite.setPosition(1960, 60);
	if (charY > 1385 && charX > 1960) sprite.setPosition(1960, 1385);
	//item string counter
	if (this->item_atk_counter != 0) this->item_atk_counter -= 1;
	if (this->item_atk_counter == 0) { this->item_atk_string = 0; status(weapon_class,weapon_rank); }
}

void player::init(int c, int r)
{
	weapon_class = c;
	weapon_rank = r;
	weapon_atk = weapon_atkDmg[weapon_class][weapon_rank];
	atk = base_atk + floor_atk + item_atk_const + item_atk_string + weapon_atk;
	max_hp = base_mh + item_maxhp + floor_maxhp;
	hp = max_hp;
	life_state = 1;
}

void player::status(int c, int r)
{
	weapon_class = c;
	weapon_rank = r;
	weapon_atk = weapon_atkDmg[weapon_class][weapon_rank];
	atk = base_atk + floor_atk + item_atk_const + item_atk_string + weapon_atk;
	max_hp = base_mh + item_maxhp + floor_maxhp;
	reduce = base_reduce + item_reduce_const;
}