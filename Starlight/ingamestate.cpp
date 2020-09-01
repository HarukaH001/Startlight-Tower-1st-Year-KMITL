#include "ingamestate.h"



ingamestate::ingamestate()
{
	text.setCharacterSize(72);
	text.setFillColor(Color::Transparent);
	text1.setCharacterSize(40);
	text1.setFillColor(Color::Transparent);
	text2.setCharacterSize(72);
	text2.setFillColor(Color::Transparent);
	text.setString("PAUSE");
	rect.setPosition(-448, -272);
	rect.setSize(Vector2f(3456,1944));
	sprite.setTextureRect(IntRect(0,100,400,100));
	Nsprite.setTextureRect(IntRect(0, 300, 400, 100));
	sprite1.setTextureRect(IntRect(0, 500, 400, 100));
	sprite2.setTextureRect(IntRect(0, 700, 400, 100));
	sprite.setOrigin(200, 50);
	Nsprite.setOrigin(200, 50);
	sprite1.setOrigin(200, 50);
	sprite2.setOrigin(200, 50);
	sprite.setScale(.75f,.75f);
	Nsprite.setScale(.75f, .75f);
	sprite1.setScale(.75f, .75f);
	sprite2.setScale(.75f, .75f);
}

void ingamestate::do_score(int score, const char* timer)
{
	do_time(timer,"Time   ",returned);
	do_temp(score, "Score  ", returned1);
	text1.setString(returned);
	text2.setString(returned1);
}

void ingamestate::do_time(const char* arg, const char* string, char* c)
{
	for (size_t f = 0; f < 7; f++)
	{
		c[f] = string[f];
	}
	for (size_t i = 0; i < 9; i++)
	{
		c[i + 6] = arg[i];
	}
}

void ingamestate::do_temp(int input, const char* string, char* c)
{
	for (size_t f = 0; f < 7; f++)
	{
		c[f] = string[f];
	}
	if (input > 9999)
	{
		c[8] = input / 10000 + '0';
		c[9] = (input / 1000) % 10 + '0';
		c[10] = (input / 100) % 10 + '0';
		c[11] = (input / 10) % 10 + '0';
		c[12] = input % 10 + '0';
	}
	else if (input > 999)
	{
		c[8] = input / 1000 + '0';
		c[9] = (input / 100) % 10 + '0';
		c[10] = (input / 10) % 10 + '0';
		c[11] = input % 10 + '0';
		c[12] = '\0';
	}
	else if (input > 99)
	{
		c[8] = input / 100 + '0';
		c[9] = (input / 10) % 10 + '0';
		c[10] = input % 10 + '0';
		c[11] = '\0';
		c[12] = '\0';
	}
	else if (input > 9)
	{
		c[8] = input / 10 + '0';
		c[9] = input % 10 + '0';
		c[10] = '\0';
		c[11] = '\0';
		c[12] = '\0';
	}
	else
	{
		c[8] = input + '0';
		c[9] = '\0';
		c[10] = '\0';
		c[11] = '\0';
		c[12] = '\0';
	}
	c[7] = ' ';
	for (size_t i = 13; i < 20; i++)
	{
		c[i] = '\0';
	}
}

int ingamestate::click(int which)
{
	if (which == 0)//resume
	{
		sprite.setTextureRect(IntRect(0, 0, 400, 100));
		if (Mouse::isButtonPressed(Mouse::Left)) { return 1; }
	}
	else if (which == 1)//quit
	{
		Nsprite.setTextureRect(IntRect(0, 200, 400, 100));
		if (Mouse::isButtonPressed(Mouse::Left)) { return 2; }
	}
	else if (which == 2)//restart
	{
		sprite1.setTextureRect(IntRect(0, 400, 400, 100));
		if (Mouse::isButtonPressed(Mouse::Left)) { return 3; }
	}
	else if (which == 3)//main menu
	{
		sprite2.setTextureRect(IntRect(0, 600, 400, 100));
		if (Mouse::isButtonPressed(Mouse::Left)) { return 4; }
	}
	else
	{
		sprite.setTextureRect(IntRect(0, 100, 400, 100)); 
		Nsprite.setTextureRect(IntRect(0, 300, 400, 100));
		sprite1.setTextureRect(IntRect(0, 500, 400, 100));
		sprite2.setTextureRect(IntRect(0, 700, 400, 100));
	}
}

void ingamestate::display(bool stat)
{
	if (stat == true)
	{
		text.setFillColor(Color::Black);
		text1.setFillColor(Color::Black);
		text2.setFillColor(Color::Black);
		sprite.setColor(Color(255,255,255,255));
		Nsprite.setColor(Color(255, 255, 255, 255));
		sprite1.setColor(Color(255, 255, 255, 255));
		sprite2.setColor(Color(255, 255, 255, 255));
		rect.setFillColor(Color(255, 255, 255, 64));
	}
	else
	{
		text.setFillColor(Color::Transparent);
		text1.setFillColor(Color::Transparent);
		text2.setFillColor(Color::Transparent);
		sprite.setColor(Color(255, 255, 255, 0));
		Nsprite.setColor(Color(255, 255, 255, 0));
		sprite1.setColor(Color(255, 255, 255, 0));
		sprite2.setColor(Color(255, 255, 255, 0));
		rect.setFillColor(Color(0, 0, 0, 0));
	}
}
