#include "Building.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;

Building Building0, Building1, Building2, Building3;

Building::Building()
{
	state=0;
	myImage = gl::Texture( loadImage( loadAsset( "misslecommand.jpg" ) ) );
}

int Building::getState()
{
	return state;
}
Building::Building(int state)
{
	switch (state)
	{
		case 0:
			myImage = gl::Texture( loadImage( loadAsset( "misslecommand.jpg" ) ) );
		case 1:
			myImage = gl::Texture( loadImage( loadAsset( "misslecommand.jpg" ) ) );
		case 2:
			myImage = gl::Texture( loadImage( loadAsset( "misslecommand.jpg" ) ) );
		case 3:
			myImage = gl::Texture( loadImage( loadAsset( "misslecommand.jpg" ) ) );
	}
}
void Building::update()
{
	if (Building0.state++)
	{
	  Building::Building(Building0.state);
	}
	if (Building1.state++)
	{
	  Building::Building(Building1.state);
	}
	if (Building2.state++)
	{
	  Building::Building(Building2.state);
	}
	if (Building3.state++)
	{
	  Building::Building(Building3.state);
	}
	
}
void Building::draw()
{
	 gl::clear( Color( 0, 0, 100 ) );
	gl::draw( Building0.myImage, Vec2f( 10.0f, 350.0f ) );
    gl::draw( Building1.myImage, Vec2f( 150.0f, 350.0f ) );
    gl::draw( Building2.myImage, Vec2f( 400.0f, 350.0f ) );
    gl::draw( Building3.myImage, Vec2f( 540.0f, 350.0f ) );

}
