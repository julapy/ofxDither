#include "testApp.h"

///////////////////////////////////////////
//	SETUP.
///////////////////////////////////////////

void testApp::setup()
{
	ofSetFrameRate( 30 );
	ofSetVerticalSync( true );
	ofBackground( 0, 0, 0 );
	
	imageIn.loadImage( "lena_512x512.png" );
	
	ditherType = ORDERED_BAYER;
}

///////////////////////////////////////////
//	UPDATE.
///////////////////////////////////////////

void testApp::update()
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

void testApp::draw()
{
	ofSetColor( 255, 255, 255 );
	
	imageIn.draw( 0, 0 );
	imageOut.draw( imageIn.width, 0 );

	//--- text info.
	
	int x = 20;
	int y = imageIn.height + 40;
	
	ditherType == ORDERED_BAYER		? ofSetColor( 0xFF0000 ) : ofSetColor( 0xFFFFFF );
	ofDrawBitmapString( "1) ordered bayer dithering",	x, y );
	
	ditherType == FLOYD_STEINBERG	? ofSetColor( 0xFF0000 ) : ofSetColor( 0xFFFFFF );
	ofDrawBitmapString( "2) floyd steinberg dithering",	x, y += 20 );
	
	ditherType == ATKINSON			? ofSetColor( 0xFF0000 ) : ofSetColor( 0xFFFFFF );
	ofDrawBitmapString( "3) atkinson dithering",		x, y += 20 );
}

///////////////////////////////////////////
//	HANDLERS.
///////////////////////////////////////////

void testApp::keyPressed(int key)
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

void testApp::keyReleased(int key)
{

}

void testApp::mouseMoved(int x, int y )
{

}

void testApp::mouseDragged(int x, int y, int button)
{

}

void testApp::mousePressed(int x, int y, int button)
{

}

void testApp::mouseReleased(int x, int y, int button)
{

}

void testApp::windowResized(int w, int h)
{

}

