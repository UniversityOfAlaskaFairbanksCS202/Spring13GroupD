#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "MissileController.h"
#include "Missile.h"

using namespace ci;
using std::list;
using namespace ci::app;

MissileController::MissileController()
{
	
	_Missiles.push_back( Missile());
}

void MissileController::addMissiles(int numMissiles)
{
	for( int i = 0; i< numMissiles; i++)
	{
		_Missiles.push_back ( Missile());
	}
}

void MissileController::removeMissiles( int numMissiles)
{
	for ( int i = 0; i < numMissiles; i++)
	{
		_Missiles.pop_back();
	}
}

