#include "BuildMenuPanel.h"
#include "ArcherTowerLv1.h"

USING_NS_CC;

void BuildMenuPanel::initPanel()
{
	PanelSprite = Sprite::create("UpdatePanel.png");
	PanelSprite->setScale(1.0f);
	PanelSprite->setPosition(Vec2(0, 0));
	this->addChild(PanelSprite);
}

void BuildMenuPanel::addTower(TowerType towerType, Vec2 position)
{

	int nTag = (int)towerType;
	switch (nTag)
	{
	case 0:
	{
		auto archerTower = new ArcherTowerLv1;
		archerTower->initTower();
		archerTower->setPosition(position);
		//archerTower->setTag(0);					//此处0为后期整合时由别的头文件传入
		
		/*在此处应有扣除金钱的相关操作
		由于缺少相关文件特于此略去*/


		/*case 别的塔*/
	}
	default:
		break;
	}
	isBuilt = true;
}

void BuildMenuPanel::addIcons()
{
	BuildIcon1 = new BaseBuildIcon;
	BuildIcon1->initIcon(ARCHER_1, 80);
	BuildIcon1->setScale(1.0f);
	BuildIcon1->BaseIcon->setRotation(-45);
	BuildIcon1->setPosition(Vec2(PanelSprite->getContentSize().width / 2 - 75, PanelSprite->getContentSize().height - 28));
	BuildIcon1->PriceBase->setPosition(Vec2(5, -BuildIcon1->BaseIcon->getContentSize().height / 2 - 5));
	PanelSprite->addChild(BuildIcon1);

	BuildIcon2 = new BaseBuildIcon;
	BuildIcon2->initIcon(ORANGE_1, 80);
	BuildIcon2->setScale(1.0f);
	BuildIcon2->BaseIcon->setRotation(45);
	BuildIcon2->setPosition(Vec2(PanelSprite->getContentSize().width / 2 + 38, PanelSprite->getContentSize().height - 28));
	BuildIcon2->PriceBase->setPosition(Vec2(-5, -BuildIcon2->BaseIcon->getContentSize().height / 2 - 5));
	PanelSprite->addChild(BuildIcon2);

	BuildIcon4 = new BaseBuildIcon;
	BuildIcon4->initIcon(GREEN_1, 120);
	BuildIcon4->setScale(1.0f);
	BuildIcon4->BaseIcon->setRotation(-135);
	BuildIcon4->setPosition(Vec2(PanelSprite->getContentSize().width / 2 - 75, 50));
	BuildIcon4->PriceBase->setPosition(Vec2(5, 35));
	PanelSprite->addChild(BuildIcon4);

	BuildIcon5 = new BaseBuildIcon;
	BuildIcon5->initIcon(BLUE_1, 100);
	BuildIcon5->setScale(1.0f);
	BuildIcon5->BaseIcon->setRotation(135);
	BuildIcon5->setPosition(Vec2(PanelSprite->getContentSize().width / 2 + 38, 50));
	BuildIcon5->PriceBase->setPosition(Vec2(-5, 35));
	PanelSprite->addChild(BuildIcon5);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(BuildMenuPanel::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(BuildMenuPanel::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, BuildIcon1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), BuildIcon2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), BuildIcon4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener->clone(), BuildIcon5);
}

void BuildMenuPanel::inAnimation()
{
	PanelSprite->runAction(Sequence::create(ScaleTo::create(0.1f, 1.0f, 1.0f),
		CallFuncN::create(CC_CALLBACK_0(BuildMenuPanel::addIcons, this)),
		NULL));
}

bool BuildMenuPanel::onTouchBegan(Touch *touch, Event *event)
{
	auto target = static_cast<BaseBuildIcon *>(event->getCurrentTarget());

	Vec2 locationInNode = target->convertTouchToNodeSpace(touch);
	Size size = target->BaseIcon->getContentSize();
	Rect rect = Rect(0 - size.width / 2, 0 - size.height / 2, size.width, size.height);
	if (rect.containsPoint(locationInNode))
	{
		if (target->isSelected)
		{
			if (target->isAble)
			{
				int i = (int)(target->towerType);
				//addTower(target->towerType,position);			//建造塔
			}
		}
		return true;
	}
	return false;
}

void BuildMenuPanel::onTouchEnded(Touch* touch, Event* event)
{
	if (isBuilt)
	{
		removeFromParent();
	}
}