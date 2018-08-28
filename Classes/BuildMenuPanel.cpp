#include "BuildMenuPanel.h"
#include "ArcherTowerLv1.h"

USING_NS_CC;

bool BuildMenuPanel::init()
{
	if (!Sprite::init())
		return false;

	return true;
}

void BuildMenuPanel::initPanel()
{
	PanelSprite = Sprite::create("UpdatePanel.png");
	PanelSprite->setScale(1.0f);
	PanelSprite->setPosition(Vec2(0, 0));
	this->addChild(PanelSprite);
}

void BuildMenuPanel::addTower(TowerType towerType)
{
	int nTag = (int)towerType;
	switch (nTag)
	{
	case 0:
	{
		auto archerTower = new ArcherTowerLv1;
		archerTower->initTower();
		archerTower->setPosition(Vec2(0, 0));
		archerTower->setTag(0);					//�˴�0Ϊ��������ʱ�ɱ��ͷ�ļ�����
		/*�ڴ˴�Ӧ�п۳���Ǯ����ز���
		����ȱ������ļ����ڴ���ȥ*/


		/*case �����*/
	}
	default:
		break;
	}
}

void BuildMenuPanel::addIcons()
{
	
}