#ifndef _FLAKE_H_
#define _FLAKE_H_

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class Flake {
public:
	const static int TYPE_WALL = 0;
	const static int TYPE_WAY = 1;
	const static int TYPE_START = 2;
	const static int TYPE_END = 3;

	Flake();
	~Flake();

	Node* createFlakeAuto(int key, int mode, int level, int x, int y, int type);
	Label* createLabel(int key, int x, int y, int value);
	Label* createLabel(int key, int x, int y, int value, int textSize);
	Sprite* createSprite(int key, int mode, int level, int x, int y);
	Sprite* createSprite(int key, int x, int y, string resource);
	MenuItemImage* createMenuItem(int key, int mode, int x, int y);
	MenuItemImage* createMenuItem(int key, int x, int y, string normalResource, string selectedResource);
	MenuItemImage* createMenuItem(int key, int x, int y, string normalResource, string selectedResource, const ccMenuCallback &callback);
	Node* getNodeByKey(int key);
	Label* getLabelByKey(int key);
	vector<int> getKeyByNode(Node* node);
	void removeNodeByKey(int key);
	void clear();
	int size();
private:
	Map<int, Node*> mapNodes;
	Map<int, Label*> mapLabel;
};

#endif
