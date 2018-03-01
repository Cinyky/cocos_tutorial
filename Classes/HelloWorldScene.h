#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "MyActionScene.h"

typedef enum
{
    PLACE_TAG = 102
    ,FLIPX_TAG
    ,FLIPY_TAG
    ,HIDE_SHOW_TAG
    ,TOGGLE_TAG
} ActionTypes;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // callback
    void OnClickMenu(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
