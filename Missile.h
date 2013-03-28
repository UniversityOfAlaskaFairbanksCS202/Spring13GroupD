#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED

#include "cinder/Channel.h"
#include "cinder/Vector.h"

#include <vector>

class Missile
{
	int _health;
public:
	Missile();
	Missile( ci::Vec2f);
	void update();
	void draw();

	ci::Vec2f	_Dir;
	ci::Vec2f	_Loc;

	float		_Vel;

	float _Radius;

};

#endif
