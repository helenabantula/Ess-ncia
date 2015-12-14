#pragma once

#include "ofMain.h"

#include "Light.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofSoundPlayer  heart;
        ofSoundPlayer heart2;
        ofSoundPlayer heart3;
        ofSoundPlayer background;
    
        float heartRate;
        int i;
        int periodMean = 857;  //857, per’ode de 70bpm
        int periodMean_Init=857;
        int RandomPeriod = 2000;
        int Randomcounter = 0;
        int timeR =0;
        ofSerial serial;
    
        int heartcounter;
    
    
        // bool		bSendSerialMessage;			// a flag for sending serial
        //char		bytesRead[1];				// data from serial, we will be reading 0, 1.
        //char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
        //int			nBytesRead;					// how much did we read?
        //int			nTimesRead;					// how many times did we read?
        //float		readTime;					// when did we last read?
    
        //vector<light> llum;
    
        Light llum;
        int countY = 0;
        int timeF = 0;
        int timeL = 0;
        int initialTime;
        int now;
        float freq = 1;        //in ms
    
        bool fadeIn = false;
        bool warming = true;
        bool disparar = false;
        bool randomPlay = true;
    
    
        //ofVec2f frequencies[5];
        //vector<ofVec2f> frequencies;
        vector<int> frequencies;
        int freqMean;
        int between;
    
    
    
        
		
};
