#ifndef TURRETMISSILE_H
#define TURRETMISSILE_H

#include "cinder/Channel.h"
#include "cinder/Vector.h"
class TurretMissile
{
public:
// CLASS CONSTRUCTORS //
    TurretMissile();                        // does nothing //
    TurretMissile(ci::Vec2f, ci::Vec2f);    // TurretMissile constructor that takes in cursor location and start location. //
    void update();
    void draw();
    bool collisionDetection();              // does what it says, collisionDetection functino for hit checks //
    
// CLASS FUNCTIONS //    
    ci::Vec2f _location;                    // missile location //
    ci::Vec2f _cursorLoc;                   // cursor location //
    ci::Vec2f _dirToCursor;                 // direction to cursor ( _cursorLoc - _location ) //
    ci::Vec2f _begLocation;                 // start location of missile //
    
// CLASS VARIABLES //
    float _velocity;                        // speed of missile //
    int _radius;                            // radius of missile aka 'hit box' //
    int _lifespan;                          // slowed growth of explosion at cursor location //
    int _age;                               // curret missile age, begins at 60 //
    bool _health;                           // yes = alive, no = EXPLOSION!!! //
    
};

#endif
