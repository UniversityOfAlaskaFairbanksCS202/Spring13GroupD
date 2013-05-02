/* University of Alaska, Fairbanks 
   CS-202 Group D
   Spring 2013
*/

/* This code is released under the standard GNU license, you may clone this repository and release your own version
   without any author credits
*/

/* This source file handles the list of missiles and turret missiles and also checks for if a missile is hit*/

/* Basic Cinder includes*/

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"

/* Custom header includes*/
#include "MissileController.h"
#include "Missile.h"
#include "TurretMissile.h"
#include "ScoringEngine.h"


using namespace ci; // cinder namescape
using std::list;
using namespace ci::app; // cinder appplication namespace

/* default constructor for missile controller,does nothing*/

MissileController::MissileController()
{
}

/* Updates the missile and turretmissile lists once every frame*/

void MissileController::update()
{
    for( list<Missile>::iterator p = _Missile.begin(); p != _Missile.end(); ++p)
    {
        if(!(p->_health)) // checks if missile health is false (missile has either hit a building or hit with turretmissile)
        {
            p = _Missile.erase(p); // erases the missile
            
        }
        else
        {
            if (_Missile.size()!=0) //checks if the list is not empty
            {
                p->update(); // runs through the update function again
            }
        }
        
        if (_Missile.size() == 0) // Bug fix for out of range error once last miisle was destroyed
     return; // exits the uodate function 
    
    }
    
    for( list<TurretMissile>::iterator Q = _TurretMissile.begin(); Q != _TurretMissile.end(); ++Q) // iterates through the list of turrretmissiles
    {
        if(!(Q->_health)) // Checks if health is false (Turret missile has hit a missile or has gone out of playable area)
        {
            Q = _TurretMissile.erase(Q); // if health is false, erase turretmissile at position Q
            
        }
        else
        {
            if (_TurretMissile.size()>0) // is list size is greater than 0, run through update again
            {
                Q->update();
            }

            else
            {
                _TurretMissile.erase(Q);
            }
        }
        
        if (_TurretMissile.size() == 0) // bug fix for last turretmissile out of range 
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
                    ScoringEngine player;
                    p = _Missile.erase(p);
                    player.updateScore(); // if a missile is destroyed, score is increased

if (_Missile.size() == 0 || _TurretMissile.size())
return;
                }
            }
        }
    }
    
}


/* Draws the missiles and turretmissiles every frame */


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

/* Takes an int as a parameter and adds an equal number of missile to the missile list*/

void MissileController::addMissiles(int numMissiles)
{
for( int i = 0; i< numMissiles; ++i)
{
        _Missile.push_back ( Missile());
}
}

/* Takes an int as a parameter and adds an equal number of turretrmissiles to the turretmissiles list*/

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
