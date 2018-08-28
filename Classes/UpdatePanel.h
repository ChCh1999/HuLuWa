#ifndef _UPDATE_PANEL_H_
#define _UPDATE_PANEL_H_

#include "cocos2d.h"
#include "BaseMenuIcon.h"
#include "SellIcon.h"
#include "BaseTower.h"

USING_NS_CC;

class UpdatePanel :public Sprite
{
public:
	void initUpdatePanel();
	void inAnimation();
	void addIcons();

	Circle* thisLvlCircle;
	Circle* nextLvlCircle;
	Sprite * PanelSprite;
	BaseMenuIcon * updateIcon;
	SellIcon * sellIcon;
	bool CouldUpdate;
	CREATE_FUNC(UpdatePanel);
};

#endif // !_UPDATE_PANEL_H_

