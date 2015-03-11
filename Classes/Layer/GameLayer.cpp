#include "GameLayer.h"

bool Game::init() {
	if (!Layer::init()) {
		return false;
	}
	initialize();
	return true;
}

void Game::initialize() {
	valueVec = FileUtils::getInstance()->getValueVectorFromFile(XML_NAME_EN);
	flake = Flake();
	vectorMenuGrid = Vector<MenuItem*>();
	vectorCheck = Vector<MenuItem*>();
	initMenu();
	initSprite();
	initLabel();
}

void Game::initLabel() {
	labelBack = Label::create(getString(valueVec, GAME_STRING_GAME_MENU_BACK), FONT_TEMPSITC, FONT_SIZE_MENU);
	labelBack->setPosition(CONSTANT_WIDTH * 2, 30);
	labelBack->setColor(Color3B::BLACK);
	this->addChild(labelBack, 2);

	labelRole = Label::create("0", FONT_TEMPSITC, FONT_SIZE_MENU);
	labelRole->setColor(Color3B::BLACK);
	labelRole->setScale(0.001f);
	this->addChild(labelRole, 21);
}

void Game::initSprite() {
	spriteBackground = Sprite::create(GAME_SPRITE_BACK_GROUND);
	spriteBackground->setPosition(CONSTANT_WIDTH / 2, CONSTANT_HIGH * 2);
	this->addChild(spriteBackground, 1);
}

void Game::initMenu() {
	menuBack = MenuItemImage::create(GAME_MENU_GRAY, GAME_MENU_WHITE);
	menuBack->setPosition(CONSTANT_WIDTH * 2, 30);
	auto menu = Menu::create(menuBack, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	menuRole = MenuItemImage::create(GAME_MENU_GRID_BLUE_EASY, GAME_MENU_GRID_BROWN_EASY, CC_CALLBACK_1(Game::menuRoleCallback, this));
	menuRole->setScale(0.001f);
	auto menuRoleFrame = Menu::create(menuRole, NULL);
	menuRoleFrame->setPosition(Vec2::ZERO);
	this->addChild(menuRoleFrame, 20);
}

void Game::menuRoleCallback(Ref* pSender) {
}

void Game::menuGridCallback(Ref* pSender) {
	int size = vectorCheck.size();
	if (size > 0) {
		bool isContinue = false;
		int id = 0;
		for (int i = 0; i < size; i++) {
			if (pSender == vectorCheck.at(i)) {
				isContinue = true;
				id = i;
			}
		}
		if (isContinue == false) {
			return;
		}
		for (int i = 0; i < size; i++) {
			MenuItemImage* menuFlake = (MenuItemImage*) vectorCheck.at(i);
			if (menuFlake == menuEnd) {
				setMenuStatus(menuFlake, false, true);
			} else {
				setMenuStatus(menuFlake, false, false);
			}
		}

		float toX, toY, nowX, nowY;
		MenuItemImage* menuFlake = (MenuItemImage*) vectorCheck.at(id);
		menuFlake->getPosition(&toX, &toY);
		menuRole->getPosition(&nowX, &nowY);
		if (toX < nowX) {
			currentX--;
		} else if (toX > nowX) {
			currentX++;
		}
		if (toY < nowY) {
			currentY++;
		} else if (toY > nowY) {
			currentY--;
		}
		vectorCheck.clear();
		moveTo(menuRole, toX, toY, 0.1f);
		if (pSender == menuEnd) {
			finishGame();
			moveTo(labelRole, toX, toY, 0.1f);
		} else {
			addScore();
			moveTo(labelRole, 0.0f, toX, toY, 0.1f, [&]() {moveRoleAtRoad();});
		}
	}
}

void Game::moveRoleAtRoad() {
	int size = vectorCheck.size();
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			MenuItemImage* menuFlake = (MenuItemImage*) vectorCheck.at(i);
			if (menuFlake == menuEnd) {
				setMenuStatus(menuFlake, false, true);
			} else {
				setMenuStatus(menuFlake, false, false);
			}
		}
	}
	vectorCheck.clear();
	if (currentX != 0) {
		if (isFlakeClickable(currentX - 1, currentY) == true) {
			MenuItemImage* menuFlake = (MenuItemImage*) flake.getNodeByKey(currentY * gameMode + currentX - 1);
			vectorCheck.pushBack(menuFlake);
		}
	}
	if (currentX != gameMode - 1) {
		if (isFlakeClickable(currentX + 1, currentY) == true) {
			MenuItemImage* menuFlake = (MenuItemImage*) flake.getNodeByKey(currentY * gameMode + currentX + 1);
			vectorCheck.pushBack(menuFlake);
		}
	}
	if (currentY != 0) {
		if (isFlakeClickable(currentX, currentY - 1) == true) {
			MenuItemImage* menuFlake = (MenuItemImage*) flake.getNodeByKey((currentY - 1) * gameMode + currentX);
			vectorCheck.pushBack(menuFlake);
		}
	}
	if (currentY != gameMode - 1) {
		if (isFlakeClickable(currentX, currentY + 1) == true) {
			MenuItemImage* menuFlake = (MenuItemImage*) flake.getNodeByKey((currentY + 1) * gameMode + currentX);
			vectorCheck.pushBack(menuFlake);
		}
	}
	size = vectorCheck.size();
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			MenuItemImage* menuFlake = (MenuItemImage*) vectorCheck.at(i);
			setMenuStatus(menuFlake, true, true);
		}
	}
}

