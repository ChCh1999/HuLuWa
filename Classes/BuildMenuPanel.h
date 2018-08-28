#ifndef _BUILD_MENU_PANEL_H_
#define _BUILD_MENU_PANEL_H_

#include "cocos2d.h"
#include "BaseTower.h"

USING_NS_CC;

class BuildMenuPanel : public Sprite
{
public:
	virtual bool init()override;
	void initPanel();
	void addTower(TowerType towerType);
	void addIcons();
	CREATE_FUNC(BuildMenuPanel);
private:
	Sprite * PanelSprite;
};

#endif // !_BUILD_MENU_PANEL_H_

