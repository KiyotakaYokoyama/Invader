#include "CharacterMgr.h"
#include "Player.h"
#include "Enemy.h"
#include "defin.h"

const int MAX_ENEMY_WEDTH_NUM = 1;
const int MAX_ENEMY_HEIGHT_NUM = 1;

CharacterMgr::CharacterMgr( ) {	
	for ( int i = 0; i < MAX_ENEMY_WEDTH_NUM; i++ ) {
		for ( int j = 0; j < MAX_ENEMY_HEIGHT_NUM; j++ ) {
			int pos_x = ( i * CHARA_WIDTH + CHARA_WIDTH / 2 ) * RATIO;
			int pos_y = ( j * CHARA_HEIGHT + CHARA_HEIGHT ) * RATIO;
			_enemys.push_back( CharacterPtr( new Enemy( pos_x, pos_y ) ) );
		}
	}
}

CharacterMgr::~CharacterMgr( ) {
}

void CharacterMgr::update( ) {
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );
	while ( ite != _enemys.end( ) ) {
		(*ite)->update( _enemys );
		ite++;
	}
}

void CharacterMgr::draw( ) {
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );
	while ( ite != _enemys.end( ) ) {
		(*ite)->draw( );
		ite++;
	}
}

void CharacterMgr::initEnemys( ) {
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );
	for ( unsigned int i = 0; i < _enemys.size( ); i++ ) {
		int pos_x = ( ( ( i / MAX_ENEMY_WEDTH_NUM ) * CHARA_WIDTH ) + CHARA_WIDTH / 2 ) * RATIO;
		int pos_y = ( ( ( i % MAX_ENEMY_HEIGHT_NUM ) * CHARA_HEIGHT ) + CHARA_HEIGHT ) * RATIO;
		(*ite)->initEnemy( pos_x, pos_y );
	}
}

int CharacterMgr::getEnemySize( ) const {
	return _enemys.size( );
}

std::list<CharacterPtr> CharacterMgr::getEnemys( ) const {
	return _enemys;
}

CharacterPtr CharacterMgr::getEnemys( int idx ) {
	CharacterPtr result = CharacterPtr( );
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );

	for ( int i = 0; i <= idx; i++, ite++ ) {
		result = (*ite);
	}
	
	return result;
}