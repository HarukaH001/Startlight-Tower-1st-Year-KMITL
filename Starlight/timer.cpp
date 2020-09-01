#include "timer.h"



timer::timer()
{
}

void timer::start()
{
	state = true;
}

void timer::stop()
{
	state = false;
}

void timer::reset()
{
	sec = 0;
	min = 0;
	hour = 0;
	state = false;
}

void timer::update()
{
	if (state)
	{
		if (tick < 60) this->tick += 1;
		if (tick == 60)
		{
			tick = 0;
			if (sec < 60) this->sec += 1;
			if (sec == 60)
			{
				sec = 0;
				if (min < 60) this->min += 1;
				if (min == 60)
				{
					min = 0;
					this->hour += 1;
				}
			}
		}
	}
	t[0] = hour / 10 + '0';
	t[1] = hour % 10 + '0';
	t[2] = ':';
	t[3] = min / 10 + '0';
	t[4] = min % 10 + '0';
	t[5] = ':';
	t[6] = sec / 10 + '0';
	t[7] = sec % 10 + '0';
	if (hour < 10) t[0] = ' ';
	if (min < 10) t[3] = ' ';
	if (sec < 10) t[6] = ' ';
	t[8] = '\0';
}