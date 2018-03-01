#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    /*
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
     */
    
    auto bg = Sprite::create("Background800x480.png");
    
    // position the label on the center of the screen
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                         origin.y + visibleSize.height /2));
    this->addChild(bg);
    
    auto placeLabel = Label::createWithBMFont("fonts/fnt2.fnt", "Place");
    auto placeMenu = MenuItemLabel::create(placeLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    placeMenu->setTag(PLACE_TAG);
    
    auto flipXLabel = Label::createWithBMFont("fonts/fnt2.fnt", "FlipX");
    auto flipXMenu = MenuItemLabel::create(flipXLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    flipXMenu->setTag(FLIPX_TAG);
    
    auto flipYLabel = Label::createWithBMFont("fonts/fnt2.fnt", "FlipY");
    auto flipYMenu = MenuItemLabel::create(flipYLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    flipYMenu->setTag(FLIPY_TAG);
    
    auto hideLabel = Label::createWithBMFont("fonts/fnt2.fnt", "Hide or Show");
    auto hideMenu = MenuItemLabel::create(hideLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    hideMenu->setTag(HIDE_SHOW_TAG);
    
    auto toggleLabel = Label::createWithBMFont("fonts/fnt2.fnt", "Toggle");
    auto toggleMenu = MenuItemLabel::create(toggleLabel, CC_CALLBACK_1(HelloWorld::OnClickMenu, this));
    toggleMenu->setTag(TOGGLE_TAG);
    
    auto mn = Menu::create(placeMenu,flipXMenu,flipYMenu, hideMenu, toggleMenu, NULL);
    mn->alignItemsVertically();
    this->addChild(mn);
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::OnClickMenu(Ref* pSender)
{
    MenuItem *nmitem = (MenuItem*)pSender;
    
    auto  sc = Scene::create();
    auto  layer = MyAction::create();
    layer->setTag(nmitem->getTag());

    sc->addChild(layer);
    auto reScene = TransitionSlideInR::create(1.0f, sc);
    Director::getInstance()->replaceScene(reScene);
}
