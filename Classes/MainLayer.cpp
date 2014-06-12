//
//  MainLayer.cpp
//  SushiCrush
//
//  Created by Sam on 14-6-12.
//
//

#include "MainLayer.h"
#include "SushiSprite.h"

#define MATRIX_WIDTH (6)
#define MATRIX_HEIGHT (8)

#define SUSHI_GAP (1)

Scene * MainLayer::createScene()
{
    Scene *scene = Scene::create();
    MainLayer *layer = MainLayer::create();
    scene->addChild(layer);
    
    return scene;
}

bool MainLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sushi.plist");
    
    Sprite *background = Sprite::create("background.png");
    background->setPosition(Point(winSize.width / 2.0, winSize.height / 2.0));
    addChild(background);
    
    initMatrix();
    
    return true;
}

void MainLayer::initMatrix()
{
    for(int x = 0; x < MATRIX_WIDTH; x ++)
    {
        for (int y = 0; y < MATRIX_HEIGHT; y++)
        {
            createAndDropSushi(x, y);
        }
    }
}

void MainLayer::createAndDropSushi(int x, int y)
{
    Size winSize = Director::getInstance()->getWinSize();
    SushiSprite *sushi = SushiSprite::create(x, y);
    
    Point sushiPosition = calculateSushiPoint(x, y);
    Point sushiInitPostion = Point(sushiPosition.x, sushiPosition.y + winSize.height);
    
    sushi->setPosition(sushiInitPostion);
    this->addChild(sushi);
    
    auto dropAction = MoveTo::create(0.25, sushiPosition);
    sushi->runAction(dropAction);
    
}

Point MainLayer::calculateSushiPoint(int x, int y)
{
    Size winSize = Director::getInstance()->getWinSize();
    float sushiWidth = SushiSprite::getSushiWidth();
    
    float matrixOriginX = (winSize.width - MATRIX_WIDTH * sushiWidth - (MATRIX_WIDTH - 1) * SUSHI_GAP) / 2.0;
    float matrixOriginY = (winSize.height - MATRIX_HEIGHT * sushiWidth - (MATRIX_HEIGHT - 1) * SUSHI_GAP) / 2.0;
    
    float sushiX = matrixOriginX + x * (sushiWidth + SUSHI_GAP) + sushiWidth / 2.0;
    float sushiY = matrixOriginY + y * (sushiWidth + SUSHI_GAP) + sushiWidth / 2.0;
    
    return Point(sushiX, sushiY);
}