void Game::setMenuStatus(MenuItemImage* item, bool isClickable, bool isEnd) {
	Sprite* normal;
	switch (gameMode) {
	case GAME_MODE_EASY_8:
		if (isClickable == true) {
			normal = Sprite::create(GAME_MENU_GRID_YELLOW_EASY);
		} else {
			if (isEnd == true) {
				normal = Sprite::create(GAME_MENU_GRID_PINK_EASY);
			} else {
				normal = Sprite::create(GAME_MENU_GRID_WHITE_EASY);
			}
		}
		break;
	case GAME_MODE_NORMAL_9:
		if (isClickable == true) {
			normal = Sprite::create(GAME_MENU_GRID_YELLOW_NORMAL);
		} else {
			if (isEnd == true) {
				normal = Sprite::create(GAME_MENU_GRID_PINK_NORMAL);
			} else {
				normal = Sprite::create(GAME_MENU_GRID_WHITE_NORMAL);
			}
		}
		break;
	case GAME_MODE_HARD_10:
		if (isClickable == true) {
			normal = Sprite::create(GAME_MENU_GRID_YELLOW_HARD);
		} else {
			if (isEnd == true) {
				normal = Sprite::create(GAME_MENU_GRID_PINK_HARD);
			} else {
				normal = Sprite::create(GAME_MENU_GRID_WHITE_HARD);
			}
		}
		break;
	}
	item->setNormalImage(normal);
}

void Game::addScore() {
	switch (gameMode) {
	case GAME_MODE_EASY_8:
		score = score + valueEasy[currentY][currentX];
		if (valueEasy[currentY][currentX] <= 0) {
			valueEasy[currentY][currentX] = 0;
		}
		break;
	case GAME_MODE_NORMAL_9:
		score = score + valueNormal[currentY][currentX];
		if (valueNormal[currentY][currentX] <= 0) {
			valueNormal[currentY][currentX] = 0;
		}
		break;
	case GAME_MODE_HARD_10:
		score = score + valueHard[currentY][currentX];
		if (valueHard[currentY][currentX] <= 0) {
			valueHard[currentY][currentX] = 0;
		}
		break;
	}
	labelRole->setString(getStringByInt(score));
	if (score >= 100) {
		TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_POP_MENU, GlyphCollection::DYNAMIC);
		labelRole->setTTFConfig(ttfConfig);
	} else if (score >= 1000) {
		TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_NANO, GlyphCollection::DYNAMIC);
		labelRole->setTTFConfig(ttfConfig);
	} else {
		TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_MENU, GlyphCollection::DYNAMIC);
		labelRole->setTTFConfig(ttfConfig);
	}
}

