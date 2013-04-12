#include "Turret.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
// draws base, cannon //
void Turret::draw()
{
gl::drawOpenCircle(275, 400)

// top side points have their own postion as well as bottom two //
// 
gl::drawSolidRect(_recPos, _recSize);
}
