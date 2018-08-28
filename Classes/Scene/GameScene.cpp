#include "GameScene.h"


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

	//地图
	Sprite * bgOflevel1 = Sprite::create("map1.png");
	float bgx = visibleSize.width / bgOflevel1->getContentSize().width;
	float bgy = visibleSize.height / bgOflevel1->getContentSize().height;
	bgOflevel1->setScale(bgx,bgy);
	bgOflevel1->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(bgOflevel1, 0);
	//血量条
	Sprite * healthicon = Sprite::create("health.png");
	healthicon->setPosition(50,730);
	this->addChild(healthicon, 1);
	Sprite * healthbg = Sprite::create("hbg.png");
	healthbg->setPosition(130,730);
	this->addChild(healthbg, 1);
	CCString * healths = CCString::createWithFormat("%d", this->health);
	auto healthlabel = Label::create(healths->getCString(), "arial.ttf", 16);
	healthlabel->setPosition(130, 730);
	this->addChild(healthlabel, 2);
	//金钱条
	Sprite * moneyicon = Sprite::create("money.png");
	moneyicon->setPosition(220,730);
	this->addChild(moneyicon, 1);
	Sprite *moneybg = Sprite::create("hbg.png");
	moneybg->setPosition(300,730);
	this->addChild(moneybg);  
	CCString * moneys = CCString::createWithFormat("%d", this->money);
	auto moneylabel = Label::create(moneys->getCString(), "arial.ttf", 16);
	moneylabel->setPosition(300, 730);
	this->addChild(moneylabel, 2);

	//塔点
	MenuItemImage* setTower1=MenuItemImage::create("SetPoint.png", "SetPoint.png",
		CC_CALLBACK_0(GameScene::SetTower1,this));
	MenuItemImage* setTower2 = MenuItemImage::create("SetPoint.png", "SetPoint.png",
		CC_CALLBACK_0(GameScene::SetTower2, this));
	MenuItemImage* setTower3 = MenuItemImage::create("SetPoint.png", "SetPoint.png",
		CC_CALLBACK_0(GameScene::SetTower3, this));
	MenuItemImage* setTower4 = MenuItemImage::create("SetPoint.png", "SetPoint.png",
		CC_CALLBACK_0(GameScene::SetTower4, this));
	MenuItemImage* setTower5 = MenuItemImage::create("SetPoint.png", "SetPoint.png",
		CC_CALLBACK_0(GameScene::SetTower5, this));
	setTower1->setPosition(290, 330);
	setTower2->setPosition(390, 510);
	setTower3->setPosition(450, 250);
	setTower4->setPosition(780, 250);
	setTower5->setPosition(780, 510);
	Menu * BuildTower = Menu::create(setTower1, setTower2, setTower3, setTower4,setTower5,NULL);
	BuildTower->setPosition(0,0);
	this->addChild(BuildTower,1);
	//开始按钮
	MenuItemImage * startmenu = MenuItemImage::create("start1.png", "start2.png", 
					CC_CALLBACK_1(GameScene::menustartCallback, this));
	Scene * CCC = Director::getInstance()->getRunningScene();
	startmenu->setPosition(Director::getInstance()->convertToGL(Vec2(480, 400)));
	Menu * mu = Menu::create(startmenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu,1,000);
	return true;
}

void GameScene::updatenum(float dt)
{
	auto i = new Enemy;
	this->addChild(i, 1, tag);
	i->createEnemy();
	for (int b = 0; b < 100; b++) {
		if (EnemyArray[b] == 0) {
			EnemyArray[b] = tag;
			break;
		}
	}
	tag++;
	i->plus();
	if (i->getNum() >= num) { this->unschedule(schedule_selector(GameScene::updatenum)); }

}
void GameScene::SetTower1() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->getEnemyArray(EnemyArray);
	tt->setPosition(290,358);
	this->addChild(tt, 2);
}
void GameScene::SetTower2() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->getEnemyArray(EnemyArray);
	tt->setPosition(390, 538);
	this->addChild(tt, 2);
}
void GameScene::SetTower3() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->getEnemyArray(EnemyArray);
	tt->setPosition(450, 278);
	this->addChild(tt, 2);
}
void GameScene::SetTower4() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->getEnemyArray(EnemyArray);
	tt->setPosition(780, 278);
	this->addChild(tt, 2);
}

void GameScene::SetTower5() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->getEnemyArray(EnemyArray);
	tt->setPosition(780, 538);
	this->addChild(tt, 2);
}

void GameScene::menustartCallback(Ref * pSender)
{
	this->schedule(schedule_selector(GameScene::updatenum), 1.0f / 1);
	this->removeChildByTag(000);
}
int Enemy::num1 = 0;
