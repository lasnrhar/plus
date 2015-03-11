#include "Flake.h"
#include "../Constant/Constant.h"
#include "../Constant/LevelManager.h"
#include "../Res/Res.h"

Flake::Flake() {
	mapNodes = Map<int, Node*>();
	mapLabel = Map<int, Label*>();
}

Flake::~Flake() {
	mapNodes.~Map();
	mapLabel.~Map();
}

Node* Flake::createFlakeAuto(int key, int mode, int level, int x, int y, int type) {
	Node* node;
	switch (type) {
	case TYPE_WALL:
		node = createSprite(key, mode, level, x, y);
		break;
	case TYPE_WAY:
		node = createMenuItem(key, mode, x, y);
		break;
	case TYPE_START:
		switch (mode) {
		case GAME_MODE_EASY_8:
			node = createSprite(key, x, y, GAME_MENU_GRID_GREEN_EASY);
			break;
		case GAME_MODE_NORMAL_9:
			node = createSprite(key, x, y, GAME_MENU_GRID_GREEN_NORMAL);
			break;
		case GAME_MODE_HARD_10:
			node = createSprite(key, x, y, GAME_MENU_GRID_GREEN_HARD);
			break;
		}
		break;
	case TYPE_END:
		switch (mode) {
		case GAME_MODE_EASY_8:
			node = createMenuItem(key, x, y, GAME_MENU_GRID_PINK_EASY, GAME_MENU_GRID_BROWN_EASY);
			break;
		case GAME_MODE_NORMAL_9:
			node = createMenuItem(key, x, y, GAME_MENU_GRID_PINK_NORMAL, GAME_MENU_GRID_BROWN_NORMAL);
			break;
		case GAME_MODE_HARD_10:
			node = createMenuItem(key, x, y, GAME_MENU_GRID_PINK_HARD, GAME_MENU_GRID_BROWN_HARD);
			break;
		}
		break;
	}
	return node;
}

Label* Flake::createLabel(int key, int x, int y, int value) {
	return createLabel(key, x, y, value, FONT_SIZE_MENU);
}

Label* Flake::createLabel(int key, int x, int y, int value, int textSize) {
	Label* label = Label::create(getStringByInt(value), FONT_TEMPSITC, textSize);
	label->setPosition(x, y);
	mapLabel.insert(key, label);
	return label;
}

Sprite* Flake::createSprite(int key, int mode, int level, int x, int y) {
	Sprite* sprite = createSprite(key, x, y, getCustomColor(mode, level));
	return sprite;
}

Sprite* Flake::createSprite(int key, int x, int y, string resource) {
	Sprite* sprite = Sprite::create(resource);
	sprite->setPosition(x, y);
	mapNodes.insert(key, sprite);
	return sprite;
}

MenuItemImage* Flake::createMenuItem(int key, int mode, int x, int y) {
	MenuItemImage* menuItem;
	switch (mode) {
	case GAME_MODE_EASY_8:
		menuItem = createMenuItem(key, x, y, GAME_MENU_GRID_WHITE_EASY, GAME_MENU_GRID_BROWN_EASY);
		break;
	case GAME_MODE_NORMAL_9:
		menuItem = createMenuItem(key, x, y, GAME_MENU_GRID_WHITE_NORMAL, GAME_MENU_GRID_BROWN_NORMAL);
		break;
	case GAME_MODE_HARD_10:
		menuItem = createMenuItem(key, x, y, GAME_MENU_GRID_WHITE_HARD, GAME_MENU_GRID_BROWN_HARD);
		break;
	}
	return menuItem;
}

MenuItemImage* Flake::createMenuItem(int key, int x, int y, string normalResource, string selectedResource) {
	MenuItemImage* menuItem = MenuItemImage::create(normalResource, selectedResource);
	menuItem->setPosition(x, y);
	mapNodes.insert(key, menuItem);
	return menuItem;
}

MenuItemImage* Flake::createMenuItem(int key, int x, int y, string normalResource, string selectedResource, const ccMenuCallback &callback) {
	MenuItemImage* menuItem = MenuItemImage::create(normalResource, selectedResource, callback);
	menuItem->setPosition(x, y);
	mapNodes.insert(key, menuItem);
	return menuItem;
}

Node* Flake::getNodeByKey(int key) {
	return mapNodes.at(key);
}

Label* Flake::getLabelByKey(int key) {
	return mapLabel.at(key);
}

vector<int> Flake::getKeyByNode(Node* node) {
	return mapNodes.keys(node);
}

void Flake::removeNodeByKey(int key) {
	mapNodes.erase(key);
}

void Flake::clear() {
	mapNodes.clear();
	mapLabel.clear();
}

int Flake::size() {
	return mapNodes.size();
}
