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
#include "Par.h"

#endif /* defined(__Corasonsitu__light__) */

class Light{
    
public:
    
    void initialize();
    void getInfo();
    void sendInfo();
    void equalFade(float k, char fade, int type, int step);
    void randomPlay(Boolean state);
    
    ofxArtnet artnet;
    vector<Par> leds;
    unsigned char packDMX[15];
    unsigned char old_packDMX[15];
    
    uint8_t dmx[3];
    

    
    
    

    
    


};