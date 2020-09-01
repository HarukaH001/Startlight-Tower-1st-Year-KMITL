#include "atk.h"

atk::atk() {
	sprite.setPosition(0, 0);
	sprite.setOrigin(32,32);
	Nsprite.setPosition(0, 0);
	Nsprite.setOrigin(25, 25);
	circle.setRadius(0.f);
	circle.setOrigin(0, 0);
	circle.setFillColor(Color(255, 255, 255, 0));
	circle.setOutlineThickness(1);
	circle.setOutlineColor(Color(255, 0, 0, 32));
	circle.setPosition(1280, 1368);
}

void atk::attack(sf::Vector2f charPos, sf::Vector2f mouseCoord) {
	circle.setRadius(weapon_range[weapon_class][weapon_rank] +16);
	circle.setOrigin(weapon_range[weapon_class][weapon_rank] + 16, weapon_range[weapon_class][weapon_rank] + 16);
	circle.setPosition(charPos);
	sprite.setTextureRect(sf::IntRect(	effect_texture[weapon_class][weapon_rank][0], 
										effect_texture[weapon_class][weapon_rank][1],
										effect_texture[weapon_class][weapon_rank][2], 
										effect_texture[weapon_class][weapon_rank][3]));
	mousePosition = mouseCoord;
	charX = (int)charPos.x;	mouseX = mousePosition.x;
	charY = (int)charPos.y;	mouseY = mousePosition.y;
	if (mouseX > charX)
	{
		Nsprite.setTextureRect(sf::IntRect(weapon_texture[weapon_class][weapon_rank][0], weapon_texture[weapon_class][weapon_rank][1] + 50, 50, 50));
		Nsprite.setPosition(charX,charY);
	}
	else
	{
		Nsprite.setTextureRect(sf::IntRect(weapon_texture[weapon_class][weapon_rank][0],weapon_texture[weapon_class][weapon_rank][1], 50, 50));
		Nsprite.setPosition(charX, charY);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->counter == 0 && this->delaycounter == 0) {
		atkSF.play();
		this->distant = 0;
		this->counter = base_atkSpeed / weapon_atkSpeed[weapon_class][weapon_rank];
		this->delaycounter = this->counter;
		velocity = weapon_range[weapon_class][weapon_rank] / (this->counter);
		sprite.setPosition((int)charPos.x , (int)charPos.y );
		sprite.setColor(sf::Color(255, 255, 255, 255));
		COORD_angel = (180 / 3.14)*(atan(((float)mouseY - (float)charY) / ((float)mouseX - (float)charX)));
		// Angle transition
		if(mouseX < charX) sprite.setRotation(COORD_angel +180);
		else sprite.setRotation(COORD_angel);
		if (mouseX > charX && mouseY < charY) {COORD_angel = -COORD_angel;
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = -sin(COORD_angel);
		} //Q4
		if (mouseX < charX && mouseY < charY) { COORD_angel = 180 - COORD_angel;
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = -sin(COORD_angel);
		} //Q3
		if (mouseX < charX && mouseY > charY) { COORD_angel = 180 - COORD_angel; 
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = -sin(COORD_angel);
		} //Q2
		if (mouseX > charX && mouseY > charY) { COORD_angel = 360 - COORD_angel; 
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = -sin(COORD_angel);
		} //Q1
		if (mouseX == charX && mouseY < charY) { COORD_angel = 90; 
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = -sin(COORD_angel);
		} //N
		if (mouseX == charX && mouseY > charY) { COORD_angel = 270; 
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = -sin(COORD_angel);
		} //S
		if (mouseX < charX && mouseY == charY) { COORD_angel = 180; 
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = sin(COORD_angel);
		} //W
		if (mouseX > charX && mouseY == charY) { COORD_angel = 0; 
		COORD_angel = COORD_angel * (3.14 / 180);
		cosX = cos(COORD_angel);
		cosY = sin(COORD_angel);
		} //E
	}
	if (this->counter > 0) {
		if (this->distant < weapon_range[weapon_class][weapon_rank]) {
			this->distant += velocity;
			sprite.move((velocity * cosX), (velocity * cosY));
		}
		this->delaycounter -= 1;
		this->counter -= 1;
	}
	if (this->counter == 0 && this->delaycounter > 0) this->delaycounter -= 1;
	if (this->counter == 0) { sprite.setPosition((int)charPos.x, (int)charPos.y); sprite.setColor(sf::Color(255,255,255,0)); }
}

void atk::update(int w_class, int w_rank) {
	weapon_class =	w_class;
	weapon_rank = w_rank;
}