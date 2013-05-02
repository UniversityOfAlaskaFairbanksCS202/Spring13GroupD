#ifndef TURRETMISSILE_H
#define TURRETMISSILE_H

#include "cinder/Channel.h"
#include "cinder/Vector.h"
class TurretMissile
{
public:
    TurretMissile();
    TurretMissile(ci::Vec2f, ci::Vec2f);
void update();
void draw();
bool collisionDetection();
    
   ci::Vec2f _location;
ci::Vec2f _cursorLoc;
    ci::Vec2f _dirToCursor;
    ci::Vec2f _begLocation;
    
float _velocity;
int _radius;
    int _lifespan;
    int _age;
    
bool _health;
    
};

#endif
