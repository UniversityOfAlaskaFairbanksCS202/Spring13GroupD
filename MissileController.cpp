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
        
        if (_Missile.size() == 0)
    		return;
    
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
        
        if (_TurretMissile.size() == 0)
			return;
    }
    
    for( list<TurretMissile>::iterator Q = _TurretMissile.begin(); Q != _TurretMissile.end(); ++Q)
    {
        if(Q->_velocity == 0.0)
        {
            for( list<Missile>::iterator p = _Missile.begin(); p != _Missile.end(); ++p)
            {
                if (collisionDetection(Q->_radius, Q->_location, p->_location) && p->_velocity != 0.0) //Changed this
                {
                    p = _Missile.erase(p);
					
					if (_Missile.size() == 0)
						return;
                }
            }
        }
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

void MissileController::addTurretMissile(int numMissiles, Vec2f mousePos, Vec2f startHolder)
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

bool MissileController::collisionDetection(int radius, Vec2f turretMissileLoc, Vec2f missileLoc)
{
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
    
    left1 = static_cast<int>(turretMissileLoc.x) - radius;
    left2 = static_cast<int>(missileLoc.x);
    right1 = static_cast<int>(turretMissileLoc.x) + radius;
    right2 = static_cast<int>(missileLoc.x);
    top1 = static_cast<int>(turretMissileLoc.y) - radius;
    top2 = static_cast<int>(missileLoc.y);
    bottom1 = static_cast<int>(turretMissileLoc.y) + radius;
    bottom2 = static_cast<int>(missileLoc.y);
    
    if (bottom1 < top2)
        return(false);
    if (top1 > bottom2)
        return(false);
    
    if (right1 < left2)
        return(false);
    if (left1 > right2)
        return(false);
    
    return(true);
}

