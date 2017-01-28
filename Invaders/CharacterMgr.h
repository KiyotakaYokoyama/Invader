#pragma once

#include "smart_ptr.h"
#include <list>
#include "Character.h"
#include "Player.h"
#include "Writer.h"

PTR( CharacterMgr );
PTR( Character );

class CharacterMgr {
public:
	CharacterMgr( );
	virtual ~CharacterMgr( );
	void update( );
	void draw( WriterConstPtr drawer );
	int getEnemySize( ) const;
	CharacterPtr getPlayer( ) const;
	std::list<CharacterPtr> getEnemys( ) const;
	CharacterPtr getEnemys( int idx );
private:
	void initEnemys( );
private:
	CharacterPtr _player;
	std::list< CharacterPtr > _enemys;
};
