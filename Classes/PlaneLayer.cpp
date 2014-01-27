#include "PlaneLayer.h"
#include "ObjectManager.h"

PlaneLayer* PlaneLayer::g_pPlaneLayer=NULL;
PlaneLayer::PlaneLayer()
{
	isActive=true;
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
		ObjectManager::sharedObjectManager()->addObject(AllSprite::plane,plane);
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

void PlaneLayer::MoveTo(CCPoint point)
{
	if (isActive&&!CCDirector::sharedDirector()->isPaused())
	{
		CCPoint actualPoint;  
		CCSize winSize=CCDirector::sharedDirector()->getWinSize();

		CCSize planeSize=ObjectManager::sharedObjectManager()->Find(AllSprite::plane)->getContentSize();
		if (point.x<planeSize.width/2)  
		{  
			point.x=planeSize.width/2;  
		}  
		if (point.x>winSize.width-planeSize.width/2)  
		{  
			point.x=winSize.width-planeSize.width/2;  
		}  
		if (point.y<planeSize.height/2)  
		{  
			point.y=planeSize.height/2;  
		}  
		if (point.y>winSize.height-planeSize.height/2)  
		{  
			point.y=winSize.height-planeSize.height/2;  
		}
		ObjectManager::sharedObjectManager()->Find(AllSprite::plane)->setPosition(point);
	}
}