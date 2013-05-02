#include "TurretMissile.h"
#include "cinder/gl/gl.h"
using namespace ci;

TurretMissile::TurretMissile()
{
    
}

TurretMissile::TurretMissile(ci::Vec2f cursor, ci::Vec2f start)
{
    _health = true;
	_location = start;
    _begLocation = _location;
    _cursorLoc = cursor;
    _dirToCursor = _cursorLoc - _location;
    _dirToCursor.safeNormalize();
	_velocity = 5.0f;
	_radius = 3.0f;
    _lifespan = 60;
    _age = 0;
}

void TurretMissile::update()
{
    _location += _dirToCursor * _velocity;
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

void TurretMissile::draw()
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


bool TurretMissile::collisionDetection()
{
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    left1 = static_cast<int>(_location.x);
    left2 = static_cast<int>(_cursorLoc.x);
    right1 = static_cast<int>(_location.x) + 5;
    right2 = static_cast<int>(_cursorLoc.x) + 5;
    top1 = static_cast<int>(_location.y);
    top2 = static_cast<int>(_cursorLoc.y);
    bottom1 = static_cast<int>(_location.y) + 5;
    bottom2 = static_cast<int>(_cursorLoc.y) + 5;
    
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
