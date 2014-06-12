//
//  MainLayer.h
//  SushiCrush
//
//  Created by Sam on 14-6-12.
//
//

#ifndef __SushiCrush__MainLayer__
#define __SushiCrush__MainLayer__

#include <iostream>
#include "cocos2d.h"
#include "SushiSprite.h"
USING_NS_CC;

class MainLayer : Layer
{
public:
    
    static Scene * createScene();
    virtual bool init();
    CREATE_FUNC(MainLayer);
    
    void initMatrix();
    void createAndDropSushi(int x, int y);
    Point calculateSushiPoint(int x, int y);
};

#endif /* defined(__SushiCrush__MainLayer__) */
