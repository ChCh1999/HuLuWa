#pragma once
#include "cocos2d.h"
class Enemy : public cocos2d::Scene
{
	bool hiddenFlag;
	cocos2d::Sprite* spriteaction;
	float HP = 100;
	float Speed = 50;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void rightmove();
	virtual void leftmove();
	virtual void upmove();
	virtual void downmove();
	virtual void move(cocos2d::Ref *pSender);
	void update1(float dt);
	void update2(float dt);
	void update3(float dt);
	void update4(float dt);
	void update5(float dt);
	void update6(float dt);
	void update7(float dt);
	void update8(float dt);
	void update9(float dt);
	void update10(float dt);
	void update11(float dt);
	void move1();
	void move2();
	void move3();
	void move4();
	void move5();
	void move6();
	void move7();
	void move8();
	void move9();
	void move10();
	void move11();
	void updatedeath(float dt);

	CREATE_FUNC(Enemy);
};

