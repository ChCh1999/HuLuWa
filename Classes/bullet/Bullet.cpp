#include "Bullet.h"
#include"Enemybat.h"

Bullet::Bullet() {
	Bullet::rScene = CCDirector::getInstance()->getRunningScene();//获取场景
	this->setTexture("Bullet1.png");
}
int Bullet::setDamage(double D) {//设置伤害
	this->damage = D;
	return damage;
}

int Bullet::Shoot(int tagoftower, int tagofenemy) {//在父对象获取到敌人后攻击 参数（防御塔tag,敌人tag）
		
	rScene->addChild(this, 2);
	auto Parent = rScene->getChildByTag(tagoftower);//防御塔
													//初始化
	this->setPosition(Parent->getPosition().x, Parent->getPosition().y+50);
	this->tagOfEnemy = tagofenemy;
	
	auto enemy = rScene->getChildByTag(tagofenemy);
	Vec2 posi = rScene->getChildByTag(tagOfEnemy)->getPosition();
	this->runAction(MoveTo::create(1.0f,rScene->getChildByTag(tagOfEnemy)->getPosition()));//rScene->getChildByTag(tagOfEnemy)->getPosition()
	this->schedule(schedule_selector(Bullet::Hit),1.0f);
	this->scheduleOnce(schedule_selector(Bullet::clear), 2.0f);


	return 0;
}

void Bullet::Hit(float dt) {//保护函数 抓取敌人 调整弹道 判断碰撞

	Scene* rScene = CCDirector::getInstance()->getRunningScene();
	auto  enemy = dynamic_cast<Enemybat *>(rScene->getChildByTag(tagOfEnemy));
	auto rectE = enemy->boundingBox();
	auto rectB = this->boundingBox();

	if (rectB.intersectsRect(rectE)) {
	
		rScene->removeChild(this);
		this->unschedule(schedule_selector(Bullet::Hit));
		enemy->HP = enemy->HP - damage;
	}
	else {
		this->runAction(MoveTo::create(1.0f, enemy->getPosition()));// enemy->getPosition()
	}
	//Bullet::IfKill();
}
void Bullet::clear(float dt) { //清除空余的子弹
	auto par = this->getParent();
	if (par != NULL)
		rScene->removeChild(this);
}

//bool Bullet::IfKill() {
//	Scene* rScene = CCDirector::getInstance()->getRunningScene();
//	auto enemy = rScene->getChildByTag(tagOfEnemy);
//	if (enemy == NULL) {
//		//rScene->removeChildByTag(tagOfEnemy);
//		//this->unscheduleAllSelectors();
//	}
//	return true;
//}