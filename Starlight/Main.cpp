#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "player.h"
#include "atk.h"
#include "rng.h"
#include "enemy.h"
#include "enemy2.h"
#include "enemy3.h"
#include "enemy_atk.h"
#include "enemy2_atk.h"
#include "enemy3_atk.h"
#include "Collision.h"
#include "DesktopResolution.h"
#include "item.h"
#include "explosion.h"
#include "displayText.h"
#include "IGUI.h"
#include "ingamestate.h"
#include "floor.h"
#include "witch.h"
#include "witch1atk.h"
#include "witch2atk.h"
#include "witch3atk.h"
#include "witch4atk.h"
#include "timer.h"
using namespace Collision;
FILE *ranking;
Texture textureHow;
Texture textureBack00;
Texture textureBack01;
Texture textureRanking;
Texture textureBack0;
Texture textureBack;
Texture textureHigh;
Texture textureTextField;
Texture textureTag;
Texture textureMenu;
Texture textureStart;
Texture textureStart0;
Texture textureQuit;
Texture textureQuit0;
Texture textureRank;
Texture textureRank0;
Texture textureHowto;
Texture textureHowto0;
Texture textureFire;
Texture textureActiveBeam;
Texture texturePassiveBeam;
Texture textureWind;
Texture textureGale;
Texture textureVortex;
Texture texturePillar;
Texture textureWater;
Texture textureWave;
Texture textureRock;
Texture textureBlock;
Texture textureWitch;
Texture texturePlayer;
Texture texturePortal;
Texture textureEnemy;
Texture textureBackground;
Texture textureOverride;
Texture textureWall;
Texture textureEffect;
Texture textureItem;
Texture textureExplosion;
Texture texturePointer;
Texture textureCrosshair;
Texture textureDirectory;
Texture textureIngamestate;
Texture textureGate;
Sprite spriteHow;
Sprite spriteBack00;
Sprite spriteBack01;
Sprite spriteRanking;
Sprite spriteBack0;
Sprite spriteBack;
Sprite spriteHigh;
Sprite spriteTextField;
Sprite spriteTag;
Sprite spriteMenu;
Sprite spriteStart;
Sprite spriteStart0;
Sprite spriteQuit;
Sprite spriteQuit0;
Sprite spriteRank;
Sprite spriteRank0;
Sprite spriteHowto;
Sprite spriteHowto0;
Sprite spritePointer;
Sprite spriteCrosshair;
Sprite spriteLeftWall;
Sprite spriteRightWall;
Sprite spriteTopWall;
Sprite spriteDownWall;
Sprite spriteBackground;
Sprite spriteOverride;
Sprite spriteGate;
Sprite spriteRing;
Text floor_screen;
Font font;
Vector2f pos;
Vector2f Epos;
Vector2f E2pos;
Vector2f E3pos;
Vector2f Wpos;
Vector2f Mpos;
Vector2f Ipos;
Vector2f center;
Vector2u windowSize;
char line1[15];
char line2[15];
char line3[15];
char line4[15];
char line5[15];
char line6[15];
char line7[15];
char line8[15];
char line9[15];
char line10[15];
char line11[15];
char line12[15];
char line13[15];
char line14[15];
char line15[15];
char line1_1[15];
char line1_2[15];
char line1_3[15];
char line2_1[15];
char line2_2[15];
char line2_3[15];
char line3_1[15];
char line3_2[15];
char line3_3[15];
char line4_1[15];
char line4_2[15];
char line4_3[15];
char line5_1[15];
char line5_2[15];
char line5_3[15];
int hrs1 = 0;
int hrs2 = 0;
int hrs3 = 0;
int hrs4 = 0;
int hrs5 = 0;
int min1 = 0;
int min2 = 0;
int min3 = 0;
int min4 = 0;
int min5 = 0;
int sec1 = 0;
int sec2 = 0;
int sec3 = 0;
int sec4 = 0;
int sec5 = 0;
int sIn1 = 0;
int sIn2 = 0;
int sIn3 = 0;
int sIn4 = 0;
int sIn5 = 0;
int sOut = 0;
bool cursorVisible = false;
bool vsync = true;
int fps = 60;
int window_style = 0;
int hit_count = 30;	//60 count per sec //0.5 sec = 30 count
int total_mob = 0;
int normal_mob = 0;
int boss_mob = 0;
int witch_dead = 0;
int score = 0;
int key = 0;
bool ingamestate = true;
bool start = false;
bool howto = false;
bool rank = false;
bool highscore = false;
bool enterName = false;
String name;
Text playerName;
Text l1;
Text l2;
Text l3;
Text l4;
Text l5;
Text l6;
Text l7;
Text l8;
Text l9;
Text l10;
Text l11;
Text l12;
Text l13;
Text l14;
Text l15;
char cname[15];
char floorText[9] = "Floor ";
bool do_rank(char* t, const char* n, int score, int hrs, int min, int sec);
int convertToInt(char* input);
void convertToStr(int input, char* returned);
void convertTime(char* input,int* h, int* m, int* s);
void convertToSec(int* sout, int h, int m, int s);
void add0(char* input);
//
Music menu;
Music ingame;
Music boss1;
Music boss2;
Music boss3;
Music boss4;
Music end;
SoundBuffer bufferEvasion;
SoundBuffer bufferExplodeAndMagic;
SoundBuffer bufferAttack;
SoundBuffer bufferPick;
SoundBuffer bufferWitchAtk;
Sound explodeSF;
Sound pickSF;
//
int main()
{
	FreeConsole();
	class timer t;
	class DesktopResolution res;
	//initializing
	res.GetDesktopResolution(res.horizontal,res.vertical);
	RenderWindow window(VideoMode(res.horizontal, res.vertical), "Starlight", Style::Fullscreen);
	window.setFramerateLimit(fps);
	window.setVerticalSyncEnabled(vsync);
	windowSize = window.getSize();
	window.setMouseCursorVisible(cursorVisible);
	View view(Vector2f(0, 0), Vector2f((res.horizontal /24) *20, (res.vertical / 24) * 20));  ///0.83 multiplier

	//Load Musics
	if (!menu.openFromFile("Resource/sfx/bg/menu.wav")) { printf_s(" menu music error\n"); }
	if (!ingame.openFromFile("Resource/sfx/bg/ingame.wav")) { printf_s(" ingame music error\n"); }
	if (!end.openFromFile("Resource/sfx/bg/end.wav")) { printf_s(" end music error\n"); }
	if (!boss1.openFromFile("Resource/sfx/bg/boss1.wav")) { printf_s(" boss1 music error\n"); }
	if (!boss2.openFromFile("Resource/sfx/bg/boss2.wav")) { printf_s(" boss2 music error\n"); }
	if (!boss3.openFromFile("Resource/sfx/bg/boss3.wav")) { printf_s(" boss3 music error\n"); }
	if (!boss4.openFromFile("Resource/sfx/bg/boss4.wav")) { printf_s(" boss4 music error\n"); }
	menu.setLoop(true); menu.setVolume(60);
	ingame.setLoop(true); ingame.setVolume(30);
	end.setLoop(true); end.setVolume(40);
	boss1.setLoop(true); boss1.setVolume(30);
	boss2.setLoop(true); boss2.setVolume(30);
	boss3.setLoop(true); boss3.setVolume(30);
	boss4.setLoop(true); boss4.setVolume(30);
	//Load SFX
	if (!bufferEvasion.loadFromFile("Resource/sfx/evasion/slide.ogg")) { printf_s("evasion sfx error\n"); }
	if (!bufferExplodeAndMagic.loadFromFile("Resource/sfx/explode and magic/explode and magic.ogg")) { printf_s("explode and magic sfx error\n"); }
	if (!bufferAttack.loadFromFile("Resource/sfx/atk/atk.ogg")) { printf_s("atk sfx error\n"); }
	if (!bufferPick.loadFromFile("Resource/sfx/pick/pick.ogg")) { printf_s("pick sfx error\n"); }
	if (!bufferWitchAtk.loadFromFile("Resource/sfx/boss atk/witch.ogg")) { printf_s("witch attack sfx error\n"); }
	explodeSF.setBuffer(bufferExplodeAndMagic);
	pickSF.setBuffer(bufferPick);

	//Load Font
	if (!font.loadFromFile("Resource/font.ttf")) { printf_s(" font error\n"); }
	playerName.setFont(font);
	playerName.setCharacterSize(64);
	playerName.setFillColor(Color::Black);
	//Load Tag
	if (!textureTag.loadFromFile("Resource/tag.png")) { printf_s(" tag error\n"); }
	spriteTag.setTexture(textureTag);
	//Load Crosshair
	if (!textureCrosshair.loadFromFile("Resource/crosshair.png")) { printf_s(" crosshair error\n"); }
	textureCrosshair.setSmooth(true);
	spriteCrosshair.setTexture(textureCrosshair);
	spriteCrosshair.setOrigin(25, 25);
	//Load Pointer
	if (!texturePointer.loadFromFile("Resource/pointer.png")) { printf_s(" pointer error\n"); }
	texturePointer.setSmooth(true);
	spritePointer.setTexture(texturePointer);
	//Load Text Field
	if (!textureTextField.loadFromFile("Resource/text field.png")) { printf_s(" text field error\n"); }
	textureTextField.setSmooth(true);
	spriteTextField.setTexture(textureTextField);
	spriteTextField.setOrigin(1280, 722);
	//Load High score tag
	if (!textureHigh.loadFromFile("Resource/high.png")) { printf_s(" high score tag error\n"); }
	textureHigh.setSmooth(true);
	spriteHigh.setTexture(textureHigh);
	spriteHigh.setOrigin(125,125);
	//Load Ranking
	if (!textureRanking.loadFromFile("Resource/ranking.png")) { printf_s(" ranking error\n"); }
	textureRanking.setSmooth(true);
	spriteRanking.setTexture(textureRanking);
	spriteRanking.setOrigin(1280, 722);
	//Load Back0
	if (!textureBack0.loadFromFile("Resource/back no click.png")) { printf_s(" back no click error\n"); }
	textureBack0.setSmooth(true);
	spriteBack0.setTexture(textureBack0);
	spriteBack0.setOrigin(1280, 722);
	//Load Back
	if (!textureBack.loadFromFile("Resource/back click.png")) { printf_s(" back click error\n"); }
	textureBack.setSmooth(true);
	spriteBack.setTexture(textureBack);
	spriteBack.setOrigin(1280, 722);
	//Load Howto screen
	if (!textureHow.loadFromFile("Resource/how.png")) { printf_s(" how to screen error\n"); }
	textureHow.setSmooth(true);
	spriteHow.setTexture(textureHow);
	spriteHow.setOrigin(1280, 722);
	//Load Back00
	if (!textureBack00.loadFromFile("Resource/back00 no click.png")) { printf_s(" back00 no click error\n"); }
	textureBack00.setSmooth(true);
	spriteBack00.setTexture(textureBack00);
	spriteBack00.setOrigin(1280, 722);
	//Load Back01
	if (!textureBack01.loadFromFile("Resource/back01 click.png")) { printf_s(" back01 click error\n"); }
	textureBack01.setSmooth(true);
	spriteBack01.setTexture(textureBack01);
	spriteBack01.setOrigin(1280, 722);

	//Load Char
	if (!texturePlayer.loadFromFile("Resource/char.png")) { printf_s(" char error\n"); }
	if (!texturePortal.loadFromFile("Resource/portal.png")) { printf_s(" portal error\n"); }
	//Load Background
	if (!textureBackground.loadFromFile("Resource/bg.png")) { printf_s("bg error\n"); }
	if (!textureOverride.loadFromFile("Resource/override.png")) { printf_s("override error\n"); }
	textureBackground.setSmooth(true);
	textureOverride.setSmooth(true);
	spriteOverride.setTexture(textureOverride);
	spriteOverride.setPosition(-448, -272);
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(-448, -272);

	//Load Wall
	if (!textureWall.loadFromFile("Resource/wall.png")) { printf_s(" wall error\n"); }
	textureWall.setSmooth(true);
	spriteLeftWall.setTexture(textureWall); spriteLeftWall.setTextureRect(IntRect(550, 0, 25, 1440)); spriteLeftWall.setPosition(575, 0); spriteLeftWall.setColor(Color(255, 255, 255, 0));
	spriteRightWall.setTexture(textureWall); spriteRightWall.setTextureRect(IntRect(1975, 0, 25, 1440)); spriteRightWall.setPosition(2000, 0); spriteRightWall.setColor(Color(255, 255, 255, 0));
	spriteTopWall.setTexture(textureWall); spriteTopWall.setTextureRect(IntRect(575, 0, 1440, 25)); spriteTopWall.setPosition(575, 0); spriteTopWall.setColor(Color(255, 255, 255, 0));
	spriteDownWall.setTexture(textureWall); spriteDownWall.setTextureRect(IntRect(575, 0, 1440, 25)); spriteDownWall.setPosition(575, 1415); spriteDownWall.setColor(Color(255, 255, 255, 0));

	//Load Item
	if (!textureItem.loadFromFile("Resource/item.png")) { printf_s("item error\n"); }

	//Load Weapon
	if (!textureDirectory.loadFromFile("Resource/directory.png")) { printf_s("directory error\n"); }

	//Load Effect
	if (!textureEffect.loadFromFile("Resource/effect.png")) { printf_s("effect error\n"); }
	textureEffect.setSmooth(true);

	//Load Ingamestate
	if (!textureIngamestate.loadFromFile("Resource/ingamestate_button.png")) { printf_s("ingamestate_button error\n"); }

	//Load Gate
	if (!textureGate.loadFromFile("Resource/gate.png")) { printf_s("gate error\n"); }
	spriteRing.setTexture(textureGate);
	spriteRing.setOrigin(32, 32);
	spriteRing.setTextureRect(IntRect(0,0,64,64));
	spriteGate.setTexture(textureGate);
	spriteGate.setOrigin(32, 32);
	spriteGate.setTextureRect(IntRect(64, 0, 64, 64));
	spriteRing.setColor(Color::Transparent);
	spriteGate.setColor(Color::Transparent);
	spriteRing.setPosition(1280, 1368);
	spriteGate.setPosition(1280, 1368);

	//Load Explosion
	if (!textureExplosion.loadFromFile("Resource/explosion.png")) { printf_s("explosion error\n"); }
	textureExplosion.setSmooth(true);

	//Load Enemy
	if (!textureEnemy.loadFromFile("Resource/char.png")) { printf_s("enemy error\n"); }
	vector<enemy> enemyArray;
	vector<enemy2> enemy2Array;
	vector<enemy3> enemy3Array;
	vector<explosion> explodeArray;
	if (!textureWitch.loadFromFile("Resource/witch.png")) { printf_s("witch error\n"); }
	vector<witch> witchi;

	//Load Rock
	if (!textureRock.loadFromFile("Resource/rock.png")) { printf_s("rock error\n"); }
	vector<witch1atk> witch1atkArray;
	//Load Block
	if (!textureBlock.loadFromFile("Resource/block.png")) { printf_s("block error\n"); }
	vector<witch1atk> witch1atk2Array;
	//Load Water
	if (!textureWater.loadFromFile("Resource/water.png")) { printf_s("water error\n"); }
	vector<witch2atk> witch2atkArray;
	//Load Wave
	if (!textureWave.loadFromFile("Resource/wave.png")) { printf_s("wave error\n"); }
	vector<witch2atk> witch2atk2Array;
	//Load Wind
	if (!textureWind.loadFromFile("Resource/wind.png")) { printf_s("wind error\n"); }
	vector<witch3atk> witch3atkArray;
	//Load Gale
	if (!textureGale.loadFromFile("Resource/gale.png")) { printf_s("gale error\n"); }
	vector<witch3atk> witch3atk2Array;
	//Load Vortex
	if (!textureVortex.loadFromFile("Resource/vortex.png")) { printf_s("vortex error\n"); }
	vector<witch3atk> witch3defArray;
	//Load Pillar
	if (!texturePillar.loadFromFile("Resource/pillar.png")) { printf_s("pillar error\n"); }
	vector<witch3atk> witch3def2Array;
	//Load Fire
	if (!textureFire.loadFromFile("Resource/fire.png")) { printf_s("fire error\n"); }
	vector<witch4atk> witch4atkArray;
	//Load Active Beam
	if (!textureActiveBeam.loadFromFile("Resource/active beam.png")) { printf_s("active beam error\n"); }
	//Load Passive Beam
	if (!texturePassiveBeam.loadFromFile("Resource/passive beam.png")) { printf_s("passive beam error\n"); }
	//Load Menu
	if (!textureMenu.loadFromFile("Resource/meni.png")) { printf_s("menu error\n"); }
	//Load Start
	if (!textureStart.loadFromFile("Resource/start.png")) { printf_s("start error\n"); }
	//Load Quit
	if (!textureQuit.loadFromFile("Resource/quit.png")) { printf_s("quit error\n"); }
	//Load Howto
	if (!textureHowto.loadFromFile("Resource/howto.png")) { printf_s("howto error\n"); }
	//Load Rank
	if (!textureRank.loadFromFile("Resource/rank.png")) { printf_s("rank error\n"); }
	//Load Start0
	if (!textureStart0.loadFromFile("Resource/start0.png")) { printf_s("start error\n"); }
	//Load Quit0
	if (!textureQuit0.loadFromFile("Resource/quit0.png")) { printf_s("quit0 error\n"); }
	//Load Howto0
	if (!textureHowto0.loadFromFile("Resource/howto0.png")) { printf_s("howto0 error\n"); }
	//Load Rank0
	if (!textureRank0.loadFromFile("Resource/rank0.png")) { printf_s("rank0 error\n"); }
	//bunches of staff
	spriteMenu.setTexture(textureMenu);
	spriteStart.setTexture(textureStart);
	spriteStart0.setTexture(textureStart0);
	spriteQuit.setTexture(textureQuit);
	spriteQuit0.setTexture(textureQuit0);
	spriteRank.setTexture(textureRank);
	spriteRank0.setTexture(textureRank0);
	spriteHowto.setTexture(textureHowto);
	spriteHowto0.setTexture(textureHowto0);
	spriteMenu.setOrigin(1280,722);
	spriteStart.setOrigin(1280, 722);
	spriteStart0.setOrigin(1280, 722);
	spriteQuit.setOrigin(1280, 722);
	spriteQuit0.setOrigin(1280, 722);
	spriteRank.setOrigin(1280, 722);
	spriteRank0.setOrigin(1280, 722);
	spriteHowto.setOrigin(1280, 722);
	spriteHowto0.setOrigin(1280, 722);

	//Set the text
	floor_screen.setFont(font);
	floor_screen.setFillColor(Color::Transparent);
	floor_screen.setCharacterSize(72);
	floor_screen.setPosition(1280, 720);

	class rng rng;

	class witch witch;
	class enemy enemy;
	class enemy2 enemy2;
	class enemy3 enemy3;
	witch.sprite.setTexture(textureWitch);
	enemy.sprite.setTexture(textureEnemy);
	enemy2.sprite.setTexture(textureEnemy);
	enemy3.sprite.setTexture(textureEnemy);

	class witch1atk witch1atk;
	class witch2atk witch2atk;
	class witch3atk witch3atk;
	class witch4atk witch4atk;
	class enemy_atk eneatk;
	class enemy2_atk ene2atk;
	class enemy3_atk ene3atk;
	witch1atk.sprite.setTexture(textureRock);
	witch1atk.sprite1.setTexture(textureBlock);
	witch1atk.atkSF.setBuffer(bufferWitchAtk);
	witch1atk.atkSF.setVolume(40);
	witch2atk.sprite.setTexture(textureWater);
	witch2atk.sprite1.setTexture(textureWave);
	witch2atk.atkSF.setBuffer(bufferWitchAtk);
	witch2atk.atkSF.setVolume(40);
	witch3atk.sprite.setTexture(textureWind);
	witch3atk.sprite1.setTexture(textureGale);
	witch3atk.sprite2.setTexture(textureVortex);
	witch3atk.sprite3.setTexture(texturePillar);
	witch3atk.atkSF.setBuffer(bufferWitchAtk);
	witch3atk.atkSF.setVolume(40);
	witch4atk.sprite.setTexture(textureFire);
	witch4atk.sprite1.setTexture(textureActiveBeam);
	witch4atk.sprite2.setTexture(texturePassiveBeam);
	witch4atk.atkSF.setBuffer(bufferWitchAtk);
	witch4atk.atkSF.setVolume(40);
	eneatk.Nsprite.setTexture(textureEffect);
	ene2atk.Nsprite.setTexture(textureEffect);
	ene3atk.Nsprite.setTexture(textureEffect);
	eneatk.sprite.setTexture(textureDirectory);
	ene2atk.sprite.setTexture(textureDirectory);
	ene3atk.sprite.setTexture(textureDirectory);
	vector<enemy_atk> eneatkArray;
	vector<enemy2_atk> ene2atkArray;
	vector<enemy3_atk> ene3atkArray;

	class player player1;
	player1.sprite.setTexture(texturePlayer);
	player1.Nsprite.setTexture(texturePortal);
	player1.init(0, 0);
	player1.evasion.setBuffer(bufferEvasion);
	player1.evasion.setVolume(30);
	player1.magic.setBuffer(bufferExplodeAndMagic);

	class atk atk1;
	atk1.sprite.setTexture(textureEffect);
	atk1.Nsprite.setTexture(textureDirectory);
	atk1.update(player1.weapon_class, player1.weapon_rank);
	vector<item> itemArray;
	atk1.atkSF.setBuffer(bufferAttack);
	atk1.atkSF.setVolume(60);

	class item item;
	item.sprite.setTexture(textureItem);

	class explosion explode;
	explode.sprite.setTexture(textureExplosion);

	class displayText dis;
	dis.text.setFont(font);
	vector<displayText> disArray;

	class IGUI ingameui;
	ingameui.text.setFont(font);
	ingameui.text1.setFont(font);
	ingameui.text2.setFont(font);
	ingameui.text3.setFont(font);
	ingameui.text4.setFont(font);
	ingameui.text5.setFont(font);
	ingameui.text6.setFont(font);
	ingameui.text7.setFont(font);
	ingameui.text8.setFont(font);
	ingameui.text9.setFont(font);

	class ingamestate igstate;
	igstate.text.setFont(font);
	igstate.text1.setFont(font);
	igstate.text2.setFont(font);
	igstate.sprite.setTexture(textureIngamestate);
	igstate.Nsprite.setTexture(textureIngamestate);
	igstate.sprite1.setTexture(textureIngamestate);
	igstate.sprite2.setTexture(textureIngamestate);

	class flooring fl;

	// gameloop
	while (window.isOpen())
	{
		//Global sequences
		//event sequences
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) { window.close(); }
			if (event.type == Event::KeyPressed &&event.key.code == Keyboard::F11)
			{
				if (window_style == 0) { window_style = 1; window.create(VideoMode(res.horizontal, res.vertical), "Starlight"); }
				else if (window_style == 1) { window_style = 0; window.create(VideoMode(res.horizontal, res.vertical), "Starlight", Style::Fullscreen); }
				window.setFramerateLimit(fps);
				window.setVerticalSyncEnabled(vsync);
				windowSize = window.getSize();
				window.setMouseCursorVisible(cursorVisible);
			}
		}
		Re:
		// get mouse position
		Mpos = window.mapPixelToCoords(Mouse::getPosition(window));
		// get view center
		center = view.getCenter();
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(start)
		{
		if (fl.floor != fl.lastfloor && fl.reset == 0 && fl.floor < 28)
		{
			floorText[6] = (fl.floor+1) / 10 + '0';
			floorText[7] = (fl.floor + 1) % 10 + '0';
			floorText[8] = '\0';
			floor_screen.setString(floorText);
			if(fl.floor != 0) floor_screen.setPosition(center.x+100, center.y+100);
			for (size_t i = 0; i < 255; i++)
			{
				floor_screen.setFillColor(Color(0, 0, 0, i));
				igstate.rect.setFillColor(Color(255, 255, 255, i));
				window.draw(igstate.rect);
				window.draw(floor_screen);
				window.display();
				Sleep(5);
			}
			//clear all array in place
			witch1atkArray.clear();
			witch1atk2Array.clear();
			witch2atkArray.clear();
			witch2atk2Array.clear();
			witch3atkArray.clear();
			witch3atk2Array.clear();
			witch3defArray.clear();
			witch3def2Array.clear();
			witch4atkArray.clear();
			eneatkArray.clear();
			ene2atkArray.clear();
			ene3atkArray.clear();
			//player init
			player1.sprite.setPosition(1280, 1368);
			player1.floor_atk = fl.all_floor_atk[fl.floor];
			player1.floor_maxhp = fl.player_floor_mh[fl.floor];
			if(fl.floor != 0)
			player1.hp += fl.player_floor_mh[fl.floor] - fl.player_floor_mh[fl.floor - 1];
			player1.status(player1.weapon_class,player1.weapon_rank);
			if (fl.floor == 0)
			player1.hp = player1.max_hp;
			//enemy						
			while (enemyArray.size() < fl.type1[fl.floor])
			{
				enemy.floor_atk = fl.all_floor_atk[fl.floor];
				enemy.floor_maxhp = fl.type1_floor_mh[fl.floor];
				enemy.update(windowSize);
				enemy.drop();
				eneatk.update(enemy.getClass(), enemy.getRank());
				eneatkArray.push_back(eneatk);
				enemyArray.push_back(enemy);
			}
			while (enemy2Array.size() < fl.type2[fl.floor])
			{
				enemy2.floor_atk = fl.all_floor_atk[fl.floor];
				enemy2.floor_maxhp = fl.type2_floor_mh[fl.floor];
				enemy2.update(windowSize);
				enemy2.drop();
				ene2atk.update(enemy2.getClass(), enemy2.getRank());
				ene2atkArray.push_back(ene2atk);
				enemy2Array.push_back(enemy2);
			}
			while (enemy3Array.size() < fl.type3[fl.floor])
			{
				enemy3.floor_atk = fl.all_floor_atk[fl.floor];
				enemy3.floor_maxhp = fl.type3_floor_mh[fl.floor];
				enemy3.update(windowSize);
				enemy3.drop();
				ene3atk.update(enemy3.getClass(), enemy3.getRank());
				ene3atkArray.push_back(ene3atk);
				enemy3Array.push_back(enemy3);
			}
			witch_dead = 0;
			//clear bomb and magic
			explodeArray.clear();
			player1.magic_duration = 0;
			//close the gate
			spriteRing.setColor(Color::Transparent);
			spriteGate.setColor(Color::Transparent);
			//clear remaining items
			itemArray.clear();
			//save last floor
			fl.lastfloor = fl.floor;
			fl.reset = 1;
			floor_screen.setFillColor(Color(0, 0, 0, 0));
			window.draw(floor_screen);
			window.display();
			t.start();
		}
		if (fl.reset == 1)
		{
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//pause & continue
			if (Keyboard::isKeyPressed(Keyboard::Escape) && igstate.counter == 0 && player1.life_state == 1)
			{
				if (ingamestate == true) 
				{
					ingamestate = false;
					t.stop();
				}
				else
				{
					ingamestate = true;
					t.start();
				}
				igstate.counter = 15;
			}
			if (igstate.counter != 0) igstate.counter -= 1;
			//running
			if (ingamestate == true)
			{
				//hack
				if (Mouse::isButtonPressed(Mouse::Middle))
				{
					player1.hp = player1.max_hp;
					score = 88888;
					enemyArray.clear();
					enemy2Array.clear();
					enemy3Array.clear();
				}
				if (witchi.size() != 0)
				{
					if (ingame.getStatus() == ingame.Playing) ingame.stop();
					if (fl.floor + 1 == 7 && boss1.getStatus() != boss1.Playing) boss1.play();
					if (fl.floor + 1 == 14 && boss2.getStatus() != boss2.Playing) boss2.play();
					if (fl.floor + 1 == 21 && boss3.getStatus() != boss3.Playing) boss3.play();
					if (fl.floor + 1 == 28 && boss4.getStatus() != boss4.Playing) boss4.play();
				}
				//timer
				t.update();
				//close the pause screen
				window.setMouseCursorVisible(cursorVisible);
				igstate.display(false);
				window.draw(igstate.rect);
				normal_mob = enemyArray.size() + enemy2Array.size() + enemy3Array.size();
				boss_mob = witchi.size();
				total_mob = boss_mob + normal_mob;
				//IGUI update
				ingameui.charUI_update(pos, player1.atk, player1.reduce, player1.armor, fl.floor + 1, player1.hp, total_mob, t.t, score) ;
				//player movement update
				player1.update(pos, Mpos);
				//unblock movement
				//player
				player1.blockleft = 0;
				player1.blockright = 0;
				player1.blockup = 0;
				player1.blockdown = 0;
				player1.d_blockleft = 0;
				player1.d_blockright = 0;
				player1.d_blockup = 0;
				player1.d_blockdown = 0;
				//enemy
				for (size_t i = 0; i < enemyArray.size(); i++)
				{
					enemyArray[i].blockleft = 0;
					enemyArray[i].blockright = 0;
					enemyArray[i].blockup = 0;
					enemyArray[i].blockdown = 0;
				}
				for (size_t i = 0; i < enemy2Array.size(); i++)
				{
					enemy2Array[i].blockleft = 0;
					enemy2Array[i].blockright = 0;
					enemy2Array[i].blockup = 0;
					enemy2Array[i].blockdown = 0;
				}
				for (size_t i = 0; i < enemy3Array.size(); i++)
				{
					enemy3Array[i].blockleft = 0;
					enemy3Array[i].blockright = 0;
					enemy3Array[i].blockup = 0;
					enemy3Array[i].blockdown = 0;
				}
				// player attack update
				pos = player1.sprite.getPosition();
				atk1.attack(pos, Mpos);
				// update player hit counter
				if (player1.hit_counter != 0)
				{
					player1.hit_counter--;
				}
				// update screen
				if (pos.x <= 640 && pos.y <= 360) view.setCenter(640, 360);
				else if (pos.x >= 1920 && pos.y <= 360) view.setCenter(1920, 360);
				else if (pos.x <= 640 && pos.y >= 1080) view.setCenter(640, 1080);
				else if (pos.x >= 1920 && pos.y >= 1080) view.setCenter(1920, 1080);
				else if (pos.y <= 360) view.setCenter(pos.x, 360);
				else if (pos.y >= 1080) view.setCenter(pos.x, 1080);
				else if (pos.x <= 640) view.setCenter(640, pos.y);
				else if (pos.x >= 1920) view.setCenter(1920, pos.y);
				else  view.setCenter(pos);
				// clear screen
				window.clear();
				// draw background & wall
				window.draw(spriteBackground);
				window.draw(spriteLeftWall);
				window.draw(spriteRightWall);
				window.draw(spriteTopWall);
				window.draw(spriteDownWall);
				// draw player magic
				window.draw(player1.Nsprite);
				// check wall collision
				//player
				if (PixelPerfectTest(spriteLeftWall, player1.sprite)) { player1.blockleft = 1; player1.d_blockleft = 1; }
				if (PixelPerfectTest(spriteRightWall, player1.sprite)) { player1.blockright = 1; player1.d_blockright = 1; }
				if (PixelPerfectTest(spriteTopWall, player1.sprite)) { player1.blockup = 1; player1.d_blockup = 1; }
				if (PixelPerfectTest(spriteDownWall, player1.sprite)) { player1.blockdown = 1; player1.d_blockdown = 1; }
				//enemy
				for (size_t i = 0; i < enemyArray.size(); i++)
				{
					if (PixelPerfectTest(spriteLeftWall, enemyArray[i].sprite)) { enemyArray[i].blockleft = 1; }
					if (PixelPerfectTest(spriteRightWall, enemyArray[i].sprite)) { enemyArray[i].blockright = 1; }
					if (PixelPerfectTest(spriteTopWall, enemyArray[i].sprite)) { enemyArray[i].blockup = 1; }
					if (PixelPerfectTest(spriteDownWall, enemyArray[i].sprite)) { enemyArray[i].blockdown = 1; }
				}
				for (size_t i = 0; i < enemy2Array.size(); i++)
				{
					if (PixelPerfectTest(spriteLeftWall, enemy2Array[i].sprite)) { enemy2Array[i].blockleft = 1; }
					if (PixelPerfectTest(spriteRightWall, enemy2Array[i].sprite)) { enemy2Array[i].blockright = 1; }
					if (PixelPerfectTest(spriteTopWall, enemy2Array[i].sprite)) { enemy2Array[i].blockup = 1; }
					if (PixelPerfectTest(spriteDownWall, enemy2Array[i].sprite)) { enemy2Array[i].blockdown = 1; }
				}
				for (size_t i = 0; i < enemy3Array.size(); i++)
				{
					if (PixelPerfectTest(spriteLeftWall, enemy3Array[i].sprite)) { enemy3Array[i].blockleft = 1; }
					if (PixelPerfectTest(spriteRightWall, enemy3Array[i].sprite)) { enemy3Array[i].blockright = 1; }
					if (PixelPerfectTest(spriteTopWall, enemy3Array[i].sprite)) { enemy3Array[i].blockup = 1; }
					if (PixelPerfectTest(spriteDownWall, enemy3Array[i].sprite)) { enemy3Array[i].blockdown = 1; }
				}
				//draw item
				for (size_t i = 0; i < itemArray.size(); i++)
				{
					window.draw(itemArray[i].sprite);
				}
				//adjust fire effect flint'n steel picked
				if (player1.item_atk_counter != 0)
				{
					if (atk1.counter != 0) atk1.sprite.setColor(Color(255, 0, 0, 255));
					else atk1.sprite.setColor(Color(255, 0, 0, 0));
				}
				else if (atk1.counter != 0) atk1.sprite.setColor(Color(255, 255, 255, 255));
				else atk1.sprite.setColor(Color(255, 255, 255, 0));
				// draw player attack
				window.draw(atk1.circle);
				window.draw(atk1.sprite);
				// Spawn equals the Pre Spawn type 1
				for (size_t i = 0; i < enemyArray.size(); i++) {
					enemyArray[i].update2();
					Epos = enemyArray[i].sprite.getPosition();
					enemyArray[i].updateMovement(pos, Epos, windowSize);
					eneatkArray[i].attack(pos, Epos);
					// enemy attack hit check
					if (PixelPerfectTest(player1.sprite, eneatkArray[i].Nsprite) && eneatkArray[i].scounter != 0)
					{
						if (player1.hit_counter == 0)
						{
							player1.hit_counter = hit_count;
							if (player1.armor_state == 0)
							{
								if (enemyArray[i].atk > player1.reduce)
									player1.hp -= (enemyArray[i].atk - player1.reduce);
								dis.dmg(pos, -(enemyArray[i].atk - player1.reduce), 0);
								disArray.push_back(dis);
							}
							else
							{
								if (enemyArray[i].atk > player1.reduce)
									player1.armor -= (enemyArray[i].atk - player1.reduce);
								dis.dmg(pos, -(enemyArray[i].atk - player1.reduce), 2);
								disArray.push_back(dis);
							}
							if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
						}
						eneatkArray[i].scounter = 0;
						score -= 10;
					}
					// player attack hit check
					if (PixelPerfectTest(atk1.sprite, enemyArray[i].sprite) && atk1.counter != 0)
					{
						if (enemyArray[i].armor_state == 0)
						{
							if (player1.atk > enemyArray[i].reduce)
								enemyArray[i].hp -= (player1.atk - enemyArray[i].reduce);
							else if (player1.atk == enemyArray[i].reduce)
								enemyArray[i].hp -= 1;
							dis.dmg(Epos, -(player1.atk - enemyArray[i].reduce), 3);
							disArray.push_back(dis);
						}
						else
						{
							if (player1.atk > enemyArray[i].reduce)
								enemyArray[i].armor -= (player1.atk - enemyArray[i].reduce);
							else if (player1.atk == enemyArray[i].reduce)
								enemyArray[i].armor -= 1;
							dis.dmg(Epos, -(player1.atk - enemyArray[i].reduce), 2);
							disArray.push_back(dis);
						}
						if (enemyArray[i].armor <= 0) { enemyArray[i].armor_state = 0; enemyArray[i].armor = 0; }
						if (enemyArray[i].hp <= 0) enemyArray[i].life_state = 0;
						atk1.counter = 0;
						//IGUI
						ingameui.enemyUI_update(1, i, enemyArray[i].hp, enemyArray[i].max_hp, enemyArray[i].reduce, enemyArray[i].armor, enemyArray[i].armor_state);
					}
					// player & enemy collision
					if (PixelPerfectTest(player1.sprite, enemyArray[i].sprite))
					{
						if (pos.x > Epos.x + 32) { player1.blockleft = 1; }
						if (pos.x < Epos.x - 32) { player1.blockright = 1; }
						if (pos.y > Epos.y + 32) { player1.blockup = 1; }
						if (pos.y < Epos.y - 32) { player1.blockdown = 1; }
					}
					// enemy & explosion collision
					for (size_t j = 0; j < explodeArray.size(); j++)
					{

						if (PixelPerfectTest(enemyArray[i].sprite, explodeArray[j].sprite))
						{
							enemyArray[i].hp -= 20;
							if (enemyArray[i].hp <= 0) enemyArray[i].life_state = 0;
						}
					}
					//draw enemy and enemy attack
					if (pos.y >= Epos.y) window.draw(eneatkArray[i].sprite);
					window.draw(enemyArray[i].sprite);
					window.draw(eneatkArray[i].Nsprite);
					if (pos.y < Epos.y) window.draw(eneatkArray[i].sprite);
					// check if enemy is dead
					if (enemyArray[i].life_state == 0)
					{
						item.update(enemyArray[i].argument_1, enemyArray[i].argument_2, enemyArray[i].argument_3);
						item.update2(Epos);
						item.drop();
						if (item.which != 0) itemArray.push_back(item);
						enemyArray.erase(enemyArray.begin() + i);
						eneatkArray.erase(eneatkArray.begin() + i);
						score += 100;
					}
				}
				// Spawn equals the Pre Spawn type 2
				for (size_t i = 0; i < enemy2Array.size(); i++) {
					enemy2Array[i].update2();
					E2pos = enemy2Array[i].sprite.getPosition();
					enemy2Array[i].updateMovement(pos, E2pos, windowSize);
					ene2atkArray[i].attack(pos, E2pos);
					// enemy attack hit check
					if (PixelPerfectTest(player1.sprite, ene2atkArray[i].Nsprite) && ene2atkArray[i].scounter != 0)
					{
						if (player1.hit_counter == 0)
						{
							player1.hit_counter = hit_count;
							if (player1.armor_state == 0)
							{
								if (enemy2Array[i].atk > player1.reduce)
									player1.hp -= (enemy2Array[i].atk - player1.reduce);
								dis.dmg(pos, -(enemy2Array[i].atk - player1.reduce), 0);
								disArray.push_back(dis);
							}
							else
							{
								if (enemy2Array[i].atk > player1.reduce)
									player1.armor -= (enemy2Array[i].atk - player1.reduce);
								dis.dmg(pos, -(enemy2Array[i].atk - player1.reduce), 2);
								disArray.push_back(dis);
							}
							if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
						}
						ene2atkArray[i].scounter = 0;
						score -= 5;
					}
					// player attack hit check
					if (PixelPerfectTest(atk1.sprite, enemy2Array[i].sprite) && atk1.counter != 0)
					{
						if (enemy2Array[i].armor_state == 0)
						{
							if (player1.atk > enemy2Array[i].reduce)
								enemy2Array[i].hp -= (player1.atk - enemy2Array[i].reduce);
							else if (player1.atk == enemy2Array[i].reduce)
								enemy2Array[i].hp -= 1;
							dis.dmg(E2pos, -(player1.atk - enemy2Array[i].reduce), 3);
							disArray.push_back(dis);
						}
						else
						{
							if (player1.atk > enemy2Array[i].reduce)
								enemy2Array[i].armor -= (player1.atk - enemy2Array[i].reduce);
							else if (player1.atk == enemy2Array[i].reduce)
								enemy2Array[i].armor -= 1;
							dis.dmg(E2pos, -(player1.atk - enemy2Array[i].reduce), 2);
							disArray.push_back(dis);
						}
						if (enemy2Array[i].armor <= 0) { enemy2Array[i].armor_state = 0; enemy2Array[i].armor = 0; }
						if (enemy2Array[i].hp <= 0) enemy2Array[i].life_state = 0;
						atk1.counter = 0;
						//IGUI
						ingameui.enemyUI_update(2, i, enemy2Array[i].hp, enemy2Array[i].max_hp, enemy2Array[i].reduce, enemy2Array[i].armor, enemy2Array[i].armor_state);
					}
					// player & enemy collision
					if (PixelPerfectTest(player1.sprite, enemy2Array[i].sprite))
					{
						if (pos.x > E2pos.x + 32) { player1.blockleft = 1; }
						if (pos.x < E2pos.x - 32) { player1.blockright = 1; }
						if (pos.y > E2pos.y + 32) { player1.blockup = 1; }
						if (pos.y < E2pos.y - 32) { player1.blockdown = 1; }
					}
					// enemy & explosion collision
					for (size_t j = 0; j < explodeArray.size(); j++)
					{

						if (PixelPerfectTest(enemy2Array[i].sprite, explodeArray[j].sprite))
						{
							enemy2Array[i].hp -= 20;
							if (enemy2Array[i].hp <= 0) enemy2Array[i].life_state = 0;
						}
					}
					//draw enemy and enemy attack
					if (pos.y >= E2pos.y) window.draw(ene2atkArray[i].sprite);
					window.draw(enemy2Array[i].sprite);
					window.draw(ene2atkArray[i].Nsprite);
					if (pos.y < E2pos.y) window.draw(ene2atkArray[i].sprite);
					// check if enemy is dead
					if (enemy2Array[i].life_state == 0)
					{
						item.update(enemy2Array[i].argument_1, enemy2Array[i].argument_2, enemy2Array[i].argument_3);
						item.update2(E2pos);
						item.drop();
						if (item.which != 0) itemArray.push_back(item);
						enemy2Array.erase(enemy2Array.begin() + i);
						ene2atkArray.erase(ene2atkArray.begin() + i);
						score += 200;
					}
				}
				// Spawn equals the Pre Spawn type 3
				for (size_t i = 0; i < enemy3Array.size(); i++) {
					enemy3Array[i].update2();
					E3pos = enemy3Array[i].sprite.getPosition();
					enemy3Array[i].updateMovement(pos, E3pos, windowSize);
					ene3atkArray[i].attack(pos, E3pos);
					// enemy attack hit check
					if (PixelPerfectTest(player1.sprite, ene3atkArray[i].Nsprite) && ene3atkArray[i].scounter != 0)
					{
						if (player1.hit_counter == 0)
						{
							player1.hit_counter = hit_count;
							if (player1.armor_state == 0)
							{
								if (enemy3Array[i].atk > player1.reduce)
									player1.hp -= (enemy3Array[i].atk - player1.reduce);
								dis.dmg(pos, -(enemy3Array[i].atk - player1.reduce), 0);
								disArray.push_back(dis);
							}
							else
							{
								if (enemy3Array[i].atk > player1.reduce)
									player1.armor -= (enemy3Array[i].atk - player1.reduce);
								dis.dmg(pos, -(enemy3Array[i].atk - player1.reduce), 2);
								disArray.push_back(dis);
							}
							if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
						}
						ene3atkArray[i].scounter = 0;
						score -= 20;
					}
					// player attack hit check
					if (PixelPerfectTest(atk1.sprite, enemy3Array[i].sprite) && atk1.counter != 0)
					{
						if (enemy3Array[i].armor_state == 0)
						{
							if (player1.atk > enemy3Array[i].reduce)
								enemy3Array[i].hp -= (player1.atk - enemy3Array[i].reduce);
							else if (player1.atk == enemy3Array[i].reduce)
								enemy3Array[i].hp -= 1;
							dis.dmg(E3pos, -(player1.atk - enemy3Array[i].reduce), 3);
							disArray.push_back(dis);
						}
						else
						{
							if (player1.atk > enemy3Array[i].reduce)
								enemy3Array[i].armor -= (player1.atk - enemy3Array[i].reduce);
							else if (player1.atk == enemy3Array[i].reduce)
								enemy3Array[i].armor -= 1;
							dis.dmg(E3pos, -(player1.atk - enemy3Array[i].reduce), 2);
							disArray.push_back(dis);
						}
						if (enemy3Array[i].armor <= 0) { enemy3Array[i].armor_state = 0; enemy3Array[i].armor = 0; }
						if (enemy3Array[i].hp <= 0) enemy3Array[i].life_state = 0;
						atk1.counter = 0;
						//IGUI
						ingameui.enemyUI_update(3, i, enemy3Array[i].hp, enemy3Array[i].max_hp, enemy3Array[i].reduce, enemy3Array[i].armor, enemy3Array[i].armor_state);
					}
					// player & enemy collision
					if (PixelPerfectTest(player1.sprite, enemy3Array[i].sprite))
					{
						if (pos.x > E3pos.x + 32) { player1.blockleft = 1; }
						if (pos.x < E3pos.x - 32) { player1.blockright = 1; }
						if (pos.y > E3pos.y + 32) { player1.blockup = 1; }
						if (pos.y < E3pos.y - 32) { player1.blockdown = 1; }
					}
					// enemy & explosion collision
					for (size_t j = 0; j < explodeArray.size(); j++)
					{

						if (PixelPerfectTest(enemy3Array[i].sprite, explodeArray[j].sprite))
						{
							enemy3Array[i].hp -= 20;
							if (enemy3Array[i].hp <= 0) enemy3Array[i].life_state = 0;
						}
					}
					//draw enemy and enemy attack
					if (pos.y >= E3pos.y) window.draw(ene3atkArray[i].sprite);
					window.draw(enemy3Array[i].sprite);
					window.draw(ene3atkArray[i].Nsprite);
					if (pos.y < E3pos.y) window.draw(ene3atkArray[i].sprite);
					// check if enemy is dead
					if (enemy3Array[i].life_state == 0)
					{
						item.update(enemy3Array[i].argument_1, enemy3Array[i].argument_2, enemy3Array[i].argument_3);
						item.update2(E3pos);
						item.drop();
						if (item.which != 0) itemArray.push_back(item);
						enemy3Array.erase(enemy3Array.begin() + i);
						ene3atkArray.erase(ene3atkArray.begin() + i);
						score += 70;
					}
				}
				// Witch process
				if (witchi.size() != 0)
				{
					Wpos = witchi[0].sprite.getPosition();
					//witch atk
					if (fl.floor + 1 == 7)
					{
						witch1atk.attack();
						//witch normal attack process
						if (witch1atkArray.size() < witch1atk.bul_count && witch1atk.charge_state == 0)
						{
							witch1atk.sprite.setPosition(Wpos.x + (128*cos((18.0f * (witch1atk.bul_count+1))*3.14/180)), Wpos.y - (80 * sin((18 * (witch1atk.bul_count+1))*3.14 / 180)));
							witch1atkArray.push_back(witch1atk);
						}
						for (size_t i = 0; i < witch1atkArray.size(); i++)
						{
							witch1atkArray[i].first(pos,Wpos,i, witch1atk.order);
							witch1atkArray[i].sprite.rotate(rng.rand_gen_ptp(1,3));
							//witch normal attack hit
							if (PixelPerfectTest(player1.sprite, witch1atkArray[i].sprite))
							{
								if (player1.hit_counter == 0)
								{
									player1.hit_counter = hit_count;
									if (player1.armor_state == 0)
									{
										if (witch1atkArray[i].normal_dmg > player1.reduce)
											player1.hp -= (witch1atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch1atkArray[i].normal_dmg - player1.reduce), 0);
										disArray.push_back(dis);
									}
									else
									{
										if (witch1atkArray[i].normal_dmg > player1.reduce)
											player1.armor -= (witch1atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch1atkArray[i].normal_dmg - player1.reduce), 2);
										disArray.push_back(dis);
									}
									if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
								}
								witch1atkArray[i].go = false;
								witch1atkArray[i].lock = false;
								witch1atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteLeftWall, witch1atkArray[i].sprite))
							{
								witch1atkArray[i].go = false;
								witch1atkArray[i].lock = false;
								witch1atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteRightWall, witch1atkArray[i].sprite))
							{
								witch1atkArray[i].go = false;
								witch1atkArray[i].lock = false;
								witch1atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteTopWall, witch1atkArray[i].sprite))
							{
								witch1atkArray[i].go = false;
								witch1atkArray[i].lock = false;
								witch1atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteDownWall, witch1atkArray[i].sprite))
							{
								witch1atkArray[i].go = false;
								witch1atkArray[i].lock = false;
								witch1atkArray[i].del = true;
							}
							window.draw(witch1atkArray[i].sprite);
						}
						for (size_t i = 0; i < witch1atkArray.size(); i++)
						{
							if (witch1atkArray[i].del)
							{
								witch1atkArray.erase(witch1atkArray.begin() + i);
								witch1atk.bul_count -= 1;
							}
						}
						if (witch1atkArray.size() == 0 && witch1atk.charge_state == 1)
						{
							witch1atk.bul_count -= 1;
							witch1atk.order = -1;
							witch1atk.charge_state = 0;
							witch1atk.counter1_1 = 0;
						}
						//////////////////////////////////////////////////////////////
						//witch random attack
						if (witch1atk.state2)
						{
							witch1atk2Array.push_back(witch1atk);
						}
						for (size_t i = 0; i < witch1atk2Array.size(); i++)
						{
							witch1atk2Array[i].second();
							if (PixelPerfectTest(player1.sprite, witch1atk2Array[i].sprite1))
							{
								if (player1.hit_counter == 0)
								{
									player1.hit_counter = hit_count;
									if (player1.armor_state == 0)
									{
										if (witch1atk2Array[i].passive_dmg > player1.reduce)
											player1.hp -= (witch1atk2Array[i].passive_dmg - player1.reduce);
										dis.dmg(pos, -(witch1atk2Array[i].passive_dmg - player1.reduce), 0);
										disArray.push_back(dis);
									}
									else
									{
										if (witch1atk2Array[i].passive_dmg > player1.reduce)
											player1.armor -= (witch1atk2Array[i].passive_dmg - player1.reduce);
										dis.dmg(pos, -(witch1atk2Array[i].passive_dmg - player1.reduce), 2);
										disArray.push_back(dis);
									}
									if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
								}
							}
							if (PixelPerfectTest(atk1.sprite, witch1atk2Array[i].sprite1) && atk1.counter != 0)
							{
								atk1.counter = 0;
							}
							window.draw(witch1atk2Array[i].sprite1);
						}
						for (size_t i = 0; i < witch1atk2Array.size(); i++)
						{
							if (witch1atk2Array[i].hit_counter == 0)
							{
								witch1atk2Array.erase(witch1atk2Array.begin()+i);
							}
						}
						//////////////////////////////////////////////////////////////
					}
					if (fl.floor + 1 == 14)
					{
						witch2atk.attack(witchi[0].hp,witchi[0].max_hp);
						//witch normal attack process
						if (witch2atkArray.size() < witch2atk.bul_count && witch2atk.charge_state == 0)
						{
							witch2atk.sprite.setPosition(Wpos.x + (128 * cos((18 * (witch2atk.bul_count + 2))*3.14 / 180)), Wpos.y - (80 * sin((18 * (witch2atk.bul_count + 2))*3.14 / 180)));
							witch2atk.sprite.setRotation(-30 * witch2atk.bul_count);
							witch2atkArray.push_back(witch2atk);
						}
						for (size_t i = 0; i < witch2atkArray.size(); i++)
						{
							witch2atkArray[i].first(pos, Wpos, witch2atk.charge_state);
							//witch normal attack hit
							if (PixelPerfectTest(player1.sprite, witch2atkArray[i].sprite))
							{
								if (player1.hit_counter == 0)
								{
									player1.hit_counter = hit_count;
									if (player1.armor_state == 0)
									{
										if (witch2atkArray[i].normal_dmg > player1.reduce)
											player1.hp -= (witch2atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch2atkArray[i].normal_dmg - player1.reduce), 0);
										disArray.push_back(dis);
									}
									else
									{
										if (witch2atkArray[i].normal_dmg > player1.reduce)
											player1.armor -= (witch2atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch2atkArray[i].normal_dmg - player1.reduce), 2);
										disArray.push_back(dis);
									}
									if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
								}
								witch2atkArray[i].go = false;
								witch2atkArray[i].lock = false;
								witch2atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteLeftWall, witch2atkArray[i].sprite))
							{
								witch2atkArray[i].go = false;
								witch2atkArray[i].lock = false;
								witch2atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteRightWall, witch2atkArray[i].sprite))
							{
								witch2atkArray[i].go = false;
								witch2atkArray[i].lock = false;
								witch2atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteTopWall, witch2atkArray[i].sprite))
							{
								witch2atkArray[i].go = false;
								witch2atkArray[i].lock = false;
								witch2atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteDownWall, witch2atkArray[i].sprite))
							{
								witch2atkArray[i].go = false;
								witch2atkArray[i].lock = false;
								witch2atkArray[i].del = true;
							}
							window.draw(witch2atkArray[i].sprite);
						}
						for (size_t i = 0; i < witch2atkArray.size(); i++)
						{
							if (witch2atkArray[i].del)
							{
								witch2atkArray.erase(witch2atkArray.begin() + i);
								witch2atk.bul_count -= 1;
							}
						}
						if (witch2atkArray.size() == 0 && witch2atk.charge_state == 1)
						{
							witch2atk.bul_count -= 1;
							witch2atk.order = -1;
							witch2atk.charge_state = 0;
							witch2atk.counter1_1 = 0;
						}
						//////////////////////////////////////////////////////////////
						//witch random attack
						if (witch2atk.state2)
						{
							for (size_t i = 0; i < 8; i++)
							{
								witch2atk.sprite1.setPosition(rng.rand_gen_ptp(632, 1928), 88);
								witch2atk2Array.push_back(witch2atk);
							}
						}
						for (size_t i = 0; i < witch2atk2Array.size(); i++)
						{
							witch2atk2Array[i].WavePos = witch2atk2Array[i].sprite1.getPosition();
							witch2atk2Array[i].sprite1.move(0, witch2atk2Array[i].accel);
							if (PixelPerfectTest(player1.sprite, witch2atk2Array[i].sprite1))
							{
								if (pos.x > witch2atk2Array[i].WavePos.x + 32) { player1.blockleft = 1; }
								if (pos.x < witch2atk2Array[i].WavePos.x - 32) { player1.blockright = 1; }
								if (pos.y > witch2atk2Array[i].WavePos.y + 32)
								{ 
									player1.blockup = 1; 								
									player1.sprite.move(0, witch2atk2Array[i].accel);
								}
								if (pos.y < witch2atk2Array[i].WavePos.y - 32) { player1.blockdown = 1; }
								if (player1.hit_counter == 0)
								{
									player1.hit_counter = hit_count;
									if (player1.armor_state == 0)
									{
										if (witch2atk2Array[i].passive_dmg > player1.reduce)
											player1.hp -= (witch2atk2Array[i].passive_dmg - player1.reduce);
										dis.dmg(pos, -(witch2atk2Array[i].passive_dmg - player1.reduce), 0);
										disArray.push_back(dis);
									}
									else
									{
										if (witch2atk2Array[i].passive_dmg > player1.reduce)
											player1.armor -= (witch2atk2Array[i].passive_dmg - player1.reduce);
										dis.dmg(pos, -(witch2atk2Array[i].passive_dmg - player1.reduce), 2);
										disArray.push_back(dis);
									}
									if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
								}
							}
							if (PixelPerfectTest(spriteDownWall, witch2atk2Array[i].sprite1)) witch2atk2Array[i].state2 = false;
							window.draw(witch2atk2Array[i].sprite1);
						}
						for (size_t i = 0; i < witch2atk2Array.size(); i++)
						{
							if (!witch2atk2Array[i].state2)
							{
								witch2atk2Array.erase(witch2atk2Array.begin() + i);
							}
						}
						//////////////////////////////////////////////////////////////
					}
					if (fl.floor + 1 == 21)
					{
						witch3atk.attack(witchi[0].hp, witchi[0].max_hp);
						//witch normal attack process
						if (witch3atk.state)
						{
							witch3atkArray.push_back(witch3atk);
						}
						for (size_t i = 0; i < witch3atkArray.size(); i++)
						{
							witch3atkArray[i].first(pos, Wpos);
							//witch normal attack hit
							if (PixelPerfectTest(player1.sprite, witch3atkArray[i].sprite))
							{
								if (player1.hit_counter == 0)
								{
									player1.hit_counter = hit_count;
									if (player1.armor_state == 0)
									{
										if (witch3atkArray[i].normal_dmg > player1.reduce)
											player1.hp -= (witch3atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch3atkArray[i].normal_dmg - player1.reduce), 0);
										disArray.push_back(dis);
									}
									else
									{
										if (witch3atkArray[i].normal_dmg > player1.reduce)
											player1.armor -= (witch3atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch3atkArray[i].normal_dmg - player1.reduce), 2);
										disArray.push_back(dis);
									}
									if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
								}
								witch3atkArray[i].go = false;
								witch3atkArray[i].lock = false;
								witch3atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteLeftWall, witch3atkArray[i].sprite))
							{
								witch3atkArray[i].go = false;
								witch3atkArray[i].lock = false;
								witch3atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteRightWall, witch3atkArray[i].sprite))
							{
								witch3atkArray[i].go = false;
								witch3atkArray[i].lock = false;
								witch3atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteTopWall, witch3atkArray[i].sprite))
							{
								witch3atkArray[i].go = false;
								witch3atkArray[i].lock = false;
								witch3atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteDownWall, witch3atkArray[i].sprite))
							{
								witch3atkArray[i].go = false;
								witch3atkArray[i].lock = false;
								witch3atkArray[i].del = true;
							}
							window.draw(witch3atkArray[i].sprite);
						}
						for (size_t i = 0; i < witch3atkArray.size(); i++)
						{
							if (witch3atkArray[i].del)
							{
								witch3atkArray.erase(witch3atkArray.begin() + i);
							}
						}
						//////////////////////////////////////////////////////////////
						//witch random attack
						if (witch3atk2Array.size() < witch3atk.size)
						{
							witch3atk.second();
								witch3atk2Array.push_back(witch3atk);
						}
						for (size_t i = 0; i < witch3atk2Array.size(); i++)
						{
							witch3atk2Array[i].sprite1.move(rng.rand_gen_ptp(0, witch3atk2Array[i].accel), rng.rand_gen_ptp(0, witch3atk2Array[i].accel));
							if (PixelPerfectTest(player1.sprite, witch3atk2Array[i].sprite1))
							{
								player1.blockleft = 1;
								player1.blockright = 1;
								player1.blockup = 1;
								player1.blockdown = 1;
								if (player1.hit_counter == 0)
								{
									player1.hit_counter = hit_count;
									if (player1.armor_state == 0)
									{
										if (witch3atk2Array[i].passive_dmg > player1.reduce)
											player1.hp -= (witch3atk2Array[i].passive_dmg - player1.reduce);
										dis.dmg(pos, -(witch3atk2Array[i].passive_dmg - player1.reduce), 0);
										disArray.push_back(dis);
									}
									else
									{
										if (witch3atk2Array[i].passive_dmg > player1.reduce)
											player1.armor -= (witch3atk2Array[i].passive_dmg - player1.reduce);
										dis.dmg(pos, -(witch3atk2Array[i].passive_dmg - player1.reduce), 2);
										disArray.push_back(dis);
									}
									if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
								}
							}
							if (PixelPerfectTest(spriteLeftWall, witch3atk2Array[i].sprite1))
							{
								witch3atk2Array[i].second();
							}
							if (PixelPerfectTest(spriteRightWall, witch3atk2Array[i].sprite1))
							{
								witch3atk2Array[i].second();
							}
							if (PixelPerfectTest(spriteTopWall, witch3atk2Array[i].sprite1))
							{
								witch3atk2Array[i].second();
							}
							if (PixelPerfectTest(spriteDownWall, witch3atk2Array[i].sprite1))
							{
								witch3atk2Array[i].second();
							}
							window.draw(witch3atk2Array[i].sprite1);
						}
						//////////////////////////////////////////////////////////////
						//witch ultimate defense
						if (witch3atk.vortex)
						{
							if (witch3atk.pillar_count < 3)
							{
								witch3atk.sprite3.setPosition(rng.rand_gen_ptp(632, 1928), rng.rand_gen_ptp(632, 1383));
								witch3def2Array.push_back(witch3atk);
								witch3atk.pillar_count += 1;
								if (witch3atk.pillar_count == 3)
								{
									witch3atk.sprite2.setPosition(Wpos);
									witch3defArray.push_back(witch3atk);
								}
							}
							if (witch3defArray.size()) 
							{
								if (PixelPerfectTest(player1.sprite, witch3defArray[0].sprite2))
								{
									player1.sprite.setPosition(rng.rand_gen_ptp(632, 1928), rng.rand_gen_ptp(632, 1383));
								}
								if (PixelPerfectTest(atk1.sprite, witch3defArray[0].sprite2) && atk1.counter != 0)
								{
									atk1.counter = 0;
								}
								window.draw(witch3defArray[0].sprite2);
							}
							for (size_t i = 0; i < witch3def2Array.size(); i++)
							{
								// player & pillar collision
								if (PixelPerfectTest(player1.sprite, witch3def2Array[i].sprite3))
								{
									witch3def2Array[i].pillar_pos = witch3def2Array[i].sprite3.getPosition();
									if (pos.x > witch3def2Array[i].pillar_pos.x + 32) { player1.blockleft = 1; }
									if (pos.x < witch3def2Array[i].pillar_pos.x - 32) { player1.blockright = 1; }
									if (pos.y > witch3def2Array[i].pillar_pos.y + 32) { player1.blockup = 1; }
									if (pos.y < witch3def2Array[i].pillar_pos.y - 32) { player1.blockdown = 1; }
								}
								if (PixelPerfectTest(atk1.sprite, witch3def2Array[i].sprite3) && atk1.counter != 0)
								{
									witch3def2Array[i].pillar_hp -= player1.atk;
									dis.dmg(witch3def2Array[i].pillar_pos, -player1.atk, 3);
									disArray.push_back(dis);
									if (witch3def2Array[i].pillar_hp <= 0)
									{
										witch3def2Array[i].del2 = true;
									}
									atk1.counter = 0;
									//IGUI
									ingameui.hit_boss = true;
									ingameui.witchUI_update((fl.floor + 1) / 7, witch3def2Array[i].pillar_hp, witch3def2Array[i].pillar_mh);
								}
								window.draw(witch3def2Array[i].sprite3);
							}
							for (size_t i = 0; i < witch3def2Array.size(); i++)
							{
								if (witch3def2Array[i].del2) witch3def2Array.erase(witch3def2Array.begin() + i);


							}
							if (!witch3def2Array.size()) { witch3defArray.clear(); witch3atk.vortex = false; }
						}
						//////////////////////////////////////////////////////////////
					}
					if (fl.floor + 1 == 28)
					{
						witch4atk.fire();
						witch4atk.passive(pos,Wpos);
						witch4atk.active(witchi[0].hp, witchi[0].max_hp);
						if (!witch4atk.justdoit)
						{
							for (size_t i = 0; i < 30; i++)
							{
								witch4atk.myangle = witch4atk.angle[i];
								witch4atkArray.push_back(witch4atk);
							}
							witch4atk.justdoit = true;
						}
						for (size_t i = 0; i < witch4atkArray.size(); i++)
						{
							witch4atkArray[i].update();
							if (PixelPerfectTest(player1.sprite, witch4atkArray[i].sprite))
							{
								if (player1.hit_counter == 0)
								{
									player1.hit_counter = hit_count;
									if (player1.armor_state == 0)
									{
										if (witch4atkArray[i].normal_dmg > player1.reduce)
											player1.hp -= (witch4atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch4atkArray[i].normal_dmg - player1.reduce), 0);
										disArray.push_back(dis);
									}
									else
									{
										if (witch4atkArray[i].normal_dmg > player1.reduce)
											player1.armor -= (witch4atkArray[i].normal_dmg - player1.reduce);
										dis.dmg(pos, -(witch4atkArray[i].normal_dmg - player1.reduce), 2);
										disArray.push_back(dis);
									}
									if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
								}
								witch4atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteLeftWall, witch4atkArray[i].sprite))
							{
								witch4atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteRightWall, witch4atkArray[i].sprite))
							{
								witch4atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteTopWall, witch4atkArray[i].sprite))
							{
								witch4atkArray[i].del = true;
							}
							if (PixelPerfectTest(spriteDownWall, witch4atkArray[i].sprite))
							{
								witch4atkArray[i].del = true;
							}
							window.draw(witch4atkArray[i].sprite);
						}
						for (size_t i = 0; i < witch4atkArray.size(); i++)
						{
							if (witch4atkArray[i].del)
							{
								witch4atkArray.erase(witch4atkArray.begin() + i);
							}
						}
						if (PixelPerfectTest(player1.sprite, witch4atk.sprite2))
						{
							if (player1.hit_counter == 0)
							{
								player1.hit_counter = hit_count;
								if (player1.armor_state == 0)
								{
									if (witch4atk.passive_dmg > player1.reduce)
										player1.hp -= (witch4atk.passive_dmg - player1.reduce);
									dis.dmg(pos, -(witch4atk.passive_dmg - player1.reduce), 0);
									disArray.push_back(dis);
								}
								else
								{
									if (witch4atk.passive_dmg > player1.reduce)
										player1.armor -= (witch4atk.passive_dmg - player1.reduce);
									dis.dmg(pos, -(witch4atk.passive_dmg - player1.reduce), 2);
									disArray.push_back(dis);
								}
								if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
							}
						}
						if (PixelPerfectTest(player1.sprite, witch4atk.sprite1) && witch4atk.state)
						{
							if (player1.hit_counter == 0)
							{
								player1.hit_counter = hit_count;
								if (player1.armor_state == 0)
								{
									if (witch4atk.active_dmg > player1.reduce)
										player1.hp -= (witch4atk.active_dmg - player1.reduce);
									dis.dmg(pos, -(witch4atk.active_dmg - player1.reduce), 0);
									disArray.push_back(dis);
								}
								else
								{
									if (witch4atk.active_dmg > player1.reduce)
										player1.armor -= (witch4atk.active_dmg - player1.reduce);
									dis.dmg(pos, -(witch4atk.active_dmg - player1.reduce), 2);
									disArray.push_back(dis);
								}
								if (player1.armor <= 0) { player1.armor_state = 0; player1.armor = 0; }
							}
						}
					}
					//player attack hit
					if (PixelPerfectTest(atk1.sprite, witchi[0].sprite) && atk1.counter != 0)
					{						
						witchi[0].hp -= player1.atk;
						dis.dmg(Wpos, -player1.atk, 3);	
						disArray.push_back(dis);
						if (witchi[0].hp <= 0) witchi[0].life_state = 0;
						atk1.counter = 0;
						//IGUI
						ingameui.hit_boss = true;
						ingameui.witchUI_update((fl.floor + 1)/7 ,witchi[0].hp, witchi[0].max_hp);
					}
					// player & witch collision
					if (PixelPerfectTest(player1.sprite, witchi[0].sprite))
					{
						if (pos.x > Wpos.x + 32) { player1.blockleft = 1; }
						if (pos.x < Wpos.x - 32) { player1.blockright = 1; }
						if (pos.y > Wpos.y + 32) { player1.blockup = 1; }
						if (pos.y < Wpos.y - 32) { player1.blockdown = 1; }
					}
					// witch & explosion collision
					for (size_t j = 0; j < explodeArray.size(); j++)
					{

						if (PixelPerfectTest(witchi[0].sprite, explodeArray[j].sprite))
						{
							witchi[0].hp -= 20;
							if (witchi[0].hp <= 0) witchi[0].life_state = 0;
						}
					}
					// check if witch is dead
					if (witchi[0].life_state == 0)
					{
						item.update(witchi[0].argument_1, witchi[0].argument_2, witchi[0].argument_3);
						item.update2(Wpos);
						item.drop();
						if (item.which != 0) itemArray.push_back(item);
						witch_dead += 1;
						witchi.clear();
						ingameui.hit_boss = false;
						score += 500 * ((fl.floor + 1) / 7);
						if (boss1.getStatus() == boss1.Playing) boss1.stop();
						if (boss2.getStatus() == boss2.Playing) boss2.stop();
						if (boss3.getStatus() == boss3.Playing) boss3.stop();
						if (boss4.getStatus() == boss4.Playing) boss4.stop();
						if (ingame.getStatus() == ingame.Stopped) ingame.play();
					}
				}
				// player & drop collision
				for (size_t i = 0; i < itemArray.size(); i++)
				{
					Ipos = itemArray[i].sprite.getPosition();
					if (sqrt(pow(pos.x - Ipos.x, 2) + pow(pos.y - Ipos.y, 2)) <= 100 && itemArray[i].state == 1)
					{
						if (itemArray[i].which == 1)
						{
							if (itemArray[i].argument_2 == 1) { dis.item(pos, "Armor UP+", 1); disArray.push_back(dis); }
							if (itemArray[i].argument_2 == 2) { dis.item(pos, "Atk UP+ (T)", 1); disArray.push_back(dis); }
							if (itemArray[i].argument_2 == 3) { dis.item(pos, "HALF HEAL", 1); disArray.push_back(dis); }
							if (itemArray[i].argument_2 == 4) { dis.item(pos, "FULL HEAL", 1); disArray.push_back(dis); }
							if (itemArray[i].argument_2 == 5) { dis.item(pos, "MaxHP UP+", 1); disArray.push_back(dis); }
							if (itemArray[i].argument_2 == 6) { dis.item(pos, "Atk UP+ (C)", 1); disArray.push_back(dis); }
							if (itemArray[i].argument_2 == 7) { dis.item(pos, "Reduce UP+", 1); disArray.push_back(dis); }
							pickSF.play();
						}
						if (player1.pickup(itemArray[i].which, itemArray[i].argument_2, itemArray[i].argument_3) == 0)
						{
							if (itemArray[i].which == 2) atk1.update(player1.weapon_class, player1.weapon_rank);
							itemArray[i].state = 0;
							pickSF.play();
						}
						else if (player1.pickup(itemArray[i].which, itemArray[i].argument_2, itemArray[i].argument_3) == 2)
						{
							//bomb
							explodeSF.play();
							explode.start(pos);
							explodeArray.push_back(explode);
							itemArray[i].state = 0;
						}
						if (itemArray[i].state == 0) itemArray.erase(itemArray.begin() + i);
					}
				}
				// clear excessive drops
				if (itemArray.size() > 10) itemArray.erase(itemArray.begin());
				// correct player status
				if (score <= 0) score = 0;
				if (player1.hp <= 0) player1.hp = 0;
				if (player1.armor <= 0) player1.armor = 0;
				//draw explosion
				for (size_t i = 0; i < explodeArray.size(); i++)
				{
					//explode process
					explodeArray[i].explode();
					window.draw(explodeArray[i].sprite);
					if (explodeArray[i].state == 0) explodeArray.erase(explodeArray.begin() + i);
				}
				// player magic & enemy hit
				if (player1.magic_state == 1 && player1.magic_duration != 0)
				{
					for (size_t i = 0; i < enemyArray.size(); i++)
					{
						if (PixelPerfectTest(player1.Nsprite, enemyArray[i].sprite))
						{
							enemyArray[i].rect.setPosition(rng.rand_gen_ptp(632, 1300), rng.rand_gen_ptp(56, 1300));
						}
					}
					for (size_t i = 0; i < enemy2Array.size(); i++)
					{
						if (PixelPerfectTest(player1.Nsprite, enemy2Array[i].sprite))
						{
							enemy2Array[i].rect.setPosition(rng.rand_gen_ptp(632, 1300), rng.rand_gen_ptp(56, 1300));
						}
					}
					for (size_t i = 0; i < enemy3Array.size(); i++)
					{
						if (PixelPerfectTest(player1.Nsprite, enemy3Array[i].sprite))
						{
							enemy3Array[i].rect.setPosition(rng.rand_gen_ptp(632, 1300), rng.rand_gen_ptp(56, 1300));
						}
					}
				}
				// draw displayText
				for (size_t i = 0; i < disArray.size(); i++)
				{
					disArray[i].display();
					window.draw(disArray[i].text);
					if (disArray[i].counter == 0) disArray.erase(disArray.begin() + i);
				}
				// draw witch
				if (normal_mob == 0)
				{
					if (witchi.size() < fl.witch[(fl.floor+1) / 7] && witch_dead == 0 && (fl.floor+1) % 7 == 0)
					{
						witch.drop();
						witch.floor_maxhp = fl.witch_mh[(fl.floor + 1) / 7];
						witch.init(fl.floor + 1);
						witchi.push_back(witch);
						boss_mob = 1;
						total_mob = boss_mob + normal_mob;
					}
					if (witchi.size() != 0)
					{
						window.draw(witchi[0].sprite);
					}
				}
				// draw gate
				if (total_mob == 0)
				{
					t.stop();
					spriteRing.setColor(Color(255, 255, 255, 255));
					spriteGate.setColor(Color(255, 255, 255, 255));
					window.draw(spriteRing);
					window.draw(spriteGate);
					if (PixelPerfectTest(spriteGate, player1.sprite))
					{
						if (fl.floor != 27)
						{
							fl.reset = 0;
							fl.floor += 1;
						}
						else if(fl.floor == 27)
						{
							printf_s("You Cleared the game\n");
							fl.reset = 1;
							fl.floor += 1;
							player1.life_state = 0;
							highscore = do_rank(t.t, cname, score, t.hour, t.min, t.sec);
							ingamestate = false;
						}
					}
				}
				//player dead
				if (player1.hp <= 0) player1.life_state = 0;
				if (player1.life_state == 0) 
				{ 
					printf_s("You're Dead\n");
					highscore = do_rank(t.t, cname, score,t.hour,t.min,t.sec);
					window.clear(); 
					ingamestate = false; 
					if (boss1.getStatus() == boss1.Playing) boss1.stop();
					if (boss2.getStatus() == boss2.Playing) boss2.stop();
					if (boss3.getStatus() == boss3.Playing) boss3.stop();
					if (boss4.getStatus() == boss4.Playing) boss4.stop();
					Sleep(300);
				}
				if (Mpos.y >= pos.y) window.draw(atk1.Nsprite);
				// draw player
				window.draw(player1.Ncircle);
				window.draw(player1.circle);
				window.draw(player1.sprite);
				if (Mpos.y < pos.y) window.draw(atk1.Nsprite);
				// draw witch beam
				if (fl.floor + 1 == 28 && witchi.size() != 0)
				{
					window.draw(witch4atk.sprite2);
					if (witch4atk.state) window.draw(witch4atk.sprite1);
				}
				// override background
				window.draw(spriteOverride);
				// draw IGUI
				window.draw(ingameui.rect);
				window.draw(ingameui.text);
				window.draw(ingameui.text1);
				window.draw(ingameui.text2);
				window.draw(ingameui.text3);
				window.draw(ingameui.text4);
				window.draw(ingameui.text5);
				window.draw(ingameui.text6);
				window.draw(ingameui.text7);
				window.draw(ingameui.text9);
				ingameui.CenemyUI_update(pos,ingameui.hit_boss);
				window.draw(ingameui.Nrect);
				window.draw(ingameui.text8);
				// draw tag
				spriteTag.setPosition(center.x + 350, center.y + 400);
				spriteTag.setColor(Color(255, 255, 255, 128));
				window.draw(spriteTag);
				// display
				window.setView(view);
				//
			}
			else if (ingamestate == false)
			{
				window.setView(view);
				igstate.display(true);
				//check cursor on the button
				if (player1.life_state == 1)
				{
					igstate.text.setString("PAUSE");
					if (PixelPerfectTest(spriteCrosshair, igstate.sprite)) //resume
					{
						if (igstate.click(0) == 1)
						{
							ingamestate = true;
							Sleep(50);
						}
					}
					else if (PixelPerfectTest(spriteCrosshair, igstate.Nsprite)) //quit
					{
						if (igstate.click(1) == 2) window.close();
					}
					else if (PixelPerfectTest(spriteCrosshair, igstate.sprite1)) //restart
					{
						if (igstate.click(2) == 3)
						{
							fl.floor = 0;
							fl.lastfloor = -1;
							fl.reset = 0;
							score = 0;
							//player reset
							if (1)
							{
								player1.item_maxhp = 0;
								player1.floor_maxhp = 0;
								player1.max_hp = 0;
								player1.hp = 0;
								//atk
								player1.floor_atk = 0;
								player1.item_atk_string = 0;
								player1.item_atk_counter = 0;
								player1.item_atk_const = 0;
								player1.weapon_atk = 0;
								player1.atk = 0;
								//reduce
								player1.item_reduce_const = 0;
								player1.reduce = 0;
								//armor
								player1.armor_state = 0; // 1 = on , 0 = off
								player1.armor = 0;
								//hit
								player1.hit_counter = 0;
								player1.dash_state = 0;
								player1.dash_count = 0;
								player1.magic_state = 0;
								player1.magic_count = 0;
								player1.magic_duration = 0;
								player1.Nsprite.setColor(Color(255, 255, 255, 0));
								player1.init(0, 0);
								atk1.update(0, 0);
								player1.sprite.setPosition(1280, 1368);
								center = view.getCenter();
								floor_screen.setPosition(center.x + 100, center.y + 100);
							}
							//Vector Array reset
							if (1)
							{
								enemyArray.clear();
								enemy2Array.clear();
								enemy3Array.clear();
								explodeArray.clear();
								witchi.clear();
								witch1atkArray.clear();
								witch1atk2Array.clear();
								witch2atkArray.clear();
								witch2atk2Array.clear();
								witch3atkArray.clear();
								witch3atk2Array.clear();
								witch3defArray.clear();
								witch3def2Array.clear();
								witch4atkArray.clear();
								eneatkArray.clear();
								ene2atkArray.clear();
								ene3atkArray.clear();
								disArray.clear();
								itemArray.clear();
							}
							//Timer Reset
							t.reset();
							ingamestate = true;
							ingame.stop();
							ingame.play();
							goto Re;
							Sleep(50);
						}
					}
					else if (PixelPerfectTest(spriteCrosshair, igstate.sprite2)) //main menu
					{
						if (igstate.click(3) == 4)
						{
							fl.floor = 0;
							fl.lastfloor = -1;
							fl.reset = 0;
							score = 0;
							//player reset
							if (1)
							{
								//atk0
								atk1.counter = 0;
								atk1.delaycounter = 0;
								//player
								player1.item_maxhp = 0;
								player1.floor_maxhp = 0;
								player1.max_hp = 0;
								player1.hp = 0;
								//atk
								player1.floor_atk = 0;
								player1.item_atk_string = 0;
								player1.item_atk_counter = 0;
								player1.item_atk_const = 0;
								player1.weapon_atk = 0;
								player1.atk = 0;
								//reduce
								player1.item_reduce_const = 0;
								player1.reduce = 0;
								//armor
								player1.armor_state = 0; // 1 = on , 0 = off
								player1.armor = 0;
								//hit
								player1.hit_counter = 0;
								player1.dash_state = 0;
								player1.dash_count = 0;
								player1.magic_state = 0;
								player1.magic_count = 0;
								player1.magic_duration = 0;
								player1.Nsprite.setColor(Color(255, 255, 255, 0));
								player1.init(0, 0);
								atk1.update(0, 0);
								player1.sprite.setPosition(1280, 1368);
								center = view.getCenter();
								floor_screen.setPosition(center.x + 100, center.y + 100);
							}
							//Vector Array reset
							if (1)
							{
								enemyArray.clear();
								enemy2Array.clear();
								enemy3Array.clear();
								explodeArray.clear();
								witchi.clear();
								witch1atkArray.clear();
								witch1atk2Array.clear();
								witch2atkArray.clear();
								witch2atk2Array.clear();
								witch3atkArray.clear();
								witch3atk2Array.clear();
								witch3defArray.clear();
								witch3def2Array.clear();
								witch4atkArray.clear();
								eneatkArray.clear();
								ene2atkArray.clear();
								ene3atkArray.clear();
								disArray.clear();
								itemArray.clear();
							}
							//Timer Reset
							t.reset();
							ingamestate = true;
							start = false;
							ingame.stop();
							for (size_t i = 0; i < 255; i++)
							{
								igstate.rect.setFillColor(Color(255, 255, 255, i));
								window.draw(igstate.rect);
								window.display();
								Sleep(1);
							}
							igstate.rect.setFillColor(Color(0, 0, 0, 0));
						}
					}
					else igstate.click(4);
					igstate.text.setPosition(center.x - 75, center.y - 325);
					igstate.sprite.setPosition(center.x, center.y - 150);
					igstate.Nsprite.setPosition(center.x, center.y + 150);
					igstate.sprite1.setPosition(center.x, center.y + 50);
					igstate.sprite2.setPosition(center.x, center.y - 50);
					window.draw(igstate.rect);
					window.draw(igstate.sprite);
					window.draw(igstate.Nsprite);
					window.draw(igstate.sprite1);
					window.draw(igstate.sprite2);
					window.draw(igstate.text);
				}
				else
				{
					igstate.text.setString("ENDED");
					if (ingame.getStatus() == ingame.Playing) ingame.stop();
					if (end.getStatus() == end.Stopped) end.play();
					if (PixelPerfectTest(spriteCrosshair, igstate.Nsprite)) //quit
				{
					if (igstate.click(1) == 2) window.close();
				}
					else if (PixelPerfectTest(spriteCrosshair, igstate.sprite1)) //restart
				{
					if (igstate.click(2) == 3)
					{
						fl.floor = 0;
						fl.lastfloor = -1;
						fl.reset = 0;
						score = 0;
						//player reset
						if (1)
						{
							//atk0
							atk1.counter = 0;
							atk1.delaycounter = 0;
							//player
							player1.item_maxhp = 0;
							player1.floor_maxhp = 0;
							player1.max_hp = 0;
							player1.hp = 0;
							//atk
							player1.floor_atk = 0;
							player1.item_atk_string = 0;
							player1.item_atk_counter = 0;
							player1.item_atk_const = 0;
							player1.weapon_atk = 0;
							player1.atk = 0;
							//reduce
							player1.item_reduce_const = 0;
							player1.reduce = 0;
							//armor
							player1.armor_state = 0; // 1 = on , 0 = off
							player1.armor = 0;
							//hit
							player1.hit_counter = 0;
							player1.dash_state = 0;
							player1.dash_count = 0;
							player1.magic_state = 0;
							player1.magic_count = 0;
							player1.magic_duration = 0;
							player1.Nsprite.setColor(Color(255, 255, 255, 0));
							player1.init(0, 0);
							atk1.update(0, 0);
							player1.sprite.setPosition(1280, 1368);
							center = view.getCenter();
							floor_screen.setPosition(center.x + 100, center.y + 100);
						}
						//Vector Array reset
						if (1)
						{
							enemyArray.clear();
							enemy2Array.clear();
							enemy3Array.clear();
							explodeArray.clear();
							witchi.clear();
							witch1atkArray.clear();
							witch1atk2Array.clear();
							witch2atkArray.clear();
							witch2atk2Array.clear();
							witch3atkArray.clear();
							witch3atk2Array.clear();
							witch3defArray.clear();
							witch3def2Array.clear();
							witch4atkArray.clear();
							eneatkArray.clear();
							ene2atkArray.clear();
							ene3atkArray.clear();
							disArray.clear();
							itemArray.clear();
						}
						//Timer Reset
						t.reset();
						ingamestate = true;
						end.stop();
						ingame.play();
						goto Re;
						Sleep(50);
					}
				}
					else if (PixelPerfectTest(spriteCrosshair, igstate.sprite2)) //main menu
				{
					if (igstate.click(3) == 4)
					{
						fl.floor = 0;
						fl.lastfloor = -1;
						fl.reset = 0;
						score = 0;
						//player reset
						if (1)
						{
							//atk0
							atk1.counter = 0;
							atk1.delaycounter = 0;
							//player
							player1.item_maxhp = 0;
							player1.floor_maxhp = 0;
							player1.max_hp = 0;
							player1.hp = 0;
							//atk
							player1.floor_atk = 0;
							player1.item_atk_string = 0;
							player1.item_atk_counter = 0;
							player1.item_atk_const = 0;
							player1.weapon_atk = 0;
							player1.atk = 0;
							//reduce
							player1.item_reduce_const = 0;
							player1.reduce = 0;
							//armor
							player1.armor_state = 0; // 1 = on , 0 = off
							player1.armor = 0;
							//hit
							player1.hit_counter = 0;
							player1.dash_state = 0;
							player1.dash_count = 0;
							player1.magic_state = 0;
							player1.magic_count = 0;
							player1.magic_duration = 0;
							player1.Nsprite.setColor(Color(255, 255, 255, 0));
							player1.init(0, 0);
							atk1.update(0, 0);
							player1.sprite.setPosition(1280, 1368);
							center = view.getCenter();
							floor_screen.setPosition(center.x + 100, center.y + 100);
						}
						//Vector Array reset
						if (1)
						{
							enemyArray.clear();
							enemy2Array.clear();
							enemy3Array.clear();
							explodeArray.clear();
							witchi.clear();
							witch1atkArray.clear();
							witch1atk2Array.clear();
							witch2atkArray.clear();
							witch2atk2Array.clear();
							witch3atkArray.clear();
							witch3atk2Array.clear();
							witch3defArray.clear();
							witch3def2Array.clear();
							witch4atkArray.clear();
							eneatkArray.clear();
							ene2atkArray.clear();
							ene3atkArray.clear();
							disArray.clear();
							itemArray.clear();
						}
						//Timer Reset
						t.reset();
						ingamestate = true;
						start = false;
						end.stop();
						for (size_t i = 0; i < 255; i++)
						{
							igstate.rect.setFillColor(Color(255, 255, 255, i));
							window.draw(igstate.rect);
							window.display();
							Sleep(1);
						}
						igstate.rect.setFillColor(Color(0, 0, 0, 0));
					}
						name.clear();
				}
					else igstate.click(4);
					igstate.do_score(score,t.t);
					igstate.text.setPosition(center.x - 75, center.y - 325);
					igstate.text2.setPosition(center.x - 100, center.y - 250);
					igstate.text1.setPosition(center.x - 85, center.y - 175);
					igstate.Nsprite.setPosition(center.x, center.y + 150);
					igstate.sprite1.setPosition(center.x, center.y + 50);
					igstate.sprite2.setPosition(center.x, center.y - 50);
					spriteHigh.setPosition(center.x + 250, center.y - 150);
					window.draw(igstate.rect);
					window.draw(igstate.Nsprite);
					window.draw(igstate.sprite1);
					window.draw(igstate.sprite2);
					window.draw(igstate.text);
					window.draw(igstate.text1);
					window.draw(igstate.text2);
					if (highscore) window.draw(spriteHigh);
				}

			}
		}
		}
		else //not start = menu
		{
		if(menu.getStatus() != menu.Playing) menu.play();
			if (1)
		{
			playerName.setPosition(center.x,center.y + 500);
			spritePointer.setPosition(Mpos);
			view.setSize(2560, 1444);
			window.setView(view);
			spriteHow.setPosition(center);
			spriteBack00.setPosition(center);
			spriteBack01.setPosition(center);
			spriteRanking.setPosition(center);
			spriteBack.setPosition(center);
			spriteBack0.setPosition(center);
			spriteTextField.setPosition(center);
			spriteMenu.setPosition(center);
			spriteStart.setPosition(center);
			spriteStart0.setPosition(center);
			spriteQuit.setPosition(center);
			spriteQuit0.setPosition(center);
			spriteRank.setPosition(center);
			spriteRank0.setPosition(center);
			spriteHowto.setPosition(center);
			spriteHowto0.setPosition(center);
			window.draw(spriteTextField);
			window.draw(spriteMenu);
			window.draw(spriteStart0);
			window.draw(spriteQuit0);
			window.draw(spriteRank0);
			window.draw(spriteHowto0);
		}
			if (rank)
			{
				if (1)
				{
					window.draw(spriteRanking);
					window.draw(spriteBack0);
					if (PixelPerfectTest(spriteBack0, spriteCrosshair))
					{
						window.draw(spriteBack);
						if (Mouse::isButtonPressed(Mouse::Left)) rank = false;
					}
					//get value
					ranking = fopen("ranking.txt", "r");
					if (ranking == NULL) printf_s("Failed to open ranking.txt\n");
					else
					{
						//name, time, score
						//1st
						fgets(line1_1, 15, ranking);
						fgets(line1_2, 15, ranking);
						fgets(line1_3, 15, ranking);
						//2nd
						fgets(line2_1, 15, ranking);
						fgets(line2_2, 15, ranking);
						fgets(line2_3, 15, ranking);
						//3rd
						fgets(line3_1, 15, ranking);
						fgets(line3_2, 15, ranking);
						fgets(line3_3, 15, ranking);
						//4th
						fgets(line4_1, 15, ranking);
						fgets(line4_2, 15, ranking);
						fgets(line4_3, 15, ranking);
						//5th
						fgets(line5_1, 15, ranking);
						fgets(line5_2, 15, ranking);
						fgets(line5_3, 15, ranking);
						if (fclose(ranking) == EOF) printf_s("Error closing ranking.txt\n");
					}
					//set value to display
					if (1)
					{
						l1.setFont(font);
						l2.setFont(font);
						l3.setFont(font);
						l4.setFont(font);
						l5.setFont(font);
						l6.setFont(font);
						l7.setFont(font);
						l8.setFont(font);
						l9.setFont(font);
						l10.setFont(font);
						l11.setFont(font);
						l12.setFont(font);
						l13.setFont(font);
						l14.setFont(font);
						l15.setFont(font);
						l1.setCharacterSize(128);
						l2.setCharacterSize(128);
						l3.setCharacterSize(128);
						l4.setCharacterSize(120);
						l5.setCharacterSize(120);
						l6.setCharacterSize(120);
						l7.setCharacterSize(112);
						l8.setCharacterSize(112);
						l9.setCharacterSize(112);
						l10.setCharacterSize(104);
						l11.setCharacterSize(104);
						l12.setCharacterSize(104);
						l13.setCharacterSize(96);
						l14.setCharacterSize(96);
						l15.setCharacterSize(96);
						l1.setFillColor(Color::White);
						l2.setFillColor(Color::White);
						l3.setFillColor(Color::White);
						l4.setFillColor(Color::White);
						l5.setFillColor(Color::White);
						l6.setFillColor(Color::White);
						l7.setFillColor(Color::White);
						l8.setFillColor(Color::White);
						l9.setFillColor(Color::White);

						l10.setFillColor(Color::White);
						l11.setFillColor(Color::White);
						l12.setFillColor(Color::White);
						l13.setFillColor(Color::White);
						l14.setFillColor(Color::White);
						l15.setFillColor(Color::White);
						l1.setPosition(center.x - 400, center.y - 250);
						l2.setPosition(center.x + 75, center.y - 250);
						l3.setPosition(center.x + 700, center.y - 250);
						l4.setPosition(center.x - 400, center.y - 75);
						l5.setPosition(center.x + 75, center.y - 75);
						l6.setPosition(center.x + 700, center.y - 75);
						l7.setPosition(center.x - 400, center.y + 90);
						l8.setPosition(center.x + 75, center.y + 90);
						l9.setPosition(center.x + 700, center.y + 90);
						l10.setPosition(center.x - 400, center.y + 250);
						l11.setPosition(center.x + 75, center.y + 250);
						l12.setPosition(center.x + 700, center.y + 250);
						l13.setPosition(center.x - 400, center.y + 415);
						l14.setPosition(center.x + 75, center.y + 415);
						l15.setPosition(center.x + 700, center.y + 415);
					}
					//1st
					l1.setString(line1_1);
					l2.setString(line1_2);
					l3.setString(line1_3);
					//2nd
					l4.setString(line2_1);
					l5.setString(line2_2);
					l6.setString(line2_3);
					//3rd
					l7.setString(line3_1);
					l8.setString(line3_2);
					l9.setString(line3_3);
					//4th
					l10.setString(line4_1);
					l11.setString(line4_2);
					l12.setString(line4_3);
					//5th
					l13.setString(line5_1);
					l14.setString(line5_2);
					l15.setString(line5_3);
					//draw
					if (1)
					{
						window.draw(l1);
						window.draw(l2);
						window.draw(l3);
						window.draw(l4);
						window.draw(l5);
						window.draw(l6);
						window.draw(l7);
						window.draw(l8);
						window.draw(l9);
						window.draw(l10);
						window.draw(l11);
						window.draw(l12);
						window.draw(l13);
						window.draw(l14);
						window.draw(l15);
					}						
				}
			}
			else if (howto)
			{
				if (1)
				{
					window.draw(spriteHow);
					window.draw(spriteBack00);
					if (PixelPerfectTest(spriteBack00, spriteCrosshair))
					{
						window.draw(spriteBack01);
						if (Mouse::isButtonPressed(Mouse::Left)) howto = false;
					}
				}
			}
			else
			{
				if (PixelPerfectTest(spriteCrosshair, spriteStart0))
				{
					window.draw(spriteStart);
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						start = true;
						view.setSize((res.horizontal / 24) * 20, (res.vertical / 24) * 20);
						view.setCenter(1280, 720); window.setView(view);
						center = view.getCenter();
						floor_screen.setPosition(center.x + 100, center.y + 100);
						menu.stop();
						ingame.play();
					}
				}
				if (PixelPerfectTest(spritePointer, spriteQuit0))
				{
					window.draw(spriteQuit);
					if (Mouse::isButtonPressed(Mouse::Left)) { window.close(); }
				}
				if (PixelPerfectTest(spritePointer, spriteRank0))
				{
					window.draw(spriteRank);
					if (Mouse::isButtonPressed(Mouse::Left)) { rank = true; }
				}
				if (PixelPerfectTest(spritePointer, spriteHowto0))
				{
					window.draw(spriteHowto);
					if (Mouse::isButtonPressed(Mouse::Left)) { howto = true; }
				}
				if (PixelPerfectTest(spritePointer, spriteTextField) && Mouse::isButtonPressed(Mouse::Left))
				{
					enterName = true;
				}
				else if (!PixelPerfectTest(spritePointer, spriteTextField) && Mouse::isButtonPressed(Mouse::Left))
				{
					enterName = false;
				}
				if (enterName)
				{
					if (Keyboard::isKeyPressed(Keyboard::Backspace) && key == 0)
					{
						if (name.getSize() != 0)
						{
							cname[name.getSize() - 1] = ' ';
							name.erase(name.getSize() - 1, 1);
							playerName.setString(name);
							key = 8;
						}
					}
					else if (event.type == sf::Event::TextEntered && name.getSize() < 14 && key == 0)
					{
						name += event.text.unicode;
						playerName.setString(name);
						key = 8;
						cname[name.getSize() - 1] = event.text.unicode;
					}
				}
				if (key != 0) key -= 1;
				window.draw(playerName);
			}
		}
		// draw crosshair
		spriteCrosshair.setPosition(Mpos);
		if(!start) window.draw(spritePointer);
		else window.draw(spriteCrosshair);
		//display anything
		window.setView(view);
		window.display();
	} // end gameloop

	return 0;
}

