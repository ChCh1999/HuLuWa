#ifndef _UPDATE_PANEL_H_
#define _UPDATE_PANEL_H_

#include "cocos2d.h"
#include "BaseMenuIcon.h"
#include "SellIcon.h"
#include "Circle.h"
#include "BaseTower.h"

USING_NS_CC;

class UpdatePanel :public Sprite
{
public:
	void initUpdatePanel();
	void inAnimation();
	void addIcons();
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch* touch, Event* event);

	BaseTower * tower;
	Circle * thisLvCircle;
	Sprite * PanelSprite;
	Sprite * Lock;
	BaseMenuIcon * updateIcon;
	SellIcon * sellIcon;

	bool CouldUpdate;
	bool isBuilt;

	CREATE_FUNC(UpdatePanel);
};

#endif // !_UPDATE_PANEL_H_

