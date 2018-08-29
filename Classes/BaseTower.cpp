#include "BaseTower.h"

bool BaseTower::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	isUpdateMenuShown = false;
	return true;
}

void BaseTower::RemoveTower()
{
	this->unscheduleAllCallbacks();
	this->removeAllChildren();
	this->removeFromParent();
}

void BaseTower::UpdateTower()
{

}