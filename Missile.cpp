#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

#include "MissileController.h"
#include "Missile.h"
#include "TurretMissile.h"
#include "globals.h"
#include "ScoringEngine.h"

using namespace ci;

static Vec2f _Building1 = Vec2f( 50.0f, 487.0f ); //coordinate for building 1
static Vec2f _Building2 = Vec2f( 200.0f, 487.0f ); //coordinate for building 2
static Vec2f _Building3 = Vec2f( 510.0f, 487.0f ); //coordinate for building 3
static Vec2f _Building4 = Vec2f( 660.0f, 487.0f ); //coordinate for building 4
static Vec2f _Building[4] = {_Building1, _Building2, _Building3, _Building4}; //array of building coordinates
static Vec2f centerCorrection = Vec2f (40.0f, 40.0f); //correct the coordinates for the building so it points at middle instead of top-left

Missile::Missile()
{
     ScoringEngine player;					//ScoringEngine object to extract data
     float velocity = player.getVelocity();			//velocity from difficulty setting
     _health = true;						//missile health is true
    _begLocation = Vec2f (Rand::randFloat(800.0), 0.0f);	//chooses a random beginning location from the top location of the screen
    _location = _begLocation;					//holds the current location of the missile
    _buildingNum = Rand::randInt(0,4);				//randomly chooses which building to target
    _buildingLoc = _Building[_buildingNum] + centerCorrection;	//gets the point at middle of building
    _velocity = velocity;					//assigns missile velocity from defined ScoringEngine velocity
    _radius = 0;						//defaults the radius of when it creates the blast
    _dirToBuilding = _buildingLoc - _location;			//finds the direction to the building
    _dirToBuilding.safeNormalize();				//  then normalizes the vector
    _lifespan = 60;						//lifespan of how big the bomb blasts
    _age = 0;							//sets the age of the missile from when it blasts
}

void Missile::update()
{
     _location += _dirToBuilding * _velocity;	//updates location by adding the direction and magnitude 
    if(collisionDetection())			//if missile hits the building set velocity to 0
    {
        _velocity = 0.0;
    }
    if (_velocity == 0.0)			//if velocity is 0, increment the age and radius
    {
        _age ++;
        _radius++;
        if (_age > _lifespan)			//until the radius is larger than the lifespan
        {
            _health = false;			//kill the missile
            if(_structure[_buildingNum] < 3)	//increment the building until it is at the lowest level
            {
                _structure[_buildingNum]++;
		_eog++;
            }
	    else
	    	return;
        }
    }
}

void Missile::draw()
{
    if (_velocity != 0.0)				//if missile is moving, draw a line
    {
        gl::drawLine(_begLocation, _location);
    }
    else						//if missile is not moving, draw a circle
    {
        gl::drawSolidCircle ( _location, _radius);
    }
}

bool Missile::collisionDetection()
{
    int left1, left2;		//create the left, right, top, and bottom of both the building and location
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    left1 = static_cast<int>(_location.x);
    left2 = static_cast<int>(_buildingLoc.x) - 10;
    right1 = static_cast<int>(_location.x);
    right2 = static_cast<int>(_buildingLoc.x) + 10;
    top1 = static_cast<int>(_location.y);
    top2 = static_cast<int>(_buildingLoc.y) - 10;
    bottom1 = static_cast<int>(_location.y);
    bottom2 = static_cast<int>(_buildingLoc.y) + 10;
    
    if (bottom1 < top2) 	//if the location and building intersect, then return false
        return(false);
    if (top1 > bottom2)
        return(false);
    
    if (right1 < left2)
        return(false);
    if (left1 > right2)
        return(false);
    
    return(true);
    
    
    
}
