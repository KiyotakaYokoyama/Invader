#include "Enemy.h"
#include "Defin.h"

static const int PROBABILITY_RATIO = 1000;
static const int PROBABILITY = 5;

Enemy::Enemy( int x, int y ) :
Character( GRAPHIC_ENEMY, x, y ) {
	setMoveSpeed( MOVE_SPEED );
}

Enemy::~Enemy( ) {
}

void Enemy::actionMove( ) {
}

void Enemy::actionShoot( ) {
	_count++;
	setShooting( false );

	if ( rand( ) % PROBABILITY_RATIO < PROBABILITY ) {
		setShooting( true );
	}
}

void Enemy::toApproach( ) {
	const int APPROACH_LENGH = 10 * RATIO;
	setRatioY( getRatioY( ) + APPROACH_LENGH );
}

void Enemy::hitLeft( ) {
	setMoveSpeed( MOVE_SPEED );
	toApproach( );
}

void Enemy::hitRight( ) {
	setMoveSpeed( -MOVE_SPEED );
	toApproach( );
}

void Enemy::initEnemy( int x, int y ) {
	setRatioX( x );
	setRatioY( y );
}

void Enemy::hitEnemy( std::list< CharacterPtr > enemys ) {
	std::list< CharacterPtr >::iterator ite = enemys.begin( );
	while ( ite != enemys.end( ) ) {
		if ( (*ite) == shared_from_this( ) ) {
			ite++;
			continue;
		}

		CharacterPtr target = (*ite);
		// ‰E‚É‚Ô‚Â‚©‚Á‚½
		int ratio_x = getRatioX( ) + ( CHARA_WIDTH * RATIO / 2 );
		if ( isOverlapped( target, ratio_x, getRatioY( ) - ( CHARA_HEIGHT * RATIO ) ) ||
			 isOverlapped( target, ratio_x, getRatioY( ) ) ) {
			hitRight( );
			target->hitLeft( );
			return;
		}
		// ¶‚É‚Ô‚Â‚©‚Á‚½
		ratio_x = getRatioX( ) - ( CHARA_WIDTH * RATIO / 2 );
		if ( isOverlapped( target, ratio_x, getRatioY( ) - ( CHARA_HEIGHT * RATIO ) ) ||
			 isOverlapped( target, ratio_x, getRatioY( ) ) ) {
			hitLeft( );
			target->hitRight( );
			return;
		}
		ite++;
	}
}