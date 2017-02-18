#include "Player.h"
#include "Bullet.h"
#include "BulletMgr.h"
#include "Defin.h"
#include "Keyboard.h"
#include "Sound.h"

static const int MAX_SHOOT_COUNT = 4;

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
	_shoot_count++;
	if ( _shoot_count < MAX_SHOOT_COUNT ) {
		return;
	}

	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->isHoldKey( "Z" ) ) {
		_shoot_count = 0;
		int x = getRatioX( ) - BULLET_SIZE * RATIO * 2 / 3;
		int y = getRatioY( ) - CHARA_HEIGHT * RATIO * 7 / 10;
		_bullet_mgr->shot( BulletPtr( new Bullet( x, y, false ) ) );
		SoundPtr sound = Sound::getTask( );
		sound->playSE( "shoot.wav" );
	}
}
