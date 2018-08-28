#ifndef _BASE_MENU_ICON_H_
#define _BASE_MENU_ICON_H_

#include "BaseTower.h"
#include "cocos2d.h"

USING_NS_CC;

class BaseMenuIcon : public Sprite
{
public:
	virtual void initIcon(TowerType towerType, int money);

	virtual void setEnoughMoney();
	virtual void setNotEnoughMoney();
	virtual void setUpdateMoney(int money);

	Sprite * BaseIcon;
	Sprite * PriceBase;
	Sprite * PriceIcon;
	Label * PriceLabel;
protected:
	bool isAble;
	bool isSelected;
	int money;
	/*void update(float dt);*/
	TowerType towerType;
	CREATE_FUNC(BaseMenuIcon);
};
#endif // !_UPDATE_MENU_ICON_H_

