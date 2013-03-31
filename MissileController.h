#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED

#include "Missile.h"
#include<list>

class MissileController
{
public:
	MissileController();
	void update();
	void draw();
	void addMissiles(int);
	void removeMissiles(int);

	std::list<Missile> _Missiles;
};


#endif