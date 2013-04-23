#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "MissileController.h"
#include "Missile.h"

using namespace ci;
using std::list;
using namespace ci::app;

MissileController::MissileController()
{
}

void MissileController::update()
{
    for( list<Missile>::iterator p = _TurretMissile.begin(); p != _TurretMissile.end(); ++p)
    {
        if(!(p->_health))
        {
            p = _Missile.erase(p);
        }
        else
            p->update();
    }
    for( list<TurretMissile>::iterator p = _TurretMissile.begin(); p != _TurretMissile.end(); ++p)
    {
        if(!(p->_health))
        {
            p = _TurretMissile.erase(p);
        }
        else
            p->update();
    }
}

void MissileController::draw()
{
    for( list<Missile>::iterator p = _Missile.begin(); p != _Missile.end(); ++p)
    {
        p->draw();
    }
    for( list<TurretMissile>::iterator p = _TurretMissile.begin(); p != _TurretMissile.end(); ++p)
    {
        p->draw();
    }
}

void MissileController::addMissiles(int numMissiles)
{
	for( int i = 0; i< numMissiles; i++)
	{
		_Missile.push_back ( Missile());
	}
	for( int i = 0; i< numMissiles; i++)
	{
		_TurretMissile.push_back ( TurretMissile());
	}
}

void MissileController::removeMissiles( int numMissiles)
{
	for ( int i = 0; i < numMissiles; i++)
	{
		_Missile.pop_back();
	}
	for ( int i = 0; i < numMissiles; i++)
	{
		_TurretMissile.pop_back();
	}
}

