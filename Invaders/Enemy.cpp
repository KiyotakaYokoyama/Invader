#include "Enemy.h"
#include "Defin.h"

Enemy::Enemy( int x, int y ) :
Character( GRAPHIC_ENEMY, x, y ) {
	setMoveSpeed( MOVE_SPEED );
}

Enemy::~Enemy( ) {
}

void Enemy::actionMove( ) {
}

void Enemy::actionShoot( ) {
}

void Enemy::toApproach( ) {
	const int APPROACH_LENGH = 10 * RATIO;
	setRatioY( getRatioY( ) + APPROACH_LENGH );
}

void Enemy::hitLeft( ) {
	setMoveSpeed( MOVE_SPEED );
	setRatioX( getRatioX( ) + RATIO );
	toApproach( );
}

void Enemy::hitRight( ) {
	setMoveSpeed( -MOVE_SPEED );
	setRatioX( getRatioX( ) - RATIO );
	toApproach( );
}

void Enemy::initEnemy( int x, int y ) {
	setRatioX( x );
	setRatioY( y );
}