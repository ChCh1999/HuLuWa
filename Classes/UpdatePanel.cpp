#include "Circle.h"
#include "UpdatePanel.h"
#include "BaseMenuIcon.h"

USING_NS_CC;

void UpdatePanel::initUpdatePanel()
{
	PanelSprite = Sprite::create("UpdatePanel.png");
	PanelSprite->setPosition(Vec2(0, 0));
	PanelSprite->setScale(1.0f);
	addChild(PanelSprite);

	updateIcon = new BaseMenuIcon;
	updateIcon->initIcon(ARCHER_1, 500);
	updateIcon->setPosition(Vec2(-18, PanelSprite->getContentSize().height / 2));
	updateIcon->setVisible(false);
	updateIcon->setTag(1);
	addChild(updateIcon);

	sellIcon = new SellIcon;
	sellIcon->initIcon();
	sellIcon->setPosition(Vec2(-18, -PanelSprite->getContentSize().height / 2));
	sellIcon->setVisible(false);
	sellIcon->setTag(2);
	addChild(sellIcon);

	CouldUpdate = true;

	Lock = Sprite::createWithSpriteFrameName("CannotBeSelected.png");
	Lock->setPosition(Point(0, PanelSprite->getContentSize().height / 2));
	addChild(Lock);
	Lock->setVisible(false);
}

void UpdatePanel::inAnimation()
{
	PanelSprite->runAction(Sequence::create(ScaleTo::create(0.1f, 1.0f, 1.0f),
		CallFuncN::create(CC_CALLBACK_0(UpdatePanel::addIcons, this)),
		NULL));
}

void UpdatePanel::addIcons()
{
	thisLvCircle = Circle::create();

	thisLvCircle->setScale(tower->towerScope);
	addChild(thisLvCircle);

	sellIcon->setVisible(true);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(UpdatePanel::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(UpdatePanel::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, sellIcon);
	if (CouldUpdate) {
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), updateIcon);
		updateIcon->setVisible(true);
		updateIcon->setUpdateMoney(tower->towerUpdateMoney);
	}
	else {
		Lock->setVisible(true);
	}
}

bool UpdatePanel::onTouchBegan(Touch *touch, Event *event)
{
	auto target = static_cast<BaseMenuIcon *>(event->getCurrentTarget());
	Vec2 locationInNode = target->convertTouchToNodeSpace(touch);
	Size size = target->BaseIcon->getContentSize();
	Rect rect = Rect(0 - size.width / 2, 0 - size.height / 2, size.width, size.height);
	if (rect.containsPoint(locationInNode))
	{
		if (target->isSelected)//如果已经选中
		{
			if (target->isAble)//如果钱够用
			{
				switch (target->getTag())
				{
				case(1)://升级
					// 此行为为扣除对应金钱
					tower->UpdateTower();		//执行升级塔的操作
					break;
				case(2)://售出
					// 此行为为增加对应金钱
					tower->RemoveTower();			//执行售卖塔的操作
					break;
				}
				this->setVisible(false);
				isBuilt = true;
			}
		}
		return true;
	}
	return false;
}

void UpdatePanel::onTouchEnded(Touch* touch, Event* event)
{
	if (isBuilt)
	{
		removeFromParent();
	}
}
