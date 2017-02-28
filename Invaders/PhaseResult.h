#pragma once

#include "Phase.h"
#include "smart_ptr.h"

PTR( Score );

class PhaseResult : public Phase {
public:
	PhaseResult( ScorePtr score );
	virtual ~PhaseResult( );
private:
	NEXT update( );
	ScorePtr _score;
};
