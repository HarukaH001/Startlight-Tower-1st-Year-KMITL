#include "IGUI.h"



IGUI::IGUI()
{
	rect.setSize(Vector2f(215,330));
	rect.setPosition(0, 0);
	rect.setFillColor(Color(255,255,255,0));
	Nrect.setSize(Vector2f(555, 28));
	Nrect.setPosition(0, 0);
	Nrect.setFillColor(Color(255, 255, 255, 0));
	rect.setOutlineThickness(1);
	rect.setOutlineColor(Color::Transparent);
	text.setCharacterSize(36);
	text.setFillColor(Color::Transparent);
	text1.setCharacterSize(36);
	text1.setFillColor(Color::Transparent);
	text2.setCharacterSize(36);
	text2.setFillColor(Color::Transparent);
	text3.setCharacterSize(36);
	text3.setFillColor(Color::Transparent);
	text4.setCharacterSize(36);
	text4.setFillColor(Color::Transparent);
	text5.setCharacterSize(36);
	text5.setFillColor(Color::Transparent);
	text6.setCharacterSize(36);
	text6.setFillColor(Color::Transparent);
	text7.setCharacterSize(36);
	text7.setFillColor(Color::Transparent);
	text8.setCharacterSize(36);
	text8.setFillColor(Color::Transparent);
	text9.setCharacterSize(36);
	text9.setFillColor(Color::Transparent);
}

