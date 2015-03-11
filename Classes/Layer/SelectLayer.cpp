#include "SelectLayer.h"
#include "../Constant/Constant.h"
#include "../Constant/LevelManager.h"
#include "../Action/Actions.h"
#include "../Res/Res.h"

bool Select::init() {
	if (!Layer::init()) {
		return false;
	}
	valueVec = FileUtils::getInstance()->getValueVectorFromFile(XML_NAME_EN);
	return true;
}

void Select::tableCellTouched(TableView* table, TableViewCell* cell) {
	int idx = cell->getTag();
	level = idx;
	int score = 0;
	bool isLock = false;
	getLevelInfo(mode, level, &isLock, &score);

	if (isLock == true) {

	} else {
		actionOut([&]() {selectLevel();});
	}
}

Size Select::tableCellSizeForIndex(TableView *table, ssize_t idx) {
	return CCSizeMake(480, 100);
}

TableViewCell* Select::tableCellAtIndex(TableView *table, ssize_t idx) {
	int level = levelSize() - idx - 1;
	int score = 0;
	bool isLock = false;
	getLevelInfo(mode, level, &isLock, &score);

	TableViewCell *cell = table->dequeueCell();
	Sprite* spriteNormal;
	Label* labelLevel;
	Label* labelLock;
	Label* labelScore;
	if (!cell) {
		cell = new TableViewCell();
		cell->autorelease();

		spriteNormal = Sprite::create(SELECT_LEVEL_GRAY);
		spriteNormal->setPosition(240, 50);
		spriteNormal->setTag(1);
		cell->addChild(spriteNormal, 1);

		Sprite* spriteSelect = Sprite::create(SELECT_LEVEL_CLEAR);
		spriteSelect->setPosition(240, 50);
		spriteSelect->setTag(2);
		cell->addChild(spriteSelect, 2);

		labelLevel = Label::create("", FONT_TEMPSITC, FONT_SIZE_LEVEL);
		labelLevel->setColor(Color3B::BLACK);
		labelLevel->setPosition(100, 80);
		labelLevel->setTag(3);
		cell->addChild(labelLevel, 3);

		labelLock = Label::create("", FONT_TEMPSITC, FONT_SIZE_POP_MENU);
		labelLock->setColor(Color3B::BLACK);
		labelLock->setPosition(240, 30);
		labelLock->setTag(4);
		cell->addChild(labelLock, 3);

		labelScore = Label::create("", FONT_TEMPSITC, FONT_SIZE_POP_MENU);
		labelScore->setColor(Color3B::BLACK);
		labelScore->setPosition(370, 80);
		labelScore->setTag(5);
		cell->addChild(labelScore, 3);
	} else {
		spriteNormal = (Sprite*) cell->getChildByTag(1);
		labelLevel = (Label*) cell->getChildByTag(3);
		labelLock = (Label*) cell->getChildByTag(4);
		labelScore = (Label*) cell->getChildByTag(5);
	}
	cell->setTag(level);
	setSelectNodesInfo(mode, level, isLock, score, spriteNormal, labelLevel, labelLock, labelScore);
	return cell;
}

ssize_t Select::numberOfCellsInTableView(TableView *table) {
	return levelSize();
}

void Select::tableCellHighlight(TableView* table, TableViewCell* cell) {
	Sprite* sprite = (Sprite*) cell->getChildByTag(2);
	sprite->setTexture(SELECT_LEVEL_GRAY);
}

void Select::tableCellUnhighlight(TableView* table, TableViewCell* cell) {
	Sprite* sprite = (Sprite*) cell->getChildByTag(2);
	sprite->setTexture(SELECT_LEVEL_CLEAR);
}

int Select::levelSize() {
	switch (mode) {
	case GAME_MODE_EASY_8:
		return EASY_LEVEL;
	case GAME_MODE_NORMAL_9:
		return NORMAL_LEVEL;
	case GAME_MODE_HARD_10:
		return HARD_LEVEL;
	}
	return 0;
}

