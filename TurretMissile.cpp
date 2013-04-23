#include "TurretMissile.h"
#include "Missile.h"

#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
using namespace ci;

// Turret Missile constructor called whenever there's a left click //
TurretMissile::TurretMissile(Vec2f _cursorLoc, Vec2f Start) 
{
  	_health = true; 
	_mLocation = Start;
	_velocity = 2.0f;
	_radius = 3.0f;
}

// moves the missile, checks for collision //	
void TurretMissile::update()
{
		_mLocation += _cursorLoc * _velocity;
	if(collisionDetection())
	{
		_radius = 100.0;
		_health = false;
	}	
	if (_health = false)
		MissileController.removemissile();
}

// draws missile path, if a hit, explosion!! //
void TurretMissile::draw()
{
	gl::drawLine(_begLocation, _mLocation);
	if (!_health)
	{
		gl::drawSolidCircle (_mLocation, _radius);
	}
}

// Collision Detection //
bool TurretMissile::collisionDetection() 
{
	if (_mLocation == Missile._location) {
		return true;
	}
	return false;
}
