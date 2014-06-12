//
//  SushiSprite.h
//  SushiCrush
//
//  Created by Sam on 14-6-12.
//
//

#ifndef __SushiCrush__SushiSprite__
#define __SushiCrush__SushiSprite__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class SushiSprite: public Sprite
{
public:
    
    static SushiSprite * create(int x, int y);
    static float getSushiWidth();
    
    virtual bool init();
    CC_SYNTHESIZE(int, _x, X);
    CC_SYNTHESIZE(int, _y, Y);
    CC_SYNTHESIZE(int, _imageIndex, ImageIndex);
    
};

#endif /* defined(__SushiCrush__SushiSprite__) */
