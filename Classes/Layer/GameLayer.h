#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_

#include "cocos2d.h"
#include "../Constant/Constant.h"
#include "../Action/Actions.h"
#include "../Flake/Flake.h"
#include "../Res/Res.h"
#include "../AStar/F.h"

using namespace std;
using namespace cocos2d;

class Game: public Layer {
public:
	bool init();

	void setMode(int mode, int level, int map[8][8], int value[8][8]);
	void setMode(int mode, int level, int map[9][9], int value[9][9]);
	void setMode(int mode, int level, int map[10][10], int value[10][10]);
	void setFinishCallback(function<void()> callback);
	void actionLoadIn();
	void actionLoadOut(function<void()> callback);

	bool isInAction = false;
	int score = 0;

	Vector<MenuItem*> vectorMenuGrid;
	MenuItemImage* menuBack;

	CREATE_FUNC (Game);
private:
	void initialize();
	void initLabel();
	void initSprite();
	void initMenu();
	void menuRoleCallback(Ref* pSender);
	void menuGridCallback(Ref* pSender);
	void moveRoleAtRoad();
	void setMenuStatus(MenuItemImage* item, bool isClickable, bool isEnd);
	void addScore();
	void finishGame();
	bool isFlakeClickable(int x, int y);

	int gameMode;
	int level = 0;
	int currentY = 0;
	int currentX = 0;
	int valueEasy[8][8];
	int mapEasy[8][8];
	int valueNormal[9][9];
	int mapNormal[9][9];
	int valueHard[10][10];
	int mapHard[10][10];

	Flake flake;
	ValueVector valueVec;
	Label* labelBack;
	Label* labelRole;
	Sprite* spriteBackground;
	MenuItemImage* menuRole;
	MenuItemImage* menuEnd;
	Vector<MenuItem*> vectorCheck;
	function<void()> finishCallback;
};

#endif
