#include "BulletLayer.h"
#include "PlaneLayer.h"

BulletLayer::BulletLayer()
{
	m_pAllBullet=CCArray::create();
	m_pAllBullet->retain();
	bulletBatchNode=NULL;
}
BulletLayer::~BulletLayer()
{
	m_pAllBullet->release();
	m_pAllBullet=NULL;
}
bool BulletLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey("ui/shoot.png");
		bulletBatchNode=CCSpriteBatchNode::createWithTexture(texture);
		this->addChild(bulletBatchNode);
//		this->schedule(schedule_selector(BulletLayer::AddBullet),0.01f);
		bRet=true;
	} while (0);
	return bRet;
}

void BulletLayer::AddBullet(float dt)
{
	CCSprite* bullet=CCSprite::createWithSpriteFrameName("bullet1.png");
	bulletBatchNode->addChild(bullet);
	this->m_pAllBullet->addObject(bullet);

	CCPoint planePosition=PlaneLayer::create()->getChildByTag(AIRPLANE)->getPosition();
	CCPoint bulletPosition=ccp(planePosition.x,planePosition.y+PlaneLayer::create()->getChildByTag(AIRPLANE)->getContentSize().height/2);
	bullet->setPosition(bulletPosition);

	float length=CCDirector::sharedDirector()->getWinSize().height+bullet->getContentSize().height/2-bulletPosition.y;
	float velocity=420/1;
	float realMoveDuration=length/velocity;
	CCFiniteTimeAction* actionMove=CCMoveTo::create(realMoveDuration,
		ccp(bulletPosition.x,CCDirector::sharedDirector()->getWinSize().height+bullet->getContentSize().height/2));
	CCFiniteTimeAction* actionDone=CCCallFuncN::create(this,callfuncN_selector(BulletLayer::bulletMoveFinished));//回调一个子弹结束处理函数

	CCSequence* sequence=CCSequence::create(actionMove,actionDone);
	bullet->runAction(sequence); 

}

void BulletLayer::bulletMoveFinished(CCNode* pSender)
{
	CCSprite* bullet=(CCSprite*)pSender;
	m_pAllBullet->removeObject(bullet);
	this->bulletBatchNode->removeChild(bullet,true);
}

void BulletLayer::StartShoot(float delay)
{
	this->schedule(schedule_selector(BulletLayer::AddBullet),0.01f,kCCRepeatForever,delay);
}

void BulletLayer::StopShoot()
{
	this->unschedule(schedule_selector(BulletLayer::AddBullet));
}

