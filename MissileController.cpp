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
    for( list<Missile>::iterator p = _Missile.begin(); p != _Missile.end(); ++p)
    {
        if(!(p->_health))
        {
            p = _Missile.erase(p);

        }
        else
{
if (_Missile.size()>0)
{
p->update();
}

else
{
_Missile.erase(p);
}
}

if (_Missile.size() == 0)
return;
    }

}


void MissileController::draw()
{
    for( list<Missile>::iterator p = _Missile.begin(); p != _Missile.end(); ++p)
    {
        if (_Missile.size()>0)
p->draw();

    }
    
}

void MissileController::addMissiles(int numMissiles)
{
for( int i = 0; i< numMissiles; ++i)
{
_Missile.push_back ( Missile());
}

/*for( int i = 0; i< numMissiles; ++i)
{
_TurretMissile.push_back ( TurretMissile());
}*/
}

