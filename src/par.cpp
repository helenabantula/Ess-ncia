//
//  par.cpp
//  Corasonsitu
//
//  Created by Helena Bantulà i Fonts on 27/11/15.
//
//

#include "Par.h"

Par::Par(unsigned char* const& colorC, int const& idC){
    color[0]=colorC[0];
    color[1]=colorC[1];
    color[2]=colorC[2];
    
    colorI[0]=colorC[0];
    colorI[1]=colorC[1];
    colorI[2]=colorC[2];
    
    id=idC;
}


void Par::update(){
    if (isFadeIn==true) {
        fadeIn();
    }
    
    if (isFadeOut==true){
        fadeOut();
    }
    
    if (isRandom){
        randomMove();
    }
    
}

//void Par::initialize(int temps){
//    
//    color[0]=(ofGetElapsedTimeMillis()-temps)*((float)colorI[0]*topFade/(float)2000);
//    color[1]=(ofGetElapsedTimeMillis()-temps)*((float)colorI[1]*topFade/(float)2000);;
//    color[2]=(ofGetElapsedTimeMillis()-temps)*((float)colorI[2]*topFade/(float)2000);;
//    
//    if ((ofGetElapsedTimeMillis()-temps)>2000) {         //sha esgotat el temps
//        color[0]=colorI[0]*topFade;
//        color[1]=colorI[1]*topFade;
//        color[2]=colorI[2]*topFade;
//    }
//    
//
//}

void Par::triggerFadeIn(int tipus, int step){ //trigger: ep, estic fent un fadein
    type=tipus;         //1: fadeIn+fadeOut,   2: fadeIn
    isFadeIn = true;
    stepFI=step;
    time = ofGetElapsedTimeMillis();
}


void Par::fadeIn(){
    
//    switch (type) {
//        case 1:
//            stepFI=500;
//            break;
//        case 2:
//            stepFI=2500;
//            break;
//    }
    
    color[0]=(ofGetElapsedTimeMillis()-time)*((float)colorI[0]*topFade/(float)stepFI);
    color[1]=(ofGetElapsedTimeMillis()-time)*((float)colorI[1]*topFade/(float)stepFI);;
    color[2]=(ofGetElapsedTimeMillis()-time)*((float)colorI[2]*topFade/(float)stepFI);;
    
    if ((ofGetElapsedTimeMillis()-time)>stepFI){
    
        color[0]=colorI[0]*topFade;
        color[1]=colorI[1]*topFade;
        color[2]=colorI[2]*topFade;
        //ofColor
        isFadeIn=false;
        
        if (type==1){
            stepFO=stepFI;
            triggerFadeOut(stepFO);
        }
    
    }
}


void Par::triggerFadeOut(int step){ //trigger: ep, estic fent un fadeOut
    if (color[0]!=0 || color[1]!=0 || color[2]!=0){
        isFadeOut = true;
        time = ofGetElapsedTimeMillis();
        stepFO=step;
    }
}


void Par::fadeOut(){
    color[0]=colorI[0]*topFade-(ofGetElapsedTimeMillis()-time)*((float)colorI[0]*topFade/(float)stepFO);
    color[1]=colorI[1]*topFade-(ofGetElapsedTimeMillis()-time)*((float)colorI[1]*topFade/(float)stepFO);
    color[2]=colorI[2]*topFade-(ofGetElapsedTimeMillis()-time)*((float)colorI[2]*topFade/(float)stepFO);
    

    if ((ofGetElapsedTimeMillis()-time)>stepFO) {         //sha esgotat el temps
        isFadeOut=false;
        color[0]=0;
        color[1]=0;
        color[2]=0;
    }

}


void Par::randomMove(){
    
    topFade=ofNoise(ofGetElapsedTimef()/1.5+(300*id));             //300*id per a crear offset entre els pars
    topFade=ofMap(topFade, 0.2, 0.8, 0, 1, true);
    //cout<<ofNoise(ofGetElapsedTimef())<<endl;
    color[0]=colorI[0]*topFade;
    color[1]=colorI[1]*topFade;
    color[2]=colorI[2]*topFade;
    

}