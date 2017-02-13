#include "Enemy.h"
#include "Defin.h"
#include "Bullet.h"
#include "BulletMgr.h"

static const int PROBABILITY = 600;

Enemy::Enemy( int x, int y, BulletMgrPtr bullet_mgr ) :
Character( GRAPHIC_ENEMY, x, y ),
_move_speed( 0 ),
_bullet_mgr( bullet_mgr ) {
	setMoveSpeed( _move_speed );
}

Enemy::~Enemy( ) {
}

void Enemy::action( ) {
	if ( rand( ) % PROBABILITY == 0  ) {
		_bullet_mgr->shot( BulletPtr( new Bullet( getRatioX( ), getRatioY( ), true ) ) );
	}
}

void Enemy::toApproach( ) {
	const int APPROACH_LENGH = 10 * RATIO;
	setRatioY( getRatioY( ) + APPROACH_LENGH );

	_move_speed *= -1;
	setMoveSpeed( _move_speed );
}

void Enemy::hitBullet( ) {
	setDead( true );
}
