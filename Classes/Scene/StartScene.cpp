

#include "StartScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
USING_NS_CC;

Scene* StartScene::createScene()
{
	return StartScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	auto winSize = Director::getInstance()->getWinSize();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//退出按钮
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(StartScene::menuCloseCallback, this));
	closeItem->setScale(0.7);
	float x = origin.x + visibleSize.width*0.8;
	float y = origin.y + closeItem->getContentSize().height*2.3;
	closeItem->setPosition(Vec2(x, y));
	//开始按钮
	auto startItem = MenuItemImage::create(
		"StartNormal.png",
		"StartSelected.png",
		CC_CALLBACK_1(StartScene::StartCallback, this));
	startItem->setScale(0.7);
	float xs = origin.x + visibleSize.width*0.8;
	float ys = origin.y + visibleSize.height - closeItem->getContentSize().height * 2.3;
	startItem->setPosition(Vec2(xs, ys));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, startItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below..
	// add a label shows "Hello World"
	// create and initialize a label


	auto bgimg = Sprite::create("startbg.png");
	float fX = winSize.width / bgimg->getContentSize().width;
	float fY = winSize.height / bgimg->getContentSize().height;
	bgimg->setScale(fX, fY);
	bgimg->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(bgimg, 0);
	return true;
}


void StartScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

}
void StartScene::StartCallback(Ref* pSender)
{
	auto playScene = GameScene::create();
	Director::getInstance()->replaceScene(playScene);

}