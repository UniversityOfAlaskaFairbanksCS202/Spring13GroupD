#include"ScoringEngine.h"

int ScoringEngine::_score = 0; //Sets all of our default values
int ScoringEngine::_level=1;
int ScoringEngine::_difficulty=0;
float ScoringEngine::_sVelocity=0;
int ScoringEngine::_missiles=0;
std::string ScoringEngine::endingscore ="0";


ScoringEngine::ScoringEngine(){} //Does nothing by default (See what I did there hahahahaha)



int ScoringEngine::getMissiles() //Lets the world know how many missiles to launch.
{
return _missiles;
}

ScoringEngine::ScoringEngine(int choice) //It's given the int choice and converts that into the difficulty level thats desired.
										 //It also sets all the values for the difficulty level.
{
_difficulty = choice;

		switch (choice) // sets the starting value for missile velocity and number of missiles for level 1 as per the difficulty passed
		{
			case 1: // easy difficulty
			{ 
				_sVelocity = 1.0f;
				_difficulty = 1;
				_missiles = 10;
				break;
			}



			case 2: // Intermediate Difficulty
			{
				_sVelocity = 1.3f;
				_difficulty = 2;
				_missiles = 15;
				break;
			}



			case 3: //Expert Difficulty
			{ 
				_sVelocity = 1.6f;
				_difficulty = 3;
				_missiles = 20;
				break;
			}



			case 4: // The infamous Brandon Difficulty
			{ 
				_sVelocity = 8.0f;
				_difficulty = 4;
				_missiles = 78;
			break;
			}
	} 
}



float ScoringEngine::getVelocity() //Lets the missile know how fast to go
{
return _sVelocity;
}

int ScoringEngine::getLevel() //Lets the game know what level you're on.
{
	return _level;
}

void ScoringEngine::updateScore() //Updates the score. It has to convert it into a string to it can be displayed in draw.
{
_score += 50;
convert<<_score;
endingscore = convert.str();
}


void ScoringEngine::updateLevel() //Makes the game funner(harder) every time you go up another level.
{
++_level;
updateVelocity(); // increases the velocity as per the dicciulty chosen 
updateMissiles(); // adds more missiles to the list as per difficulty selected 

}


void ScoringEngine::updateVelocity() //CHanges the velocity every level.
{
switch(_difficulty)
{
case 1: { _sVelocity += 0.1f; // increase velocity by 0.1 every level
break;
}

case 2: { _sVelocity += 0.3f; // increases velocity by 0.3 every level
break;
}

case 3: { _sVelocity += 0.6f; // increases velocity by 0.6 every level
break;
}

case 4: { _sVelocity += 5.0f; // increases velocity by 5 every level
break;
}
}
}


void ScoringEngine::updateMissiles() //CHanges the number of missiles every level.
{
	switch(_difficulty)
	{
	case 1: _missiles += 5; // adds 5 missiles every new level
		break;
	case 2: _missiles += 10; // adds 10 missiles every new level
		break;
	case 3: _missiles += 15; // adds 15 missiles every new level
		break;
	case 4: _missiles += 100; // adds 100 missiles every new level
		break;
	}
}