void Game::finishGame() {
	string currentLevel = getStringByInt(level);
	string nextLevel = getStringByInt(level + 1);
	switch (gameMode) {
	case GAME_MODE_EASY_8: {
		setBoolValue(KEY_EASYISLOCK + nextLevel, false);
		int score = getIntValue(KEY_EASYBESTSCORE + currentLevel, -1);
		if (this->score < score || score == -1) {
			setIntValue(KEY_EASYBESTSCORE + currentLevel, this->score);
		}
	}
		break;
	case GAME_MODE_NORMAL_9: {
		setBoolValue(KEY_NORMALISLOCK + nextLevel, false);
		int score = getIntValue(KEY_NORMALBESTSCORE + currentLevel, -1);
		if (this->score < score || score == -1) {
			setIntValue(KEY_NORMALBESTSCORE + currentLevel, this->score);
		}
	}
		break;
	case GAME_MODE_HARD_10: {
		setBoolValue(KEY_HARDISLOCK + nextLevel, false);
		int score = getIntValue(KEY_HARDBESTSCORE + currentLevel, -1);
		if (this->score < score || score == -1) {
			setIntValue(KEY_HARDBESTSCORE + currentLevel, this->score);
		}
	}
		break;
	}
	finishCallback();
}

bool Game::isFlakeClickable(int x, int y) {
	bool result = false;
	switch (gameMode) {
	case GAME_MODE_EASY_8:
		if (mapEasy[y][x] == Flake::TYPE_WAY || mapEasy[y][x] == Flake::TYPE_END) {
			result = true;
		}
		break;
	case GAME_MODE_NORMAL_9:
		if (mapNormal[y][x] == Flake::TYPE_WAY || mapNormal[y][x] == Flake::TYPE_END) {
			result = true;
		}
		break;
	case GAME_MODE_HARD_10:
		if (mapHard[y][x] == Flake::TYPE_WAY || mapHard[y][x] == Flake::TYPE_END) {
			result = true;
		}
		break;
	}
	return result;
}

void Game::setMode(int mode, int level, int map[8][8], int value[8][8]) {
	Sprite* normal = Sprite::create(GAME_MENU_GRID_BLUE_EASY);
	Sprite* selected = Sprite::create(GAME_MENU_GRID_BROWN_EASY);
	menuRole->setNormalImage(normal);
	menuRole->setSelectedImage(selected);

	this->level = level;
	gameMode = mode;
	int index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			mapEasy[i][j] = map[i][j];
			valueEasy[i][j] = value[i][j];
			int type = map[i][j];
			auto menuGrid = flake.createFlakeAuto(index, gameMode, level, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, type);
			auto label = flake.createLabel(index, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, value[i][j]);
			label->setColor(Color3B::BLACK);
			if (type == Flake::TYPE_WAY || type == Flake::TYPE_END) {
				vectorMenuGrid.pushBack((MenuItem*) menuGrid);
				((MenuItem*) menuGrid)->setCallback(CC_CALLBACK_1(Game::menuGridCallback, this));
			}
			if (type == Flake::TYPE_START) {
				label->setString(getString(valueVec, GAME_STRING_GAME_LABEL_START));
				TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_MID, GlyphCollection::DYNAMIC);
				label->setTTFConfig(ttfConfig);
				menuRole->setPosition(getGroupX(j, gameMode), getGroupY(i, gameMode));
				labelRole->setPosition(getGroupX(j, gameMode), getGroupY(i, gameMode));
				currentY = i;
				currentX = j;
			}
			if (type == Flake::TYPE_END) {
				menuEnd = (MenuItemImage*) menuGrid;
				label->setString(getString(valueVec, GAME_STRING_GAME_LABEL_END));
				TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_MID, GlyphCollection::DYNAMIC);
				label->setTTFConfig(ttfConfig);
			}
			index++;
		}
	}
	if (vectorMenuGrid.size() != 0) {
		auto menuGrids = Menu::createWithArray(vectorMenuGrid);
		menuGrids->setPosition(Vec2::ZERO);
		this->addChild(menuGrids, 10);
	}
	index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			int type = map[i][j];
			if (type != Flake::TYPE_WAY) {
				this->addChild(flake.getNodeByKey(index), 10);
			}
			if (type != Flake::TYPE_WALL) {
				this->addChild(flake.getLabelByKey(index), 11);
			}
			index++;
		}
	}
}

