#pragma once
#include"cocos2d.h"
#include"Enemy.h"
#include"ArcherTowerLv1.h"
#include<math.h>
class GameScene: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	int health = 20;
	int money = 200;
	int num = 15;
	int EnemyArray[100];
	int tag = 1;
	void menustartCallback(Ref * pSender);
	void SetTower1();
	void SetTower2();
	void SetTower3();
	void SetTower4();
	void SetTower5();
	void updatenum(float dt);

	CREATE_FUNC(GameScene);

};