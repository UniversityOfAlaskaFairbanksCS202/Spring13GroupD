#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "globals.h" //Changed this

#include "Missile.h"
#include "MissileController.h"
#include "TurretMissile.h"


using namespace ci;
using namespace ci::app;
using namespace std;

//static double _mouseX;
static Vec2f _centerBase = Vec2f (275, 400);

static Vec2f _Building1 = Vec2f( 50.0f, 487.0f );
static Vec2f _Building2 = Vec2f( 200.0f, 487.0f );
static Vec2f _Building3 = Vec2f( 510.0f, 487.0f );
static Vec2f _Building4 = Vec2f( 660.0f, 487.0f );
static Vec2f _Building[4] = {_Building1, _Building2, _Building3, _Building4};
static Vec2f _missileStartHolder = Vec2f( 390.0f, 500.0f );

static int level1Missiles = 10;

class CinderProjectTESTINGApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
    void setup();
    void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event); //Added this
    void update();
    void draw();
    gl::Texture _buildingImage1; //Changed this
	gl::Texture _buildingImage2; //Changed this
	gl::Texture _buildingImage3; //Changed this
	gl::Texture _buildingImage4; //Changed this
	gl::Texture _buildingImage[4]; //Changed this
    gl::Texture _background;
	gl::Texture _frontPage;
    static int count;
    
    MissileController _MissileController;
    
};

int CinderProjectTESTINGApp::count = 0;

void CinderProjectTESTINGApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 600 );
    settings->setFrameRate( 60.0f );
}

void CinderProjectTESTINGApp::setup() //Changed this whole section
{
   _background = gl::Texture( loadImage( loadResource(RES_BACKGROUND ) ) );
    _buildingImage1 = gl::Texture( loadImage( loadResource(RES_BUILDING1 ) ) );
    _buildingImage2 = gl::Texture( loadImage( loadResource(RES_BUILDING2 ) ) );
    _buildingImage3 = gl::Texture( loadImage( loadResource(RES_BUILDING3 ) ) );
    _buildingImage4 = gl::Texture( loadImage( loadResource(RES_BUILDING4 ) ) );
    _buildingImage[0] = _buildingImage1;
    _buildingImage[1] = _buildingImage2;
    _buildingImage[2] = _buildingImage3;
    _buildingImage[3] = _buildingImage4;


	_frontPage = gl::Texture( loadImage( loadResource(RES_FRONTPAGE) ) );
}


void CinderProjectTESTINGApp::mouseDown( MouseEvent event )
{
    if ( event.isLeft())
    {
        _MissileController.addTurretMissile(1, event.getPos(), _missileStartHolder);
        //_mouseX = event.getX();
    }
}

void CinderProjectTESTINGApp::keyDown( KeyEvent event ) //Added all this
{
    if (event.getChar() == '6')
    {
        _MissileController.addMissiles(1);
    }
    if (event.getChar() == '9')
    {
        _structure[0] = 0;
        _structure[1] = 0;
        _structure[2] = 0;
        _structure[3] = 0;
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
    /*static Vec2f _linePoint = Vec2f( _mouseX, 350);
gl::drawLine(_linePoint, _centerBase);
gl::drawSolidCircle(_centerBase, 20);*/
    gl::draw(_frontPage);
    gl::draw(_background);
    
    gl::enableAlphaBlending();
    //Width Height
    gl::draw( _buildingImage[_structure[0]], _Building[0] ); //changed this
    gl::draw( _buildingImage[_structure[1]], _Building[1] );//changed this
    gl::draw( _buildingImage[_structure[2]], _Building[2] );//changed this
    gl::draw( _buildingImage[_structure[3]], _Building[3] );//changed this
    gl::disableAlphaBlending();
    
    _MissileController.draw();
    
}

CINDER_APP_BASIC( CinderProjectTESTINGApp, RendererGl )
