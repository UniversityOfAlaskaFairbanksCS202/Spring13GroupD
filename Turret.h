// Turret Class //
// position will be 275, 400 //
// contains all parts and missile functions: //
// draws base //
// draws cannon //
// on Mouse click creates missile with direction and velocity. //

#include <MouseEvent.h>

#ifndef TURRET_H
#define TURRET_H
class Turret {
public:
// CLASS VARIABLES //
  ci::Vec2f _recPos( 275, 410 ); 
	ci::Vec2f _recSize();		   
	
	
// CLASS FUNCTIONS //
	void draw();
	void update();
	void mouseDown( MouseEvent );	
	void fireMissile( Vec2f, );
	
};

#endif
