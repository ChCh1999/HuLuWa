#include "BaseTower.h"
#include "Bullet.h"
#include "Enemy.h"


BaseTower::BaseTower():isUpdateMenuShown(false){}

BaseTower::~BaseTower() {}

bool BaseTower::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	isUpdateMenuShown = false;
	return true;
}

void BaseTower::updateTower(){}

void BaseTower::sellTower()
{
	this->setVisible(false);
	this->removeChild;
}

void BaseTower::searchNearestEnemy()
{
	Enemy * EnemyTemp, Enemy;
	double shorterDistance = towerScope;
	Vec2 towerPosition = this->getPosition();
	for (int i = 0; i <= maxEnemyTaginLevel; i++)
	{
		EnemyTemp->getParent()->getChildByTag(i);
		Vec2 enemyPosition = EnemyTemp->getPosition();
		double distance = towerPosition.getDistance(enemyPosition);
		if (distance < shorterDistance && EnemyTemp->getAttackByTower())
		{
			shorterDistance = distance;
			Enemy = EnemyTemp;
		}
	}
	nearestEnemy = Enemy;
}

void showUpdateMenu()
{

}

void hideUpdateMenu()
{

}

void attack(float dt)
{

}