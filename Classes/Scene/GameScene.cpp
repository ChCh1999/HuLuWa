#include "GameScene.h"
#include"enemy\Enemy.h"
#include<math.h>

USING_NS_CC;

Scene * GameScene::createScene() {
	return GameScene::create();
}

bool GameScene::init() {
	if (!Scene::init())
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Sprite * bgOflevel1 = Sprite::create("level1.png");
	float bgx = visibleSize.width / bgOflevel1->getContentSize().width;
	float bgy = visibleSize.height / bgOflevel1->getContentSize().height;
	bgOflevel1->setScale(bgx,bgy);
	bgOflevel1->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(bgOflevel1, 0);

	Sprite * SetPoint = Sprite::create("SetPoint.png");
	SetPoint->setPosition(290,330);
	this->addChild(SetPoint, 1);
	
	MenuItemImage * startmenu = MenuItemImage::create("start1.png", "start2.png", 
					CC_CALLBACK_1(GameScene::menustartCallback, this));
	Scene * CCC = Director::getInstance()->getRunningScene();
	startmenu->setPosition(Director::getInstance()->convertToGL(Vec2(480, 400)));
	Menu * mu = Menu::create(startmenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu,1,000);
	return true;

}

void GameScene::menustartCallback(Ref * pSender)
{
	auto ene = new Enemy;
	this->addChild(ene);
	ene->createEnemy();
}