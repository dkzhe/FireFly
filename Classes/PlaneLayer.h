#ifndef __PLANELAYER_H__
#define __PLANELAYER_H__
#include "BulletLayer.h"
#include "cocos2d.h"
USING_NS_CC;

const int AIRPLANE=747;
class PlaneLayer
	:public CCLayer
{
public:
	
	~PlaneLayer();

	virtual bool init();
	static PlaneLayer* create();
	static PlaneLayer* g_pPlaneLayer;
private:
	PlaneLayer();
	BulletLayer *m_BulletLayer;
};

#endif