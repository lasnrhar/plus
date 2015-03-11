#include "MainScene.h"

Scene* Main::createScene() {
	auto scene = Scene::create();
	auto layer = Main::create();
	scene->addChild(layer);
	return scene;
}

bool Main::init() {
	if (!Layer::init()) {
		return false;
	}
	Load* load = Load::create();
	this->addChild(load, 10);
	load->loading([&]() {initialize();}, [&]() {actionLoadIn();});
	return true;
}

void Main::initialize() {
	valueVec = FileUtils::getInstance()->getValueVectorFromFile(XML_NAME_EN);

	game = Game::create();
	game->menuBack->setCallback(CC_CALLBACK_1(Main::gameMenuBackCallback, this));
	this->addChild(game, 6);

	finish = Finish::create();
	finish->menuRestart->setCallback(CC_CALLBACK_1(Main::finishMenuRestartCallback, this));
	finish->menuNext->setCallback(CC_CALLBACK_1(Main::finishMenuNextCallback, this));
	finish->menuBack->setCallback(CC_CALLBACK_1(Main::finishMenuBackCallback, this));
	this->addChild(finish, 10);

	select = Select::create();
	select->setSelectCallback([&](int level) {this->level=level;setMode();select->actionOut([&]() {game->actionLoadIn();});});
	select->setBackCallback([&]() {actionLoadIn();level=0;});
	this->addChild(select, 8);

	setBoolValue(KEY_EASYISLOCK + getStringByInt(0), false);
	setBoolValue(KEY_NORMALISLOCK + getStringByInt(0), false);
	setBoolValue(KEY_HARDISLOCK + getStringByInt(0), false);

	initLabel();
	initSprite();
	initMenu();
}

void Main::initLabel() {
	labelTitle = Label::create(getString(valueVec, MAIN_STRING_SPRITE_TITLE), FONT_TEMPSITC, FONT_SIZE_TITLE);
	labelTitle->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 120);
	this->addChild(labelTitle, 2);
	labelStart = Label::create(getString(valueVec, MAIN_STRING_MENU_START), FONT_TEMPSITC, FONT_SIZE_MENU);
	labelStart->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 360);
	labelStart->setColor(Color3B::BLACK);
	this->addChild(labelStart, 2);
	labelSetting = Label::create(getString(valueVec, MAIN_STRING_MENU_SETTING), FONT_TEMPSITC, FONT_SIZE_MENU);
	labelSetting->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 600);
	this->addChild(labelSetting, 2);
	labelExit = Label::create(getString(valueVec, MAIN_STRING_MENU_EXIT), FONT_TEMPSITC, FONT_SIZE_MENU);
	labelExit->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 840);
	labelExit->setColor(Color3B::BLACK);
	this->addChild(labelExit, 2);

	labelStartEasy = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_EASY), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	labelStartEasy->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 280);
	this->addChild(labelStartEasy, 4);
	labelStartNormal = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_NORMAL), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	labelStartNormal->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 360);
	this->addChild(labelStartNormal, 4);
	labelStartHard = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_HARD), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	labelStartHard->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 440);
	this->addChild(labelStartHard, 4);

	isPlayMusic = getBoolValue(KEY_ISPLAYMUSIC, true);
	if (isPlayMusic == false) {
		labelSettingMusic = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_MUSIC_CLOSE), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	} else {
		labelSettingMusic = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_MUSIC), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	}
	labelSettingMusic->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 540);
	labelSettingMusic->setColor(Color3B::BLACK);
	this->addChild(labelSettingMusic, 4);
	isPlaySound = getBoolValue(KEY_ISPLAYSOUND, true);
	if (isPlaySound == false) {
		labelSettingSound = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_SOUND_CLOSE), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	} else {
		labelSettingSound = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_SOUND), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	}
	labelSettingSound->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 660);
	labelSettingSound->setColor(Color3B::BLACK);
	this->addChild(labelSettingSound, 4);

	labelExitYes = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_EXIT_YES), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	labelExitYes->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 780);
	this->addChild(labelExitYes, 4);
	labelExitNo = Label::create(getString(valueVec, MAIN_STRING_MENU_POP_EXIT_NO), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	labelExitNo->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 900);
	this->addChild(labelExitNo, 4);
}

