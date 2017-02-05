#pragma once

#include "Task.h"
#include "smart_ptr.h"
#include "Phase.h"
#include <string>

PTR( Game );
PTR( Phase );

class Game : public Task {
public:
	Game( );
	virtual ~Game( );
	static std::string getTag( ) { return "GAME"; }
	static GamePtr getTask( );
	void initialize( );
	void update( );
private:
	void changeScene( );
private:
	PhasePtr _phase;
	Phase::NEXT _next;
};

