#ifndef MISSILECONTROLLER_H
#define MISSILECONTROLLER_H


#include "cinder/Channel.h"
#include "Missile.h"
#include "TurretMissile.h"
#include <list>


class MissileController
{
public:
	MissileController();
	void update();
	void draw();
	void addMissiles(int);
	void removeMissiles(int);
	void addTurretMissile (int, ci::Vec2f, ci::Vec2f);
	void removeTurretMissile (int);
    
	std::list <Missile> _Missile;
	std::list <TurretMissile> _TurretMissile;
};


#endif
