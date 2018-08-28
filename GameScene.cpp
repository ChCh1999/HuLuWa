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
		this->addChild(bat,1,tagbat);
		bat->createEnemybat();
		for ( b; b < 100; b++) {
			if (a[b] == 0) 
			{
				a[b] = tagbat;
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
		if (a[b] == 0)
		{
			a[b] = tagtree;
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
		if (a[b] == 0)
		{
			a[b] = tagspider;
			break;
		}
	}

	if (i == numspider) { this->unschedule(schedule_selector(GameScene::updatenumspider)); }
	i++;
}
void GameScene::menustartCallback(Ref * pSender)
{
	this->schedule(schedule_selector(GameScene::updatenumbat), 1.0f / 1);
	this->schedule(schedule_selector(GameScene::updateEnemy), 40.0f / 1);
}
