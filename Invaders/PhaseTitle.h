#pragma once

#include "Phase.h"

class PhaseTitle : public Phase {
public:
	PhaseTitle( );
	virtual ~PhaseTitle( );
private:
	NEXT update( );
};
