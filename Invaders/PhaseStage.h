#pragma once

#include "smart_ptr.h"
#include "Phase.h"

PTR( Player );
PTR( EnemyMgr );
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
	void gameover( );
	void wait( );
	void draw( );
	void debugDraw( );
private:
	int _wait_count;
	STATE _state;
	PlayerPtr _player;
	EnemyMgrPtr _enemy_mgr;
	BulletMgrPtr _bullet_mgr;
};
