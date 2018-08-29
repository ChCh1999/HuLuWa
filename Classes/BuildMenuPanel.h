#ifndef _BUILD_MENU_PANEL_H_
#define _BUILD_MENU_PANEL_H_

#include "Circle.h"
#include "cocos2d.h"
#include "BaseTower.h"
#include "BaseBuildIcon.h"

USING_NS_CC;

class BuildMenuPanel : public Sprite
{
public:
	void initPanel();
	void inAnimation();
	void addTower(TowerType towerType, Vec2 position);
	void addIcons();
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);
	CREATE_FUNC(BuildMenuPanel);

	BaseTower * tower;
	Circle * thisLvCircle;
	Sprite * PanelSprite;
	BaseBuildIcon * BuildIcon1;
	BaseBuildIcon * BuildIcon2;
	BaseBuildIcon * BuildIcon4;
	BaseBuildIcon * BuildIcon5;
	bool isBuilt;
};

#endif // !_BUILD_MENU_PANEL_H_

