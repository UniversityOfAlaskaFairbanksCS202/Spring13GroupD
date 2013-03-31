#pragma once

#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "MissileController.h"

#include <vector>

class Missile
{
	int _health;
public:
	Missile();
	void update();
	void draw();
	void collisionDetection(MissileController &);
	ci::Vec2f	_Dir;
	ci::Vec2f	_Loc;

	float		_Vel;

	float _Radius;

	

};


