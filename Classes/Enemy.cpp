#include"myscene.h"
#include"Enemy.h"

USING_NS_CC;
Scene* Enemy::createScene()
{
	return Enemy::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in scene1.cpp\n");
}
bool Enemy::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto winsize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!Scene::init())
	{
		return false;
	}

	Sprite * bg1 = Sprite::create("background1.png");
	bg1->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	auto sizebg1 = bg1->getContentSize();
	double x = winsize.width / sizebg1.width;
	double y = winsize.height / sizebg1.height;
	bg1->setScale(x, y);
	this->addChild(bg1);

	this->schedule(schedule_selector(Enemy::updatedeath), 1.0f / 10);
	return true;
}
void Enemy::updatedeath(float dt) 
{ 
	if (HP >0) 
	{ 
		Sprite * startmoveitem = Sprite::create("go.png");
		MenuItemSprite * goitem = MenuItemSprite::create(startmoveitem, startmoveitem, CC_CALLBACK_1(Enemy::move, this));
		goitem->setPosition(Director::getInstance()->convertToGL(Vec2(700, 170)));
		auto menu = Menu::create(goitem, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 3);
	}
	else 
	{
		spriteaction->setVisible(false);
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
	spriteaction->runAction(RepeatForever::create(action));

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
	spriteaction->runAction(RepeatForever::create(action));

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
	spriteaction->runAction(RepeatForever::create(action));

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
	spriteaction->runAction(RepeatForever::create(action));

}
void Enemy::move(Ref *pSender)
	{

	Enemy::move1();

	}
void Enemy::update1(float dt) 
{
	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	if (spriteaction->getPosition().x == node2->getPosition().x && spriteaction->getPosition().y == node2->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move2();
	}
}
void Enemy::update2(float dt)
{

		Node * node3 = Node::create();
		node3->setPosition(183, 415);
		if (spriteaction->getPosition().x == node3->getPosition().x && spriteaction->getPosition().y == node3->getPosition().y)
		{
			spriteaction->stopAllActions();
			Enemy::move3();
		}
	
}
void Enemy::update3(float dt)
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	if (spriteaction->getPosition().x == node4->getPosition().x && spriteaction->getPosition().y == node4->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move4();
	}
}
void Enemy::update4(float dt)
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	if (spriteaction->getPosition().x == node5->getPosition().x && spriteaction->getPosition().y == node5->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move5();
	}
}
void Enemy::update5(float dt)
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	if (spriteaction->getPosition().x == node6->getPosition().x && spriteaction->getPosition().y == node6->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move6();
	}
}
void Enemy::update6(float dt)
{
	Node * node7 = Node::create();
	node7->setPosition(845, 295);
	if (spriteaction->getPosition().x == node7->getPosition().x && spriteaction->getPosition().y == node7->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move7();
	}
}
void Enemy::update7(float dt)
{
	Node * node8 = Node::create();
	node8->setPosition(580, 295);
	if (spriteaction->getPosition().x == node8->getPosition().x && spriteaction->getPosition().y == node8->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move8();
	}
}
void Enemy::update8(float dt)
{
	Node * node9 = Node::create();
	node9->setPosition(580, 415);
	if (spriteaction->getPosition().x == node9->getPosition().x && spriteaction->getPosition().y == node9->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move9();
	}
}
void Enemy::update9(float dt)
{
	Node * node10 = Node::create();
	node10->setPosition(845, 415);
	if (spriteaction->getPosition().x == node10->getPosition().x && spriteaction->getPosition().y == node10->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move10();
	}
}
void Enemy::update10(float dt)
{
	Node * node11 = Node::create();
	node11->setPosition(845, 604);
	if (spriteaction->getPosition().x == node11->getPosition().x && spriteaction->getPosition().y == node11->getPosition().y)
	{
		spriteaction->stopAllActions();
		Enemy::move11();
	}
}
void Enemy::update11(float dt)
{
	Node * node12 = Node::create();
	node12->setPosition(57, 604);
	if (spriteaction->getPosition().x == node12->getPosition().x && spriteaction->getPosition().y == node12->getPosition().y)
	{
		spriteaction->stopAllActions();
		removeChildByTag(123, true);
	}
}
void Enemy::move1() 
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("right.plist", "right.png");
	spriteaction = Sprite::createWithSpriteFrameName("9.png");
	spriteaction->setPosition(Vec2(57.96, 169.15));
	this->addChild(spriteaction, 1, 123);
	Node * node2 = Node::create();
	node2->setPosition(183, 169);
	spriteaction->runAction(MoveTo::create((183 - 57) / Speed, node2->getPosition()));    //1-2
	Enemy::rightmove();
	this->schedule(schedule_selector(Enemy::update1), 1.0f / 10);

}
void Enemy::move2()                                                                    //第二个点到第三个点
{
	Node * node3 = Node::create();
	node3->setPosition(183, 415);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node3->getPosition()));
	Enemy::upmove();
	this->schedule(schedule_selector(Enemy::update2), 1.0f / 10);
}
void Enemy::move3()                                                                   
{
	Node * node4 = Node::create();
	node4->setPosition(386, 415);
	spriteaction->runAction(MoveTo::create((386 - 183) / Speed, node4->getPosition()));   //3-4
	Enemy::rightmove();
	this->schedule(schedule_selector(Enemy::update3), 1.0f / 10);
}
void Enemy::move4()                                                                   
{
	Node * node5 = Node::create();
	node5->setPosition(386, 169);
	spriteaction->runAction(MoveTo::create((415 - 169) / Speed, node5->getPosition()));   //4-5
	Enemy::downmove();
	this->schedule(schedule_selector(Enemy::update4), 1.0f / 10);;
}
void Enemy::move5()                                                              
{
	Node * node6 = Node::create();
	node6->setPosition(845, 169);
	spriteaction->runAction(MoveTo::create((845 - 386) / Speed, node6->getPosition()));   //5-6
	Enemy::rightmove();
	this->schedule(schedule_selector(Enemy::update5), 1.0f / 10);;
}
void Enemy::move6()                                                                      
{
	Node * node7 = Node::create();
	node7->setPosition(845, 295);
	spriteaction->runAction(MoveTo::create((295 - 169) / Speed, node7->getPosition()));//6-7
	Enemy::upmove();
	this->schedule(schedule_selector(Enemy::update6), 1.0f / 10);
}
void Enemy::move7()                                                                    
{
	Node * node8 = Node::create();
	node8->setPosition(580, 295);
	spriteaction->runAction(MoveTo::create((845 - 580) / Speed, node8->getPosition()));    //7-8
	Enemy::leftmove();
	this->schedule(schedule_selector(Enemy::update7), 1.0f / 10);
}
void Enemy::move8()                                                                   
{
	Node * node9 = Node::create();
	node9->setPosition(580, 415);
	spriteaction->runAction(MoveTo::create((415 - 295) / Speed, node9->getPosition()));   //8-9
	Enemy::upmove();
	this->schedule(schedule_selector(Enemy::update8), 1.0f / 10);
}
void Enemy::move9()                                                                     
{
	Node * node10 = Node::create();
	node10->setPosition(845, 415);
	spriteaction->runAction(MoveTo::create((845 - 580) / Speed, node10->getPosition()));  //9-10
	Enemy::rightmove();
	this->schedule(schedule_selector(Enemy::update9), 1.0f / 10);
}
void Enemy::move10()                                                                    
{
	Node * node11 = Node::create();
	node11->setPosition(845, 604);
	spriteaction->runAction(MoveTo::create((604 - 415) / Speed, node11->getPosition()));  //10-11
	Enemy::upmove();
	this->schedule(schedule_selector(Enemy::update10), 1.0f / 10);
}
void Enemy::move11()                                                                   
{
	Node * node12 = Node::create();
	node12->setPosition(57, 604);
	spriteaction->runAction(MoveTo::create((845 - 57) / Speed, node12->getPosition()));    //11-12
	Enemy::leftmove();
	this->schedule(schedule_selector(Enemy::update11), 1.0f / 10);
}

