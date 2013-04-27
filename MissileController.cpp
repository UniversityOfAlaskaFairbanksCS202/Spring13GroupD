#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"

#include "MissileController.h"
#include "Missile.h"
#include "TurretMissile.h"


using namespace ci;
using std::list;
using namespace ci::app;

MissileController::MissileController()
{
}

void MissileController::update()
{
    for( list<Missile>::iterator p = _Missile.begin(); p != _Missile.end(); ++p)
    {
        if(!(p->_health))
        {
            p = _Missile.erase(p);
            
        }
        else
        {
            if (_Missile.size()!=0)
            {
                p->update();
            }
        }
        
        /*if (_Missile.size() == 0)
			return;*/
    
    }
    
    for( list<TurretMissile>::iterator Q = _TurretMissile.begin(); Q != _TurretMissile.end(); ++Q)
    {
        if(!(Q->_health))
        {
            Q = _TurretMissile.erase(Q);
            
        }
        else
        {
            if (_TurretMissile.size()>0)
            {
                Q->update();
            }
			
            else
            {
                _TurretMissile.erase(Q);
            }
        }
        
        /*if (_TurretMissile.size() == 0)
			return;*/
    }
    
}


void MissileController::draw()
{
    for( list<Missile>::iterator p = _Missile.begin(); p != _Missile.end(); ++p)
    {
        p->draw();
        
    }
    
    for( list<TurretMissile>::iterator Q = _TurretMissile.begin(); Q != _TurretMissile.end(); ++Q)
    {
        Q->draw();
        
    }
}

void MissileController::addMissiles(int numMissiles)
{
	for( int i = 0; i< numMissiles; ++i)
	{
        _Missile.push_back ( Missile());
	}
}

void MissileController::addTurretMissile(int numMissiles, ci::Vec2f mousePos, ci::Vec2f startHolder)
{
    for( int i = 0; i< numMissiles; ++i)
	{
       _TurretMissile.push_back ( TurretMissile(mousePos, startHolder));
	}
}

void MissileController::removeMissiles( int numMissiles)
{
    for( int i = 0; i< numMissiles; ++i)
    {
        _Missile.pop_back();
    }
}

void MissileController::removeTurretMissile(int numMissiles)
{
    for( int i = 0; i< numMissiles; ++i)
    {
        _TurretMissile.pop_back();
    }
}


