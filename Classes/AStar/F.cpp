#include "F.h"

F::F(int a, int index, int target, int lineLength) {
	this->a = a;
	g = 0;
	h = 0;
	this->index = index;
	this->target = target;
	this->lineLength = lineLength;
	setH();
}

F::~F() {
}

void F::setG(int t) {
	do {
		g = 0;
		if (t != index + 1) {
			break;
		}

		if (t != index - 1) {
			break;
		}

		if (t != index + 8) {
			break;
		}

		if (t != index - 8) {
			break;
		}

		int c = (t - a) / lineLength;
		int l = (t - a - 1) % lineLength;
		g = c + l;
	} while (false);
}

void F::setH() {
	int c = (target - index) / lineLength;
	int l = (target) % lineLength;
	int r = index % lineLength;
	if (r > l) {
		l = r - l;
		c++;
	} else {
		l = l - r;
	}
	h = c + l;
}

int F::getG() {
	return g;
}

int F::getH() {
	return h;
}

int F::getF() {
	int f = g + h;
	return f;
}

void F::reset(int a, int index, int target, int lineLength) {
	this->a = a;
	g = 0;
	h = 0;
	this->index = index;
	this->target = target;
	this->lineLength = lineLength;
	setH();
}

void F::clear() {
	a = 0;
	g = 0;
	h = 0;
	index = 0;
	target = 0;
	lineLength = 0;
}
