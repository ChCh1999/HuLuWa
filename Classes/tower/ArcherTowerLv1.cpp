
#include "ArcherTowerLv1.h"
#include"Bullet.h"
#include"GameScene.h"

bool ArcherTowerLv1::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	//ÓÎÏ·Êı¾İ
	//towerType = ARCHER_1;
	
	return true;
}

void ArcherTowerLv1::initTower()
{	
	towerLevel = 1;
	towerScope = 160.0;
	towerAttackPower = 30;
	towerUpdateMoney = 100;
	towerBuildMoney = 70;
	isUpdateMenuShown = false;
	TowerBase = Sprite::create("TowerBase.png");
	Shooter = Sprite::create("Shooter.png");
	Shooter->setRotation(-3);
	Shooter->setPosition(Vec2(TowerBase->getContentSize().width / 2, 
		TowerBase->getContentSize().height / 2 + 30));
	TowerBase->addChild(Shooter);
	this->schedule(schedule_selector(ArcherTowerLv1::attack),1.0f);
	this->addChild(TowerBase);
}
void ArcherTowerLv1::attack(float dt)
{
	
	this->searchNearestEnemy();
	if (nearestEnemy != NULL)
	{
		int nTag = nearestEnemy->getTag();
		auto aBullet = new Bullet;
		aBullet->Shoot(this->getTag(),nTag);
	}
}

