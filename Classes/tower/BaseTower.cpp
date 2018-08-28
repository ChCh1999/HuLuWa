#include "BaseTower.h"

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
	//this->removeChild();
}

void BaseTower::searchNearestEnemy()
{
	Enemy * EnemyTemp, *Enemy;
	Scene* rScene = CCDirector::getInstance()->getRunningScene();
	double shorterDistance = towerScope;
	Vec2 towerPosition = this->getPosition();
	for (int i = 0; i <=100; i++)
	{
		if(EnemyArray[i]!=0){
			auto temp = EnemyTemp->getParent()->getChildByTag(EnemyArray[i]);
			//EnemyTemp = dynamic_cast<Enemy *>(temp);
		Vec2 enemyPosition = EnemyTemp->getPosition();
		double distance = towerPosition.getDistance(enemyPosition);
		if (distance < shorterDistance )
		{
			shorterDistance = distance;
			Enemy = EnemyTemp;
		}
		}
	}
	nearestEnemy = Enemy;
}

//void showUpdateMenu()
//{
//
//}

//void hideUpdateMenu()
//{
//
//}

//void attack(float dt)
//{
//
//}