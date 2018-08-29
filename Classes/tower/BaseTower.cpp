#include "BaseTower.h"
#include "GameScene.h"
#include "Enemy.h"
extern int * EnemyArray;
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
	Node * EnemyTemp, *Enemy;
	Enemy = NULL;
	Scene* rScene = CCDirector::getInstance()->getRunningScene();
	double shorterDistance = 2000;
	Vec2 towerPosition = this->getPosition();
	for (int i = 0; i <100; i++)
	{
		if(EnemyArray[i]!=0){
			auto temp = rScene->getChildByTag(EnemyArray[i]);
			
			EnemyTemp = temp;
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