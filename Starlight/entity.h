#pragma once

#ifndef _InstallingSFML_entity_
#define _InstallingSFML_entity_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <time.h>
#include <vector>
using std::vector;
using namespace sf;

	class entity
	{
	public:
		// weapon class + different weapon in each class
		// class : 0 = sword; 1 = axe; 2 = spear; 3 = bow; 4 = staff; 
		// index : 0 = wooden;
		int weapon_atkSpeed[5][5] = {	{ 60,	65,		75,		80, 	90 },
										{ 50,	55,		65,		70,		80 },
										{ 100,	110,	125,	135,	155 },
										{ 80,	88,		100,		110,		120 },
										{ 40,	45,		52,		58,		65 } };
		int weapon_atkDmg[5][5] = {		{ 4,	5,		9,		12,		15  },
										{ 6,	7,		11,		14,		18 },
										{ 3,	4,		8,		12,		15 },
										{ 3,	4,		8,		11,		15 },
										{ 8,	9,		15,		18,		22 } };
		int weapon_range[5][5] = {		{ 56,	56,		56,		64,		78 },
										{ 44,	44,		44,		50,		64 },
										{ 128,	128,	128,	144,	196},
										{ 288,	288,	288,	302,	336 },
										{ 192,	192,	192,	208,	240 } };
		int effect_texture[5][5][4] = { 
		{{ 0,	0,		64,		64 },{ 0,	0,		64,		64 },{ 0,	0,		64,		64 },{ 0,	0,		64,		64 },{ 0,	0,		64,		64 }},
		{{ 0,	0,		64,		64 },{ 0,	0,		64,		64 },{ 0,	0,		64,		64 },{ 0,	0,		64,		64 },{ 0,	0,		64,		64 }},
		{{ 0,	64,		64,		64 },{ 0,	64,		64,		64 },{ 0,	64,		64,		64 },{ 0,	64,		64,		64 },{ 0,	64,		64,		64 }},
		{{ 0,	128,	64,		64 },{ 0,	128,	64,		64 },{ 0,	128,	64,		64 },{ 0,	128,	64,		64 },{ 0,	128,	64,		64 }},
		{{ 0,	192,	64,		64 },{ 0,	192,	64,		64 },{ 0,	192,	64,		64 },{ 0,	192,	64,		64 },{ 0,	192,	64,		64 }} };
		int weapon_texture[5][5][2] = { {{ 0,0},{ 50,0},{ 100,0},{ 150,0 },{ 200,0 }},
										{{ 0,100},{ 50,100 },{ 100,100 },{ 150,100 },{ 200,100 }},
										{{ 0,200},{ 50,200 },{ 100,200 },{ 150,200 },{ 200,200 }},
										{{ 0,300},{ 50,300},{ 100,300 },{ 150,300 },{ 200,300 }},
										{{ 0,400},{ 50,400 },{ 100,400 },{ 150,400 },{ 200,400 }} };
		////
		sf::RectangleShape rect;
		sf::RectangleShape Nrect;
		sf::CircleShape circle;
		sf::CircleShape Ncircle;
		sf::Sprite sprite;
		sf::Sprite sprite1;
		sf::Sprite sprite2;
		sf::Sprite sprite3;
		sf::Sprite sprite4;
		sf::Sprite sprite5;
		sf::Sprite Nsprite;
		sf::Text text;
		sf::Text text1;
		sf::Text text2;
		sf::Text text3;
		sf::Text text4;
		sf::Text text5;
		sf::Text text6;
		sf::Text text7;
		sf::Text text8;
		sf::Text text9;
		sf::Text Ntext; 
	};

#endif