#pragma once
#include "cocos2d.h"
#include "Enemy.h"
class Enemyspider : public Enemy
{

	cocos2d::Sprite* spriteaction;

	float HP = 120;
	float Speed = 50;
	cocos2d::Scene* rScene;

public:
	Enemyspider();
	bool createEnemyspider();
	virtual void rightmove();
	virtual void leftmove();
	virtual void upmove();
	virtual void downmove();
	virtual void move();

	void update1(float dt);
	void update2(float dt);
	void update3(float dt);
	void update4(float dt);
	void update5(float dt);
	void update6(float dt);
	void update7(float dt);

	void move1();
	void move2();
	void move3();
	void move4();
	void move5();
	void move6();
	void move7();

	void updatedeath(float dt);
};