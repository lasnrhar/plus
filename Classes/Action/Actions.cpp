#include "Actions.h"

void moveTo(Node *item, float delay, int x, int y, float speed, function<void()> callback) {
	ActionInterval *moveTo = MoveTo::create(speed, Point(x, y));
	EaseExponentialOut *slowMove = EaseExponentialOut::create(moveTo);
	CallFunc *call = CallFunc::create(callback);
	FiniteTimeAction* action = Sequence::create(DelayTime::create(delay), slowMove, call, NULL);
	item->runAction(action);
}

void moveTo(Node *item, float delay, int x, int y, float speed) {
	ActionInterval *moveTo = MoveTo::create(speed, Point(x, y));
	EaseExponentialOut *slowMove = EaseExponentialOut::create(moveTo);
	FiniteTimeAction* action = Sequence::create(DelayTime::create(delay), slowMove, NULL);
	item->runAction(action);
}

void moveTo(Node *item, int x, int y, float speed) {
	ActionInterval *moveTo = MoveTo::create(speed, Point(x, y));
	ActionInterval *easeSineOut = EaseSineOut::create(moveTo);
	item->runAction(easeSineOut);
}

void fadeIn(Node *item, function<void()> callback, float delay) {
	FadeIn *fadeIn = FadeIn::create(0.3f);
	CallFunc *call = CallFunc::create(callback);
	Sequence *sequence = Sequence::create(DelayTime::create(delay), fadeIn, call, NULL);
	item->runAction(sequence);
}

void fadeOut(Node *item, function<void()> callback, float delay) {
	FadeOut *fadeOut = FadeOut::create(0.5f);
	CallFunc *call = CallFunc::create(callback);
	Sequence *sequence = Sequence::create(DelayTime::create(delay), fadeOut, call, NULL);
	item->runAction(sequence);
}

void scaleIn(Node *item, function<void()> callback, float delay) {
	ScaleTo *scaleTo1 = ScaleTo::create(0.2f, 1.3f);
	ScaleTo *scaleTo2 = ScaleTo::create(0.1f, 1.0f);
	CallFunc *call = CallFunc::create(callback);
	Sequence *sequence = Sequence::create(DelayTime::create(delay), scaleTo1, scaleTo2, call, NULL);
	item->runAction(sequence);
}

void scaleOut(Node *item, function<void()> callback, float delay) {
	ScaleTo *scaleTo1 = ScaleTo::create(0.2f, 1.3f);
	ScaleTo *scaleTo2 = ScaleTo::create(0.1f, 0.001f);
	CallFunc *call = CallFunc::create(callback);
	Sequence *sequence = Sequence::create(DelayTime::create(delay), scaleTo1, scaleTo2, call, NULL);
	item->runAction(sequence);
}

void moveAndScale(Node *item, int x, int y, function<void()> callback, float delay) {
	MoveTo *moveTo = MoveTo::create(0.5f, Point(x, y));
	EaseExponentialOut *slowMove = EaseExponentialOut::create(moveTo);
	ScaleTo *scaleTo = ScaleTo::create(0.5f, 20.0f);
	CallFunc *call = CallFunc::create(callback);
	Spawn *spawn = Spawn::create(slowMove, scaleTo, NULL);
	Sequence *sequence = Sequence::create(DelayTime::create(delay), spawn, call, NULL);
	item->runAction(sequence);
}
