#include"myscene.h"
#include"Enemy.h"

USING_NS_CC;
Scene* myscene::createScene()
{
	return myscene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in myscene.cpp\n");
}
bool myscene::init()
{
	
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite * bg = Sprite::create("background.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y +visibleSize.height/2));
	this->addChild(bg);
	MenuItemImage * startmenu = MenuItemImage::create("start1.png", "start2.png", CC_CALLBACK_1(myscene::menustartCallback, this));
	startmenu->setPosition(Director::getInstance()->convertToGL(Vec2(480, 400)));
	Menu * mu = Menu::create(startmenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);

	return true;
}
void myscene::menustartCallback(Ref * pSender)
{
	auto sc = Enemy::createScene();
	Director::getInstance()->pushScene(sc);
}