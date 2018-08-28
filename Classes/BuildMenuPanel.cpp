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
		archerTower->setTag(0);					//此处0为后期整合时由别的头文件传入
		/*在此处应有扣除金钱的相关操作
		由于缺少相关文件特于此略去*/


		/*case 别的塔*/
	}
	default:
		break;
	}
}

void BuildMenuPanel::addIcons()
{
	
}