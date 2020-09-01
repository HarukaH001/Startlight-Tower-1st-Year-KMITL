#pragma once
#include "entity.h"
#include "rng.h"
class displayText : public entity , rng
{
public:
	int counter = 0;
	char string[10] = "";
	displayText();
	void item(Vector2f pos, const char* input, int color_code);
	void dmg(Vector2f pos, int input, int color_code);
	void display();
};

