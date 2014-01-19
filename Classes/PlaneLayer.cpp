#include "PlaneLayer.h"

PlaneLayer* PlaneLayer::g_pPlaneLayer=NULL;
PlaneLayer::PlaneLayer()
{

}

PlaneLayer::~PlaneLayer()
{


}

PlaneLayer * PlaneLayer::create()
{
	if (NULL==g_pPlaneLayer)
	{
		g_pPlaneLayer=new PlaneLayer;
		if (g_pPlaneLayer&&g_pPlaneLayer->init())
		{
			g_pPlaneLayer->autorelease();
			return g_pPlaneLayer;
		}
	}
	return g_pPlaneLayer;
}

bool PlaneLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSize winSize=CCDirector::sharedDirector()->getWinSize();
		CCSprite* plane=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero1.png"));
		plane->setPosition(ccp(winSize.width/2,plane->getContentSize().height/2));
		this->addChild(plane,0,AIRPLANE);

		CCBlink *blink=CCBlink::create(1,3);

		CCAnimation *animation=CCAnimation::create();
		animation->setDelayPerUnit(0.1f);
		animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero1.png"));
		animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("hero2.png"));

		CCAnimate* animate=CCAnimate::create(animation);
		plane->runAction(blink);
		plane->runAction(CCRepeatForever::create(animate));

		bRet=true;

	} while (0);
	return bRet;
}