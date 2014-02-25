//
//  GamePlay.h
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#ifndef __SimpleGameRev__GamePlay__
#define __SimpleGameRev__GamePlay__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class GamePlayLayer : public cocos2d::CCLayerColor
{
public:
	GamePlayLayer();
	~GamePlayLayer();
    
	// Here's a difference. Method 'init' in cocos2d-x returns bool,
    // instead of returning 'id' in cocos2d-iphone
	virtual bool init();
    
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
    
	// a selector callback
	virtual void menuCloseCallback(cocos2d::CCObject* pSender);
    
	// implement the "static node()" method manually
	CREATE_FUNC(GamePlayLayer);
    
	void spriteMoveFinished(cocos2d::CCNode* sender);
    
	void gameLogic(float dt);
    
	void updateGame(float dt);
    
	void registerWithTouchDispatcher();
	void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    
protected:
	cocos2d::CCArray *_targets;
	cocos2d::CCArray *_projectiles;
	int _projectilesDestroyed;
    int _score;
    int _highScore;
    
	void addTarget();
    
    
};

class GamePlayScene : public cocos2d::CCScene {
public:
	GamePlayScene():_layer(NULL) {};
	virtual ~GamePlayScene();
	bool init();
	CREATE_FUNC(GamePlayScene);
    
	CC_SYNTHESIZE_READONLY(GamePlayLayer*, _layer, Layer);
};

#endif /* defined(__SimpleGameRev__GamePlay__) */
