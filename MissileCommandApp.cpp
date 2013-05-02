//COPYWRIGHT BY DIGITECH INDUSTRIES
//I OWN THAT BRANDON DON'T EVEN TRY. 

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "globals.h" 

#include "Missile.h"
#include "MissileController.h"
#include "TurretMissile.h"
#include"ScoringEngine.h"



using namespace ci;
using namespace ci::app;
using namespace std;


static Vec2f _centerBase = Vec2f (275, 400); //Sets where the center is for our turret

static Vec2f _Building1 = Vec2f( 50.0f, 487.0f ); //Sets the locations of all of the buildings
static Vec2f _Building2 = Vec2f( 200.0f, 487.0f );
static Vec2f _Building3 = Vec2f( 510.0f, 487.0f );
static Vec2f _Building4 = Vec2f( 660.0f, 487.0f );
static Vec2f _Building[4] = {_Building1, _Building2, _Building3, _Building4}; //Creates vector of the buildings.
static Vec2f _missileStartHolder = Vec2f( 390.0f, 500.0f ); //Tells the program where the missiles will start from.



class MissileCommand : public AppBasic {
public:
    void prepareSettings( Settings *settings ); //Class declarations for the functions we will use in MissileCommand
    void setup(); //Sets up the drawing field
    void mouseDown( MouseEvent event ); //Tells the program what to do on mouse down.
    void keyDown( KeyEvent event);  //Tells the computer what to do on the various keydown events.
    void update(); //Tells the program to know what to update every timme update runs
    void draw(); //Draws all our stuff on the screen
    gl::Texture _buildingImage1; //All gl::Texture are declarations of the images we are using in the program
gl::Texture _buildingImage2; 
gl::Texture _buildingImage3; 
gl::Texture _buildingImage4; 
gl::Texture _buildingImage[4]; 
gl::Texture _background;
gl::Texture _frontPage;
gl::Texture _GameOver;

    static int count; //Creates a static int called count that will keep track of how many missiles are being drawn
    MissileController _MissileController; //Creates an instance of Missile Controller called _MissileController
    
};

int MissileCommand::count = 0;

void MissileCommand::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 600 ); //Sets our window size to a static rectangle.
    settings->setFrameRate( 60.0f ); //Sets the fps to an expected sixty.
}

void MissileCommand::setup() //This functions adds all of our images from resources and 
							 //sets them equal to the gl::textures set up at the begining of the class
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


void MissileCommand::mouseDown( MouseEvent event ) //When a left mouse click happens this function tells MissileController to add a turret missle
												   //going from the startholder(turret) to the location the mouse was at.
{
    
	if ( event.isLeft())
    {
        _MissileController.addTurretMissile(1, event.getPos(), _missileStartHolder);
        
    }
}

void MissileCommand::keyDown( KeyEvent event )  //Used to select the difficulty during the front page.
{
    
    if (event.getChar() == '9') //CHEAT CODE!!!!!! I mean not cheat code *cough cough*
    {
        _structure[0] = 0;
        _structure[1] = 0;
        _structure[2] = 0;
        _structure[3] = 0;
    }
	 if (event.getChar() == '1') //This for example sets the difficulty to easy and creates an easy player and sends it to 
								 // Scoring engine.
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
	if (event.getCode() == KeyEvent::KEY_ESCAPE) //Gets you out of the game if you're tired of being the best around.
	{
		quit();
	}
}


void MissileCommand::update() //Updates the game, this is a cinder function and is still kind of magic to me. 
{
	ScoringEngine player; //Creates an instance of player. //Since all values of player are static it knows what difficulty was selected.
	if(count < player.getMissiles()) //Adds the amount of missiles the difficulty level tells it to.
    {
        if(app::getElapsedFrames()%60 == 59 && (_choice >0 && _choice<5)) //once a second. 60 frames a second, one time it is 60
        {
            _MissileController.addMissiles(1);
            count++;
			
		}
		
    }
	if(count == player.getMissiles()) //Makes sure all your missiles are dead.
		{
			player.updateLevel(); //Takes things to a whole 'nother level.
		}
    _MissileController.update(); //Runs through it again. Recursively. (Browny points because that's gonna be on the final and I identified it)
}

void MissileCommand::draw() //It draws our images and missiles
{

    if (_choice < 1 || _choice > 5) //This draws the main menu until one of the difficulties is selected. Hit q all you want but it will
									//still display and wait for you to hit 1-4. (Idiot proofed it)
	{
		gl::enableAlphaBlending();
		gl::draw(_frontPage);
		gl::disableAlphaBlending(); 
	}   

	else if (_eog ==12) //Calls the global eog(end of game) to tell when all your buildings are destroyed.
	{
		
		ScoringEngine player;
		gl::enableAlphaBlending();
		gl::draw(_GameOver); //It ends all the fun with a game over screen.
		gl::drawStringCentered( "Your Score " +player.endingscore, Vec2f(400.0f,200.0f),ColorA(1,0,0,1),Font("Arial", 90)); //Lets you know how bad you did. 
		gl::disableAlphaBlending();
	}
	else if (!(_eog >= 12)) //This diplays the actual game as long as all of your buildings are not destroyed and you've decided to select a difficulty level
	{
	gl::draw(_background);
    gl::enableAlphaBlending();
    gl::draw( _buildingImage[_structure[0]], _Building[0] ); 
    gl::draw( _buildingImage[_structure[1]], _Building[1] );
    gl::draw( _buildingImage[_structure[2]], _Building[2] );
    gl::draw( _buildingImage[_structure[3]], _Building[3] );
    gl::disableAlphaBlending();
    
    _MissileController.draw(); //Calls in missile controllers draw which draws the lines and circles we call missiles. 
	}

}

CINDER_APP_BASIC( MissileCommand, RendererGl )
