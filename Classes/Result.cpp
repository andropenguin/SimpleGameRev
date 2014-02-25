//
//  Result.cpp
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#include "Result.h"

USING_NS_CC;

bool ResultScene::init() {
	if ( CCScene::init() ) {
		this->_layer = ResultLayer::create();
		this->_layer->retain();
		this->addChild(_layer);
        
		return true;
	} else {
		return false;
	}
}

ResultScene::~ResultScene() {
	if (_layer) {
		_layer->release();
		_layer = NULL;
	}
}

ResultLayer::~ResultLayer() {
}

CCScene* ResultLayer::scene() {
	CCScene *scene = CCScene::create();
    
	ResultLayer *layer = ResultLayer::create();
    
	scene->addChild(layer);
    
	return scene;
}

bool ResultLayer::init() {
	if ( CCLayerColor::initWithColor( ccc4(255, 255, 255, 255) ) ) {
        
        
        
		// 1. Add a menu item with "X" image, which is clicked to quit the program.
        
		// Create a "close" menu item with close icon, it's an auto release object.
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                              "BackNormal.png",
                                                              "BackSelected.png",
                                                              this,
                                                              menu_selector(ResultLayer::menuBackCallback));
        
		// Place the menu item bottom-right conner.
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
        
		pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2,
                                    origin.y + pCloseItem->getContentSize().height/2));
        
		// Create a menu with the "close" menu item, it's an auto release object.
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
        
		// Add the menu to SecondWorld layer as a child layer.
		this->addChild(pMenu, 1);
        
        return true;
    } else {
        return false;
    }
}

void ResultLayer::menuBackCallback(CCObject* pSender)
{
	// "back" menu item clicked
//	CCDirector::sharedDirector()->end();
}
