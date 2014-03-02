#include "AppDelegate.h"
#include "GameEntry.h"

USING_NS_CC;

static CCSize designResolutionSize = CCSizeMake(720, 1080);

typedef struct tagResource {
    CCSize size;
    char directory[100];
} Resource;
static Resource smallResource_yoko = { CCSizeMake(1080, 720), "iphone" };
static Resource smallResource_tate2 = { CCSizeMake(720, 1080), "iphone" };


AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();

//    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    pDirector->setOpenGLView(pEGLView);
    CCSize frameSize = pEGLView->getFrameSize();
    CCLOG("applicationDidFinishLaunching frameSize.width = %f  frameSize.height= %f", frameSize.width,frameSize.height);
    if (frameSize.height / frameSize.width > 1.4) {
        pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionFixedWidth);
    } else {
        pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionFixedHeight);
    }
    
    if (designResolutionSize.width == 720) {
        pDirector->setContentScaleFactor(smallResource_tate2.size.width /
                                         designResolutionSize.width);  // 縦
    } else {
        pDirector->setContentScaleFactor(smallResource_yoko.size.width /
                                         designResolutionSize.width);  // 横
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleSize();
    
    CCLOG("applicationDidFinishLaunching designResolutionSize.width = %f ", designResolutionSize.width);
    CCLOG("applicationDidFinishLaunching designResolutionSize.height = %f ", designResolutionSize.height);
    CCLOG("applicationDidFinishLaunching pDirector->getContentScaleFactor() = %f ", pDirector->getContentScaleFactor() );
    CCLOG("applicationDidFinishLaunching visibleSize  width=%f height=%f ", visibleSize.width, visibleSize.height );
    CCLOG("applicationDidFinishLaunching origin  x=%f y=%f ", origin.x, origin.y );

    

//    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
//    CCSize designSize = CCSizeMake(480, 320);
    std::vector<std::string> searchPaths;

//    if (screenSize.height > 320)
//    {
//        searchPaths.push_back("hd");
//        searchPaths.push_back("sd");
//        pDirector->setContentScaleFactor(640.0f/designSize.height);
//    }
//    else
//    {
//        searchPaths.push_back("sd");
//        pDirector->setContentScaleFactor(320.0f/designSize.height);
//    }
    if (visibleSize.height > 320)
    {
        searchPaths.push_back("hd");
        searchPaths.push_back("sd");
//        pDirector->setContentScaleFactor(640.0f/designSize.height);
    }
    else
    {
        searchPaths.push_back("sd");
//        pDirector->setContentScaleFactor(320.0f/designSize.height);
    }

    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);

//    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionNoBorder);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = GameEntryLayer::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
