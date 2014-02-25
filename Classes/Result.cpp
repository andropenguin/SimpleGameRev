//
//  Result.cpp
//  SimpleGameRev
//
//  Created by osabe on 2014/02/25.
//
//

#include "Result.h"
#include "Score.h"
#include "GameEntry.h"

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
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
        
        int score = Score::getScore();
        int highScore = Score::getHighScore();
//        CCLog("score = %d", score);
//        CCLog("high score= %d", highScore);
        CCString* scoreValue = CCString::createWithFormat("Score: %d", score);
        CCString* highScoreValue = CCString::createWithFormat("High Score: %d", highScore);
        
//        CCLabelTTF* pScoreLabel = CCLabelTTF::create(scoreValue, "", 24.0);
        CCLabelTTF* pScoreLabel = CCLabelTTF::create(scoreValue->getCString(), "arial", 48.0);
        pScoreLabel->setColor(ccc3(255, 0, 127));
        int widthScoreLabel =pScoreLabel->getContentSize().width;
        CCLabelTTF* pHighScoreLabel = CCLabelTTF::create(highScoreValue->getCString(), "arial", 48.0);
        pHighScoreLabel->setColor(ccc3(255, 0, 127));
        int widthHighScoreLabel =pHighScoreLabel->getContentSize().width;
        int heightHighScoreLabel = pHighScoreLabel->getContentSize().height;
        pScoreLabel->setPosition(ccp(origin.x + visibleSize.width / 2 - widthScoreLabel / 2,
                                     origin.y + (int)(visibleSize.height * (1.0 - 0.4))));
        pHighScoreLabel->setPosition(ccp(origin.x + visibleSize.width / 2 - widthScoreLabel/ 2
                                         + abs(widthHighScoreLabel - widthScoreLabel) / 2,
                                         origin.y + (int)(visibleSize.height * (1.0 - 0.4))
                                         - heightHighScoreLabel - 20));
        
        this->addChild(pScoreLabel, 1);
        this->addChild(pHighScoreLabel, 1);
        
        
		// 1. Add a menu item with "X" image, which is clicked to quit the program.
        
		// Create a "close" menu item with close icon, it's an auto release object.
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                              "BackNormal.png",
                                                              "BackSelected.png",
                                                              this,
                                                              menu_selector(ResultLayer::menuBackCallback));
        
		// Place the menu item bottom-right conner.
//        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//        CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
        
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
    GameEntryScene* gameEntryScene = GameEntryScene::create();
    CCDirector::sharedDirector()->replaceScene(gameEntryScene);
}
