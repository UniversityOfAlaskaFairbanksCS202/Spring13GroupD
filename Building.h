#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED
#include "cinder/app/AppBasic.h"
#include "cinder/Channel.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

class Building
{
	int state; //"Health" of buildings.
	gl::Texture myImage; // The image displayed for each building
	
public:
	Building(); //Defualt constructor sets buildings equal to full health and base animation
	Building(int state); //Checks the state agaisnt a switch loop and changes the picture displayed based on the state(health)
	void update(); //Checks for imapct from missile.
	void draw();  //Draws the 4 Buildings in the 4 locations around the map.
private:



};


#endif