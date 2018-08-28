
#include"Enemytree.h"

USING_NS_CC;

Enemytree::Enemytree() {
	rScene = Director::getInstance()->getRunningScene();

}
bool Enemytree::createEnemytree()
{
	move();
	this->schedule(schedule_selector(Enemytree::updatedeath), 1.0f / 10);
	return true;
}
void Enemytree::updatedeath(float dt)
{
	if (HP <= 0)
	{
		spriteaction->setVisible(false);
	}
}
void Enemytree::rightmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("treeright.plist", "treeright.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 7; i++)
	{
		__String *frameName = __String::createWithFormat("treeright%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemytree::leftmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("treeleft.plist", "treeleft.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 6; i++)
	{
		__String *frameName = __String::createWithFormat("treeleft%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemytree::downmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("treedown.plist", "treedown.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 6; i++)
	{
		__String *frameName = __String::createWithFormat("treedown%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemytree::upmove()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("treeup.plist", "treeup.png");
	Animation * animation = Animation::create();
	for (int i = 1; i <= 5; i++)
	{
		__String *frameName = __String::createWithFormat("treeup%d.png", i);
		log("frameName = %s", frameName->getCString());
		SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
		animation->addSpriteFrame(spriteFrame);
	}

	animation->setDelayPerUnit(0.15f);           //设置两个帧播放时间
	animation->setRestoreOriginalFrame(true);    //动画执行后还原初始状态

	Animate* action = Animate::create(animation);
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemytree::move()
{

	Enemytree::move1();


}
void Enemytree::update1(float dt)
{

	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	if (spriteaction->getPosition().x == node2->getPosition().x && spriteaction->getPosition().y == node2->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemytree::move2();
	}
}
void Enemytree::update2(float dt)
{

	Node * node3 = Node::create();
	node3->setPosition(183, 415);
	if (spriteaction->getPosition().x == node3->getPosition().x && spriteaction->getPosition().y == node3->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemytree::move3();
	}

}
void Enemytree::update3(float dt)
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	if (spriteaction->getPosition().x == node4->getPosition().x && spriteaction->getPosition().y == node4->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemytree::move4();
	}
}
void Enemytree::update4(float dt)
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	if (spriteaction->getPosition().x == node5->getPosition().x && spriteaction->getPosition().y == node5->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemytree::move5();
	}
}
void Enemytree::update5(float dt)
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	if (spriteaction->getPosition().x == node6->getPosition().x && spriteaction->getPosition().y == node6->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemytree::move6();
	}
}
void Enemytree::update6(float dt)
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	if (spriteaction->getPosition().x == node7->getPosition().x && spriteaction->getPosition().y == node7->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemytree::move7();
	}
}
void Enemytree::update7(float dt)
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	if (spriteaction->getPosition().x == node8->getPosition().x && spriteaction->getPosition().y == node8->getPosition().y)
	{
		spriteaction->stopAllActions();
		spriteaction->setVisible(false);
	}
}
void Enemytree::move1()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("treeright.plist", "treeright.png");
	spriteaction = Sprite::createWithSpriteFrameName("treeright1.png");
	spriteaction->setPosition(Vec2(57.96, 169.15));
	rScene->addChild(spriteaction, 1, 123);
	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	spriteaction->runAction(MoveTo::create((183 - 57) / Speed, node2->getPosition()));    //1-2
	Enemytree::rightmove();
	this->schedule(schedule_selector(Enemytree::update1), 1.0f / 3);

}
void Enemytree::move2()                                                                    //第二个点到第三个点
{
	Node * node3 = Node::create();
	node3->setPosition(183, 415);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node3->getPosition()));
	Enemytree::upmove();
	this->schedule(schedule_selector(Enemytree::update2), 1.0f / 10);
}
void Enemytree::move3()
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	spriteaction->runAction(MoveTo::create((386 - 183) / Speed, node4->getPosition()));   //3-4
	Enemytree::rightmove();
	this->schedule(schedule_selector(Enemytree::update3), 1.0f / 10);
}
void Enemytree::move4()
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node5->getPosition()));   //4-5
	Enemytree::downmove();
	this->schedule(schedule_selector(Enemytree::update4), 1.0f / 10);;
}
void Enemytree::move5()
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	spriteaction->runAction(MoveTo::create((845 - 386) / Speed, node6->getPosition()));   //5-6
	Enemytree::rightmove();
	this->schedule(schedule_selector(Enemytree::update5), 1.0f / 10);;
}
void Enemytree::move6()
{
	Node * node7 = Node::create();
	node7->setPosition(845, 604);
	spriteaction->runAction(MoveTo::create((604 - 169) / Speed, node7->getPosition()));//6-7
	Enemytree::upmove();
	this->schedule(schedule_selector(Enemytree::update6), 1.0f / 10);
}
void Enemytree::move7()
{
	Node * node8 = Node::create();
	node8->setPosition(57, 604);
	spriteaction->runAction(MoveTo::create((845 - 57) / Speed, node8->getPosition()));    //7-8
	Enemytree::leftmove();
	this->schedule(schedule_selector(Enemytree::update7), 1.0f / 10);
}
