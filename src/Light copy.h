//
//  Light.h
//  Corasonsitu
//
//  Created by Helena Bantulà i Fonts on 17/11/15.
//
//

#ifndef __Corasonsitu__light__
#define __Corasonsitu__light__

#include <iostream>
#include "ofxArtnet.h"

#endif /* defined(__Corasonsitu__light__) */

class Light{
    
public:
    //light(){};
    //~light(){};
    
    void fadeIn();
    void triggerFadeIn();
    void triggerFadeOut();
    void fadeOut();
    void initialize();
    void update();
    
    ofxArtnet artnet;
    unsigned char color[3];
    Boolean isFadeIn = false;
    Boolean isFadeOut = false;
    
    int time;

    int i;
    int step = 500; //in milliseconds
};