#include "Res.h"
string getString(ValueVector txt_vec, const char* wordId) {
	auto txt_map = txt_vec.at(0).asValueMap();
	string ret = txt_map.at(wordId).asString();
	return ret;
}

void setBoolValue(string key, bool value) {
	UserDefault::sharedUserDefault()->setBoolForKey(key.data(), value);
}

void setStringValue(string key, string value) {
	UserDefault::sharedUserDefault()->setStringForKey(key.data(), value);
}

void setIntValue(string key, int value) {
	UserDefault::sharedUserDefault()->setIntegerForKey(key.data(), value);
}

bool getBoolValue(string key, bool defaultValue) {
	return UserDefault::sharedUserDefault()->getBoolForKey(key.data(), defaultValue);
}

string getStringValue(string key, char *defaultValue) {
	return UserDefault::sharedUserDefault()->getStringForKey(key.data(), defaultValue);
}

int getIntValue(string key, int defaultValue) {
	return UserDefault::sharedUserDefault()->getIntegerForKey(key.data(), defaultValue);
}

string getStringByInt(int value) {
	CCString* ns = CCString::createWithFormat("%d", value);
	string s = ns->_string;
	return s;
}
