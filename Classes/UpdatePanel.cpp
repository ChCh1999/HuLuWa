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
}

void UpdatePanel::inAnimation()
{
	PanelSprite->runAction(Sequence::create(ScaleTo::create(0.1f, 1.0f, 1.0f),
		CallFuncN::create(CC_CALLBACK_0(UpdatePanel::addIcons, this)),
		NULL));
}

void UpdatePanel::addIcons()
{
	thisLvlCircle = Circle::create();
	nextLvlCircle = Circle::create();

	thisLvlCircle->setScale(tower->getScope() / 160.0f);
	addChild(thisLvlCircle, -1);
	nextLvlCircle->setScale((tower->getScope() + 20) / 160.0f);
	addChild(nextLvlCircle, -1);
	nextLvlCircle->setVisible(false);
	sellIcon->setVisible(true);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(UpdatePanel::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(UpdatePanel::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, sellIcon);
	if (CouldUpdate) {
		_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), updateIcon);
		updateIcon->setVisible(true);
		updateIcon->setUpdateMoney(tower->getUpdateMoney());
	}
	else {
		lock->setVisible(true);
	}


}