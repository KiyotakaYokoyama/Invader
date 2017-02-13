#include "EnemyMgr.h"
#include "Player.h"
#include "Enemy.h"
#include "defin.h"

const int MAX_ENEMY_WEDTH_NUM = 2;
const int MAX_ENEMY_HEIGHT_NUM = 2;

EnemyMgr::EnemyMgr( BulletMgrPtr bullet_mgr ) :
_bullet_mgr( bullet_mgr ) {
	initEnemys( );
}

EnemyMgr::~EnemyMgr( ) {
}

void EnemyMgr::update( ) {
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );

	switch( checkState( ) ) {
	case STATE_INIT:
		initEnemys( );
		break;
	case STATE_APPROACH:
		while ( ite != _enemys.end( ) ) {
			(*ite)->toApproach( );
			ite++;
		}
		break;
	case STATE_NORMAL:
		while ( ite != _enemys.end( ) ) {
			if ( (*ite)->isDead( ) ) {
				ite = _enemys.erase( ite );
				if ( ite == _enemys.end( ) ) break;
			} else {
				(*ite)->update( _enemys );
				ite++;
			}
		}
		break;
	}
}

void EnemyMgr::draw( ) {
	std::list< CharacterPtr >::iterator ite = _enemys.begin( );
	while ( ite != _enemys.end( ) ) {
		(*ite)->draw( );
		ite++;
	}
}

int EnemyMgr::getEnemySize( ) const {
	return _enemys.size( );
}

std::list<CharacterPtr> EnemyMgr::getEnemys( ) const {
	return _enemys;
}

void EnemyMgr::initEnemys( ) {
	for ( int i = 0; i < MAX_ENEMY_WEDTH_NUM; i++ ) {
		for ( int j = 0; j < MAX_ENEMY_HEIGHT_NUM; j++ ) {
			int pos_x = ( i * CHARA_WIDTH + CHARA_WIDTH / 2 ) * RATIO;
			int pos_y = ( j * CHARA_HEIGHT + CHARA_HEIGHT ) * RATIO;
			_enemys.push_back( CharacterPtr( new Enemy( pos_x, pos_y, _bullet_mgr ) ) );
		}
	}
}

bool EnemyMgr::outofScreen( ) {
	bool result = false;

	auto ite = _enemys.begin( );
	while( ite != _enemys.end( ) ) {
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

EnemyMgr::STATE EnemyMgr::checkState( ) {
	if ( _enemys.empty( ) ) {
		return STATE_INIT;
	}
		
	if ( outofScreen( ) ) {
		return STATE_APPROACH;
	}

	return STATE_NORMAL;
}