bool do_rank(char* t,const char* n,int score, int hrs,int min, int sec)
{
	bool hs = true;
	char sscore[15];
	convertToStr(score, sscore);
	//get value to arrange
	ranking = fopen("ranking.txt","r");
	if (ranking == NULL) printf_s("Failed to open ranking.txt\n");
	else
	{
		//name, time, score
		//1st
		fgets(line1, 15, ranking);
		fgets(line2, 15, ranking);
		fgets(line3, 15, ranking);
		//2nd
		fgets(line4, 15, ranking);
		fgets(line5, 15, ranking);
		fgets(line6, 15, ranking);
		//3rd
		fgets(line7, 15, ranking);
		fgets(line8, 15, ranking);
		fgets(line9, 15, ranking);
		//4th
		fgets(line10, 15, ranking);
		fgets(line11, 15, ranking);
		fgets(line12, 15, ranking);
		//5th
		fgets(line13, 15, ranking);
		fgets(line14, 15, ranking);
		fgets(line15, 15, ranking);
		if (fclose(ranking) == EOF) printf_s("Error closing ranking.txt\n");
	}
	//arrange and input
	ranking = fopen("ranking.txt", "w");
	if (ranking == NULL) printf_s("Failed to open ranking.txt\n");
	else
	{
		//arrange
		//line 3 6 9 12 15 = score //line score-1 = time
		convertTime(line2, &hrs1, &min1, &sec1);
		convertTime(line5, &hrs2, &min2, &sec2);
		convertTime(line8, &hrs3, &min3, &sec3);
		convertTime(line11, &hrs4, &min4, &sec4);
		convertTime(line14, &hrs5, &min5, &sec5);
		convertToSec(&sOut, hrs, min, sec);
		convertToSec(&sIn1, hrs1, min1, sec1);
		convertToSec(&sIn2, hrs2, min2, sec2);
		convertToSec(&sIn3, hrs3, min3, sec3);
		convertToSec(&sIn4, hrs4, min4, sec4);
		convertToSec(&sIn5, hrs5, min5, sec5);
		add0(t);
		printf_s("%d %d %d %d %d %d\n",sOut, sIn1, sIn2, sIn3, sIn4, sIn5);
		if (score > convertToInt(line3))
		{
			printf_s("your score is more than 1st rank\n");
			fputs(n, ranking); fputs("\n", ranking);
			fputs(t, ranking); fputs("\n", ranking);
			fputs(sscore, ranking); fputs("\n", ranking);
			fputs(line1, ranking); 
			fputs(line2, ranking); 
			fputs(line3, ranking); 
			fputs(line4, ranking); 
			fputs(line5, ranking); 
			fputs(line6, ranking); 
			fputs(line7, ranking); 
			fputs(line8, ranking); 
			fputs(line9, ranking); 
			fputs(line10, ranking); 
			fputs(line11, ranking); 
			fputs(line12, ranking); 
		}
		else if (score <= convertToInt(line3))
		{
			if (sOut <= sIn1 && score == convertToInt(line3))
			{
				printf_s("your time faster than 1st rank\n");
				fputs(n, ranking); fputs("\n", ranking);
				fputs(t, ranking); fputs("\n", ranking);
				fputs(sscore, ranking); fputs("\n", ranking);
				fputs(line1, ranking);
				fputs(line2, ranking);
				fputs(line3, ranking);
				fputs(line4, ranking);
				fputs(line5, ranking);
				fputs(line6, ranking);
				fputs(line7, ranking);
				fputs(line8, ranking);
				fputs(line9, ranking);
				fputs(line10, ranking);
				fputs(line11, ranking);
				fputs(line12, ranking);
			}
			else
			{
				printf_s("your time slower than 1st rank\n");
				if (score > convertToInt(line6))
				{
					printf_s("your score is more than 2nd rank\n");
					fputs(line1, ranking);
					fputs(line2, ranking);
					fputs(line3, ranking);
					fputs(n, ranking); fputs("\n", ranking);
					fputs(t, ranking); fputs("\n", ranking);
					fputs(sscore, ranking); fputs("\n", ranking);
					fputs(line4, ranking);
					fputs(line5, ranking);
					fputs(line6, ranking);
					fputs(line7, ranking);
					fputs(line8, ranking);
					fputs(line9, ranking);
					fputs(line10, ranking);
					fputs(line11, ranking);
					fputs(line12, ranking);
				}
				else if (score <= convertToInt(line6))
				{
					if (sOut <= sIn2 && score == convertToInt(line6))
					{
						printf_s("your time faster than 2nd rank\n");
						fputs(line1, ranking);
						fputs(line2, ranking);
						fputs(line3, ranking);
						fputs(n, ranking); fputs("\n", ranking);
						fputs(t, ranking); fputs("\n", ranking);
						fputs(sscore, ranking); fputs("\n", ranking);
						fputs(line4, ranking);
						fputs(line5, ranking);
						fputs(line6, ranking);
						fputs(line7, ranking);
						fputs(line8, ranking);
						fputs(line9, ranking);
						fputs(line10, ranking);
						fputs(line11, ranking);
						fputs(line12, ranking);
					}
					else
					{
						printf_s("your time slower than 2nd rank\n");
						if (score > convertToInt(line9))
						{
							printf_s("your score is more than 3rd rank\n");
							fputs(line1, ranking);
							fputs(line2, ranking);
							fputs(line3, ranking);
							fputs(line4, ranking);
							fputs(line5, ranking);
							fputs(line6, ranking);
							fputs(n, ranking); fputs("\n", ranking);
							fputs(t, ranking); fputs("\n", ranking);
							fputs(sscore, ranking); fputs("\n", ranking);
							fputs(line7, ranking);
							fputs(line8, ranking);
							fputs(line9, ranking);
							fputs(line10, ranking);
							fputs(line11, ranking);
							fputs(line12, ranking);
						}
						else if (score <= convertToInt(line9))
						{
							if (sOut <= sIn3 && score == convertToInt(line9))
							{
								printf_s("your time faster than 3rd rank\n");
								fputs(line1, ranking);
								fputs(line2, ranking);
								fputs(line3, ranking);
								fputs(line4, ranking);
								fputs(line5, ranking);
								fputs(line6, ranking);
								fputs(n, ranking); fputs("\n", ranking);
								fputs(t, ranking); fputs("\n", ranking);
								fputs(sscore, ranking); fputs("\n", ranking);
								fputs(line7, ranking);
								fputs(line8, ranking);
								fputs(line9, ranking);
								fputs(line10, ranking);
								fputs(line11, ranking);
								fputs(line12, ranking);
							}
							else
							{
								if (score > convertToInt(line12))
								{
								printf_s("your score is more than 4th rank\n");
								fputs(line1, ranking);
								fputs(line2, ranking);
								fputs(line3, ranking);
								fputs(line4, ranking);
								fputs(line5, ranking);
								fputs(line6, ranking);
								fputs(line7, ranking);
								fputs(line8, ranking);
								fputs(line9, ranking);
								fputs(n, ranking); fputs("\n", ranking);
								fputs(t, ranking); fputs("\n", ranking);
								fputs(sscore, ranking); fputs("\n", ranking);
								fputs(line10, ranking);
								fputs(line11, ranking);
								fputs(line12, ranking);
								}
								else if (score <= convertToInt(line12))
								{
									if (sOut <= sIn4 && score == convertToInt(line12))
									{
										printf_s("your time faster than 4th rank\n");
										fputs(line1, ranking);
										fputs(line2, ranking);
										fputs(line3, ranking);
										fputs(line4, ranking);
										fputs(line5, ranking);
										fputs(line6, ranking);
										fputs(line7, ranking);
										fputs(line8, ranking);
										fputs(line9, ranking);
										fputs(n, ranking); fputs("\n", ranking);
										fputs(t, ranking); fputs("\n", ranking);
										fputs(sscore, ranking); fputs("\n", ranking);
										fputs(line10, ranking);
										fputs(line11, ranking);
										fputs(line12, ranking);
									}
									else
									{
										printf_s("your time slower than 4th rank\n");
										if (score > convertToInt(line15))
										{
											printf_s("your score is more than 5th rank\n");
											fputs(line1, ranking);
											fputs(line2, ranking);
											fputs(line3, ranking);
											fputs(line4, ranking);
											fputs(line5, ranking);
											fputs(line6, ranking);
											fputs(line7, ranking);
											fputs(line8, ranking);
											fputs(line9, ranking);
											fputs(line10, ranking);
											fputs(line11, ranking);
											fputs(line12, ranking);
											fputs(n, ranking); fputs("\n", ranking);
											fputs(t, ranking); fputs("\n", ranking);
											fputs(sscore, ranking); fputs("\n", ranking);
										}
										else if (score <= convertToInt(line15))
										{
											if (sOut <= sIn5 && score == convertToInt(line15))
											{
												printf_s("your time faster than 5th rank\n");
												fputs(line1, ranking);
												fputs(line2, ranking);
												fputs(line3, ranking);
												fputs(line4, ranking);
												fputs(line5, ranking);
												fputs(line6, ranking);
												fputs(line7, ranking);
												fputs(line8, ranking);
												fputs(line9, ranking);
												fputs(line10, ranking);
												fputs(line11, ranking);
												fputs(line12, ranking);
												fputs(n, ranking); fputs("\n", ranking);
												fputs(t, ranking); fputs("\n", ranking);
												fputs(sscore, ranking); fputs("\n", ranking);
											}
											else
											{
												hs = false;
												printf_s("your time slower than 5th rank\n");
												fputs(line1, ranking);
												fputs(line2, ranking);
												fputs(line3, ranking);
												fputs(line4, ranking);
												fputs(line5, ranking);
												fputs(line6, ranking);
												fputs(line7, ranking);
												fputs(line8, ranking);
												fputs(line9, ranking);
												fputs(line10, ranking);
												fputs(line11, ranking);
												fputs(line12, ranking);
												fputs(line13, ranking);
												fputs(line14, ranking);
												fputs(line15, ranking);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (fclose(ranking) == EOF) printf_s("Error closing ranking.txt\n");
		return hs;
	}
}
int convertToInt(char* input)
{
	///only array of char which have only numbers
	int returned = 0;
	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	i--;
	if (i > 4)
	{
		returned = (input[0] - '0') * 10000 +(input[1] - '0') * 1000 + (input[2] - '0') * 100 + (input[3] - '0') * 10 + (input[4] - '0') * 1;
	}
	else if (i > 3)
	{
		returned = (input[0]-'0') * 1000 + (input[1]-'0') * 100 + (input[2]-'0') * 10 + (input[3]-'0') * 1;
	}
	else if (i > 2)
	{
		returned = (input[0]-'0') * 100 + (input[1]-'0') * 10 + (input[2]-'0') * 1;
	}
	else if (i > 1)
	{
		returned = (input[0]-'0') * 10 + (input[1]-'0') * 1;
	}
	else
	{
		returned = (input[0]-'0') * 1;
	}
	return returned;
}
void convertToStr(int input,char* returned)
{
	///only array of char which have only numbers
	int i = 0;
	if (input > 9999)
	{
		returned[0] = input / 10000 + '0';
		returned[1] = (input / 1000) % 10 + '0';
		returned[2] = (input / 100) % 10 + '0';
		returned[3] = (input / 10) % 10 + '0';
		returned[4] = input % 10 + '0';
	}
	else if (input > 999)
	{
		returned[0] = input / 1000 + '0';
		returned[1] = (input / 100) % 10 + '0';
		returned[2] = (input / 10) % 10 + '0';
		returned[3] = input % 10 + '0';
		returned[4] = '\0';
	}
	else if (input > 99)
	{
		returned[0] = input / 100 + '0';
		returned[1] = (input / 10) % 10 + '0';
		returned[2] = input % 10 + '0';
		returned[3] = '\0';
		returned[4] = '\0';
	}
	else if (input > 9)
	{
		returned[0] = input / 10 + '0';
		returned[1] = input % 10 + '0';
		returned[2] = '\0';
		returned[3] = '\0';
		returned[4] = '\0';
	}
	else
	{
		returned[0] = input + '0';
		returned[1] = '\0';
		returned[2] = '\0';
		returned[3] = '\0';
		returned[4] = '\0';
	}
	returned[5] = ' ';
	for (size_t i = 6; i < 15; i++)
	{
		returned[i] = '\0';
	}
}
void convertTime(char* input, int* h, int* m, int* s)
{
	//00:00:00
	// 0: 0: 0
	//01234567
	if (input[0] == ' ')
	{
		*h = input[1] - '0';
	}
	else
	{
		*h = (input[0] - '0') * 10 + (input[1] - '0');
	}
	if (input[3] == ' ')
	{
		*m = input[4] - '0';
	}
	else
	{
		*m = (input[3] - '0') * 10 + (input[4] - '0');
	}
	if (input[6] == ' ')
	{
		*s = input[7] - '0';
	}
	else
	{
		*s = (input[6] - '0') * 10 + (input[7] - '0');
	}
}
void convertToSec(int* sout,int h,int m,int s)
{
	*sout = h * 3600 + m * 60 + s;
}
void add0(char* input)
{
	//00:00:00
	// 0: 0: 0
	//01234567
	if (input[0] == ' ')
	{
		*(input+0) = '0';
	}
	if (input[3] == ' ')
	{
		*(input+3) = '0';
	}
	if (input[6] == ' ')
	{
		*(input+6) = '0';
	}
}