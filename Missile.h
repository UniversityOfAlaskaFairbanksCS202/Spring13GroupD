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
	Missile( ci::Vec2f,float);
	void update();
	void draw();

	ci::Vec2f	mdir;
	ci::Vec2f	mloc;

	float		mvel;

};

#endif
