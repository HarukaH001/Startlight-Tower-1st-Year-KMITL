#include "item.h"

item::item()
{
	sprite.setPosition(0, 0);
	sprite.setOrigin(32,32);
	sprite.setColor(Color(255, 255, 255, 0));
}

void item::update(int whic, int argu2, int argu3)
{
	which = whic;
	if (whic != 0) state = 1;
	argument_2 = argu2;
	argument_3 = argu3;
}

void item::update2(Vector2f Epos)
{
	sprite.setPosition(Epos);
	if(which == 1)
	sprite.setTextureRect(sf::IntRect(	item_texture[argument_2][0],
										item_texture[argument_2][1],
										item_texture[argument_2][2],
										item_texture[argument_2][3]));
	if(which == 2)
	sprite.setTextureRect(sf::IntRect(	item2_texture[argument_2][argument_3][0],
										item2_texture[argument_2][argument_3][1],
										item2_texture[argument_2][argument_3][2],
										item2_texture[argument_2][argument_3][3]));
}

void item::drop()
{
	sprite.setColor(Color(255, 255, 255, 255));
}
