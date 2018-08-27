#ifndef _BASE_TOWER_H_
#define _BASE_TOWER_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum {
	ARCHER_1 = 0,					// һ������
	ARCHER_2,						// ��������
	ARCHER_3						// ��������
}TowerType;

class BaseTower : public Sprite
{
public:
	BaseTower();
	~BaseTower();
	virtual void updateTower();		// ������
	virtual void sellTower();		// ������
	virtual bool init();			// ��ʼ����
	bool isUpdateMenuShown;			// ����������Ϣ���Ƿ��
	TowerType towerType;			// ��������
	int towerLevel;					// ���ĵȼ�
	double towerScope;					// ���Ĺ�����Χ
	int towerAttackPower;			// ���Ĺ�����
	int towerUpdateMoney;			// �����������ý�Ǯ
	int towerBuildMoney;			// ���Ľ������ý�Ǯ
	void searchNearestEnemy();		// Ѱ����Χ�ĵ���
protected:
	Enemy * nearestEnemy;			//ȷ������ĵ���
	virtual void showUpdateMenu();	//չʾ�����˵�
	virtual void hideUpdateMenu();	//���������˵�
	virtual void attack(float dt);	//������
};

#endif // !_BASE_TOWER_H_

