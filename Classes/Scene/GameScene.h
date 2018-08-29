#pragma once
#include"cocos2d.h"
#include"Enemy.h"
#include"bullet\Bullet.h"
#include"ArcherTowerLv1.h"
#include"Enemybat.h"
#include"Enemyspider.h"
#include"Enemytree.h"
#include<math.h>


class GameScene: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	int health = 20;
	int money = 200;
	
	
	int i = 1;
	int b = 0;
	int bo = 2;
	void menustartCallback(Ref * pSender);

	void SetTower1();
	void SetTower2();
	void SetTower3();
	void SetTower4();
	void SetTower5();
	int Enemies[100];
	int numbat = 15;
	int numtree = 20;
	int numspider = 15;
	int tagbat = 1;
	int tagtree = 21;
	int tagspider = 41;
	void updatenumbat(float dt);
	void updatenumtree(float dt);
	void updatenumspider(float dt);
	void updateEnemy(float dt);
	int hurt();
	CREATE_FUNC(GameScene);

};