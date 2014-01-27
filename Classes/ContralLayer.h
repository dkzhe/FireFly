#ifndef __CONTRALLAYER_H__
#define __CONTRALLAYER_H__

#include "cocos2d.h"
USING_NS_CC;
class ContralLayer:
	public CCLayer
{
public:
	ContralLayer();
	~ContralLayer();

	CREATE_FUNC(ContralLayer);
	virtual bool init();

	virtual void registerWithTouchDispatcher();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);

	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
};

#endif
