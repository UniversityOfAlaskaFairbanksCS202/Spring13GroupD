#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "globals.h" //Changed this
//#include <time.h>

#include "Missile.h"
#include "MissileController.h"
#include "TurretMissile.h"
#include"ScoringEngine.h"



using namespace ci;
using namespace ci::app;
using namespace std;


static Vec2f _centerBase = Vec2f (275, 400);

static Vec2f _Building1 = Vec2f( 50.0f, 487.0f );
static Vec2f _Building2 = Vec2f( 200.0f, 487.0f );
static Vec2f _Building3 = Vec2f( 510.0f, 487.0f );
static Vec2f _Building4 = Vec2f( 660.0f, 487.0f );
static Vec2f _Building[4] = {_Building1, _Building2, _Building3, _Building4};
static Vec2f _missileStartHolder = Vec2f( 390.0f, 500.0f );



class CinderProjectTESTINGApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
    void setup();
    void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event); 
    void update();
    void draw();
    gl::Texture _buildingImage1; 
gl::Texture _buildingImage2; 
gl::Texture _buildingImage3; 
gl::Texture _buildingImage4; 
gl::Texture _buildingImage[4]; 
gl::Texture _background;
gl::Texture _frontPage;
gl::Texture _GameOver;

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
    _buildingImage1 = gl::Texture( loadImage( loadResource(RES_BUILDING1 ) ) );
    _buildingImage2 = gl::Texture( loadImage( loadResource(RES_BUILDING2 ) ) );
    _buildingImage3 = gl::Texture( loadImage( loadResource(RES_BUILDING3 ) ) );
    _buildingImage4 = gl::Texture( loadImage( loadResource(RES_BUILDING4 ) ) );
    _buildingImage[0] = _buildingImage1;
    _buildingImage[1] = _buildingImage2;
    _buildingImage[2] = _buildingImage3;
    _buildingImage[3] = _buildingImage4;

	_frontPage = gl::Texture( loadImage( loadResource(RES_FRONTPAGE) ) );
	_GameOver = gl::Texture( loadImage( loadResource(RES_GAMEOVER) ) );

}


void CinderProjectTESTINGApp::mouseDown( MouseEvent event )
{
    
	if ( event.isLeft())
    {
        _MissileController.addTurretMissile(1, event.getPos(), _missileStartHolder);
        
    }
}

void CinderProjectTESTINGApp::keyDown( KeyEvent event ) 
{
    
    if (event.getChar() == '9')
    {
        _structure[0] = 0;
        _structure[1] = 0;
        _structure[2] = 0;
        _structure[3] = 0;
    }
	 if (event.getChar() == '1')
    {
        _choice = 1;
		ScoringEngine player(1);
    }
    if (event.getChar() == '2')
    {
        _choice = 2;
		ScoringEngine player(2);
    }
	if (event.getChar() == '3')
    {
		_choice = 3;
		ScoringEngine player(3);
	}
	if (event.getChar() == '4')
    {
        _choice = 4;
		ScoringEngine player(4);
    }
	if (event.getCode() == KeyEvent::KEY_ESCAPE)
	{
		quit();
	}
}


void CinderProjectTESTINGApp::update()
{
	ScoringEngine player;
	if(count < player.getMissiles())
    {
        if(app::getElapsedFrames()%60 == 59 && (_choice >0 && _choice<5)) //once a second. 60 frames a second, one time it is 60
        {
            _MissileController.addMissiles(1);
            count++;
			
		}
		
    }
	if(count == player.getMissiles())
		{
			player.updateLevel();
		}
    _MissileController.update();
}

void CinderProjectTESTINGApp::draw()
{

    if (_choice < 1 || _choice > 5) 
	{
		gl::enableAlphaBlending();
		gl::draw(_frontPage);
		gl::disableAlphaBlending(); 
	}   

	else if (_eog ==12)
	{
		
		ScoringEngine player;
		gl::enableAlphaBlending();
		gl::draw(_GameOver);
		gl::drawStringCentered( "Your Score " +player.endingscore, Vec2f(400.0f,200.0f),ColorA(1,0,0,1),Font("Arial", 90));
		gl::disableAlphaBlending();
	}
	else if (!(_eog >= 12))
	{
	gl::draw(_background);
    gl::enableAlphaBlending();
    gl::draw( _buildingImage[_structure[0]], _Building[0] ); 
    gl::draw( _buildingImage[_structure[1]], _Building[1] );
    gl::draw( _buildingImage[_structure[2]], _Building[2] );
    gl::draw( _buildingImage[_structure[3]], _Building[3] );
    gl::disableAlphaBlending();
    
    _MissileController.draw();
	}

}

CINDER_APP_BASIC( CinderProjectTESTINGApp, RendererGl )
