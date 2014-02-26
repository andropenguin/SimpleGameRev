//
//  GameEntry.cpp
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#include "GameEntry.h"
#include "GamePlay.h"

USING_NS_CC;

bool GameEntryScene::init() {
    if ( CCScene::init() ) {
        this->_layer = GameEntryLayer::create();
        this->_layer->retain();
        this->addChild(_layer);
        
        return true;
    } else {
        return false;
    }
}

GameEntryScene::~GameEntryScene() {
    if (_layer) {
        _layer->release();
        _layer = NULL;
    }
}

GameEntryLayer::~GameEntryLayer() {
}

CCScene* GameEntryLayer::scene() {
    CCScene *scene = CCScene::create();
    GameEntryLayer *layer = GameEntryLayer::create();
    scene->addChild(layer);
    return scene;
}

bool GameEntryLayer::init() {
    if ( !CCLayerColor::initWithColor( ccc4(255, 255, 255, 255) ) ) {
		return false;
	}
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    // make the menu itemof start game.
    CCMenuItemImage *pStartGameItem = CCMenuItemImage::create(
                                                              "StartNormal.png",
                                                              "StartSelected.png",
                                                              this,
                                                              menu_selector(GameEntryLayer::menuStartGameCallback));
    
    pStartGameItem->setPosition(ccp(origin.x + visibleSize.width / 2 - pStartGameItem->getContentSize().width/2 ,
                                    origin.y + visibleSize.height / 2 + pStartGameItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pStartGameItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    
    return true;
}

void GameEntryLayer::menuStartGameCallback(CCObject* pSender)
{
    // replace the scenss.
    GamePlayScene* gamePlaydScene = GamePlayScene::create();
    CCDirector::sharedDirector()->replaceScene(gamePlaydScene);

}