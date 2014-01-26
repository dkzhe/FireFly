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
<<<<<<< HEAD
//	BulletLayer *m_BulletLayer;
=======
	BulletLayer *m_BulletLayer;
>>>>>>> 0fd1d4af53462490df9af9a21c0ed1bb00c3a786
};

