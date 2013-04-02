#ifndef BUILDING_H_INCLUDED
#define BUILDING_H_INCLUDED
#include "cinder/app/AppBasic.h"
#include "cinder/Channel.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

class Building
{
	int state;
	gl::Texture myImage;
	
public:
	Building();
	int getState();
	Building(int state);
	void update();
	void draw();
private:



};


#endif