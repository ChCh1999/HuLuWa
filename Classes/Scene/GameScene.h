#include"cocos2d.h"
#include"Bullet\Bullet.h"
class GameScene: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	int health = 20;
	int money = 200;
	void menustartCallback(Ref * pSender);
	CREATE_FUNC(GameScene);

};