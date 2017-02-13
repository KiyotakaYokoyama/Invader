#include "Enemy.h"
#include "Defin.h"

static const int PROBABILITY = 1000;

Enemy::Enemy( int x, int y ) :
Character( GRAPHIC_ENEMY, x, y ),
_move_speed( MOVE_SPEED ) {
	setMoveSpeed( _move_speed );
}

Enemy::~Enemy( ) {
}

void Enemy::action( ) {
	actionMove( );
	actionShoot( );
}

void Enemy::actionMove( ) {
}

void Enemy::actionShoot( ) {
	setShooting( false );

	if ( rand( ) % PROBABILITY == 0  ) {
		setShooting( true );
	}
}

void Enemy::toApproach( ) {
	const int APPROACH_LENGH = 10 * RATIO;
	setRatioY( getRatioY( ) + APPROACH_LENGH );

	_move_speed *= -1;
	setMoveSpeed( _move_speed );
}

void Enemy::hitEnemy( std::list< CharacterPtr > enemys ) {
//	std::list< CharacterPtr >::iterator ite = enemys.begin( );
//	while ( ite != enemys.end( ) ) {
//		if ( (*ite) == shared_from_this( ) ) {
//			ite++;
//			continue;
//		}
//
//		CharacterPtr target = (*ite);
//		// 右にぶつかった
//		int ratio_x = getRatioX( ) + ( CHARA_WIDTH * RATIO / 2 );
//		if ( isOverlapped( target, ratio_x, getRatioY( ) - ( CHARA_HEIGHT * RATIO ) ) ||
//			 isOverlapped( target, ratio_x, getRatioY( ) ) ) {
//			return;
//		}
//		// 左にぶつかった
//		ratio_x = getRatioX( ) - ( CHARA_WIDTH * RATIO / 2 );
//		if ( isOverlapped( target, ratio_x, getRatioY( ) - ( CHARA_HEIGHT * RATIO ) ) ||
//			 isOverlapped( target, ratio_x, getRatioY( ) ) ) {
//			return;
//		}
//		ite++;
//	}
}

void Enemy::hitBullet( ) {
	setRatioX( -100 );
	setRatioY( -100 );
	setDead( true );
}
