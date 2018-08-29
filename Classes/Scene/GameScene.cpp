#include "GameScene.h"


USING_NS_CC;

int * EnemyArray;
int HealthOfScene1 = 20;

Scene * GameScene::createScene() {
	return GameScene::create();
}

bool GameScene::init() {
	if (!Scene::init())
	{
		return false;
	}
	EnemyArray = Enemies;
	Size winSize = Director::getInstance()->getWinSize();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//地图
	Sprite * bgOflevel1 = Sprite::create("map1.png");
	float bgx = visibleSize.width / bgOflevel1->getContentSize().width;
	float bgy = visibleSize.height / bgOflevel1->getContentSize().height;
	bgOflevel1->setScale(bgx,bgy);
	bgOflevel1->setPosition(winSize.width / 2, winSize.height / 2);
	this->addChild(bgOflevel1, 0);

	//老爷爷
	Sprite * grandpa = Sprite::create("grand.png");
	grandpa->setPosition(57, 604);
	grandpa->setScale(0.2);
	this->addChild(grandpa, 1);
	//血量条
	Sprite * healthicon = Sprite::create("health.png");
	healthicon->setPosition(50,730);
	this->addChild(healthicon, 1);
	Sprite * healthbg = Sprite::create("hbg.png");
	healthbg->setPosition(130,730);
	healthbg->setScaleX(0.85);
	this->addChild(healthbg, 1);
	CCString * healths = CCString::createWithFormat("%d", HealthOfScene1);
	auto healthlabel = Label::create(healths->getCString(), "arial.ttf", 20);
	healthlabel->setPosition(130, 730);
	healthlabel -> setName("HealthBar");
	this->addChild(healthlabel, 2);

	//金钱条
	Sprite * moneyicon = Sprite::create("money.png");
	moneyicon->setPosition(210,730);
	moneyicon->setScale(1.3);
	this->addChild(moneyicon, 1);
	Sprite *moneybg = Sprite::create("hbg.png");
	moneybg->setPosition(290,730);
	moneybg->setScaleX(0.85);
	this->addChild(moneybg);  
	CCString * moneys = CCString::createWithFormat("%d", this->money);
	auto moneylabel = Label::create(moneys->getCString(), "arial.ttf", 20);
	moneylabel->setPosition(290, 730);
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



void GameScene::SetTower1() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->setPosition(290,358);
	this->addChild(tt, 2,100);
}
void GameScene::SetTower2() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->setPosition(390, 538);
	this->addChild(tt, 2,200);
}
void GameScene::SetTower3() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->setPosition(450, 278);
	this->addChild(tt, 2,300);
}
void GameScene::SetTower4() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->setPosition(780, 278);
	this->addChild(tt, 2,400);
}
void GameScene::SetTower5() {
	ArcherTowerLv1 * tt = new ArcherTowerLv1;
	tt->initTower();
	tt->setPosition(780, 538);
	this->addChild(tt, 2,500);
}

void GameScene::menustartCallback(Ref * pSender)
{
	this->schedule(schedule_selector(GameScene::updatenumbat), 1.0f / 1);
	this->schedule(schedule_selector(GameScene::updateEnemy), 40.0f / 1);
	this->removeChildByTag(000);
}

void GameScene::updateEnemy(float dt)
{
	if (bo == 2) {
		i = 1;
		this->schedule(schedule_selector(GameScene::updatenumtree), 1.0f / 1);
	}
	else if (bo == 3) {
		i = 1;
		this->schedule(schedule_selector(GameScene::updatenumspider), 1.0f / 1);
	}
	else
	{
		this->unschedule(schedule_selector(GameScene::updateEnemy));
	}
	bo += 1;
}
void GameScene::updatenumbat(float dt)
{

	auto bat = new Enemybat;
	this->addChild(bat, 1, tagbat);
	bat->createEnemybat();
	for (b; b < 100; b++) {
		if (Enemies[b] == 0)
		{
			Enemies[b] = tagbat;
			break;
		}
	}
	tagbat++;
	if (i == numbat) { this->unschedule(schedule_selector(GameScene::updatenumbat)); }
	i++;
}
void GameScene::updatenumtree(float dt)
{
	auto tree = new Enemytree;
	this->addChild(tree, 1, tagtree);
	tree->createEnemytree();
	for (int b = 0; b < 100; b++) {
		if (Enemies[b] == 0)
		{
			Enemies[b] = tagtree;
			break;
		}
	}

	if (i == numtree) { this->unschedule(schedule_selector(GameScene::updatenumtree)); }
	i++;
}
void GameScene::updatenumspider(float dt)
{
	auto spider = new Enemyspider;
	this->addChild(spider, 1, tagspider);
	spider->createEnemyspider();
	for (int b = 0; b < 100; b++) {
		if (Enemies[b] == 0)
		{
			Enemies[b] = tagspider;
			break;
		}
	}

	if (i == numspider) { this->unschedule(schedule_selector(GameScene::updatenumspider)); }
	i++;
}
int GameScene::hurt() {
	HealthOfScene1--;
	CCString * healths = CCString::createWithFormat("%d", HealthOfScene1);
	auto healthlabel = Label::create(healths->getCString(), "arial.ttf", 16);
	healthlabel->setPosition(130, 730);
	this->addChild(healthlabel, 2);
	return HealthOfScene1;
}