#pragma once

#include "Phase.h"

class PhaseResult : public Phase {
public:
	PhaseResult( );
	virtual ~PhaseResult( );
private:
	NEXT update( );
};
