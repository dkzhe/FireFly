
#include "ContralLayer.h"
#include "PlaneLayer.h"
#include "ObjectManager.h"
ContralLayer::ContralLayer()
{

}

ContralLayer::~ContralLayer()
{

}

bool ContralLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		this->setTouchEnabled(true);
		
		bRet=true;
	} while (0);
	return bRet;
}

void ContralLayer::registerWithTouchDispatcher()
{
	 CCDirector *pDirector=CCDirector::sharedDirector();
	 pDirector->getTouchDispatcher()->addTargetedDelegate(this,0,true);
}

bool ContralLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void ContralLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	if (PlaneLayer::create()->isActive)
	{
		CCPoint beginPoint=pTouch->getLocation();
//		beginPoint=CCDirector::sharedDirector()->convertToGL(beginPoint);
		CCRect planeRect=ObjectManager::sharedObjectManager()->Find(AllSprite::plane)->boundingBox();
		planeRect.origin.x-=15;
		planeRect.origin.y-=15;  
		planeRect.size.width+=30;  
		planeRect.size.height+=30;

		if (planeRect.containsPoint(this->getParent()->convertTouchToNodeSpace(pTouch)))
		{
			CCPoint previousPoint=pTouch->getPreviousLocation();
//			previousPoint=CCDirector::sharedDirector()->convertToGL(previousPoint);

			CCPoint offset=ccpSub(beginPoint,previousPoint);
			CCPoint toPoint=ccpAdd(ObjectManager::sharedObjectManager()->Find(AllSprite::plane)->getPosition(),offset);
			PlaneLayer::create()->MoveTo(toPoint);
		}
	}
}