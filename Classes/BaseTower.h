#ifndef _BASE_TOWER_H_
#define _BASE_TOWER_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum {
	ARCHER_1 = 0,					// һ������
	ARCHER_2,						// ��������
	ORANGE_1,						// һ�������
	ORANGE_2,						// ���������
	GREEN_1,						// һ���һ���
	GREEN_2,						// �����һ���
	BLUE_1,							// һ��������
	BLUE_2							// ����������
}TowerType;	

class BaseTower : public Sprite
{
public:
	virtual bool init();			// ��ʼ����
	void UpdateTower();				// ������
	void RemoveTower();				// �Ƴ���

	bool isUpdateMenuShown;			// ����������Ϣ���Ƿ��
	TowerType towerType;			// ��������
	int towerLevel;					// ���ĵȼ�
	double towerScope;				// ���Ĺ�����Χ
	int towerAttackPower;			// ���Ĺ�����
	int towerUpdateMoney;			// �����������ý�Ǯ
	int towerBuildMoney;			// ���Ľ������ý�Ǯ
};

#endif // !_BASE_TOWER_H_

