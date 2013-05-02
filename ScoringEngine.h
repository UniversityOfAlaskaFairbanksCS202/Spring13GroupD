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
void updateVelocity();
float getVelocity();
void updateLevel();
int getLevel();
void updateMissiles();
int getMissiles();
std::stringstream convert;
static std::string endingscore;
;


private:
static int _level;
static int _score;
static float _sVelocity;
static int _difficulty;
static int _missiles;

};


#endif
