#pragma once

#include "smart_ptr.h"
#include <list>
#include "Character.h"
#include "Player.h"
#include "Writer.h"

PTR( CharacterMgr );

class CharacterMgr {
public:
	CharacterMgr( );
	virtual ~CharacterMgr( );
	void update( );
	void draw( WriterConstPtr drawer );
	int getCharacterSize( );
	CharacterPtr getCharacter( int idx );
private:
	void initEnemys( );
private:
	PlayerPtr _player;
	std::list< CharacterPtr > _characters;
};
