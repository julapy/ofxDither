#include "ofApp.h"

///////////////////////////////////////////
//	SETUP.
///////////////////////////////////////////

void ofApp::setup()
{
	ofSetFrameRate( 30 );
	ofSetVerticalSync( true );
	ofBackground( 0, 0, 0 );
	
	imageIn.load( "lena_512x512.png" );
	
	ditherType = ORDERED_BAYER;
}

///////////////////////////////////////////
//	UPDATE.
///////////////////////////////////////////

void ofApp::update()
{
	switch( ditherType ) 
	{
		case ORDERED_BAYER:
			
			dither.dither_ordered( imageIn, imageOut, DITHER_ORDERED_8x8 );
			break;
			
		case FLOYD_STEINBERG:
			
			dither.dither_floyd_steinberg( imageIn, imageOut );
			break;
			
		case ATKINSON:
			
			dither.dither_atkinson( imageIn, imageOut );
			break;
	}
}

///////////////////////////////////////////
//	DRAW.
///////////////////////////////////////////

void ofApp::draw()
{
	ofSetColor( 255, 255, 255 );
	
	imageIn.draw( 0, 0 );
	imageOut.draw( imageIn.getWidth(), 0 );

	//--- text info.
	
	int x = 20;
	int y = imageIn.getHeight() + 40;
	
	ditherType == ORDERED_BAYER		? ofSetColor( ofColor :: magenta ) : ofSetColor( ofColor :: white );
	ofDrawBitmapString( "1) ordered bayer dithering", x, y );
	
	ditherType == FLOYD_STEINBERG	? ofSetColor( ofColor :: magenta ) : ofSetColor( ofColor :: white );
	ofDrawBitmapString( "2) floyd steinberg dithering",	x, y += 20 );
	
	ditherType == ATKINSON			? ofSetColor( ofColor :: magenta ) : ofSetColor( ofColor :: white );
	ofDrawBitmapString( "3) atkinson dithering", x, y += 20 );
}

///////////////////////////////////////////
//	HANDLERS.
///////////////////////////////////////////

void ofApp::keyPressed(int key)
{
	switch (key) 
	{
		case '1':
			ditherType = ORDERED_BAYER;
			break;
		case '2':
			ditherType = FLOYD_STEINBERG;
			break;
		case '3':
			ditherType = ATKINSON;
			break;
	}
}

void ofApp::keyReleased(int key)
{

}

void ofApp::mouseMoved(int x, int y )
{

}

void ofApp::mouseDragged(int x, int y, int button)
{

}

void ofApp::mousePressed(int x, int y, int button)
{

}

void ofApp::mouseReleased(int x, int y, int button)
{

}

void ofApp::windowResized(int w, int h)
{

}

