#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    ////////////////////////// SERIAL ////////////////////////
    ofSetVerticalSync(true);
    i=0;
    serial.listDevices();

    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    serial.setup("/dev/cu.usbmodem1411",9600);
    
    
    
    int baud = 9600;
	//serial.setup(0, baud); //open the first device
    
    //nTimesRead = 0;
	//nBytesRead = 0;
	//readTime = 0;
	//memset(bytesReadString, 0, 4);
    
    ////////////////////////// SOUND ////////////////////////
    heart.load("Cor_greu1.wav");
    heart.setVolume(1);
    heart.setMultiPlay(false);
    
    heart2.load("Cor_greu2.wav");
    heart2.setVolume(1);
    heart2.setMultiPlay(false);
    
    heart3.load("Cor3.wav");
    heart2.setVolume(1);
    heart2.setMultiPlay(false);
    
    background.load("So_fons2.mp3");
    background.setVolume(1);
    background.setLoop(true);
    background.play();
    
    
    ////////////////////////// LIGHT ////////////////////////
    
    llum.initialize();
    
}

//--------------------------------------------------------------    es crida a cada frame
void ofApp::update(){

    //cout<<ofGetElapsedTimeMillis()<<endl;
    unsigned  char resposta[1];
    serial.readBytes(resposta, 1);  //int readBytes(unsigned char * buffer, int length);
    //cout<<resposta<<endl;
    
    now=ofGetElapsedTimeMillis()-timeL; // timeL: temps que ha passat des de que rebem un 'n'.

    
    
    if (now>7000 & disparar==true) {            //véns d'un usuari, 7s després
        background.setVolume(0.75);
        //fadeIn=true;
        disparar=false;
        warming==true;
        llum.equalFade(0.5, 'I', 2, 2500); //(topFade, fade, type, step)
        count=0;
        randomPlay=true;
        freqMean=freqMean_Init;
        
    }
    
    
    if ((now>10000) & (randomPlay==true)) {
        llum.randomPlay(true);
        randomPlay=false;
        
//        if (RandomCounter>=RandomPeriod){            //han passat 10s després d'un usuari
//            llum.randomPlay();
//            //cout<<RandomCounter<<endl;
//            //cout<<ofGetElapsedTimeMillis()%RandomPeriod<<endl;
//            RandomCounter=0;
//            timeR=ofGetElapsedTimeMillis();
//        }
//        
//        else if (RandomCounter<RandomPeriod) {
//            RandomCounter=ofGetElapsedTimeMillis()-timeR;
//            //cout<<RandomCounter<<endl;
//        
//        }
    }
    
    
    //& (!llum.leds[0].isFadeIn) & (!llum.leds[0].isFadeOut))
    if (disparar & !llum.leds[0].isFadeIn & !llum.leds[0].isFadeOut){
        
        if (heartCounter >=freqMean) {
            heart3.play();
            background.setVolume(0.006f);
            llum.equalFade(1,'I', 1, 200);
            
            heartCounter=0;
            initialTime=ofGetElapsedTimeMillis();
        }
        
        else if (heartCounter<freqMean){
            heartCounter=ofGetElapsedTimeMillis()-initialTime;
        }
    }
    
    
    if (resposta[0]=='y') {             //calcul frequencia
        
                // FREQ COMPUTATION //
                freq=1000/((float)ofGetElapsedTimeMillis()-(float)timeF)*60;
        
                //cout<<timeF<<endl;
                //cout<<freq<<endl;
                timeF = ofGetElapsedTimeMillis();
        

        
//        if (count==0){
//            randomPlay=false;
//            initialTime=ofGetElapsedTimeMillis();
//            llum.randomPlay(false);
//            llum.equalFade(1,'O', 1, 2500); //(topFade, fade, type, step)
//            disparar=true;
//        }
        
        switch (count) {
            case 0:
                
                randomPlay=false;
                initialTime=ofGetElapsedTimeMillis();
                llum.randomPlay(false);
                llum.equalFade(1,'O', 1, 2500); //(topFade, fade, type, step)
                //count++;
                break;
                
            case 1:
                disparar=true;
                
            case 4:
                warming=false;
                count=1;
                break;
                
            default:
                break;
        }
        
        
        if (freq<200){
            frequencies[count].set(freq);
        }
        else {
            frequencies[count].set(freqMean*60/1000);
        }
        
        cfreq.average(frequencies, 5);
        
        if (warming==false){                // vols recalcularla nomes quan reps una y
            freqMean=cfreq[0]*1000/60;
            cout<<freqMean<<endl;
        }
        count++;
    }
    
    if (resposta[0]=='n'){
    
        //heart2.play();
        //llum.equalFade(1, 'O', 0);
        timeL = ofGetElapsedTimeMillis();
        //fadeIn=false;
    }
    
    llum.getInfo();
}


        

//--------------------------------------------------------------    es crida a cada frame
void ofApp::draw(){

    ofSetColor(0);
    
    ofDrawBitmapString((int)llum.packDMX[0], 50, 50);
    ofDrawBitmapString((int)llum.packDMX[1], 50, 70);
    ofDrawBitmapString((int)llum.packDMX[2], 50, 90);
    
    ofDrawBitmapString((int)llum.packDMX[3], 200, 50);
    ofDrawBitmapString((int)llum.packDMX[4],200, 70);
    ofDrawBitmapString((int)llum.packDMX[5], 200, 90);
    
    ofDrawBitmapString((int)llum.packDMX[6], 350, 50);
    ofDrawBitmapString((int)llum.packDMX[7], 350, 70);
    ofDrawBitmapString((int)llum.packDMX[8], 350, 90);
    
    ofDrawBitmapString((int)llum.packDMX[9], 500, 50);
    ofDrawBitmapString((int)llum.packDMX[10], 500, 70);
    ofDrawBitmapString((int)llum.packDMX[11], 500, 90);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==OF_KEY_UP){
        heart.play();
}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
