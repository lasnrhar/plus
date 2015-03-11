#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "../Constant/Constant.h"
#include "../Constant/LevelManager.h"
#include "../Res/Res.h"
#include "../Action/Actions.h"
#include "../Layer/LoadLayer.h"
#include "../Layer/GameLayer.h"
#include "../Layer/FinishLayer.h"
#include "../Layer/SelectLayer.h"

using namespace std;
using namespace cocos2d;

class Main: public Layer {
public:
	static Scene* createScene();
	virtual bool init();

	void finishMenuRestartCallback(Ref* pSender);
	void finishMenuNextCallback(Ref* pSender);
	void finishMenuBackCallback(Ref* pSender);

	CREATE_FUNC (Main);
private:
	void initialize();
	void initLabel();
	void initSprite();
	void initMenu();
	void setMode();

	void menuStartCallback(Ref* pSender);
	void menuSettingCallback(Ref* pSender);
	void menuExitCallback(Ref* pSender);
	void menuStartEasyCallback(Ref* pSender);
	void menuStartNormalCallback(Ref* pSender);
	void menuStartHardCallback(Ref* pSender);
	void menuSettingMusicCallback(Ref* pSender);
	void menuSettingSoundCallback(Ref* pSender);
	void menuExitYesCallback(Ref* pSender);
	void menuExitNoCallback(Ref* pSender);
	void gameMenuBackCallback(Ref* pSender);

	void actionLoadIn();
	void actionLoadOut(function<void()> callback);
	void actionMenuStartIn();
	void actionMenuStartOut(function<void()> callback);
	void actionMenuSettingIn();
	void actionMenuSettingOut(function<void()> callback);
	void actionMenuExitIn();
	void actionMenuExitOut(function<void()> callback);

	void startWithMode(int mode);
	void switchSound(bool isPlaySound);
	void switchMusic(bool isPlayMusic);

	ValueVector valueVec;
	Game* game;
	Finish* finish;
	Select* select;

	bool isClickStart = false;
	bool isClickSetting = false;
	bool isClickExit = false;
	bool isPlaySound = true;
	bool isPlayMusic = true;
	bool isInAction = false;
	int mode = 0;
	int level = 0;

	Sprite* spriteTitle;

	MenuItemImage* menuStart;
	MenuItemImage* menuSetting;
	MenuItemImage* menuExit;
	MenuItemImage* menuStartEasy;
	MenuItemImage* menuStartNormal;
	MenuItemImage* menuStartHard;
	MenuItemImage* menuSettingMusic;
	MenuItemImage* menuSettingSound;
	MenuItemImage* menuExitYes;
	MenuItemImage* menuExitNo;

	Label* labelTitle;
	Label* labelStart;
	Label* labelSetting;
	Label* labelExit;
	Label* labelStartEasy;
	Label* labelStartNormal;
	Label* labelStartHard;
	Label* labelSettingMusic;
	Label* labelSettingSound;
	Label* labelExitYes;
	Label* labelExitNo;
};

#endif
