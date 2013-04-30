#ifndef MISSILECONTROLLER_H
#define MISSILECONTROLLER_H


#include "cinder/Channel.h"
#include "Missile.h"
#include "TurretMissile.h"
#include <list>

using namespace ci;

class MissileController
{
public:
MissileController();
void update();
void draw();
void addMissiles(int);
void removeMissiles(int);
void addTurretMissile (int, Vec2f, Vec2f);
void removeTurretMissile (int);
    
std::list <Missile> _Missile;
std::list <TurretMissile> _TurretMissile;
    
    bool collisionDetection(int radius, Vec2f turretMissileLoc, Vec2f missileLoc);
};


#endif
