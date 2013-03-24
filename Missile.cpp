#include "Missile.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;

Missile::Missile()
{
}

Missile::Missile(Vec2f Loc, float vel)
{
	mloc=Loc;
	//mdir= getWindowHeight() cant figure out how to get it to go straight down?
	mvel=vel;

