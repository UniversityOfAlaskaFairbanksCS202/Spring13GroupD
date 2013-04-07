#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "Missile.h"
#include "MissileController.h"
#include "Building.h"

using namespace ci;
using namespace ci::app;
using namespace std;

static Vec2f _Building1 = Vec2f( 50.0f, 487.0f );
static Vec2f _Building2 = Vec2f( 200.0f, 487.0f );
static Vec2f _Building3 = Vec2f( 510.0f, 487.0f );
static Vec2f _Building4 = Vec2f( 660.0f, 487.0f );
static Vec2f _Building[4] = {_Building1, _Building2, _Building3, _Building4};

class CinderProjectTESTINGApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    gl::Texture _buildingImage;
    gl::Texture _background;
    
    MissileController _MissileController;
};

void CinderProjectTESTINGApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 600 );
	settings->setFrameRate( 60.0f );
}

void CinderProjectTESTINGApp::setup()
{
    _background = gl::Texture( loadImage( loadResource( "MC.BG.Placeholder.png" ) ) );
    _buildingImage = gl::Texture( loadImage( loadResource( "building.png" ) ) );
 
    _MissileController.addMissiles(10);
}
void CinderProjectTESTINGApp::mouseDown( MouseEvent event )
{
    if( event.isLeft())
    {
        _MissileController.addMissiles(1);
    }
}

void CinderProjectTESTINGApp::update()
{
    _MissileController.update();
}

void CinderProjectTESTINGApp::draw()
{
    gl::draw(_background);

    gl::enableAlphaBlending();
        //Width  Height
    gl::draw( _buildingImage, _Building[0] );
    gl::draw( _buildingImage, _Building[1] );
    gl::draw( _buildingImage, _Building[2] );
    gl::draw( _buildingImage, _Building[3] );
    gl::disableAlphaBlending();
    
    _MissileController.draw();
    
}

CINDER_APP_BASIC( CinderProjectTESTINGApp, RendererGl )
