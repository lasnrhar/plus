#include "FinishLayer.h"
#include "../Constant/Constant.h"
#include "../Action/Actions.h"
#include "../Res/Res.h"

bool Finish::init() {
	if (!Layer::init()) {
		return false;
	}

	initialize();

	return true;
}

void Finish::setScore(int score) {
	labelScore->setString(getStringByInt(score));
}

void Finish::actionIn() {
	isInAction = true;
	moveTo(spriteBackground, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH / 2, 0.4f);
	moveTo(labelPrompt, 0.0f, CONSTANT_WIDTH / 2 - 100, 800, 0.4f);
	moveTo(labelScore, 0.0f, CONSTANT_WIDTH / 2, 650, 0.4f);

	moveTo(menuRestart, 0.1f, CONSTANT_WIDTH / 2, 400, 0.4f);
	moveTo(labelRestart, 0.1f, CONSTANT_WIDTH / 2, 400, 0.4f);

	moveTo(menuNext, 0.2f, CONSTANT_WIDTH / 2, 240, 0.4f);
	moveTo(labelNext, 0.2f, CONSTANT_WIDTH / 2, 240, 0.4f);

	moveTo(menuBack, 0.3f, CONSTANT_WIDTH / 2, 80, 0.4f);
	moveTo(labelBack, 0.3f, CONSTANT_WIDTH / 2, 80, 0.4f, [&]() {isInAction=false;});
}

void Finish::actionOut(function<void()> callback) {
	isInAction = true;
	moveTo(spriteBackground, 0.0f, CONSTANT_WIDTH * 2, CONSTANT_HIGH / 2, 0.4f);
	moveTo(labelPrompt, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH * 2, 0.4f);
	moveTo(labelScore, 0.0f, CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH * 2, 0.4f);

	moveTo(menuRestart, 0.1f, CONSTANT_WIDTH / 2 - 600, 400, 0.4f);
	moveTo(labelRestart, 0.1f, CONSTANT_WIDTH / 2 - 600, 400, 0.4f);

	moveTo(menuNext, 0.2f, CONSTANT_WIDTH / 2 + 600, 240, 0.4f);
	moveTo(labelNext, 0.2f, CONSTANT_WIDTH / 2 + 600, 240, 0.4f);

	moveTo(menuBack, 0.3f, CONSTANT_WIDTH / 2 - 600, 80, 0.4f, [&]() {isInAction=false;});
	moveTo(labelBack, 0.3f, CONSTANT_WIDTH / 2 - 600, 80, 0.4f, callback);
}

void Finish::initialize() {
	valueVec = FileUtils::getInstance()->getValueVectorFromFile(XML_NAME_EN);
	initLabel();
	initSprite();
	initMenu();
}

void Finish::initLabel() {
	labelPrompt = Label::create(getString(valueVec, FINISH_LABEL_PROMPT), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	labelPrompt->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH * 2);
	labelPrompt->setColor(Color3B::BLACK);
	this->addChild(labelPrompt, 2);
	labelScore = Label::create("", FONT_TEMPSITC, FONT_SIZE_TITLE);
	labelScore->setPosition(CONSTANT_WIDTH / 2 + 600, CONSTANT_HIGH * 2);
	labelScore->setColor(Color3B::BLACK);
	this->addChild(labelScore, 2);

	labelRestart = Label::create(getString(valueVec, FINISH_MENU_RESTART), FONT_TEMPSITC, FONT_SIZE_MENU);
	labelRestart->setPosition(CONSTANT_WIDTH / 2 - 600, 400);
	labelRestart->setColor(Color3B::BLACK);
	this->addChild(labelRestart, 2);
	labelNext = Label::create(getString(valueVec, FINISH_MENU_NEXT), FONT_TEMPSITC, FONT_SIZE_MENU);
	labelNext->setPosition(CONSTANT_WIDTH / 2 + 600, 240);
	this->addChild(labelNext, 2);
	labelBack = Label::create(getString(valueVec, FINISH_MENU_BACK), FONT_TEMPSITC, FONT_SIZE_MENU);
	labelBack->setPosition(CONSTANT_WIDTH / 2 - 600, 80);
	labelBack->setColor(Color3B::BLACK);
	this->addChild(labelBack, 2);
}

void Finish::initSprite() {
	spriteBackground = Sprite::create(FINISH_SPRITE_BACK_GROUND);
	spriteBackground->setPosition(CONSTANT_WIDTH * 2, CONSTANT_HIGH / 2);
	this->addChild(spriteBackground, 0);
}

void Finish::initMenu() {
	menuRestart = MenuItemImage::create(FINISH_MENU_WHITE, FINISH_MENU_GRAY);
	menuRestart->setPosition(CONSTANT_WIDTH / 2 - 600, 400);
	menuNext = MenuItemImage::create(FINISH_MENU_BLACK, FINISH_MENU_GRAY);
	menuNext->setPosition(CONSTANT_WIDTH / 2 + 600, 240);
	menuBack = MenuItemImage::create(FINISH_MENU_WHITE, FINISH_MENU_GRAY);
	menuBack->setPosition(CONSTANT_WIDTH / 2 - 600, 80);
	auto menu = Menu::create(menuRestart, menuNext, menuBack, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}
