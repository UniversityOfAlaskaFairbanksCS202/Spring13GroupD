#include"ScoringEngine.h"

int ScoringEngine::_score = 0;
int ScoringEngine::_level=1;
int ScoringEngine::_difficulty=0;
float ScoringEngine::_sVelocity=0;
int ScoringEngine::_missiles=0;

ScoringEngine::ScoringEngine(){}

/*ScoringEngine::ScoringEngine(int choice)
{
_level = choice;
}*/


int ScoringEngine::getMissiles()
{
return _missiles;
}

ScoringEngine::ScoringEngine(int choice)
{
_level = choice;

		switch (choice)
		{
			case 1: 
			{ 
				_sVelocity = 1.0f;
				_difficulty = 1;
				_missiles = 10;
				break;
			}



			case 2: 
			{
				_sVelocity = 1.3f;
				_difficulty = 2;
				_missiles = 15;
				break;
			}



			case 3: 
			{ 
				_sVelocity = 1.6f;
				_difficulty = 3;
				_missiles = 20;
				break;
			}



			case 4: 
			{ 
				_sVelocity = 8.0f;
				_difficulty = 4;
				_missiles = 78;
			break;
			}
	} 
}



float ScoringEngine::getVelocity()
{
return _sVelocity;
}


void ScoringEngine::updateScore()
{
_score += 50;
convert<<_score;
endingscore = convert.str();
}


void ScoringEngine::updateLevel()
{
++_level;
updateVelocity();
}


void ScoringEngine::updateVelocity()
{
switch(_difficulty)
{
case '1': { _sVelocity += 0.1f;
break;
}

case '2': { _sVelocity += 0.3f;
break;
}

case '3': { _sVelocity += 0.6f;
break;
}

case '4': { _sVelocity += 5.0f;
break;
}
}
}
