#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "CinderProjectTESTING_Prefix.pch"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectTESTINGApp : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    gl::Texture myImage;
};

void CinderProjectTESTINGApp::setup()
{
    myImage = gl::Texture( loadImage( loadResource( "mcommand copy.jpg" ) ) );
}
void CinderProjectTESTINGApp::mouseDown( MouseEvent event )
{
}

void CinderProjectTESTINGApp::update()
{
   
}

void CinderProjectTESTINGApp::draw()
{
	// clear out the window with blue
	 gl::clear( Color( 0, 0, 100 ) );

    if(myImage) {             //Width  Height
    gl::draw( myImage, Vec2f( 10.0f, 350.0f ) );
    gl::draw( myImage, Vec2f( 150.0f, 350.0f ) );
    gl::draw( myImage, Vec2f( 400.0f, 350.0f ) );
    gl::draw( myImage, Vec2f( 540.0f, 350.0f ) );}
}

CINDER_APP_BASIC( CinderProjectTESTINGApp, RendererGl )
