
#include"Enemybat.h"
#include"GameScene.h"
USING_NS_CC;

extern int HealthOfScene1;
Enemybat::Enemybat() {
	 rScene = Director::getInstance()->getRunningScene();
	 
}
bool Enemybat::createEnemybat()
{
	move();
	this->schedule(schedule_selector(Enemybat::updatedeath), 1.0f / 10);
	return true;
}
void Enemybat::updatedeath(float dt) 
{ 
	if (HP <=0) 
	{ 
		spriteaction->setVisible(false);
	}
}
void Enemybat::rightmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("right.plist", "right.png");
	Animation * animation = Animation::create();
	for (int i = 9; i <= 12; i++)
	{
		__String *frameName = __String::createWithFormat("%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemybat::leftmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("left.plist", "left.png");
	Animation * animation = Animation::create();
	for (int i = 13; i <= 16; i++)
	{
		__String *frameName = __String::createWithFormat("%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemybat::downmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("down.plist", "down.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		__String *frameName = __String::createWithFormat("%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemybat::upmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("up.plist", "up.png");
	Animation * animation = Animation::create();
	for (int i = 5; i <= 8; i++)
	{
		__String *frameName = __String::createWithFormat("%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemybat::move()
	{

	Enemybat::move1();
	

	}
void Enemybat::update1(float dt) 
{

	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	if (spriteaction->getPosition().x == node2->getPosition().x && spriteaction->getPosition().y == node2->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemybat::move2();
	}
}
void Enemybat::update2(float dt)
{

		Node * node3 = Node::create();
		node3->setPosition(183, 415);
		if (spriteaction->getPosition().x == node3->getPosition().x && spriteaction->getPosition().y == node3->getPosition().y)
		{
			spriteaction->stopAllActions();
			Enemybat::move3();
		}
	
}
void Enemybat::update3(float dt)
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	if (spriteaction->getPosition().x == node4->getPosition().x && spriteaction->getPosition().y == node4->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemybat::move4();
	}
}
void Enemybat::update4(float dt)
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	if (spriteaction->getPosition().x == node5->getPosition().x && spriteaction->getPosition().y == node5->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemybat::move5();
	}
}
void Enemybat::update5(float dt)
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	if (spriteaction->getPosition().x == node6->getPosition().x && spriteaction->getPosition().y == node6->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemybat::move6();
	}
}
void Enemybat::update6(float dt)
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	if (spriteaction->getPosition().x == node7->getPosition().x && spriteaction->getPosition().y == node7->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemybat::move7();
	}
}
void Enemybat::update7(float dt)
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	if (spriteaction->getPosition().x == node8->getPosition().x && spriteaction->getPosition().y == node8->getPosition().y)
	{
		spriteaction->stopAllActions();
		spriteaction->setVisible(false);
		if (HP >= 0) { 
			HealthOfScene1--;
			CCString * healths = CCString::createWithFormat("%d", HealthOfScene1);
			dynamic_cast<Label *>(rScene->getChildByName("HealthBar"))->setString(healths->getCString());
		};
	}
}
void Enemybat::move1() 
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("right.plist", "right.png");
	spriteaction = Sprite::createWithSpriteFrameName("9.png");
	spriteaction->setPosition(Vec2(57.96, 169.15));
    rScene->addChild(spriteaction, 1, 123);
	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	spriteaction->runAction(MoveTo::create((183 - 57) / Speed, node2->getPosition()));    //1-2
	Enemybat::rightmove();
	this->schedule(schedule_selector(Enemybat::update1), 1.0f / 3);

}
void Enemybat::move2()                                                                    //第二个点到第三个点
{
	Node * node3 = Node::create();
	node3->setPosition(183, 415);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node3->getPosition()));
	Enemybat::upmove();
	this->schedule(schedule_selector(Enemybat::update2), 1.0f / 10);
}
void Enemybat::move3()                                                                   
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	spriteaction->runAction(MoveTo::create((386 - 183) / Speed, node4->getPosition()));   //3-4
	Enemybat::rightmove();
	this->schedule(schedule_selector(Enemybat::update3), 1.0f / 10);
}
void Enemybat::move4()                                                                   
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node5->getPosition()));   //4-5
	Enemybat::downmove();
	this->schedule(schedule_selector(Enemybat::update4), 1.0f / 10);;
}
void Enemybat::move5()                                                              
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	spriteaction->runAction(MoveTo::create((845 - 386) / Speed, node6->getPosition()));   //5-6
	Enemybat::rightmove();
	this->schedule(schedule_selector(Enemybat::update5), 1.0f / 10);;
}
void Enemybat::move6()
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	spriteaction->runAction(MoveTo::create((604 - 169) / Speed, node7->getPosition()));//6-7
	Enemybat::upmove();
	this->schedule(schedule_selector(Enemybat::update6), 1.0f / 10);
}
void Enemybat::move7()
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	spriteaction->runAction(MoveTo::create((845 - 57) / Speed, node8->getPosition()));    //7-8
	Enemybat::leftmove();
	this->schedule(schedule_selector(Enemybat::update7), 1.0f / 10);
}

