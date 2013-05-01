#ifndef SCORING_ENGINE_H_INCLUDED
#define SCORING_ENGINE_H_INCLUDED

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

class ScoringEngine
{
public:
  ScoringEngine();
ScoringEngine( int );
void updateScore ();
//void setVelocity(int);
void updateVelocity();
float getVelocity();
void updateLevel();
int getMissiles();

static int _level;
static int _score;
static float _sVelocity;
static int _difficulty;
static int _missiles;
std::ostringstream convert;
std::string endingscore;
};


#endif
