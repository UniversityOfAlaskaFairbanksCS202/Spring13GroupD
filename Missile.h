#pragma once

#include "cinder/Channel.h"
#include "cinder/Vector.h"

#include <vector>

class Missile
{
public:
	Missile();
	void update();
	void draw();
	bool collisionDetection();
    
    
	ci::Vec2f	_buildingLoc;
	ci::Vec2f	_location;
    ci::Vec2f   _dirToBuilding;
	float		_velocity;
	float       _radius;
    bool        _health;
    

};


