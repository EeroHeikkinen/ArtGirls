#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* BattleUI::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BattleUI::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool BattleUI::init()
{
    //////////////////////////////
    // 1. super init first
    if( !LayerColor::initWithColor(Color4B(0,0,0,0)) )
    {
        return false;
    }
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("BattleUI.png", "BattleUI.png",
                                           CC_CALLBACK_1(BattleUI::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width / 3,
                                origin.y + visibleSize.height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Effect.wav");
    
    return true;
}


void BattleUI::menuCloseCallback(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Effect.wav");
    
    Director::getInstance()->popScene();
}
