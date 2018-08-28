
#include"Enemyspider.h"

USING_NS_CC;

Enemyspider::Enemyspider() {
	rScene = Director::getInstance()->getRunningScene();

}
bool Enemyspider::createEnemyspider()
{
	move();
	this->schedule(schedule_selector(Enemyspider::updatedeath), 1.0f / 10);
	return true;
}
void Enemyspider::updatedeath(float dt)
{
	if (HP <= 0)
	{
		spriteaction->setVisible(false);
	}
}
void Enemyspider::rightmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spiderright.plist", "spiderright.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		__String *frameName = __String::createWithFormat("spiderright%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemyspider::leftmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spiderleft.plist", "spiderleft.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		__String *frameName = __String::createWithFormat("spiderleft%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemyspider::downmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spiderdown.plist", "spiderdown.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		__String *frameName = __String::createWithFormat("spiderdown%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemyspider::upmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spiderup.plist", "spiderup.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 4; i++)
	{
		__String *frameName = __String::createWithFormat("spiderup%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemyspider::move()
{

	Enemyspider::move1();


}
void Enemyspider::update1(float dt)
{

	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	if (spriteaction->getPosition().x == node2->getPosition().x && spriteaction->getPosition().y == node2->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemyspider::move2();
	}
}
void Enemyspider::update2(float dt)
{

	Node * node3 = Node::create();
	node3->setPosition(183, 415);
	if (spriteaction->getPosition().x == node3->getPosition().x && spriteaction->getPosition().y == node3->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemyspider::move3();
	}

}
void Enemyspider::update3(float dt)
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	if (spriteaction->getPosition().x == node4->getPosition().x && spriteaction->getPosition().y == node4->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemyspider::move4();
	}
}
void Enemyspider::update4(float dt)
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	if (spriteaction->getPosition().x == node5->getPosition().x && spriteaction->getPosition().y == node5->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemyspider::move5();
	}
}
void Enemyspider::update5(float dt)
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	if (spriteaction->getPosition().x == node6->getPosition().x && spriteaction->getPosition().y == node6->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemyspider::move6();
	}
}
void Enemyspider::update6(float dt)
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	if (spriteaction->getPosition().x == node7->getPosition().x && spriteaction->getPosition().y == node7->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemyspider::move7();
	}
}
void Enemyspider::update7(float dt)
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	if (spriteaction->getPosition().x == node8->getPosition().x && spriteaction->getPosition().y == node8->getPosition().y)
	{
		spriteaction->stopAllActions();
		spriteaction->setVisible(false);
	}
}
void Enemyspider::move1()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("spiderright.plist", "spiderright.png");
	spriteaction = Sprite::createWithSpriteFrameName("spiderright1.png");
	spriteaction->setPosition(Vec2(57.96, 169.15));
	rScene->addChild(spriteaction, 1, 123);
	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	spriteaction->runAction(MoveTo::create((183 - 57) / Speed, node2->getPosition()));    //1-2
	Enemyspider::rightmove();
	this->schedule(schedule_selector(Enemyspider::update1), 1.0f / 3);

}
void Enemyspider::move2()                                                                    //第二个点到第三个点
{
	Node * node3 = Node::create();
	node3->setPosition(183, 415);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node3->getPosition()));
	Enemyspider::upmove();
	this->schedule(schedule_selector(Enemyspider::update2), 1.0f / 10);
}
void Enemyspider::move3()
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	spriteaction->runAction(MoveTo::create((386 - 183) / Speed, node4->getPosition()));   //3-4
	Enemyspider::rightmove();
	this->schedule(schedule_selector(Enemyspider::update3), 1.0f / 10);
}
void Enemyspider::move4()
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node5->getPosition()));   //4-5
	Enemyspider::downmove();
	this->schedule(schedule_selector(Enemyspider::update4), 1.0f / 10);;
}
void Enemyspider::move5()
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	spriteaction->runAction(MoveTo::create((845 - 386) / Speed, node6->getPosition()));   //5-6
	Enemyspider::rightmove();
	this->schedule(schedule_selector(Enemyspider::update5), 1.0f / 10);;
}
void Enemyspider::move6()
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	spriteaction->runAction(MoveTo::create((604 - 169) / Speed, node7->getPosition()));//6-7
	Enemyspider::upmove();
	this->schedule(schedule_selector(Enemyspider::update6), 1.0f / 10);
}
void Enemyspider::move7()
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	spriteaction->runAction(MoveTo::create((845 - 57) / Speed, node8->getPosition()));    //7-8
	Enemyspider::leftmove();
	this->schedule(schedule_selector(Enemyspider::update7), 1.0f / 10);
}
