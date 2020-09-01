#pragma once
#include "entity.h"

class ingamestate : public entity
{
public:
	int counter = 0;
	char returned[20];
	char returned1[20];
	ingamestate();
	void display(bool stat);
	void do_score(int score, const char* timer);
	void do_time(const char* arg, const char* string, char* c);
	void do_temp(int input, const char* string, char* c);
	int click(int which);
};

