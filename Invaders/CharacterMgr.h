#pragma once

#include "smart_ptr.h"
#include "Defin.h"
#include <list>

PTR( Character );

class CharacterMgr {
public:
	CharacterMgr( );
	virtual ~CharacterMgr( );
	void update( );
	void draw( );
	int getEnemySize( ) const;
	std::list<CharacterPtr> getEnemys( ) const;
	CharacterPtr getEnemys( int idx );
private:
	bool outofScreen( );
private:
	std::list< CharacterPtr > _enemys;
};
