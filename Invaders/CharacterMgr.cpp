#include "CharacterMgr.h"
#include "Enemy.h"
#include "defin.h"

const int MAX_ENEMY_WEDTH_NUM = 1;
const int MAX_ENEMY_HEIGHT_NUM = 1;
const int PLAYER_START_POS_X = SCREEN_WIDTH * RATIO / 2;
const int PLAYER_START_POS_Y = SCREEN_HEIGHT * RATIO;

CharacterMgr::CharacterMgr( ) {
	_player = CharacterPtr( new Player( PLAYER_START_POS_X, PLAYER_START_POS_Y ) );
	
	for ( int i = 0; i < MAX_ENEMY_WEDTH_NUM * MAX_ENEMY_HEIGHT_NUM; i++ ) {
		int pos_x = ( ( ( i / MAX_ENEMY_WEDTH_NUM ) * CHARA_WIDTH ) + CHARA_WIDTH / 2 ) * RATIO;
		int pos_y = ( ( ( i % MAX_ENEMY_HEIGHT_NUM ) * CHARA_HEIGHT ) + CHARA_HEIGHT ) * RATIO;
		_enemys.push_back( CharacterPtr( new Enemy( pos_x, pos_y ) ) );
	}
}

CharacterMgr::~CharacterMgr( ) {
}

void CharacterMgr::update( ) {
	_player->update( _enemys );
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );
	while ( ite != _enemys.end( ) ) {
		(*ite)->update( _enemys );
		ite++;
	}
}

void CharacterMgr::draw( WriterConstPtr drawer ) {
	_player->draw( drawer );
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );
	while ( ite != _enemys.end( ) ) {
		(*ite)->draw( drawer );
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

CharacterPtr CharacterMgr::getPlayer( ) const {
	return _player;
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