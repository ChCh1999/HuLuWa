#include "SettingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

cocos2d::Scene * Setting::createScene()
{
	auto scene = Scene::create();

	auto layer = Setting::create();

	scene->addChild(layer);

	return scene;
}

bool Setting::init()
{
	if (!Scene::init())
	{
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	// set the background
	Sprite * bg = Sprite::create("setting-back.png");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	// set the music menu
	auto musicOnMenuItem = MenuItemImage::create(
							"on.png",
							"on.png");
	auto musicOffMenuItem = MenuItemImage::create(
							"off.png",
							"off.png");
	auto musicToggleMenuItem = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(Setting::menuItemMusicCallback, this),
		musicOnMenuItem, musicOffMenuItem, NULL);
	musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 220)));

	// set the bgm menu item
	auto bgmOnMenuItem = MenuItemImage::create(
		"on.png",
		"on.png");
	bgmOnMenuItem->setUserData((void *)"ON");
	auto bgmOffMenuItem = MenuItemImage::create(
		"off.png",
		"off.png");
	bgmOffMenuItem->setUserData((void *)"OFF");
	// set the bgm button 
	auto bgmToggleMenuItem = MenuItemToggle::createWithCallback([](Ref * obj){
		MenuItemFont * item = (MenuItemFont *)((MenuItemToggle *)obj)->getSelectedItem();
		char * musicState = (char *)item->getUserData();
		if (musicState == "ON")
			SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		else
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}, bgmOnMenuItem, bgmOffMenuItem, NULL);
	bgmToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(818, 362)));

	//set the OK button
	auto okMenuItem = MenuItemImage::create(
		"ok-up.png", "ok-down.png", CC_CALLBACK_1(Setting::menuItemOKCallback, this));
	okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(600, 510)));

	Menu * mn = Menu::create(musicToggleMenuItem, bgmToggleMenuItem, okMenuItem, NULL);
	mn->setPosition(Vec2::ZERO);
	this->addChild(mn);

	return true;
}

void Setting::menuItemMusicCallback(cocos2d::Ref * pSender)
{
	
}

void Setting::menuItemOKCallback(cocos2d::Ref * pSender)
{
	Director::getInstance()->popSceneWithTransition<TransitionCrossFade>(0.65f);
}
