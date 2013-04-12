#include "TurretMissile.h"
#include "Missile.h"

#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
using namespace ci;

// Turret Missile constructor called whenever there's a left click //
TurretMissile::TurretMissile(Vec2f cursorLoc, Vec2f rect) 
{
  _health = true; 
	_begLocation = Vec2f ( rect.x + 2.5, rect.y + 2.5);
	_location = begLocation;
	
	_velocity = 2.0f;
	_radius = 3.0f;
	
	_mPath = _dirToCursorLoc - _location;
}

// mouseMove + mouseDrag allow the turret to follow cursor //
// gets mouse location //
void Turret::mouseMove(MouseEvent event) 
{
		_dirToCursorLoc = event.getPos();
}

// as you move the cursor, alerts mouseMove to get position //
void Turret::mouseDrag(MouseEvent event) 
{
		mouseMove( event );	
}

// on left click, FIRE MISSILE //
void TurretMissile::mouseDown( event ) 
{
	if ( event.isLeft()) {
		TurretMissile(_mLoc, _rect);
		}
}

// moves the missile, checks for collision //	
void TurretMissile::update()
{
		_location += _dirToCursor * _velocity;
	if(collisionDetection())
	{
		_radius = 100.0;
		_health = false;
	}	
}

// draws missile path, if a hit, explosion!! //
void TurretMissile::draw()
{
	gl::drawLine(_begLocation, _location);
	if (!_health)
	{
		gl::drawSolidCircle (_location, _radius);
	}
}

// Collision Detection //
bool TurretMissile::collisionDetection() 
{
	if (_location == Missile._location) {
		return true;
	}
	return false;
}
