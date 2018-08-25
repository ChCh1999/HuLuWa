#include "HelloWorldScene.h"
#include "SettingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	SimpleAudioEngine::getInstance()->playBackgroundMusic("July - Cold Winter.mp3", true);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// set the background
    Sprite * bg = Sprite::create("background.png");
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height /2));
    this->addChild(bg);

	// start the sprite
    Sprite *startSpriteNormal = Sprite::create("start-up.png");
    Sprite *startSpriteSelected = Sprite::create("start-down.png");

	MenuItemSprite *startMenuItem = MenuItemSprite::create(startSpriteNormal, 
													startSpriteSelected,
											 	   CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
	startMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(700, 190)));
    
	// set the image menu
    MenuItemImage *settingMenuItem = MenuItemImage::create(
                             "setting-up.png",
                             "setting-down.png",
							 CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this)); 
	settingMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(700, 430)));
	
	Menu* mu = Menu::create(startMenuItem, settingMenuItem, NULL);	
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);
    
    return true;
}

void HelloWorld::menuItemSettingCallback(Ref* pSender)
{
	auto sc = Setting::createScene();
	auto reScene = TransitionCrossFade::create(0.65f,sc);
	Director::getInstance()->pushScene(reScene);
}

void HelloWorld::menuItemHelpCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
	log("Touch Help %p", item);
}

void HelloWorld::menuItemStartCallback(Ref* pSender)
{
    MenuItem* item = (MenuItem*)pSender;
	log("Touch Start %p", item);
}
