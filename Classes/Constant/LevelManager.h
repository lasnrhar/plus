#ifndef __LEVEL_MANAGER_H__
#define __LEVEL_MANAGER_H__

#include "Easy.h"
#include "Normal.h"
#include "Hard.h"
#include "../Res/Res.h"

using namespace std;
using namespace cocos2d;

static int ( *getEasyMap(int level) )[8] {
	switch (level) {
	case 0:
		return easyMap1;
	case 1:
		return easyMap2;
	case 2:
		return easyMap3;
	case 3:
		return easyMap4;
	case 4:
		return easyMap5;
	case 5:
		return easyMap6;
	case 6:
		return easyMap7;
	case 7:
		return easyMap8;
	case 8:
		return easyMap9;
	case 9:
		return easyMap10;
	}
	return nullptr;
}
static int ( *getEasyValue(int level) )[8] {
	switch (level) {
	case 0:
		return easyValue1;
	case 1:
		return easyValue2;
	case 2:
		return easyValue3;
	case 3:
		return easyValue4;
	case 4:
		return easyValue5;
	case 5:
		return easyValue6;
	case 6:
		return easyValue7;
	case 7:
		return easyValue8;
	case 8:
		return easyValue9;
	case 9:
		return easyValue10;
	}
	return nullptr;
}

static int ( *getNormalMap(int level) )[9]{
	switch (level) {
	case 0:
		return normalMap1;
	case 1:
		return normalMap2;
	case 2:
		return normalMap3;
	case 3:
		return normalMap4;
	case 4:
		return normalMap5;
	case 5:
		return normalMap6;
	case 6:
		return normalMap7;
	case 7:
		return normalMap8;
	case 8:
		return normalMap9;
	case 9:
		return normalMap10;
	}
	return nullptr;
}
static int ( *getNormalValue(int level) )[9]{
	switch (level) {
	case 0:
		return normalValue1;
	case 1:
		return normalValue2;
	case 2:
		return normalValue3;
	case 3:
		return normalValue4;
	case 4:
		return normalValue5;
	case 5:
		return normalValue6;
	case 6:
		return normalValue7;
	case 7:
		return normalValue8;
	case 8:
		return normalValue9;
	case 9:
		return normalValue10;
	}
	return nullptr;
}

static int ( *getHardMap(int level) )[10]{
	switch (level) {
	case 0:
		return hardMap1;
	case 1:
		return hardMap2;
	case 2:
		return hardMap3;
	case 3:
		return hardMap4;
	case 4:
		return hardMap5;
	case 5:
		return hardMap6;
	case 6:
		return hardMap7;
	case 7:
		return hardMap8;
	case 8:
		return hardMap9;
	case 9:
		return hardMap10;
	}
	return nullptr;
}
static int ( *getHardValue(int level) )[10]{
	switch (level) {
	case 0:
		return hardValue1;
	case 1:
		return hardValue2;
	case 2:
		return hardValue3;
	case 3:
		return hardValue4;
	case 4:
		return hardValue5;
	case 5:
		return hardValue6;
	case 6:
		return hardValue7;
	case 7:
		return hardValue8;
	case 8:
		return hardValue9;
	case 9:
		return hardValue10;
	}
	return nullptr;
}

static void setLevelInfo(int mode, int level, bool isLock, int bestScore) {
	string s = getStringByInt(level);
	switch(mode){
	case GAME_MODE_EASY_8:
		setBoolValue(KEY_EASYISLOCK + s, isLock);
		setIntValue(KEY_EASYBESTSCORE + s, bestScore);
		break;
	case GAME_MODE_NORMAL_9:
		setBoolValue(KEY_NORMALISLOCK + s, isLock);
		setIntValue(KEY_NORMALBESTSCORE + s, bestScore);
		break;
	case GAME_MODE_HARD_10:
		setBoolValue(KEY_HARDISLOCK + s, isLock);
		setIntValue(KEY_HARDBESTSCORE + s, bestScore);
		break;
	}
}

static void getLevelInfo(int mode, int level, bool *isLock, int *bestScore){
	string s = getStringByInt(level);
	switch(mode){
	case GAME_MODE_EASY_8:
		*isLock = getBoolValue(KEY_EASYISLOCK + s, true);
		*bestScore = getIntValue(KEY_EASYBESTSCORE + s, -1);
		break;
	case GAME_MODE_NORMAL_9:
		*isLock = getBoolValue(KEY_NORMALISLOCK + s, true);
		*bestScore = getIntValue(KEY_NORMALBESTSCORE + s, -1);
		break;
	case GAME_MODE_HARD_10:
		*isLock = getBoolValue(KEY_HARDISLOCK + s, true);
		*bestScore = getIntValue(KEY_HARDBESTSCORE + s, -1);
		break;
	}
}

