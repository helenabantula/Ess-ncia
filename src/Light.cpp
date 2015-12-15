//
//  light.cpp
//  Corasonsitu
//
//  Created by Helena Bantulà i Fonts on 17/11/15.
//
//

#include "Light.h"


void Light::initialize(){
    artnet.setup("192.168.1.113"); //IP de l'ordinador
    
    //// Temporary Par ///
    unsigned char  color[3];
    
    color[0]=0;
    color[1]=0;
    color[2]=255;
    Par temPar(color,0);
    leds.push_back(temPar);
    
    
    
    color[0]=255;
    color[1]=0;
    color[2]=0;
    Par temPar1(color,1);
    leds.push_back(temPar1);
    
    
    color[0]=0;
    color[1]=0;
    color[2]=255;
    Par temPar2(color,2);
    leds.push_back(temPar2);
    
    color[0]=150;
    color[1]=0;
    color[2]=255;
    Par temPar3(color,3);
    leds.push_back(temPar3);
}


void Light::getInfo(){
    
    int j=0;
    for (int i=0; i<leds.size(); i++){
        leds[i].update();
        
        packDMX[j]=leds[i].color[0];
        packDMX[j+1]=leds[i].color[1];
        packDMX[j+2]=leds[i].color[2];
        j=j+3;
    }
    
    sendInfo();
}


void Light::sendInfo(){
//    int n;
//    n=memcmp(packDMX, old_packDMX, sizeof(packDMX));
//    
//    if (n==1) {
//        artnet.sendDmx("192.168.1.156",packDMX, sizeof(packDMX));
//       old_packDMX=packDMX;
//    }
    artnet.sendDmx("192.168.1.150",packDMX, sizeof(packDMX));
}


void Light::equalFade(float k, char fade, int type, int step){
    
    for (int i=0; i<leds.size(); i++){
        leds[i].topFade=k;
        
        if (fade=='I'){
            leds[i].triggerFadeIn(type, step);
        }
        else if (fade == 'O') {
            leds[i].triggerFadeOut(step);
        }
    }
}


void Light::randomPlay(bool state){
    
//    int numPar = ofRandom(0, leds.size());
//    float topFade = ofRandom(0.3, 1);
//    
//    int step = ofRandom(2000,5000);
//    
//    if (!leds[numPar].isFadeIn && !leds[numPar].isFadeOut) {
//        
//        leds[numPar].topFade=topFade;
//        leds[numPar].triggerFadeIn(1, step);
//    }
    
    for (int i=0; i<leds.size(); i++){
        leds[i].isRandom=state;
    }

    


}



