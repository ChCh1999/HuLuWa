
#ifndef __SETTING_SCENE_H__
#define __SETTING_SCENE_H__

#include "cocos2d.h"

class Setting : public cocos2d::Scene
{
public:
	//
	static cocos2d::Scene * createScene();

	virtual bool init();

	//菜单回调函数
	void menuItemMusicCallback(cocos2d::Ref * pSender);
	void menuItemBgmCallback(cocos2d::Ref * pSender);
	void menuItemOKCallback(cocos2d::Ref * pSender);

	CREATE_FUNC(Setting);
};

#endif //__SETTING_SCENE_H__