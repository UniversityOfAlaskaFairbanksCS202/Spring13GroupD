#include "TurretMissile.h"
#include "cinder/gl/gl.h"
using namespace ci;

TurretMissile::TurretMissile()				// does nothing but needed //
{
    
}

TurretMissile::TurretMissile(ci::Vec2f cursor, ci::Vec2f start)	// constructor that creates class object and gives initial instructions, chaged with updates //
{
    _health = true;				            // missile is alive //
    _location = start;			        	// taken from second arg //
    _begLocation = _location;			    // missile's beginning location (at turret) //
    _cursorLoc = cursor;			        // _cursorLoc taken in from first arg (position where clicked) //
    _dirToCursor = _cursorLoc - _location;	// direction to cursor, path the missile will follow //
    _dirToCursor.safeNormalize();	    	// makes it safe, normalizing it //
    _velocity = 5.0f;			        	// how fast the turret missile moves //
    _radius = 3.0f;			            	// size of turret missile //
    _lifespan = 60;			            	// life span of turret missile, when up, missile dies - memory safety //
    _age = 0;				            	// increases with time, if greater than lifespan, missile is dead //
}

void TurretMissile::update()			// part of the update-draw cycle; updates missile position... //
{						                // checks for collision and checks age //
    _location += _dirToCursor * _velocity;
    if(collisionDetection())            // if there's a hit, missile stops moving //
    {
        _velocity = 0.0;
    }
    if (_velocity == 0.0)               // if the missile isn't moving, increase it's age and radius //
    {
        _age ++;
        _radius++;
        if (_age > _lifespan)           // if age is greater than lifespan, kill the missile //
        {
            _health = false;
        }
    }

}

void TurretMissile::draw()			        	// draws missile path with line, also draws missile //
{
    if (_velocity != 0.0)
    {
        gl::drawLine(_begLocation, _location);  // draws a line until the missile stops //
    }
    else
    {
        gl::drawSolidCircle ( _location, _radius); // once the missile stops draw explosion circle //
    }
}


bool TurretMissile::collisionDetection()			
{
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    left1 = static_cast<int>(_location.x);
    left2 = static_cast<int>(_cursorLoc.x);
    right1 = static_cast<int>(_location.x) + 5;     // (+5 to radius) gives an explosion radius //
    right2 = static_cast<int>(_cursorLoc.x) + 5;
    top1 = static_cast<int>(_location.y);
    top2 = static_cast<int>(_cursorLoc.y);
    bottom1 = static_cast<int>(_location.y) + 5;
    bottom2 = static_cast<int>(_cursorLoc.y) + 5;
    
    if (bottom1 < top2)
        return(false);
    if (top1 > bottom2)
        return(false);
                                                    // if statements check for a miss and return false until a hit //
    if (right1 < left2)
        return(false);
    if (left1 > right2)
        return(false);
    
    return(true);                                   // once there is a hit collisionDetection will return true //
    
    
    
}
