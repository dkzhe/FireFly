#include "HelloWorldScene.h"
#include "ObjectManager.h"

HelloWorld::HelloWorld()
{

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
		CCSprite *background1=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
		background1->setAnchorPoint(ccp(0,0));
		background1->setPosition(ccp(0,0));
		ObjectManager::sharedObjectManager()->addObject(AllSprite::background1,background1);
		this->addChild(background1);

		CCSprite *background2=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("background.png"));
		background2->setAnchorPoint(ccp(0,0));
		background2->setPosition(ccp(0,background2->getContentSize().height-2));
		ObjectManager::sharedObjectManager()->addObject(AllSprite::background2,background2);
		this->addChild(background2);

		this->schedule(schedule_selector(HelloWorld::backgroundMove),0.01f);

		bRet=true;
	} while (0);
	
    
    return bRet;
}

void HelloWorld::backgroundMove(float dt)
{

	ObjectManager::sharedObjectManager()->Find(AllSprite::background1)->setPositionY(
		ObjectManager::sharedObjectManager()->Find(AllSprite::background1)->getPositionY()-2);
	ObjectManager::sharedObjectManager()->Find(AllSprite::background2)->setPositionY(
		ObjectManager::sharedObjectManager()->Find(AllSprite::background1)->getPositionY()+
		ObjectManager::sharedObjectManager()->Find(AllSprite::background1)->getContentSize().height-2);
	if(ObjectManager::sharedObjectManager()->Find(AllSprite::background2)->getPositionY()==0)
	{
		ObjectManager::sharedObjectManager()->Find(AllSprite::background1)->setPositionY(0);
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