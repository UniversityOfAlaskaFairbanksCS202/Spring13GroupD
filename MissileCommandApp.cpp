#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"

#include "Missile.h"
#include "MissileController.h"
#include "TurretMissile.h"


using namespace ci;
using namespace ci::app;
using namespace std;

static double _mouseX;
static Vec2f _centerBase = Vec2f (275, 400);
static Vec2f _missileStartHolder = Vec2f (300, 400);
static Vec2f _Building1 = Vec2f( 50.0f, 487.0f );
static Vec2f _Building2 = Vec2f( 200.0f, 487.0f );
static Vec2f _Building3 = Vec2f( 510.0f, 487.0f );
static Vec2f _Building4 = Vec2f( 660.0f, 487.0f );
static Vec2f _Building[4] = {_Building1, _Building2, _Building3, _Building4};

static int level1Missiles = 10;

class CinderProjectTESTINGApp : public AppBasic {
public:
void prepareSettings( Settings *settings );
void setup();
void mouseDown( MouseEvent event );
void update();
void draw();
    gl::Texture _buildingImage;
    gl::Texture _background;
    static int count;
    
    MissileController _MissileController;
    
};

int CinderProjectTESTINGApp::count = 0;

void CinderProjectTESTINGApp::prepareSettings( Settings *settings )
{
settings->setWindowSize( 800, 600 );
settings->setFrameRate( 60.0f );
}

void CinderProjectTESTINGApp::setup()
{
    _background = gl::Texture( loadImage( loadResource(RES_BACKGROUND ) ) );
    _buildingImage = gl::Texture( loadImage( loadResource(RES_BUILDING ) ) );
}

/*
void CinderProjectTESTINGApp::mouseMove(MouseEvent event)
{
TurretMissile._cursorLoc = event.getPos();
}
*/

void CinderProjectTESTINGApp::mouseDown( MouseEvent event )
{
    if ( event.isLeft())
    {
    TurretMissile currentMissile;
   currentMissile=TurretMissile(event.getPos(), _missileStartHolder);
   _mouseX = event.getX();
   currentMissile.draw();
   }
}



void CinderProjectTESTINGApp::update()
{
    if(count < level1Missiles)
    {
        if(app::getElapsedFrames()%60 == 59) //once a second. 60 frames a second, one time it is 60
        {
            _MissileController.addMissiles(1);
            count++;

        }
    }
    _MissileController.update();
}

void CinderProjectTESTINGApp::draw()
{
    static Vec2f _linePoint = Vec2f( _mouseX, 350);
    gl::drawLine(_linePoint, _centerBase);
    
    gl::drawSolidCircle(_centerBase, 20);
    
    gl::draw(_background);

    gl::enableAlphaBlending();
        //Width Height
    gl::draw( _buildingImage, _Building[0] );
    gl::draw( _buildingImage, _Building[1] );
    gl::draw( _buildingImage, _Building[2] );
    gl::draw( _buildingImage, _Building[3] );
    gl::disableAlphaBlending();
    
    _MissileController.draw();
    
}

CINDER_APP_BASIC( CinderProjectTESTINGApp, RendererGl )
