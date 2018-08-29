#ifndef _BASE_TOWER_H_
#define _BASE_TOWER_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum {
	ARCHER_1 = 0,					// 一级箭塔
	ARCHER_2,						// 二级箭塔
	ORANGE_1,						// 一级金刚塔
	ORANGE_2,						// 二级金刚塔
	GREEN_1,						// 一级烈火塔
	GREEN_2,						// 二级烈火塔
	BLUE_1,							// 一级激浪塔
	BLUE_2							// 二级激浪塔
}TowerType;	

class BaseTower : public Sprite
{
public:
	virtual bool init();			// 初始化塔
	void UpdateTower();				// 升级塔
	void RemoveTower();				// 移除塔

	bool isUpdateMenuShown;			// 塔的升级信息栏是否打开
	TowerType towerType;			// 塔的类型
	int towerLevel;					// 塔的等级
	double towerScope;				// 塔的攻击范围
	int towerAttackPower;			// 塔的攻击力
	int towerUpdateMoney;			// 塔的升级所用金钱
	int towerBuildMoney;			// 塔的建造所用金钱
};

#endif // !_BASE_TOWER_H_

