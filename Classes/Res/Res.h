#ifndef _RES_H_
#define _RES_H_
#include <string>
#include <cocos2d.h>
using namespace std;
using namespace cocos2d;

string getString(ValueVector txt_vec, const char* wordId);
void setBoolValue(string key, bool value);
void setStringValue(string key, string value);
void setIntValue(string key, int value);
bool getBoolValue(string key, bool defaultValue);
string getStringValue(string key, char *defaultValue);
int getIntValue(string key, int defaultValue);
string getStringByInt(int value);

#endif
