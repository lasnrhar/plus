#ifndef __ITEM_ACTION_H__
#define __ITEM_ACTION_H__

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

void moveTo(Node *item, float delay, int x, int y, float speed, function<void()> callback);
void moveTo(Node *item, float delay, int x, int y, float speed);
void moveTo(Node *item, int x, int y, float speed);
void fadeIn(Node *item, function<void()> callback, float delay);
void fadeOut(Node *item, function<void()> callback, float delay);
void scaleIn(Node *item, function<void()> callback, float delay);
void scaleOut(Node *item, function<void()> callback, float delay);
void moveAndScale(Node *item, int x, int y, function<void()> callback, float delay);

#endif
