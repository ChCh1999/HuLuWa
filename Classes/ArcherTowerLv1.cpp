#include "BaseTower.h"
#include "ArcherTowerLv1.h"
#include "bullet.h"

bool ArcherTower_1::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	//ÓÎÏ·Êı¾İ
	towerType = ARCHER_1;
	towerLevel = 1;
	towerScope = 160.0;
	towerAttackPower = 30;
	towerUpdateMoney = 100;
	towerBuildMoney = 70;
	isUpdateMenuShown = false;
	return true;
}

void attack(float dt)
{
	BaseTower * ArcherTower = new BaseTower;
	ArcherTower->searchNearestEnemy();
	if (nearestEnemy != NULL && nearestEnemy.HP > 0)
	{
		int nTag = nearestEnemy.getTag();
		auto aBullet = new Bullet;
		Scene * scene = CCDirector::getInstance()->getRunningScene();
		scene->addChild(aBullet);
		aBullet->Shoot(ArcherTower->getTag(),nTag);
	}
}

