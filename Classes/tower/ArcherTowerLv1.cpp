
#include "ArcherTowerLv1.h"

bool ArcherTowerLv1::init()
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
int * ArcherTowerLv1::getEnemyArray(int * ee) {
	return ee;
}
void ArcherTowerLv1::initTower()
{
	TowerBase = Sprite::create("TowerBase.png");
	Shooter = Sprite::create("Shooter.png");
	Shooter->setRotation(-3);
	Shooter->setPosition(Vec2(TowerBase->getContentSize().width / 2, TowerBase->getContentSize().height / 2 + 30));
	TowerBase->addChild(Shooter);

	this->addChild(TowerBase);
}
void ArcherTowerLv1::attack(float dt)
{
	ArcherTowerLv1 * ArcherTower = new ArcherTowerLv1;
	ArcherTower->searchNearestEnemy();
	if (nearestEnemy != NULL && nearestEnemy->HP > 0)
	{
		int nTag = nearestEnemy->getTag();
		auto aBullet = new Bullet;
		Scene * scene = CCDirector::getInstance()->getRunningScene();
		scene->addChild(aBullet);
		aBullet->Shoot(ArcherTower->getTag(),nTag);
	}
}

