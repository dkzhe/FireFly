#include "HelloWorldScene.h"


HelloWorld::HelloWorld()
{
	background1=NULL;
	background2=NULL;
	background3=NULL;
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		background1=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
		background1->setAnchorPoint(ccp(0,0));
		background1->setPosition(ccp(0,0));
		this->addChild(background1);

		background2=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
		background2->setAnchorPoint(ccp(0,0));
		background2->setPosition(ccp(0,background2->getContentSize().height-2));

		this->addChild(background2);

		this->schedule(schedule_selector(HelloWorld::backgroundMove),0.01f);

		bRet=true;
	} while (0);
	
    
    return bRet;
}

void HelloWorld::backgroundMove(float dt)
{

	background1->setPositionY(background1->getPositionY()-2);
	background2->setPositionY(background1->getPositionY()+background1->getContentSize().height-2);
	if(background2->getPositionY()==0)
	{
		background1->setPositionY(0);
	}
}
/*
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
*/