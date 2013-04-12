#ifndef TURRETMISSILE_H
#define TURRETMISSILE_H
class TurretMissile
{
public:
  ci::Vec2f _location;
	ci::Vec2f _dirToCursor;
	ci::Vec2f _mPath;
	float _velocity;
	float _radius;
	bool _health;

	TurretMissile(Vec2f, Vec2f);
	
	void update();
	void draw();
	bool collisionDetection();
	
	void mouseMove( MouseEvent );	
	void mouseDrag( MouseEvent )
	void mouseDown( MouseEvent );	
};

#endif
