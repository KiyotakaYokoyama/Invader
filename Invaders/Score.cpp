#include "Score.h"

Score::Score( ) :
_score( 0 ) {
}

Score::~Score( ) {
}

void Score::reset( ) {
	_score = 0;
}

void Score::add( int score ) {
	_score += score;
}

int Score::getScore( ) const {
	return _score;
}