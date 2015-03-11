#ifndef _LOAD_LAYER_H_
#define _LOAD_LAYER_H_

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class Load: public Layer {
public:
	bool init();
	void loading(function<void()> callback1, function<void()> callback2);

	CREATE_FUNC (Load);
private:
	Sprite* sprite;
};

#endif
