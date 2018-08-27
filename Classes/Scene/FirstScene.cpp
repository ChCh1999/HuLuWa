#include "FirstScene.h"

#include<math.h>

USING_NS_CC;

Scene * FirstScene::createScene() {
	return FirstScene::create();
}

bool FirstScene::init() {
	if (!Scene::init())
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();

	Sprite * tower = Sprite::create("tower.png");
	Sprite * enemy = Sprite::create("blank.png");
	enemy->setTag(001);
	tower->setTag(000);
	this->addChild(tower, 1);
	this->addChild(enemy, 1);
	tower->setPosition(Vec2(winSize.width / 2+200, winSize.height / 2));
	enemy->setPosition(Vec2(10, winSize.height / 2+200));
	enemy->runAction(MoveTo::create(10, Vec2(winSize.width-10, winSize.height / 2+200)));
	this->schedule(schedule_selector(FirstScene::searchEnemy), 1.0f);
	return true;
}
void FirstScene::searchEnemy(float dt) {
	auto tower = this->getChildByTag(000);
	auto enemy = this->getChildByTag(001);
	if (enemy == NULL)
		return;
	Vec2 TP = tower->getPosition();
	Vec2 EP = enemy->getPosition();
	double distence = sqrt(pow(TP.x - EP.x, 2) + pow(TP.y - EP.y, 2));
	if (distence < 300) {
		auto myB =new Bullet;
		this->addChild(myB,1);
		myB->Shoot(000,001);
	}
}


//µ÷ÊÔÓÃÄ£°å
//void FirstScene::searchEnemy(float dt) {
//	auto tower = this->getChildByTag(0)->getChildByTag(000);
//	auto enemy = this->getChildByTag(0)->getChildByTag(001);
//	
//	Vec2 TP = tower->getPosition();
//	Vec2 EP = enemy->getPosition();
//	double distence = sqrt(pow(TP.x - EP.x, 2) + pow(TP.y - EP.y, 2));
//	if (distence < 300) {
//		Sprite * Bullet= Sprite::create("blank.png");
//		this->getChildByTag(000)->addChild(Bullet, 0, 002);
//		Bullet->setScale(0.2f, 0.2f);
//		Bullet->setPosition(tower->getPosition());
//		Bullet->runAction(MoveTo::create(0.3f, EP));
//
//		int hit = 0;
//		this->schedule(schedule_selector(FirstScene::hit), 0.1f);
//		//this->sechedule->(schedule_selector(), 0.5f);
//
//	}
//}
//int hite1 = 0;
//void FirstScene::hit(float dt) {
//	auto Bullet= this->getChildByTag(0)->getChildByTag(002);
//	auto enemy = this->getChildByTag(0)->getChildByTag(001);
//	auto rectE = enemy->boundingBox();
//	auto rectB = Bullet->boundingBox();
//	if (rectB.intersectsRect(rectE)) {
//		hite1++;
//		this->getChildByTag(0)->removeChildByTag(002);
//		this->unschedule(schedule_selector(FirstScene::hit));
//	}
//	if (hite1 >= 5) {
//		this->getChildByTag(0)->removeChildByTag(001);
//		
//		this->unscheduleAllSelectors();
//	}
//}