void Game::setMode(int mode, int level, int map[9][9], int value[9][9]) {
	Sprite* normal = Sprite::create(GAME_MENU_GRID_BLUE_NORMAL);
	Sprite* selected = Sprite::create(GAME_MENU_GRID_BROWN_NORMAL);
	menuRole->setNormalImage(normal);
	menuRole->setSelectedImage(selected);

	this->level = level;
	gameMode = mode;
	int index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			mapNormal[i][j] = map[i][j];
			valueNormal[i][j] = value[i][j];
			int type = map[i][j];
			auto menuGrid = flake.createFlakeAuto(index, gameMode, level, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, type);
			auto label = flake.createLabel(index, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, value[i][j]);
			label->setColor(Color3B::BLACK);
			if (type == Flake::TYPE_WAY || type == Flake::TYPE_END) {
				vectorMenuGrid.pushBack((MenuItem*) menuGrid);
				((MenuItem*) menuGrid)->setCallback(CC_CALLBACK_1(Game::menuGridCallback, this));
			}
			if (type == Flake::TYPE_START) {
				label->setString(getString(valueVec, GAME_STRING_GAME_LABEL_START));
				TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_MID, GlyphCollection::DYNAMIC);
				label->setTTFConfig(ttfConfig);
				menuRole->setPosition(getGroupX(j, gameMode), getGroupY(i, gameMode));
				labelRole->setPosition(getGroupX(j, gameMode), getGroupY(i, gameMode));
				currentY = i;
				currentX = j;
			}
			if (type == Flake::TYPE_END) {
				menuEnd = (MenuItemImage*) menuGrid;
				label->setString(getString(valueVec, GAME_STRING_GAME_LABEL_END));
				TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_MID, GlyphCollection::DYNAMIC);
				label->setTTFConfig(ttfConfig);
			}
			index++;
		}
	}
	if (vectorMenuGrid.size() != 0) {
		auto menuGrids = Menu::createWithArray(vectorMenuGrid);
		menuGrids->setPosition(Vec2::ZERO);
		this->addChild(menuGrids, 10);
	}
	index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			int type = map[i][j];
			if (type != Flake::TYPE_WAY) {
				this->addChild(flake.getNodeByKey(index), 10);
			}
			if (type != Flake::TYPE_WALL) {
				this->addChild(flake.getLabelByKey(index), 11);
			}
			index++;
		}
	}
}

