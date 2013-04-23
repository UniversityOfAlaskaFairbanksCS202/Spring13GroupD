#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED


#include "cinder/Channel.h"
#include "Missile.h"
#include "TurretMissile.h"
#include <list>


class MissileController
{
public:
	friend class TurretMissile;
	MissileController();
	void update();
	void draw();
	void addMissiles(int);
	void removeMissiles(int);
	void addTurretMissile (int);
	//void removeTurretMissile (int);

	std::list <Missile> _Missile;
	std::list <TurretMissile> _TurretMissile;
};


#endif
