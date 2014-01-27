#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include "cocos2d.h"
USING_NS_CC;

enum AllSprite
{
	background1,
	background2,
	plane,
	totalSprite
};
enum AllArray
{
	totalArray
};
class ObjectManager:
	public CCLayer
{
public:
	ObjectManager();
	~ObjectManager();

	static ObjectManager * sharedObjectManager();

	void addObject(AllSprite num,CCSprite * sprite);
	void addObject(AllArray num,CCArray * arr);

	CCSprite * Find(AllSprite num);
	CCArray * Find(AllArray num);
private:
	CCSprite ** m_Sprite;
	CCArray ** m_Array;
};

#endif