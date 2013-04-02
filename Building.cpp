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
	state=0; //Sets Building to full health when created.
	myImage = gl::Texture( loadImage( loadAsset( "misslecommand.jpg" ) ) ); //Sets defeault full health image to display.
}

Building::Building(int state) 
{
	switch (state) //Switch statement changing the image that is displayed based on the state(Health) of a building.
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
void Building::update() //Checks to see if state changes(A hit is registered) with a series of if 
	                    //statements and runs Building(state) again to change the image
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
	 gl::clear( Color( 0, 0, 100 ) ); //Sets Background to Blue, i haven't added the background file yet. 
	gl::draw( Building0.myImage, Vec2f( 10.0f, 350.0f ) ); //Draws the four buildings in the locations on the map.
    gl::draw( Building1.myImage, Vec2f( 150.0f, 350.0f ) );
    gl::draw( Building2.myImage, Vec2f( 400.0f, 350.0f ) );
    gl::draw( Building3.myImage, Vec2f( 540.0f, 350.0f ) );

}
