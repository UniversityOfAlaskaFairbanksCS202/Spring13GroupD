#ifndef MISSILE_H
#define MISSILE_H

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
    
    
    ci::Vec2f _buildingLoc;
    ci::Vec2f	_location;
    ci::Vec2f _dirToBuilding;
    ci::Vec2f _begLocation;
    float	_velocity;
    int _radius;
    bool _health;
    int _lifespan;
    int _age;

int _buildingNum;
    
};

#endif
