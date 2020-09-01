#include "displayText.h"



displayText::displayText()
{
	//dmg
	text.setCharacterSize(32);
	text.setFillColor(Color::Red);
	//item pick effect
	/*	bomb-nothing
		armor-armor up
		flint'n steel-atk up(show countdown)
		cross-half heal
		green gem-full heal
		yellow gem-max hp up
		red gem-atk up
		blue gem-reduce up*/
	//flint'n steel time up
	/*	atk down*/
	//armor break
	/*	armor break*/
}
void displayText::item(Vector2f pos, const char* input, int color_code)
{
	if (color_code == 0) text.setFillColor(Color::Red);
	else if (color_code == 1) text.setFillColor(Color::Green);
	else if (color_code == 2) text.setFillColor(Color::Blue);
	else if (color_code == 3) text.setFillColor(Color::Yellow);
	text.setPosition(pos.x + rand_gen_ptp(-64, 64), pos.y - 64);
	text.setString(input);
	counter = 50;
}
void displayText::dmg(Vector2f pos , int input , int color_code)
{
	for (size_t i = 0; i < 10; i++)
	{
		string[i] = '\0';
	}
	if(color_code == 0) text.setFillColor(Color::Red);
	else if (color_code == 1) text.setFillColor(Color::Green);
	else if (color_code == 2) text.setFillColor(Color::Blue);
	else if (color_code == 3) text.setFillColor(Color::Yellow);
	text.setPosition(pos.x + rand_gen_ptp(-64,64), pos.y - 64);
	if (color_code != 1)
	{
		if(input > 0)
		input = 0;
	}
	if (input < 0)
	{
		string[0] = '-';
		input = -input;
	}
	else
	{
		if(input != 0)
		string[0] = '+';
	}
	if (input > 999)
	{
		string[1] = input / 1000 + '0';
		string[2] = (input /100) %10 + '0';
		string[3] = (input / 10) % 10 + '0';
		string[4] = input % 10 + '0';
	}
	else if (input > 99)
	{
		string[1] = input / 100 + '0';
		string[2] = (input / 10) % 10 + '0';
		string[3] = input % 10 + '0';
	}
	else if (input > 9)
	{
		string[1] = input / 10 + '0';
		string[2] = input % 10 + '0';
	}
	else
	{
		if (input != 0)
		string[1] = input + '0';
		else
		string[0] = input + '0';
	}
	text.setString(string);
	counter = 50;
}

void displayText::display()
{
	//dmg
	if (counter != 0)
	{
		this->counter -= 1;
		text.move(0,-0.32);
	}
}
