#pragma once

#include "smart_ptr.h"
#include "Defin.h"
#include <list>

PTR( Character );
PTR( BulletMgr );

class EnemyMgr {
public:
	EnemyMgr( BulletMgrPtr bullet_mgr );
	virtual ~EnemyMgr( );
	void update( );
	void draw( );
	int getEnemySize( ) const;
	std::list<CharacterPtr> getEnemys( ) const;
private:
	enum STATE {
		STATE_INIT,
		STATE_APPROACH,
		STATE_NORMAL
	};
private:
	void initEnemys( );
	bool outofScreen( );
	STATE checkState( );
private:
	BulletMgrPtr _bullet_mgr;
	std::list< CharacterPtr > _enemys;
};
