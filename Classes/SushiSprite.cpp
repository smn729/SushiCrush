//
//  SushiSprite.cpp
//  SushiCrush
//
//  Created by Sam on 14-6-12.
//
//

#include "SushiSprite.h"

#define TOTAL_SUSHI     6

static const char* sushiNormal[TOTAL_SUSHI] = {
    "sushi_1n.png",
	"sushi_2n.png",
	"sushi_3n.png",
	"sushi_4n.png",
	"sushi_5n.png",
    "sushi_6n.png"
};

static float SushiWidth = 0;

SushiSprite * SushiSprite::create(int x, int y)
{
    SushiSprite *sushi = new SushiSprite();
    
    sushi->setX(x);
    sushi->setY(y);
    sushi->init();
    
    sushi->autorelease();
    return sushi;
}

bool SushiSprite::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    
    int imageIndex = floor(CCRANDOM_0_1() * TOTAL_SUSHI);
    this->setImageIndex(imageIndex);
    this->initWithSpriteFrameName(sushiNormal[imageIndex]);
    
    return true;
}

float SushiSprite::getSushiWidth()
{
    if (SushiWidth == 0)
    {
        Sprite *sprite = Sprite::createWithSpriteFrameName(sushiNormal[0]);
        
        SushiWidth = sprite->getContentSize().width;
    }
    
    return SushiWidth;
}
