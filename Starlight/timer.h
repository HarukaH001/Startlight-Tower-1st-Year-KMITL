#pragma once
#include "entity.h"
class timer : public entity
{
public:
	char t[9];
	int sec = 0;
	int min = 0;
	int hour = 0;
	int tick = 0;
	bool state = false;
	timer();
	void start();
	void stop();
	void reset();
	void update();
};

