//
//  light.cpp
//  Corasonsitu
//
//  Created by Helena Bantulà i Fonts on 17/11/15.
//
//

#include "Light.h"


void Light::update(){
    if (isFadeIn==true) {
        fadeIn();
    }
    
    if (isFadeOut==true){
        fadeOut();
    }
}

void Light::initialize(){
    artnet.setup("192.168.1.113"); //IP de l'ordinador
    color[0]=0;
    color[1]=255;
    color[2]=0;
    artnet.sendDmx("192.168.1.156", color, 3);
}

void Light::triggerFadeIn(){ //trigger: ep, estic fent un fadein
    isFadeIn = true;
    time = ofGetElapsedTimeMillis();
    //cout<<time<<endl;
    
}


void Light::fadeIn(){
    
    //cout<<((ofGetElapsedTimeMillis()-time)*((float)255/(float)step))<<endl;
    
    //cout<<(ofGetElapsedTimeMillis()-time)<<endl;
    //cout<<((float)255/(float)step)<<endl;
    
    color[0]=(ofGetElapsedTimeMillis()-time)*((float)255/(float)step);
    //cout<<color[0]<<endl;
    color[1]=40;
    color[2]=0;
    
    artnet.sendDmx("192.168.1.156", color, 3);
    
    if ((ofGetElapsedTimeMillis()-time)>step) {         //sha esgotat el temps
        color[0]=255;
        artnet.sendDmx("192.168.1.156", color, 3);
        isFadeIn=false;
        triggerFadeOut();
    }

    
}

void Light::triggerFadeOut(){ //trigger: ep, estic fent un fadein
    isFadeOut = true;
    time = ofGetElapsedTimeMillis();
    //cout<<time<<endl;
    
}


void Light::fadeOut(){
    color[0]=255-(ofGetElapsedTimeMillis()-time)*((float)255/(float)step);
    color[1]=0;
    color[2]=0;
    artnet.sendDmx("192.168.1.156", color, 3);
    
    if ((ofGetElapsedTimeMillis()-time)>step) {         //sha esgotat el temps
        isFadeOut=false;
        color[0]=0;
        artnet.sendDmx("192.168.1.156", color, 3);
        
    }
}