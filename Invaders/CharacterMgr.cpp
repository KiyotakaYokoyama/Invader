#include "CharacterMgr.h"
#include "Player.h"
#include "Enemy.h"
#include "defin.h"

const int MAX_ENEMY_WEDTH_NUM = 2;
const int MAX_ENEMY_HEIGHT_NUM = 2;

CharacterMgr::CharacterMgr( BulletMgrPtr bullet_mgr ) {
	for ( int i = 0; i < MAX_ENEMY_WEDTH_NUM; i++ ) {
		for ( int j = 0; j < MAX_ENEMY_HEIGHT_NUM; j++ ) {
			int pos_x = ( i * CHARA_WIDTH + CHARA_WIDTH / 2 ) * RATIO;
			int pos_y = ( j * CHARA_HEIGHT + CHARA_HEIGHT ) * RATIO;
			_enemys.push_back( CharacterPtr( new Enemy( pos_x, pos_y, bullet_mgr ) ) );
		}
	}
}

CharacterMgr::~CharacterMgr( ) {
}

void CharacterMgr::update( ) {
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );
	unsigned int init = 0;
	while ( ite != _enemys.end( ) ) {
		if ( (*ite)->isDead( ) ) {
			init++;
		}
		ite++;
	}
	if ( !( init < _enemys.size( ) ) ) {
		initEnemys( );
		return;
	}

	ite = _enemys.begin( );

	if ( outofScreen( ) ) {
		while ( ite != _enemys.end( ) ) {
			(*ite)->toApproach( );
			ite++;
		}
		ite = _enemys.begin( );
	}

	while ( ite != _enemys.end( ) ) {
		if ( !(*ite)->isDead( ) ) {
			(*ite)->update( _enemys );
		}
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

void CharacterMgr::initEnemys( ) {
	auto ite = _enemys.begin( );
	for ( int i = 0; i < MAX_ENEMY_WEDTH_NUM; i++ ) {
		for ( int j = 0; j < MAX_ENEMY_HEIGHT_NUM; j++ ) {
			int pos_x = ( i * CHARA_WIDTH + CHARA_WIDTH / 2 ) * RATIO;
			int pos_y = ( j * CHARA_HEIGHT + CHARA_HEIGHT ) * RATIO;
			(*ite)->initPos( pos_x, pos_y );
			ite++;
		}
	}
}

bool CharacterMgr::outofScreen( ) {
	bool result = false;

	auto ite = _enemys.begin( );
	while( ite != _enemys.end( ) ) {
		if ( (*ite)->getRatioY( ) < -50 ) {
			(*ite)->setDead( true );
			ite++;
			continue;
		}

		int ratio_x = (*ite)->getRatioX( ) + (*ite)->getMoveSpeed( );
		int screen_r = ( SCREEN_WIDTH - CHARA_WIDTH / 2 ) * RATIO;
		int screen_l = ( CHARA_WIDTH / 2 ) * RATIO;

		if ( ratio_x < screen_l || ratio_x > screen_r ) {
			result = true;
			break;
		}
		ite++;
	}

	return result;
}