void Main::initSprite() {
	auto spriteBackGround = Sprite::create(MAIN_SPRITE_BACK_GROUND);
	spriteBackGround->setPosition(CONSTANT_WIDTH / 2, CONSTANT_HIGH / 2);
	this->addChild(spriteBackGround, 0);

	spriteTitle = Sprite::create(MAIN_MENU_BLACK);
	spriteTitle->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 120);
	this->addChild(spriteTitle, 1);
}

void Main::initMenu() {
	menuStart = MenuItemImage::create(MAIN_MENU_WHITE, MAIN_MENU_GRAY, CC_CALLBACK_1(Main::menuStartCallback, this));
	menuStart->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 360);
	menuSetting = MenuItemImage::create(MAIN_MENU_BLACK, MAIN_MENU_GRAY, CC_CALLBACK_1(Main::menuSettingCallback, this));
	menuSetting->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 600);
	menuExit = MenuItemImage::create(MAIN_MENU_WHITE, MAIN_MENU_GRAY, CC_CALLBACK_1(Main::menuExitCallback, this));
	menuExit->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 840);
	auto menu = Menu::create(menuStart, menuSetting, menuExit, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	menuStartEasy = MenuItemImage::create(MAIN_MENU_POP_BLACK_3, MAIN_MENU_POP_GRAY_3, CC_CALLBACK_1(Main::menuStartEasyCallback, this));
	menuStartEasy->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 280);
	menuStartNormal = MenuItemImage::create(MAIN_MENU_POP_BLACK_3, MAIN_MENU_POP_GRAY_3, CC_CALLBACK_1(Main::menuStartNormalCallback, this));
	menuStartNormal->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 360);
	menuStartHard = MenuItemImage::create(MAIN_MENU_POP_BLACK_3, MAIN_MENU_POP_GRAY_3, CC_CALLBACK_1(Main::menuStartHardCallback, this));
	menuStartHard->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 440);
	auto menuStart = Menu::create(menuStartEasy, menuStartNormal, menuStartHard, NULL);
	menuStart->setPosition(Vec2::ZERO);
	this->addChild(menuStart, 3);

	menuSettingMusic = MenuItemImage::create(MAIN_MENU_POP_WHITE_2, MAIN_MENU_POP_GRAY_2, CC_CALLBACK_1(Main::menuSettingMusicCallback, this));
	menuSettingMusic->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 540);
	menuSettingSound = MenuItemImage::create(MAIN_MENU_POP_WHITE_2, MAIN_MENU_POP_GRAY_2, CC_CALLBACK_1(Main::menuSettingSoundCallback, this));
	menuSettingSound->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 660);
	auto menuSetting = Menu::create(menuSettingMusic, menuSettingSound, NULL);
	menuSetting->setPosition(Vec2::ZERO);
	this->addChild(menuSetting, 3);

	menuExitYes = MenuItemImage::create(MAIN_MENU_POP_BLACK_2, MAIN_MENU_POP_GRAY_2, CC_CALLBACK_1(Main::menuExitYesCallback, this));
	menuExitYes->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 780);
	menuExitNo = MenuItemImage::create(MAIN_MENU_POP_BLACK_2, MAIN_MENU_POP_GRAY_2, CC_CALLBACK_1(Main::menuExitNoCallback, this));
	menuExitNo->setPosition(CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 900);
	auto menuExit = Menu::create(menuExitYes, menuExitNo, NULL);
	menuExit->setPosition(Vec2::ZERO);
	this->addChild(menuExit, 3);
}

void Main::setMode() {
	switch (mode) {
	case GAME_MODE_EASY_8: {
		int (*map)[8] = getEasyMap(level);
		int (*value)[8] = getEasyValue(level);
		game->setMode(mode, level, map, value);
	}
		break;
	case GAME_MODE_NORMAL_9: {
		int (*map)[9] = getNormalMap(level);
		int (*value)[9] = getNormalValue(level);
		game->setMode(mode, level, map, value);
	}
		break;
	case GAME_MODE_HARD_10: {
		int (*map)[10] = getHardMap(level);
		int (*value)[10] = getHardValue(level);
		game->setMode(mode, level, map, value);
	}
		break;
	}
	game->setFinishCallback([&]() {finish->setScore(game->score);game->actionLoadOut([&]() {finish->actionIn();});});
}

