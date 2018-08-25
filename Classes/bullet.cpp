#include "bullet.h"

int Bullet::setDamage(int D) {
	this->damage = D;
	return damage;
}
int Bullet::Shoot(int tagoftower, int tagofenemy) {//在父对象获取到敌人后攻击
	 //获取值
	
	Scene* rScene = CCDirector::getInstance()->getRunningScene();//获取场景
	auto Parent = rScene->getChildByTag(tagoftower);//父对象 防御塔
	//初始化
	ParticleSystem * particleSystem = ParticleFire::create();
	particleSystem->setPosition(Parent->getPosition());
	this->tagOfEnemy = tagofenemy;
	
	auto enemy = rScene->getChildByTag(tagofenemy);
	this->runAction(MoveTo::create(0.3f,rScene->getChildByTag(tagOfEnemy)->getPosition() ));
	this->schedule(schedule_selector(Bullet::Hit));

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
	if (hite >= 5) {
		rScene->removeChildByTag(tagOfEnemy);
		this->unscheduleAllSelectors();
	}
}