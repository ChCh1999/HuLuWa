#include "SellIcon.h"

void SellIcon::initIcon()
{
	isAble = true;
	PriceBase->setVisible(false);
	BaseIcon = Sprite::create("SellIcon.png");
}