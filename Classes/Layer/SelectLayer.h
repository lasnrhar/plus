#ifndef _SELECT_LAYER_H_
#define _SELECT_LAYER_H_

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace std;
using namespace cocos2d;
using namespace extension;

class Select: public Layer, public TableViewDataSource, public TableViewDelegate {
public:
	bool init();
	void setMode(int mode);
	void actionIn();
	void actionOut(function<void()> callback);
	void setSelectCallback(function<void(int)> callback);
	void setBackCallback(function<void()> callback);

	void scrollViewDidScroll(ScrollView* view) {};
	void scrollViewDidZoom(ScrollView* view) {};
	void tableCellTouched(TableView* table, TableViewCell* cell);
	Size tableCellSizeForIndex(TableView *table, ssize_t idx);
	TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
	ssize_t numberOfCellsInTableView(TableView *table);
	void tableCellHighlight(TableView* table, TableViewCell* cell);
	void tableCellUnhighlight(TableView* table, TableViewCell* cell);

	CREATE_FUNC (Select);
private:
	void initialize();
	void initLabel();
	void initSprite();
	void initMenu();
	void initList();
	int levelSize();
	void selectLevel();
	void setSelectNodesInfo(int mode, int level, bool isLock, int score, Sprite* spriteNormal, Label* labelLevel, Label* labelLock, Label* labelScore);

	void menuBackCallback(Ref* pSender);

	int mode = 0;
	int level = 0;
	bool isInAction = false;

	function<void(int)> selectCall;
	function<void()> backCall;
	ValueVector valueVec;
	Label* labelBack;
	Sprite* spriteBackground;
	MenuItemImage* menuBack;
	TableView* tableView;
};

#endif
