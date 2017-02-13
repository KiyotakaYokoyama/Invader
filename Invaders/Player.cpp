#include "Player.h"
#include "Bullet.h"
#include "BulletMgr.h"
#include "Defin.h"
#include "Keyboard.h"

static const int MAX_SHOOT_COUNT = 4;
static const int GAMEOVER_LINE = 400;

PTR( Bullet );

Player::Player( int x, int y, BulletMgrPtr bullet_mgr ) :
Character( GRAPHIC_PLAYER, x, y ),
_bullet_mgr( bullet_mgr ) {
}

Player::~Player( ) {
}

void Player::action( ) {
	actionMove( );
	actionShoot( );
}

void Player::actionMove( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	if ( keyboard->isHoldKey( "ARROW_RIGHT" ) ) {
		setMoveSpeed( MOVE_SPEED );
	} else  if ( keyboard->isHoldKey( "ARROW_LEFT" ) ) {
		setMoveSpeed( -MOVE_SPEED );
	} else {
		setMoveSpeed( 0 );
	}	
}

void Player::actionShoot( ) {
	setShooting( false );
	_shoot_count++;
	if ( _shoot_count < MAX_SHOOT_COUNT ) {
		return;
	}

	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->isHoldKey( "Z" ) ) {
		_shoot_count = 0;
		_bullet_mgr->shot( BulletPtr( new Bullet( getRatioX( ), getRatioY( ), false ) ) );
	}
}

void Player::hitEnemy( std::list< CharacterPtr > enemys ) {
	std::list< CharacterPtr >::iterator ite = enemys.begin( );
	while ( ite != enemys.end( ) ) {
		if ( (*ite) == shared_from_this( ) ) {
			ite++;
			continue;
		}
		if ( (*ite)->getRatioY( ) > GAMEOVER_LINE * RATIO ) {
			setDead( true );
		}
		ite++;
	}
}
