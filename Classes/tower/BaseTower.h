#ifndef _BASE_TOWER_H_
#define _BASE_TOWER_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum {
	ARCHER_1 = 0,					// 一级箭塔
	ARCHER_2,						// 二级箭塔
	ARCHER_3						// 三级箭塔
}TowerType;

class BaseTower : public Sprite
{
public:
	BaseTower();
	~BaseTower();
	virtual void updateTower();		// 升级塔
	virtual void sellTower();		// 售卖塔
	virtual bool init();			// 初始化塔
	bool isUpdateMenuShown;			// 塔的升级信息栏是否打开
	TowerType towerType;			// 塔的类型
	int towerLevel;					// 塔的等级
	double towerScope;					// 塔的攻击范围
	int towerAttackPower;			// 塔的攻击力
	int towerUpdateMoney;			// 塔的升级所用金钱
	int towerBuildMoney;			// 塔的建造所用金钱
	void searchNearestEnemy();		// 寻找周围的敌人
protected:
	Enemy * nearestEnemy;			//确定最近的敌人
	virtual void showUpdateMenu();	//展示升级菜单
	virtual void hideUpdateMenu();	//隐藏升级菜单
	virtual void attack(float dt);	//攻击！
};

#endif // !_BASE_TOWER_H_

