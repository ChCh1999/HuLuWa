#ifndef _ARCHER_TOWER_H_
#define _ARCHER_TOWER_H_

#include "cocos2d.h"
#include "BaseTower.h"
#include "bullet.h"

USING_NS_CC;

class ArcherTower_1 : public BaseTower
{
public:
	bool init();
	virtual void showUpdateMenu();
protected:
	Sprite * TowerBase;
	Sprite * Shooter;
	int shootTag;
	virtual void attack(float dt);
};

#endif // !_ARCHER_TOWER_H_

