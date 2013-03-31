#include "Missile.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "MissileController.h"

using namespace ci;



Missile::Missile()
{
	Rand pos;
	_Loc = Vec2f (0,pos.nextFloat());
	_Dir = Rand::randVec2f(); // random direction is just a placeholder till i get the direction function written
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

void Missile::collisionDetection(MissileController &lhs)
{
	/* created a vector object for each building,though i am worried this approach will lead to a out of memory error if the game is played too long
	   (if someone can come up with a logic using dyanmic allocation,feel free to change it (PS: Group D only :D))*/
	
	Vec2f building_1(10.0f, 350.0f);
	Vec2f building_2(150.0f, 350.0f);
	Vec2f building_3(400.0f,350.0f);
	Vec2f building_4(540.0f, 350.0f);

	
	// If the location of any missile object equals the location of any building then remove one missile
	
	if (_Loc == building_1 || _Loc == building_2 || _Loc == building_3 || _Loc == building_3)
	{
		lhs.removeMissiles (1); // function defined in MissileController.cpp

		//Placeholder for building health reduction function
	}
}





