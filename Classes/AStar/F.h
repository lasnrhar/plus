#ifndef __F_H__
#define __F_H__

#include "cocos2d.h"

using namespace cocos2d;

class F {
public:
	F(int a, int index, int target, int lineLength);
	~F();

	void setG(int target);
	int getG();
	int getH();
	int getF();
	void reset(int a, int index, int target, int lineLength);
	void clear();
private:
	int a;
	int g;
	int h;
	int index;
	int target;
	int lineLength;

	void setH();
};

#endif