static string getCustomColor(int mode, int level) {
	string color = "";
	switch (mode) {
	case GAME_MODE_EASY_8: {
		switch (level) {
		case 0:
			color = GAME_MENU_GRID_PURPLE_EASY;
			break;
		case 1:
			color = GAME_MENU_GRID_DARK_BLUE_EASY;
			break;
		case 2:
			color = GAME_MENU_GRID_DARK_BROWN_EASY;
			break;
		case 3:
			color = GAME_MENU_GRID_DARK_GREEN_EASY;
			break;
		case 4:
			color = GAME_MENU_GRID_DEEP_BLUE_EASY;
			break;
		case 5:
			color = GAME_MENU_GRID_GOLD_EASY;
			break;
		case 6:
			color = GAME_MENU_GRID_GRAY_BLUE_EASY;
			break;
		case 7:
			color = GAME_MENU_GRID_ORANGE_EASY;
			break;
		case 8:
			color = GAME_MENU_GRID_RED_EASY;
			break;
		case 9:
			color = GAME_MENU_GRID_VIOLET_EASY;
			break;
		}
	}
		break;
	case GAME_MODE_NORMAL_9: {
		switch (level) {
		case 0:
			color = GAME_MENU_GRID_PURPLE_NORMAL;
			break;
		case 1:
			color = GAME_MENU_GRID_DARK_BLUE_NORMAL;
			break;
		case 2:
			color = GAME_MENU_GRID_DARK_BROWN_NORMAL;
			break;
		case 3:
			color = GAME_MENU_GRID_DARK_GREEN_NORMAL;
			break;
		case 4:
			color = GAME_MENU_GRID_DEEP_BLUE_NORMAL;
			break;
		case 5:
			color = GAME_MENU_GRID_GOLD_NORMAL;
			break;
		case 6:
			color = GAME_MENU_GRID_GRAY_BLUE_NORMAL;
			break;
		case 7:
			color = GAME_MENU_GRID_ORANGE_NORMAL;
			break;
		case 8:
			color = GAME_MENU_GRID_RED_NORMAL;
			break;
		case 9:
			color = GAME_MENU_GRID_VIOLET_NORMAL;
			break;
		}
	}
		break;
	case GAME_MODE_HARD_10: {
		switch (level) {
		case 0:
			color = GAME_MENU_GRID_PURPLE_HARD;
			break;
		case 1:
			color = GAME_MENU_GRID_DARK_BLUE_HARD;
			break;
		case 2:
			color = GAME_MENU_GRID_DARK_BROWN_HARD;
			break;
		case 3:
			color = GAME_MENU_GRID_DARK_GREEN_HARD;
			break;
		case 4:
			color = GAME_MENU_GRID_DEEP_BLUE_HARD;
			break;
		case 5:
			color = GAME_MENU_GRID_GOLD_HARD;
			break;
		case 6:
			color = GAME_MENU_GRID_GRAY_BLUE_HARD;
			break;
		case 7:
			color = GAME_MENU_GRID_ORANGE_HARD;
			break;
		case 8:
			color = GAME_MENU_GRID_RED_HARD;
			break;
		case 9:
			color = GAME_MENU_GRID_VIOLET_HARD;
			break;
		}
	}
		break;
	}
	return color;
}

static string getCustomSliceColor(int mode, int level) {
	string color = "";
	switch (level) {
	case 0:
		color = SELECT_LEVEL_PURPLE;
		break;
	case 1:
		color = SELECT_LEVEL_DARK_BLUE;
		break;
	case 2:
		color = SELECT_LEVEL_DARK_BROWN;
		break;
	case 3:
		color = SELECT_LEVEL_DARK_GREEN;
		break;
	case 4:
		color = SELECT_LEVEL_DEEP_BLUE;
		break;
	case 5:
		color = SELECT_LEVEL_GOLD;
		break;
	case 6:
		color = SELECT_LEVEL_GRAY_BLUE;
		break;
	case 7:
		color = SELECT_LEVEL_ORANGE;
		break;
	case 8:
		color = SELECT_LEVEL_RED;
		break;
	case 9:
		color = SELECT_LEVEL_VIOLET;
		break;
	}
	return color;
}

#endif
