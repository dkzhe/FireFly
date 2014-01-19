#include "GameScene.h"


GameScene::GameScene(void)
{
	m_hellowordLay=NULL;
}


GameScene::~GameScene(void)
{
}

bool GameScene::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());
		

		m_hellowordLay=HelloWorld::create();
		CC_BREAK_IF(!m_hellowordLay);
		this->addChild(m_hellowordLay);

		m_PlaneLayer=PlaneLayer::create();
		CC_BREAK_IF(!m_PlaneLayer);
		this->addChild(m_PlaneLayer);
		bRet=true;

	} while (0);
	return bRet;
}