void Main::actionLoadIn() {
	isInAction = true;
	moveTo(spriteTitle, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 120, 0.4f);
	moveTo(labelTitle, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 120, 0.4f);

	moveTo(menuStart, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 360, 0.4f);
	moveTo(labelStart, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 360, 0.4f);

	moveTo(menuSetting, 0.2f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 600, 0.4f);
	moveTo(labelSetting, 0.2f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 600, 0.4f);

	moveTo(menuExit, 0.3f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 840, 0.4f);
	moveTo(labelExit, 0.3f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 840, 0.4f, [&]() {isInAction=false;});
}

void Main::actionLoadOut(function<void()> callback) {
	if (isClickStart == true) {
		actionMenuStartOut(nullptr);
		isClickStart = false;
	}
	if (isClickSetting == true) {
		actionMenuSettingOut(nullptr);
		isClickSetting = false;
	}
	if (isClickExit == true) {
		actionMenuExitOut(nullptr);
		isClickExit = false;
	}
	isInAction = true;
	moveTo(spriteTitle, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 120, 0.4f);
	moveTo(labelTitle, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 120, 0.4f);

	moveTo(menuStart, 0.1f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 360, 0.4f);
	moveTo(labelStart, 0.1f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 360, 0.4f);

	moveTo(menuSetting, 0.2f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 600, 0.4f);
	moveTo(labelSetting, 0.2f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 600, 0.4f);

	moveTo(menuExit, 0.3f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 840, 0.4f, [&]() {isInAction=false;});
	moveTo(labelExit, 0.3f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 840, 0.4f, callback);
}

void Main::actionMenuStartIn() {
	if (isClickSetting == true) {
		actionMenuSettingOut(nullptr);
		isClickSetting = false;
	}
	if (isClickExit == true) {
		actionMenuExitOut(nullptr);
		isClickExit = false;
	}
	isInAction = true;
	moveTo(menuStartEasy, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 280, 0.4f);
	moveTo(labelStartEasy, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 280, 0.4f);

	moveTo(menuStartNormal, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 360, 0.4f);
	moveTo(labelStartNormal, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 360, 0.4f);

	moveTo(menuStartHard, 0.2f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 440, 0.4f);
	moveTo(labelStartHard, 0.2f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 440, 0.4f, [&]() {isInAction=false;});
}

void Main::actionMenuStartOut(function<void()> callback) {
	isInAction = true;
	moveTo(menuStartEasy, 0.0f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 280, 0.4f);
	moveTo(labelStartEasy, 0.0f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 280, 0.4f);

	moveTo(menuStartNormal, 0.1f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 360, 0.4f);
	moveTo(labelStartNormal, 0.1f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 360, 0.4f);

	moveTo(menuStartHard, 0.2f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 440, 0.4f, [&]() {isInAction=false;});
	moveTo(labelStartHard, 0.2f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 440, 0.4f, callback);
}

void Main::actionMenuSettingIn() {
	if (isClickStart == true) {
		actionMenuStartOut(nullptr);
		isClickStart = false;
	}
	if (isClickExit == true) {
		actionMenuExitOut(nullptr);
		isClickExit = false;
	}
	isInAction = true;
	moveTo(menuSettingMusic, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 540, 0.4f);
	moveTo(labelSettingMusic, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 540, 0.4f);

	moveTo(menuSettingSound, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 660, 0.4f);
	moveTo(labelSettingSound, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 660, 0.4f, [&]() {isInAction=false;});
}

void Main::actionMenuSettingOut(function<void()> callback) {
	isInAction = true;
	moveTo(menuSettingMusic, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 540, 0.4f);
	moveTo(labelSettingMusic, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 540, 0.4f);

	moveTo(menuSettingSound, 0.1f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 660, 0.4f, [&]() {isInAction=false;});
	moveTo(labelSettingSound, 0.1f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 660, 0.4f, callback);
}

void Main::actionMenuExitIn() {
	if (isClickStart == true) {
		actionMenuStartOut(nullptr);
		isClickStart = false;
	}
	if (isClickSetting == true) {
		actionMenuSettingOut(nullptr);
		isClickSetting = false;
	}
	isInAction = true;
	moveTo(menuExitYes, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 780, 0.4f);
	moveTo(labelExitYes, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 780, 0.4f);

	moveTo(menuExitNo, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 900, 0.4f);
	moveTo(labelExitNo, 0.1f, CONSTANT_WIDTH / 2, CONSTANT_HIGH - 900, 0.4f, [&]() {isInAction=false;});
}

