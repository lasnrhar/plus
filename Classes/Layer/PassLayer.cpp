#include "PassLayer.h"
#include "../Constant/Constant.h"
#include "../Action/Actions.h"

bool Pass::init() {
	if (!Layer::init()) {
		return false;
	}
	return true;
}
