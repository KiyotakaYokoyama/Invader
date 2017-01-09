#include "Enemy.h"
#include "Defin.h"

Enemy::Enemy( int x, int y ) :
Character( GRAPHIC_ENEMY, x, y ) {
	setMoveSpeed( MOVE_SPEED );
}

Enemy::~Enemy( ) {
}

void Enemy::actionMove( ) {
	bool approach = false;
	int x = ( getRatioX( ) + IVD_RATIO ) / IVD_RATIO;
	if ( x > SCREEN_WIDTH || x < 0 ) {
		approach = true;
	}
	//if ( ƒLƒƒƒ‰“¯Žm‚Ì‚ ‚½‚è”»’è )

	if ( approach ) {
		setMoveSpeed( -getMoveSpeed( ) );
		toApproach( );
	}
}

void Enemy::actionShoot( ) {
}
