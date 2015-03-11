#ifndef _PASS_LAYER_H_
#define _PASS_LAYER_H_

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class Pass: public Layer {
public:
	bool init();

	CREATE_FUNC (Pass);
private:
	MenuItemImage* menuLevels[10];
	Label* labelLevel[10];
	Label* labelScore[10];
};

#endif
