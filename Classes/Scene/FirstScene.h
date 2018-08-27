#include"cocos2d.h"
#include"Bullet\Bullet.h"
class FirstScene: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void searchEnemy(float dt);
	CREATE_FUNC(FirstScene);

};