//
//  Result.h
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#ifndef __SimpleGameRev__Result__
#define __SimpleGameRev__Result__

#include "cocos2d.h"

class ResultLayer : public cocos2d::CCLayerColor {
public:
	ResultLayer() {};
	virtual ~ResultLayer();
	bool init();
	CREATE_FUNC(ResultLayer);
	static cocos2d::CCScene* scene();
	virtual void menuBackCallback(cocos2d::CCObject* pSender);
};

class ResultScene : public cocos2d::CCScene {
public:
	ResultScene():_layer(NULL) {};
	~ResultScene();
	bool init();
	CREATE_FUNC(ResultScene);
    
	CC_SYNTHESIZE_READONLY(ResultLayer*, _layer, Layer);
};

#endif /* defined(__SimpleGameRev__Result__) */
