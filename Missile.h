#ifndef MISSILE_H
#define MISSILE_H

#include "cinder/Channel.h"
#include "cinder/Vector.h"

class Missile
{
public:
    Missile();                  //default constructor
    void update();              //updates the missile location and missile blast
    void draw();                //decides to draw the missile line or blast circle
    bool collisionDetection();  //detects if missile hits the building
    
    ci::Vec2f _buildingLoc;     //holds location of building
    ci::Vec2f _location;        //holds location that gets updated
    ci::Vec2f _dirToBuilding;   //holds normalized direction to the building
    ci::Vec2f _begLocation;     //holds random beginning location of missile
    float	  _velocity;        //holds the velocity of the missile
    int       _radius;  
    bool      _health;
    int       _lifespan;        //the lifespan of the blast radius
    int       _age;             //gets incremented until it reaches the lifespan
    int       _buildingNum;     //holds the random building number
};

#endif
