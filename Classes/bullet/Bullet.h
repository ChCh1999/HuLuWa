#pragma once
#include"cocos2d.h"

USING_NS_CC;

class Bullet:public Sprite {
public:
	Bullet();

	int Shoot(int tagoftower, int Tag);

	//bool IfKill();
	int setDamage(int D);
protected:
	bool kill = 0;
	Scene * rScene;
	void Hit(float dt);
	void clear(float dt);
	int damage = 25;
	int tagOfEnemy;
	int tagOfTower;
};

