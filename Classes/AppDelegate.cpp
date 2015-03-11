#include "AppDelegate.h"

#include "Constant/Constant.h"
#include "Scene/MainScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		glview = GLView::create("Plus");
		director->setOpenGLView(glview);
	}

	director->setDisplayStats(false);
	director->setAnimationInterval(1.0 / 60);
	auto scene = Main::createScene();
	director->runWithScene(scene);

	glview->setDesignResolutionSize(CONSTANT_WIDTH, CONSTANT_HIGH,
			kResolutionExactFit);

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();
}
