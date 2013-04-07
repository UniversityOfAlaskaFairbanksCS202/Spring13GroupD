#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED

#include "cinder/Channel.h"
#include "Missile.h"
#include <list>

class MissileController
{
public:
	MissileController();
	void update();
	void draw();
	void addMissiles(int);
	void removeMissiles(int);

	std::list <Missile> _Missile;
};


#endif