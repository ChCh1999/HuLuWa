#include "BaseMenuIcon.h"
#include "cocos2d.h"

USING_NS_CC;


void BaseMenuIcon::initIcon(TowerType towerType, int money)		//������Ӧ��������
{
	isSelected = false;
	int nTag = (int)towerType;
	switch (nTag)													//���ݶ�Ӧ�������������Ӧ������ͼ��
	{
	case 0:
		BaseIcon = Sprite::create("UpdateIcon1.png");
		break;
		/*���б������ķ���������δ���룬֮�����������������*/
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
	PriceIcon->setPosition(Vec2(PriceBase->getContentSize().width/2 - 27,PriceBase->getContentSize().height/2 + 2));
	PriceBase->addChild(PriceIcon);

	PriceLabel = Label::createWithTTF(String::createWithFormat("%d", money)->getCString(), "fonts/consola.ttf", 35);
	PriceLabel->setColor(Color3B(255, 255, 0));
	PriceLabel->setPosition(Vec2(PriceIcon->getContentSize().width / 2 + 45, BaseIcon->getContentSize().height / 2));
	PriceIcon->addChild(PriceLabel);

	BaseMenuIcon::towerType = towerType;
	BaseMenuIcon::money = money;

	this->scheduleUpdate();
}

void BaseMenuIcon::setUpdateMoney(int money)
{
	BaseMenuIcon::money = money;
	PriceLabel->setString(String::createWithFormat("%d", money)->getCString());
}

void BaseMenuIcon::setEnoughMoney()
{
	isAble = true;
	PriceLabel->setColor(Color3B(255, 255, 0));
	int nTag = (int)towerType;
	switch (nTag)													//���ݶ�Ӧ�������������Ӧ������ͼ��
	{
	case 0:
		BaseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("UpdateIcon1.png"));
		break;
		/*���б������ķ���������δ���룬֮�����������������*/
	default:
		break;
	}
}

void BaseMenuIcon::setNotEnoughMoney()
{
	isAble = false;
	PriceLabel->setColor(Color3B(102, 102, 102));
	BaseIcon->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("CannotBeSelected.png"));
}

//void UpdateMenuIcon::update(float dt)
//{
//	if (money <= MONEY)								//MONEYΪ�����ӵ�е���Ǯ��
//		setEnoughMoney();
//	else
//		setNotEnoughMoney();
//}