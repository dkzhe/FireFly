#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::CCLayer
{
public:
	HelloWorld();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
//    static cocos2d::CCScene* scene();
    
    // a selector callback
//    void menuCloseCallback(CCObject* pSender);
    
	void backgroundMove(float dt);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
private:
	CCSprite* background1;
	CCSprite* background2;
	CCSprite* background3;
};

#endif // __HELLOWORLD_SCENE_H__
