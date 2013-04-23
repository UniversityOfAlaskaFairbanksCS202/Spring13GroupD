#ifndef TURRETMISSILE_H
#define TURRETMISSILE_H
class TurretMissile
{
public:
  	ci::Vec2f _mLocation;
	ci::Vec2f _cursorLoc;
	ci::Vec2f _mPath;
	float _velocity;
	float _radius;
	bool _health;
	
	ci::Vec2f _missileStartHolder;

	TurretMissile(Vec2f, Vec2f);
	
	void update();
	void draw();
	bool collisionDetection();

};

#endif
