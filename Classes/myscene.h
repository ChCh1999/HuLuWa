#pragma once
#include "cocos2d.h"
class myscene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();


	void menustartCallback(cocos2d::Ref* pSender);


	CREATE_FUNC(myscene);
};