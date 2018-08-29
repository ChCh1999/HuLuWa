#include "BaseBuildIcon.h"
#include "cocos2d.h"

USING_NS_CC;


void BaseBuildIcon::initIcon(TowerType towerType, int money)		//传入相应塔的种类
{
	isSelected = false;
	int nTag = (int)towerType;
	switch (nTag)													//根据对应塔的种类输入对应的升级图标
	{
	case 0:
		BaseIcon = Sprite::create("TowerLeaf1.png");
		break;
	case 2:
		BaseIcon = Sprite::create("TowerLeaf2.png");
		break;
	case 4:
		BaseIcon = Sprite::create("TowerLeaf4.png");
		break;
	case 6:
		BaseIcon = Sprite::create("TowerLeaf5.png");
		break;
	default:
		break;
	}
	addChild(BaseIcon);

	PriceBase = Sprite::create("Frame.png");
	PriceBase->setScale(0.5f);
	PriceBase->setPosition(Vec2(0, -BaseIcon->getContentSize().height / 2 - 5));
	addChild(PriceBase);

	PriceIcon = Sprite::create("MoneyIcon.png");
	PriceIcon->setScale(0.87f);
	PriceIcon->setPosition(Vec2(PriceBase->getContentSize().width / 2 - 27, PriceBase->getContentSize().height / 2 + 2));
	PriceBase->addChild(PriceIcon);

	PriceLabel = Label::createWithTTF(String::createWithFormat("%d", money)->getCString(), "fonts/consola.ttf", 35);
	PriceLabel->setColor(Color3B(255, 255, 0));
	PriceLabel->setPosition(Vec2(PriceIcon->getContentSize().width / 2 + 45, BaseIcon->getContentSize().height / 2));
	PriceIcon->addChild(PriceLabel);

	OKIcon = Sprite::create("OK.png");
	OKIcon->setScaleX(0.83f);
	OKIcon->setScaleY(0.65f);
	OKIcon->setPosition(Vec2(PriceBase->getContentSize().width / 2, PriceBase->getContentSize().height / 2));
	OKIcon->setVisible(false);
	PriceBase->addChild(OKIcon);

	BaseBuildIcon::towerType = towerType;
	BaseBuildIcon::money = money;

	this->scheduleUpdate();
}

void BaseBuildIcon::setUpdateMoney(int money)
{
	BaseBuildIcon::money = money;
	PriceLabel->setString(String::createWithFormat("%d", money)->getCString());
}

void BaseBuildIcon::setEnoughMoney()
{
	isAble = true;
	PriceLabel->setColor(Color3B(255, 255, 0));
	int nTag = (int)towerType;
	switch (nTag)													//根据对应塔的种类输入对应的升级图标
	{
	case 0:
		BaseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("TowerLeaf1.png"));
		break;
	case 2:
		BaseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("TowerLeaf2.png"));
		break;
	case 4:
		BaseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("TowerLeaf4.png"));
		break;
	case 6:
		BaseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("TowerLeaf5.png"));
		break;
	default:
		break;
	}
}

void BaseBuildIcon::setNotEnoughMoney()
{
	isAble = false;
	PriceLabel->setColor(Color3B(102, 102, 102));
	BaseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("CannotBeSelected.png"));
}

void BaseBuildIcon::setSelected()
{
	isSelected = true;
	OKIcon->setVisible(true);
}

void BaseBuildIcon::setNotSelected()
{
	isSelected = false;
	OKIcon->setVisible(false);
}

//void BaseBuildIcon::update(float dt)
//{
//	if (money <= MONEY)								//MONEY为玩家所拥有的总钱数
//		setEnoughMoney();
//	else
//		setNotEnoughMoney();
//}