void IGUI::enemyUI_update(int type, int order, int hp, int max_hp, int reduce, int shield, int shield_state)
{
	t = type;
	o = order;
	h = hp;
	mh = max_hp;
	r = reduce;
	s = shield;
	if (t <= 0) t = 0;
	if (o <= 0) o = 0;
	if (h <= 0) h = 0;
	if (mh <= 0) mh = 0;
	if (r <= 0) r = 0;
	if (s <= 0 || shield_state == 0) s = 0;
	if (t > 9) t = 9;
	if (o > 99) o = 99;
	if (h > 9999) h = 9999;
	if (mh > 9999) mh = 9999;
	if (r > 9999) r = 9999;
	if (s > 9999) s = 9999;
	for (size_t i = 0; i < 46; i++) enemy[i] = '\0';
}
void IGUI::witchUI_update(int order, int hp, int max_hp)
{
	o = order;
	h = hp;
	mh = max_hp;
	if (h <= 0) h = 0;
	if (mh <= 0) mh = 0;
	if (h > 9999) h = 9999;
	if (mh > 9999) mh = 9999;
	for (size_t i = 0; i < 46; i++) enemy[i] = '\0';
}
void IGUI::CenemyUI_update(Vector2f pos, bool boss)
{
	const char I[20] = "The First Witch    ";
	const char II[20] = "The Second Witch   ";
	const char III[20] = "The Third Witch    ";
	const char VI[20] = "The Forth Witch    ";
	const char a[5] = "TYPE";
	const char b[6] = "  HP ";
	const char c[8] = " ARMOR ";
	const char d[9] = " SHIELD ";
	if (boss)
	{
		//
		for (size_t i = 0; i < 19; i++)
		{
			if (o == 1) enemy[i] = I[i];
			if (o == 2) enemy[i] = II[i];
			if (o == 3) enemy[i] = III[i];
			if (o == 4) enemy[i] = VI[i];
		}
		for (size_t i = 19; i < 21; i++) enemy[i] = ' ';
		enemy[21] = h / 1000 + '0';
		enemy[22] = h / 100 % 10 + '0';
		enemy[23] = h / 10 % 10 + '0';
		enemy[24] = h % 10 + '0';
		if (h < 1000) enemy[21] = ' ';
		if (h < 100) enemy[22] = ' ';
		if (h < 10) enemy[23] = ' ';
		enemy[25] = '/';
		enemy[26] = mh / 1000 + '0';
		enemy[27] = mh / 100 % 10 + '0';
		enemy[28] = mh / 10 % 10 + '0';
		enemy[29] = mh % 10 + '0';
		if (mh < 1000) enemy[26] = ' ';
		if (mh < 100) enemy[27] = ' ';
		if (mh < 10) enemy[28] = ' ';
		//
		text8.setCharacterSize(36);
		text8.setPosition(pos.x + 32 + 32*3, pos.y + 64);
		Nrect.setPosition(pos.x + 28, pos.y + 78);
		if (h == 0)
		{
			text8.setFillColor(Color(0, 0, 0, 0));
			Nrect.setFillColor(Color(0, 0, 0, 0));
		}
		else
		{
			text8.setFillColor(Color(0, 0, 0, 224));
			Nrect.setFillColor(Color(255, 255, 255, 64));
		}
		text8.setString(enemy);
	}
	else
	{
		for (size_t i = 0; i < 4; i++) enemy[i] = a[i];
		enemy[4] = t + '0';
		enemy[5] = ':';
		enemy[6] = o / 10 + '0';
		enemy[7] = o % 10 + '0';
		if (o < 10) enemy[6] = ' ';
		for (size_t i = 8; i < 13; i++) enemy[i] = b[i - 8];
		enemy[13] = h / 1000 + '0';
		enemy[14] = h / 100 % 10 + '0';
		enemy[15] = h / 10 % 10 + '0';
		enemy[16] = h % 10 + '0';
		if (h < 1000) enemy[13] = ' ';
		if (h < 100) enemy[14] = ' ';
		if (h < 10) enemy[15] = ' ';
		enemy[17] = '/';
		enemy[18] = mh / 1000 + '0';
		enemy[19] = mh / 100 % 10 + '0';
		enemy[20] = mh / 10 % 10 + '0';
		enemy[21] = mh % 10 + '0';
		if (mh < 1000) enemy[18] = ' ';
		if (mh < 100) enemy[19] = ' ';
		if (mh < 10) enemy[20] = ' ';
		for (size_t i = 22; i < 29; i++) enemy[i] = c[i - 22];
		enemy[29] = s / 1000 + '0';
		enemy[30] = r / 100 % 10 + '0';
		enemy[31] = r / 10 % 10 + '0';
		enemy[32] = r % 10 + '0';
		if (r < 1000) enemy[29] = ' ';
		if (r < 100) enemy[30] = ' ';
		if (r < 10) enemy[31] = ' ';
		for (size_t i = 33; i < 41; i++) enemy[i] = d[i - 33];
		enemy[41] = s / 1000 + '0';
		enemy[42] = s / 100 % 10 + '0';
		enemy[43] = s / 10 % 10 + '0';
		enemy[44] = s % 10 + '0';
		if (s < 1000) enemy[41] = ' ';
		if (s < 100) enemy[42] = ' ';
		if (s < 10) enemy[43] = ' ';
		text8.setCharacterSize(36);
		text8.setPosition(pos.x + 32, pos.y + 64);
		Nrect.setPosition(pos.x + 28, pos.y + 78);
		if (h == 0)
		{
			text8.setFillColor(Color(0, 0, 0, 0));
			Nrect.setFillColor(Color(0, 0, 0, 0));
		}
		else
		{
			text8.setFillColor(Color(0, 0, 0, 224));
			Nrect.setFillColor(Color(255, 255, 255, 64));
		}
		text8.setString(enemy);
	}
	
}
void IGUI::charUI_update(Vector2f pos, int atk, int def, int shield, int floor, int hp, int mob, const char* t, int score)
{
	if (Keyboard::isKeyPressed(Keyboard::Tab) && counter == 0)
	{
		if (charUI_state == 0) charUI_state = 1;
		else charUI_state = 0;
		counter = 10;
	}
	if (charUI_state == 1)
	{
		if (hp <= 0) hp = 0;
		if (shield <= 0) shield = 0;
		rect.setPosition(pos.x - 300, pos.y - 330);
		rect.setFillColor(Color(255, 255, 255, 64));
		//weapon
		text.setCharacterSize(32);
		text.setPosition(pos.x - 285, pos.y - 325);
		text.setFillColor(Color(0, 0, 0, 160));
		text.setString("        Status");
		//atk
		text1.setPosition(pos.x - 285,pos.y - 295);
		text1.setFillColor(Color(0, 0, 0, 160));
		do_temp(atk, "Attack ", returned1);
		text1.setString(returned1);
		//def
		text2.setPosition(pos.x - 285, pos.y - 265);
		text2.setFillColor(Color(0, 0, 0, 160));
		do_temp(def, "Def    ", returned2);
		text2.setString(returned2);
		//shield
		text3.setPosition(pos.x - 285, pos.y - 235);
		text3.setFillColor(Color(0, 0, 0, 160));
		do_temp(shield, "Shield ", returned3);
		text3.setString(returned3);
		//hp
		text4.setCharacterSize(42);
		text4.setPosition(pos.x - 285, pos.y - 205);
		text4.setFillColor(Color(0, 0, 0, 160));
		do_temp(hp, "Health ", returned4);
		text4.setString(returned4);
		//floor
		text5.setPosition(pos.x - 285, pos.y - 155);
		text5.setFillColor(Color(0, 0, 0, 160));
		do_temp(floor, "Floor  ", returned5);
		text5.setString(returned5);
		//Mob left
		text6.setPosition(pos.x - 285, pos.y - 125);
		text6.setFillColor(Color(0, 0, 0, 160));
		do_temp(mob, "Mob    ", returned6);
		text6.setString(returned6);
		//timer
		text7.setCharacterSize(42);
		text7.setPosition(pos.x - 285, pos.y - 95);
		text7.setFillColor(Color(0, 0, 0, 160));
		do_time(t, "Time   ", returned7);
		text7.setString(returned7);
		//Score
		text9.setCharacterSize(42);
		text9.setPosition(pos.x - 285, pos.y - 65);
		text9.setFillColor(Color(0, 0, 0, 160));
		do_temp(score, "Score  ", returned9);
		text9.setString(returned9);
	}
	else
	{
		rect.setFillColor(Color::Transparent);
		rect.setOutlineColor(Color::Transparent);
		rect.setOutlineColor(Color::Transparent);
		text.setFillColor(Color::Transparent);
		text1.setFillColor(Color::Transparent);
		text2.setFillColor(Color::Transparent);
		text3.setFillColor(Color::Transparent);
		text4.setFillColor(Color::Transparent);
		text5.setFillColor(Color::Transparent);
		text6.setFillColor(Color::Transparent);
		text7.setFillColor(Color::Transparent);
		text8.setFillColor(Color::Transparent);
		text9.setFillColor(Color::Transparent);
	}
	if (counter != 0)
	{
		this->counter -= 1;
	}
}

void IGUI::do_temp(int input, const char* string, char* c)
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

void IGUI::do_time(const char* arg, const char* string, char* c)
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