void Main::actionMenuExitOut(function<void()> callback) {
	isInAction = true;
	moveTo(menuExitYes, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 780, 0.4f);
	moveTo(labelExitYes, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH - 780, 0.4f);

	moveTo(menuExitNo, 0.1f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 900, 0.4f, [&]() {isInAction=false;});
	moveTo(labelExitNo, 0.1f, CONSTANT_WIDTH / 2 - 600, CONSTANT_HIGH - 900, 0.4f, callback);
}

void Main::startWithMode(int mode) {
	this->mode = mode;
	select->setMode(mode);
	actionLoadOut([&]() {
		select->actionIn();
	});
}

void Main::switchSound(bool isPlaySound) {
	setBoolValue(KEY_ISPLAYSOUND, isPlaySound);
	this->isPlaySound = isPlaySound;
	if (isPlaySound == true) {
		labelSettingSound->setString(getString(valueVec, MAIN_STRING_MENU_POP_SOUND));
	} else {
		labelSettingSound->setString(getString(valueVec, MAIN_STRING_MENU_POP_SOUND_CLOSE));
	}
}

void Main::switchMusic(bool isPlayMusic) {
	setBoolValue(KEY_ISPLAYMUSIC, isPlayMusic);
	this->isPlayMusic = isPlayMusic;
	if (isPlayMusic == true) {
		labelSettingMusic->setString(getString(valueVec, MAIN_STRING_MENU_POP_MUSIC));
	} else {
		labelSettingMusic->setString(getString(valueVec, MAIN_STRING_MENU_POP_MUSIC_CLOSE));
	}
}

void Main::menuStartCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	if (isClickStart == false) {
		actionMenuStartIn();
		isClickStart = true;
	}
}

void Main::menuSettingCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	if (isClickSetting == false) {
		actionMenuSettingIn();
		isClickSetting = true;
	}
}

void Main::menuExitCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	if (isClickExit == false) {
		actionMenuExitIn();
		isClickExit = true;
	}
}

void Main::menuStartEasyCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	actionMenuStartOut([&]() {isClickStart=false;startWithMode(GAME_MODE_EASY_8);});
}

void Main::menuStartNormalCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	actionMenuStartOut([&]() {isClickStart=false;startWithMode(GAME_MODE_NORMAL_9);});
}

void Main::menuStartHardCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	actionMenuStartOut([&]() {isClickStart=false;startWithMode(GAME_MODE_HARD_10);});
}

void Main::menuSettingMusicCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	actionMenuSettingOut([&]() {isClickSetting=false;switchMusic(!isPlayMusic);});
}

void Main::menuSettingSoundCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	actionMenuSettingOut([&]() {isClickSetting=false;switchSound(!isPlaySound);});
}

void Main::menuExitYesCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	actionLoadOut([&]() {Director::getInstance()->end();});
}

void Main::menuExitNoCallback(Ref* pSender) {
	if (isInAction == true) {
		return;
	}
	actionMenuExitOut([&]() {isClickExit=false;});
}

void Main::gameMenuBackCallback(Ref* pSender) {
	if (game->isInAction == true) {
		return;
	}
	game->actionLoadOut([&]() {actionLoadIn();});
}

void Main::finishMenuRestartCallback(Ref* pSender) {
	if (finish->isInAction == true) {
		return;
	}
	setMode();
	finish->actionOut([&]() {game->actionLoadIn();});
}

void Main::finishMenuNextCallback(Ref* pSender) {
	if (finish->isInAction == true) {
		return;
	}
	level++;
	switch (mode) {
	case GAME_MODE_EASY_8:
		if (level >= EASY_LEVEL) {
			return;
		}
		break;
	case GAME_MODE_NORMAL_9:
		if (level >= NORMAL_LEVEL) {
			return;
		}
		break;
	case GAME_MODE_HARD_10:
		if (level >= HARD_LEVEL) {
			return;
		}
		break;
	}
	setMode();
	finish->actionOut([&]() {game->actionLoadIn();});
}

void Main::finishMenuBackCallback(Ref* pSender) {
	if (finish->isInAction == true) {
		return;
	}
	finish->actionOut([&]() {actionLoadIn();});
}
