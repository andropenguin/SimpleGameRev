//
//  GameEntry.h
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#ifndef __SimpleGameRev__GameEntry__
#define __SimpleGameRev__GameEntry__

#include "cocos2d.h"

class GameEntryLayer : public cocos2d::CCLayerColor {
public:
    GameEntryLayer() {};
    virtual ~GameEntryLayer();
    bool init();
    CREATE_FUNC(GameEntryLayer);
    static cocos2d::CCScene* scene();
    void menuStartGameCallback(CCObject* pSender);
};

class GameEntryScene : public cocos2d::CCScene {
public:
    GameEntryScene():_layer(NULL) {};
    ~GameEntryScene();
    bool init();
    CREATE_FUNC(GameEntryScene);
    CC_SYNTHESIZE_READONLY(GameEntryLayer* , _layer, Layer);
};

#endif /* defined(__SimpleGameRev__GameEntry__) */
