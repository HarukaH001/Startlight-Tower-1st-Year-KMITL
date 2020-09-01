#pragma once
#include "entity.h"
class IGUI : public entity
{
public:
	bool hit_boss = false;
	int charUI_state = 0; // 0 = off 1 = on ;
	int counter = 0;
	int t = 0;
	int o = 0;
	int h = 0;
	int mh = 0;
	int r = 0;
	int s = 0;
	char returned[20];
	char returned1[20];
	char returned2[20];
	char returned3[20];
	char returned4[20];
	char returned5[20];
	char returned6[20];
	char returned7[20];
	char returned9[20];
	char enemy[45];
	IGUI();
	void enemyUI_update(int type, int order, int hp, int max_hp, int reduce, int shield, int shield_state);
	void witchUI_update(int order,int hp, int max_hp);
	void CenemyUI_update(Vector2f pos, bool boss);
	void charUI_update(Vector2f pos,int atk, int def, int shield, int floor, int hp, int mob, const char* t, int score);
	void do_time(const char* arg, const char* string, char* c);
	void do_temp(int input, const char* string, char* c);
};

