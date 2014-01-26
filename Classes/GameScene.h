#pragma once
#include "cocos2d.h"  
#include "HelloWorldScene.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"
USING_NS_CC;
class GameScene :
	public CCScene
{
public:
	GameScene(void);
	~GameScene(void);

	CREATE_FUNC(GameScene);
	virtual bool init();

	HelloWorld *m_hellowordLay;
	PlaneLayer *m_PlaneLayer;
	BulletLayer *m_BulletLayer;
};

