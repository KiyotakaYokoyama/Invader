#pragma once

#include "smart_ptr.h"
#include "Phase.h"

PTR( Player );
PTR( CharacterMgr );
PTR( BulletMgr );

class PhaseStage : public Phase {
public:
	PhaseStage( );
	virtual ~PhaseStage( );
private:
	enum STATE {
		STATE_NORMAL,
		STATE_WAIT,
	};
private:
	NEXT update( );
	void act( );
	void wait( );
	void draw( );
	void debugDraw( );
private:
	int _wait_count;
	STATE _state;
	PlayerPtr _player;
	CharacterMgrPtr _character_mgr;
	BulletMgrPtr _bullet_mgr;
};
