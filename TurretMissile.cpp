#include "TurretMissile.h"
#include "Missile.h"
#include "MissileController.h"

#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
using namespace ci;

using std::list;

static Vec2f _missileStartHolder = Vec2f (300, 400);

std::list <TurretMissile> _TurretMissile;


// default Ctor, does absolutely nothing.
TurretMissile::TurretMissile() {}

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
TurretMissile::removeMissile(m);
}

// draws missile path, if a hit, explosion!! //
void TurretMissile::draw()
{
gl::drawLine(_missileStartHolder, _mLocation);
if (!_health)
{
gl::drawSolidCircle (_mLocation, _radius);
}
for( list<TurretMissile>::iterator p = _TurretMissile.begin(); p != _TurretMissile.end(); ++p)
    {
        if (_TurretMissile.size()>0)
		p->draw();

    }
}

// Collision Detection //
bool TurretMissile::collisionDetection()
{
/*if (_mLocation == Missile._location) {
return true;
}
return false;*/
	return false;
}

void TurretMissile::removeMissile( int numMissiles)
{
/*for ( int i = 0; i < numMissiles; ++i)
{
MissileController._TurretMissile.pop_back();
}*/
}
