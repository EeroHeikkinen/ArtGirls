#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("concept.png");

    auto spriteSize = sprite->getContentSize();
    sprite->setScale(visibleSize.width / spriteSize.width);
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height / 2));

    // add the sprite as a child to this layer
    this->addChild(sprite, 1);
    
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Effect.wav");
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::openBattleUI, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

bool HelloWorld::openBattleUI(cocos2d::Touch * touch, cocos2d::Event * event) {
    auto *battleUI = BattleUI::create();
    if (! battleUI)
        return false;
    
    this->addChild(battleUI, 100);
    
    return true;
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    //Director::getInstance()->end();
    
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Effect.wav");
    

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //exit(0);
#endif
}


bool BattleUI::init()
{
    if( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto closeItem = MenuItemImage::create("BattleUI.png", "BattleUISelected.png",
                                           CC_CALLBACK_1(BattleUI::OnMenu, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width / 3,
                                origin.y + visibleSize.height / 2));
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 100);
    
    return true;
}


void BattleUI::OnMenu(cocos2d::Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Effect.wav");
    this->removeFromParentAndCleanup(true);
}


