#ifndef _FINISH_LAYER_H_
#define _FINISH_LAYER_H_

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class Finish: public Layer {
public:
	bool init();
	void setScore(int score);
	void actionIn();
	void actionOut(function<void()> callback);

	MenuItemImage* menuRestart;
	MenuItemImage* menuNext;
	MenuItemImage* menuBack;
	bool isInAction = false;

	CREATE_FUNC (Finish);
private:
	void initialize();
	void initLabel();
	void initSprite();
	void initMenu();

	ValueVector valueVec;
	Sprite* spriteBackground;
	Label* labelPrompt;
	Label* labelScore;
	Label* labelRestart;
	Label* labelNext;
	Label* labelBack;
};

#endif
