#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

#include "MissileController.h"
#include "Missile.h"
#include "TurretMissile.h"
#include "globals.h"
#include "ScoringEngine.h"

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
     ScoringEngine player;
     float velocity = player.getVelocity();
     _health = true;
    _begLocation = Vec2f (Rand::randFloat(800.0), 0.0f);
    _location = _begLocation;
    _buildingNum = Rand::randInt(0,4);
    _buildingLoc = _Building[_buildingNum] + centerCorrection;
    _velocity = velocity;
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
            if(_structure[_buildingNum] < 3)
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
    left2 = static_cast<int>(_buildingLoc.x) - 10;
    right1 = static_cast<int>(_location.x);
    right2 = static_cast<int>(_buildingLoc.x) + 10;
    top1 = static_cast<int>(_location.y);
    top2 = static_cast<int>(_buildingLoc.y) - 10;
    bottom1 = static_cast<int>(_location.y);
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
