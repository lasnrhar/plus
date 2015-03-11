#include "LoadLayer.h"
#include "../Constant/Constant.h"
#include "../Action/Actions.h"

bool Load::init() {
	if (!Layer::init()) {
		return false;
	}

	sprite = Sprite::create(LOAD_SPRITE_BACK_GROUND);
	sprite->setPosition(CONSTANT_WIDTH / 2, CONSTANT_HIGH / 2);
	sprite->setOpacity(0);
	this->addChild(sprite, 1);

	return true;
}

void Load::loading(function<void()> callback1, function<void()> callback2) {
	fadeIn(sprite, callback1, 0);
	fadeOut(sprite, callback2, 2);
}
