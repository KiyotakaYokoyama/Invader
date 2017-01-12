#include "CharacterMgr.h"
#include "Enemy.h"

const int MAX_ENEMY_NUM = 2;
const int PLAYER_START_POS_X = SCREEN_WIDTH * RATIO / 2;
const int PLAYER_START_POS_Y = ( SCREEN_HEIGHT - 100 ) * RATIO;

CharacterMgr::CharacterMgr( ) {
	_player = PlayerPtr( new Player( PLAYER_START_POS_X, PLAYER_START_POS_Y ) );
	_characters.push_back( CharacterPtr( _player ) );

	initEnemys( );
}

CharacterMgr::~CharacterMgr( ) {
}

void CharacterMgr::update( ) {
	std::list< CharacterPtr >::iterator ite = _characters.begin( );
	while ( ite != _characters.end( ) ) {
		(*ite)->update( );
		ite++;
	}
}

void CharacterMgr::draw( WriterConstPtr drawer ) {
	std::list< CharacterPtr >::iterator ite = _characters.begin( );
	while ( ite != _characters.end( ) ) {
		(*ite)->draw( drawer );
		ite++;
	}
}

void CharacterMgr::initEnemys( ) {
	for ( int i = 0; i < MAX_ENEMY_NUM; i++ ) {
		int pos = ( i + 1 ) * 100;
		_characters.push_back( CharacterPtr( new Enemy( pos , pos ) ) );
	}
}

int CharacterMgr::getCharacterSize( ) {
	return _characters.size( );
}

CharacterPtr CharacterMgr::getCharacter( int idx ) {
	CharacterPtr result = CharacterPtr( );
	std::list< CharacterPtr >::iterator ite = _characters.begin( );

	for ( int i = 0; i <= idx; i++, ite++ ) {
		if ( ite == _characters.end( ) ) {
			break;
		}
		result = (*ite);
	}


	return result;
}