#include "Missile.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Missile::Missile()
{
}

Missile::Missile(Vec2f Loc)
{
	Rand pos;
	_Loc = Vec2f (0,pos.nextFloat());
	_Dir = Rand::randVec2f();
	_Vel = pos.randFloat();
	_Radius = 3.0f;
}

void Missile::update()
{
	_Loc += _Dir * _Vel;
}

void Missile::draw()
{
	gl::drawSolidCircle ( _Loc, _Radius);
}


