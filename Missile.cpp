#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

#include "MissileController.h"
#include "Missile.h"
#include "TurretMissile.h"

using namespace ci;

static Vec2f _Building1 = Vec2f( 50.0f, 487.0f );
static Vec2f _Building2 = Vec2f( 200.0f, 487.0f );
static Vec2f _Building3 = Vec2f( 510.0f, 487.0f );
static Vec2f _Building4 = Vec2f( 660.0f, 487.0f );
static Vec2f _Building[4] = {_Building1, _Building2, _Building3, _Building4};
static Vec2f centerCorrection = Vec2f (40.0f, 40.0f);

static MissileController _MissileController;

Missile::Missile()
{
    _health = true;
    _begLocation = Vec2f (Rand::randFloat(800.0), 0.0f);
    _location = _begLocation;
    _buildingLoc = _Building[Rand::randInt(0,5)] + centerCorrection;
    _velocity = 1.0f;
    _radius = 0;
    _dirToBuilding = _buildingLoc - _location;
    _dirToBuilding.safeNormalize();
    _lifespan = 60;
    _age = 0;
}

void Missile::update()
{
    _location += _dirToBuilding * _velocity;
    if(collisionDetection())
    {
        _velocity = 0.0;
    }
    if (_velocity == 0.0)
    {
        _age ++;
        _radius++;
        if (_age > _lifespan)
        {
            _health = false;
        }
    }
}

void Missile::draw()
{
    if (_velocity != 0.0)
    {
        gl::drawLine(_begLocation, _location);
    }
    else
    {
        gl::drawSolidCircle ( _location, _radius);
    }
}

bool Missile::collisionDetection()
{
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    left1 = static_cast<int>(_location.x);
    left2 = static_cast<int>(_buildingLoc.x);
    right1 = static_cast<int>(_location.x) + 10;
    right2 = static_cast<int>(_buildingLoc.x) + 10;
    top1 = static_cast<int>(_location.y);
    top2 = static_cast<int>(_buildingLoc.y);
    bottom1 = static_cast<int>(_location.y) + 10;
    bottom2 = static_cast<int>(_buildingLoc.y) + 10;
    
    if (bottom1 < top2)
        return(false);
    if (top1 > bottom2)
        return(false);
    
    if (right1 < left2)
        return(false);
    if (left1 > right2)
        return(false);
    
    return(true);
    
    
    
}