void Game::setMode(int mode, int level, int map[10][10], int value[10][10]) {
	Sprite* normal = Sprite::create(GAME_MENU_GRID_BLUE_HARD);
	Sprite* selected = Sprite::create(GAME_MENU_GRID_BROWN_HARD);
	menuRole->setNormalImage(normal);
	menuRole->setSelectedImage(selected);

	this->level = level;
	gameMode = mode;
	int index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			mapHard[i][j] = map[i][j];
			valueHard[i][j] = value[i][j];
			int type = map[i][j];
			auto menuGrid = flake.createFlakeAuto(index, gameMode, level, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, type);
			auto label = flake.createLabel(index, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, value[i][j]);
			label->setColor(Color3B::BLACK);
			if (type == Flake::TYPE_WAY || type == Flake::TYPE_END) {
				vectorMenuGrid.pushBack((MenuItem*) menuGrid);
				((MenuItem*) menuGrid)->setCallback(CC_CALLBACK_1(Game::menuGridCallback, this));
			}
			if (type == Flake::TYPE_START) {
				label->setString(getString(valueVec, GAME_STRING_GAME_LABEL_START));
				TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_MID, GlyphCollection::DYNAMIC);
				label->setTTFConfig(ttfConfig);
				menuRole->setPosition(getGroupX(j, gameMode), getGroupY(i, gameMode));
				labelRole->setPosition(getGroupX(j, gameMode), getGroupY(i, gameMode));
				currentY = i;
				currentX = j;
			}
			if (type == Flake::TYPE_END) {
				menuEnd = (MenuItemImage*) menuGrid;
				label->setString(getString(valueVec, GAME_STRING_GAME_LABEL_END));
				TTFConfig ttfConfig(FONT_TEMPSITC.c_str(), FONT_SIZE_MID, GlyphCollection::DYNAMIC);
				label->setTTFConfig(ttfConfig);
			}
			F f = F(33, index, 64, 10);
			index++;
		}
	}
	if (vectorMenuGrid.size() != 0) {
		auto menuGrids = Menu::createWithArray(vectorMenuGrid);
		menuGrids->setPosition(Vec2::ZERO);
		this->addChild(menuGrids, 10);
	}
	index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			int type = map[i][j];
			if (type != Flake::TYPE_WAY) {
				this->addChild(flake.getNodeByKey(index), 10);
			}
			if (type != Flake::TYPE_WALL) {
				this->addChild(flake.getLabelByKey(index), 11);
			}
			index++;
		}
	}
}

void Game::setFinishCallback(function<void()> callback) {
	finishCallback = callback;
}

void Game::actionLoadIn() {
	isInAction = true;
	moveTo(spriteBackground, 0.0f, CONSTANT_WIDTH / 2, 510, 0.4f);

	moveTo(labelBack, 0.1f, CONSTANT_WIDTH / 2, 30, 0.4f);
	moveTo(menuBack, 0.1f, CONSTANT_WIDTH / 2, 30, 0.4f);

	int index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			auto menuItem = flake.getNodeByKey(index);
			auto label = flake.getLabelByKey(index);
			moveTo(label, 0.1f * index / gameMode, getGroupX(j, gameMode), getGroupY(i, gameMode), 0.4f);
			if (index < gameMode * gameMode - 1) {
				moveTo(menuItem, 0.1f * index / gameMode, getGroupX(j, gameMode), getGroupY(i, gameMode), 0.4f);
			} else {
				moveTo(menuItem, 0.1f * index / gameMode, getGroupX(j, gameMode), getGroupY(i, gameMode), 0.4f, [&]() {
					scaleIn(menuRole,[&]() {isInAction=false;},0.0f);
					scaleIn(labelRole,[&]() {moveRoleAtRoad();},0.0f);
				});
			}
			index++;
		}
	}
}

void Game::actionLoadOut(function<void()> callback) {
	isInAction = true;
	score = 0;
	moveTo(spriteBackground, 0.0f, CONSTANT_WIDTH / 2, CONSTANT_HIGH * 2, 0.4f);

	int index = 0;
	for (int i = 0; i < gameMode; i++) {
		for (int j = 0; j < gameMode; j++) {
			auto menuItem = flake.getNodeByKey(index);
			auto label = flake.getLabelByKey(index);
			moveTo(menuItem, 0.1f, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, 0.4f);
			moveTo(label, 0.1f, getGroupX(j, gameMode) - 600, getGroupY(i, gameMode) - 1000, 0.4f);
			index++;
		}
	}

	scaleOut(menuRole, nullptr, 0.0f);
	scaleOut(labelRole, nullptr, 0.0f);

	moveTo(labelBack, 0.2f, CONSTANT_WIDTH * 2, 30, 0.4f, callback);
	moveTo(menuBack, 0.2f, CONSTANT_WIDTH * 2, 30, 0.4f, [&]() {
		isInAction=false;
		vectorMenuGrid.clear();
		flake.clear();
		menuRole->setPosition(-100,-100);
		labelRole->setString("0");
	});
}
