
#include"Enemy.h"

USING_NS_CC;

Enemy::Enemy() {
	rScene = Director::getInstance()->getRunningScene();
}
bool Enemy::createEnemy()
{
	rScene->schedule(schedule_selector(Enemy::updatedeath), 1.0f / 10);
	return true;
}
void Enemy::updatedeath(float dt) 
{ 
	if (HP >0) 
	{ 
		Enemy::move();
	}
	else 
	{
		this->setVisible(false);
	}
}
void Enemy::rightmove()
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
	this->runAction(RepeatForever::create(action));

}
void Enemy::leftmove()
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
	this->runAction(RepeatForever::create(action));

}
void Enemy::downmove()
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
	this->runAction(RepeatForever::create(action));

}
void Enemy::upmove()
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
	this->runAction(RepeatForever::create(action));

}
void Enemy::move()
	{

	Enemy::move1();
	

	}
void Enemy::update1(float dt) 
{
	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	if (this->getPosition().x == node2->getPosition().x && this->getPosition().y == node2->getPosition().y)
	{
		this->stopAllActions();
		Enemy::move2();
	}
}
void Enemy::update2(float dt)
{

		Node * node3 = Node::create();
		node3->setPosition(183, 415);
		if (this->getPosition().x == node3->getPosition().x && this->getPosition().y == node3->getPosition().y)
		{
			this->stopAllActions();
			Enemy::move3();
		}
	
}
void Enemy::update3(float dt)
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	if (this->getPosition().x == node4->getPosition().x && this->getPosition().y == node4->getPosition().y)
	{
		this->stopAllActions();
		Enemy::move4();
	}
}
void Enemy::update4(float dt)
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	if (this->getPosition().x == node5->getPosition().x && this->getPosition().y == node5->getPosition().y)
	{
		this->stopAllActions();
		Enemy::move5();
	}
}
void Enemy::update5(float dt)
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	if (this->getPosition().x == node6->getPosition().x && this->getPosition().y == node6->getPosition().y)
	{
		this->stopAllActions();
		Enemy::move6();
	}
}
void Enemy::update6(float dt)
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	if (this->getPosition().x == node7->getPosition().x && this->getPosition().y == node7->getPosition().y)
	{
		this->stopAllActions();
		Enemy::move7();
	}
}
void Enemy::update7(float dt)
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	if (this->getPosition().x == node8->getPosition().x && this->getPosition().y == node8->getPosition().y)
	{
		this->stopAllActions();
		this->setVisible(false);
	}
}


void Enemy::move1() 
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("right.plist", "right.png");
	this->createWithSpriteFrameName("9.png");

	this->setPosition(Vec2(57.96, 169.15));
	rScene->addChild(this, 1, 123);
	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	this->runAction(MoveTo::create((183 - 57) / Speed, node2->getPosition()));    //1-2
	Enemy::rightmove();
	rScene->schedule(schedule_selector(Enemy::update1), 1.0f / 10);

}
void Enemy::move2()                                                                    //第二个点到第三个点
{
	Node * node3 = Node::create();
	node3->setPosition(183, 415);
	this->runAction(MoveTo::create((415 - 169) / Speed, node3->getPosition()));
	Enemy::upmove();
	rScene->schedule(schedule_selector(Enemy::update2), 1.0f / 10);
}
void Enemy::move3()                                                                   
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	this->runAction(MoveTo::create((386 - 183) / Speed, node4->getPosition()));   //3-4
	Enemy::rightmove();
	rScene->schedule(schedule_selector(Enemy::update3), 1.0f / 10);
}
void Enemy::move4()                                                                   
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	this->runAction(MoveTo::create((415 - 169) / Speed, node5->getPosition()));   //4-5
	Enemy::downmove();
	rScene->schedule(schedule_selector(Enemy::update4), 1.0f / 10);;
}
void Enemy::move5()                                                              
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	this->runAction(MoveTo::create((845 - 386) / Speed, node6->getPosition()));   //5-6
	Enemy::rightmove();
	rScene->schedule(schedule_selector(Enemy::update5), 1.0f / 10);;
}
void Enemy::move6()
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	this->runAction(MoveTo::create((604 - 169) / Speed, node7->getPosition()));//6-7
	Enemy::upmove();
	this->schedule(schedule_selector(Enemy::update6), 1.0f / 10);
}
void Enemy::move7()
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	this->runAction(MoveTo::create((845 - 57) / Speed, node8->getPosition()));    //7-8
	Enemy::leftmove();
	this->schedule(schedule_selector(Enemy::update7), 1.0f / 10);
}
