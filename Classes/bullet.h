#include"cocos2d.h"

USING_NS_CC;

class Bullet:public Sprite{
public:
	int Shoot(int tagoftower, int Tag);
	void Hit(float dt);
	bool IfKill();
	int setDamage(int D);
protected:
	int damage = 25 ;
	int tagOfEnemy;
	int tagOfTower;
};