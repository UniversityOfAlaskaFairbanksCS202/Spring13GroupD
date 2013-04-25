#pragma once
#ifndef TURRETMISSILE_H
#define TURRETMISSILE_H


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

class TurretMissile
{
public:
ci::Vec2f _mLocation;
ci::Vec2f _cursorLoc;
float _velocity;
float _radius;
bool _health;
int m;


TurretMissile(ci::Vec2f, ci::Vec2f);

void update();
void draw();
bool collisionDetection();
void removeMissile(int);
TurretMissile();

};



#endif
