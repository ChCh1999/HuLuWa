#ifndef _ARCHER_TOWER_H_
#define _ARCHER_TOWER_H_

#include "cocos2d.h"
#include "BaseTower.h"
#include "bullet.h"

USING_NS_CC;

class ArcherTowerLv1 : public BaseTower
{
public:
	bool init();
	void initTower();
	virtual void showUpdateMenu();
	virtual void attack(float dt);
protected:
	Sprite * TowerBase;
	Sprite * Shooter;
	int shootTag;
};

#endif // !_ARCHER_TOWER_H_

