#include "bullet.h"

Bullet::Bullet() {
	Bullet::rScene = CCDirector::getInstance()->getRunningScene();//获取场景
	this->setTexture("bullet.png");
}
int Bullet::setDamage(int D) {
	this->damage = D;
	return damage;
}
int Bullet::Shoot(int tagoftower, int tagofenemy) {//在父对象获取到敌人后攻击
	 //获取值
	auto Parent = rScene->getChildByTag(tagoftower);//防御塔
	//初始化
	this->setPosition(Parent->getPosition());
	this->tagOfEnemy = tagofenemy;
	
	auto enemy = rScene->getChildByTag(tagofenemy);
	this->runAction(MoveTo::create(1.0f,rScene->getChildByTag(tagOfEnemy)->getPosition() ));
	this->schedule(schedule_selector(Bullet::Hit));
	this->scheduleOnce(schedule_selector(Bullet::clear),2.0f);
	return 0;
}
bool Bullet::IfKill() {

	return true;
}
int hite = 0;
void Bullet::Hit(float dt) {
	
	Scene* rScene = CCDirector::getInstance()->getRunningScene();
	auto enemy = rScene->getChildByTag(tagOfEnemy);
	auto rectE = enemy->boundingBox();
	auto rectB = this->boundingBox();
	if (rectB.intersectsRect(rectE)) {
		hite++;
		rScene->removeChild(this);
		this->unschedule(schedule_selector(Bullet::Hit));
	}
	else {
		this->runAction(MoveTo::create(10.0f,enemy->getPosition()));
	}
	if (hite >= 5) {
		rScene->removeChildByTag(tagOfEnemy);
		this->unscheduleAllSelectors();
	}
}
void Bullet::clear(float dt) {
	auto par = this->getParent();
	if (par != NULL)
		rScene->removeChild(this);
}