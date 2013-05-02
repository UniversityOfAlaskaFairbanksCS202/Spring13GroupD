#ifndef MISSILECONTROLLER_H
#define MISSILECONTROLLER_H


#include "cinder/Channel.h"
#include "Missile.h"
#include "TurretMissile.h"
#include <list>

using namespace ci;

class MissileController
{
public:
	MissileController(); //Default ctor
	void update(); //Checks on the missiles status whenever called throughout the game.
	void draw(); //Draws the missiles and explosions
	void addMissiles(int); // Adds Missiles
	void removeMissiles(int); //Removes Missiles When destroyed
	void addTurretMissile (int, Vec2f, Vec2f); //Add turret Missiles to the screen
	void removeTurretMissile (int); //Removes turret missiles
    
	std::list <Missile> _Missile; //Creates the list of Missiles
	std::list <TurretMissile> _TurretMissile; //Creates the list of turret Missiles
    
   bool collisionDetection(int radius, Vec2f turretMissileLoc, Vec2f missileLoc); //Collision detection for Missiles and Turret Missiles
};


#endif
