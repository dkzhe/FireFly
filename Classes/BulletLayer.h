#ifndef __BULLETLAYER_H__
#define __BULLETLAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class BulletLayer:
	public CCLayer
{
public:
	BulletLayer();
	~BulletLayer();
	CREATE_FUNC(BulletLayer);
	virtual bool init();
	void AddBullet(float dt);
	void bulletMoveFinished(CCNode* pSender);
	void StartShoot(float delay=0.0f);
	void StopShoot();

	CCSpriteBatchNode* bulletBatchNode;
	CCArray *m_pAllBullet;
};


#endif