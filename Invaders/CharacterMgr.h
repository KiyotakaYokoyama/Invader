#pragma once

#include "smart_ptr.h"
#include "Defin.h"
#include <list>

PTR( Character );
PTR( BulletMgr );

class CharacterMgr {
public:
	CharacterMgr( BulletMgrPtr bullet_mgr );
	virtual ~CharacterMgr( );
	void update( );
	void draw( );
	int getEnemySize( ) const;
	std::list<CharacterPtr> getEnemys( ) const;
	CharacterPtr getEnemys( int idx );
private:
	void initEnemys( );
	bool outofScreen( );
private:
	std::list< CharacterPtr > _enemys;
};