void Select::selectLevel() {
	selectCall(level);
}

void Select::setMode(int mode) {
	this->mode = mode;
	initialize();
}

void Select::actionIn() {
	isInAction = true;

	moveTo(spriteBackground, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH / 2, 0.2f);
	moveTo(tableView, 0.1f, 0, 65, 0.2F);
	moveTo(menuBack, 0.2f, CONSTANT_WIDTH / 2, 30, 0.2F);
	moveTo(labelBack, 0.2f, CONSTANT_WIDTH / 2, 30, 0.2F, [&]() {isInAction=false;});
}

void Select::actionOut(function<void()> callback) {
	isInAction = true;

	moveTo(spriteBackground, 0.1f, CONSTANT_WIDTH / 2, 1600, 0.2f);
	moveTo(tableView, 0.1f, 0, 1000, 0.2F);
	moveTo(menuBack, 0.2f, 800, 30, 0.2F, callback);
	moveTo(labelBack, 0.2f, 800, 30, 0.2f, [&]() {isInAction=false;});
}

void Select::setSelectCallback(function<void(int)> callback) {
	selectCall = callback;
}

void Select::setBackCallback(function<void()> callback) {
	backCall = callback;
}

void Select::initialize() {
	initLabel();
	initSprite();
	initMenu();
	initList();
}

void Select::initLabel() {
	labelBack = Label::create(getString(valueVec, FINISH_MENU_BACK), FONT_TEMPSITC, FONT_SIZE_POP_MENU);
	labelBack->setPosition(800, 30);
	labelBack->setColor(Color3B::BLACK);
	this->addChild(labelBack, 4);
}

void Select::initSprite() {
	spriteBackground = Sprite::create(SELECT_SPRITE_BACK_GROUND);
	spriteBackground->setPosition(CONSTANT_WIDTH / 2, 1600);
	this->addChild(spriteBackground, 0);
}

void Select::initMenu() {
	menuBack = MenuItemImage::create(GAME_MENU_GRAY, GAME_MENU_WHITE, CC_CALLBACK_1(Select::menuBackCallback, this));
	menuBack->setPosition(800, 30);
	auto menu = Menu::create(menuBack, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);
}

void Select::initList() {
	tableView = TableView::create(this, CCSizeMake(480, 880));
	tableView->setDirection(ScrollView::Direction::VERTICAL);
	tableView->setPosition(0, 1000);
	tableView->setDelegate(this);
	this->addChild(tableView, 3);
	tableView->reloadData();
}

void Select::menuBackCallback(Ref* pSender) {
	actionOut(backCall);
}

void Select::setSelectNodesInfo(int mode, int level, bool isLock, int score, Sprite* spriteNormal, Label* labelLevel, Label* labelLock, Label* labelScore) {
	if (isLock == true) {
		spriteNormal->setTexture(SELECT_LEVEL_GRAY);
		labelLock->setString(getString(valueVec, SELECT_LABEL_LOCK));
	} else {
		spriteNormal->setTexture(getCustomSliceColor(mode, level));
		labelLock->setString(getString(valueVec, SELECT_LABEL_UNLOCK));
	}
	labelLevel->setString(getString(valueVec, SELECT_LABEL_LEVEL) + getStringByInt(level + 1));
	if (score > -1) {
		labelScore->setString(getString(valueVec, SELECT_LABEL_BEST_SCORE) + getStringByInt(score));
	} else {
		labelScore->setString("");
	}

	if ((level == 2 || level == 4 || level == 8 || level == 9) && isLock == false) {
		labelLevel->setColor(Color3B::WHITE);
		labelLock->setColor(Color3B::WHITE);
		labelScore->setColor(Color3B::WHITE);
	}else{
		labelLevel->setColor(Color3B::BLACK);
		labelLock->setColor(Color3B::BLACK);
		labelScore->setColor(Color3B::BLACK);
	}
}
