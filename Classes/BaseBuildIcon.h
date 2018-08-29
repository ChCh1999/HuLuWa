#ifndef _BASE_BUILD_ICON_H_
#define _BASE_BUILD_ICON_H_

#include "BaseTower.h"
#include "cocos2d.h"

USING_NS_CC;

class BaseBuildIcon : public Sprite
{
public:
	virtual void initIcon(TowerType towerType, int money);

	virtual void setEnoughMoney();
	virtual void setNotEnoughMoney();
	virtual void setUpdateMoney(int money);
	virtual void setSelected();
	virtual void setNotSelected();

	Sprite * BaseIcon;
	Sprite * PriceBase;
	Sprite * PriceIcon;
	Label * PriceLabel;
	Sprite * OKIcon;
	bool isAble;
	bool isSelected;
	int money;
	/*void update(float dt);*/
	TowerType towerType;
	CREATE_FUNC(BaseBuildIcon);
};
#endif // !_UPDATE_MENU_ICON_H_