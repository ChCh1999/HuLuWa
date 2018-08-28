#include"cocos2d.h"
#include"Enemybat.h"
#include"Enemytree.h"
#include<math.h>
#include"Enemyspider.h"
class GameScene: public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	int health = 20;
	int money = 200;
	int numbat = 15;
	int numtree = 20;
	int numspider = 15;
	int tagbat = 1;
	int tagtree = 21;
	int tagspider = 41;
	int a[100];
	int i = 1;
	int b = 0;
	int bo =2;
	void menustartCallback(Ref * pSender);
	void updatenumbat(float dt);
	void updatenumtree(float dt);
	void updatenumspider(float dt);
	void updateEnemy(float dt);
	CREATE_FUNC(GameScene);

};