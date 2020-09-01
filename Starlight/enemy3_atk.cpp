#include "enemy3_atk.h"

enemy3_atk::enemy3_atk() {
	Nsprite.setPosition(0, 0);
	Nsprite.setOrigin(32, 32);
	sprite.setPosition(0, 0);
	sprite.setOrigin(25, 25);
}

void enemy3_atk::attack(sf::Vector2f charPos, sf::Vector2f enemyPos) {
	Nsprite.setTextureRect(sf::IntRect(effect_texture[weapon_class][weapon_rank][0],
		effect_texture[weapon_class][weapon_rank][1],
		effect_texture[weapon_class][weapon_rank][2],
		effect_texture[weapon_class][weapon_rank][3]));
	charX = (int)charPos.x;
	charY = (int)charPos.y;
	enemyX = (int)enemyPos.x;
	enemyY = (int)enemyPos.y;
	if (charX > enemyX)
	{
		sprite.setTextureRect(sf::IntRect(weapon_texture[weapon_class][weapon_rank][0], weapon_texture[weapon_class][weapon_rank][1] + 50, 50, 50));
		sprite.setPosition(enemyX, enemyY);
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(weapon_texture[weapon_class][weapon_rank][0], weapon_texture[weapon_class][weapon_rank][1], 50, 50));
		sprite.setPosition(enemyX, enemyY);
	}
	currentDis = (float)sqrt(pow(charX - enemyX, 2) + pow(charY - enemyY, 2));
	if (currentDis <= weapon_range[weapon_class][weapon_rank] && this->scounter == 0 && this->delaycounter == 0) {
		this->distant = 0;
		this->scounter = base_atkSpeed / (weapon_atkSpeed[weapon_class][weapon_rank] / 2);
		this->delaycounter = this->scounter;
		velocity = weapon_range[weapon_class][weapon_rank] / (this->scounter);
		Nsprite.setPosition((int)enemyPos.x, (int)enemyPos.y);
		Nsprite.setColor(sf::Color(255, 255, 255, 255));
		sCOORD_angel = (180 / 3.14)*(atan(((float)charY - (float)enemyY) / ((float)charX - (float)enemyX)));
		// Angle transition
		if (charX < enemyX) Nsprite.setRotation(sCOORD_angel + 180);
		else Nsprite.setRotation(sCOORD_angel);
		if (charX > enemyX && charY < enemyY) {
			sCOORD_angel = -sCOORD_angel;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = -sin(sCOORD_angel);
		} //Q4
		if (charX < enemyX && charY < enemyY) {
			sCOORD_angel = 180 - sCOORD_angel;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = -sin(sCOORD_angel);
		} //Q3
		if (charX < enemyX && charY > enemyY) {
			sCOORD_angel = 180 - sCOORD_angel;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = -sin(sCOORD_angel);
		} //Q2
		if (charX > enemyX && charY > enemyY) {
			sCOORD_angel = 360 - sCOORD_angel;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = -sin(sCOORD_angel);
		} //Q1
		if (charX == enemyX && charY < enemyY) {
			sCOORD_angel = 90;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = -sin(sCOORD_angel);
		} //N
		if (charX == enemyX && charY > enemyY) {
			sCOORD_angel = 270;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = -sin(sCOORD_angel);
		} //S
		if (charX < enemyX && charY == enemyY) {
			sCOORD_angel = 180;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = sin(sCOORD_angel);
		} //W
		if (charX > enemyX && charY == enemyY) {
			sCOORD_angel = 0;
			sCOORD_angel = sCOORD_angel * (3.14 / 180);
			scosX = cos(sCOORD_angel);
			scosY = sin(sCOORD_angel);
		} //E
	}
	if (this->scounter > 0) {
		if (this->distant < weapon_range[weapon_class][weapon_rank]) {
			this->distant += velocity;
			Nsprite.move((velocity * scosX), (velocity * scosY));
		}
		this->delaycounter -= 1;
		this->scounter -= 1;
	}
	if (this->scounter == 0 && this->delaycounter > 0) this->delaycounter -= 1;
	if (this->scounter == 0) { Nsprite.setPosition((int)enemyPos.x, (int)enemyPos.y); Nsprite.setColor(sf::Color(255, 255, 255, 0)); }
}

void enemy3_atk::update(int w_class, int w_rank) {
	weapon_class = w_class;
	weapon_rank = w_rank;
}