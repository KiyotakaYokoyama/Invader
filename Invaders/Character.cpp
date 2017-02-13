#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Defin.h"
#include "Drawer.h"

Character::Character( GRAPHIC graph, int x, int y ) :
_ratio_x( x ),
_ratio_y( y ),
_graph( graph ),
_dead( false ) {
}

Character::~Character( ) {
}

void Character::update( std::list< CharacterPtr > enemys ) {
	action( );
	moveHorizontal( enemys );
	moveVertical( );
}

void Character::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	int sx = _ratio_x / RATIO;
	int sy = _ratio_y / RATIO;

	drawer->setSprite( Drawer::Sprite( Drawer::Transform( sx - CHARA_WIDTH / 2, sy - CHARA_HEIGHT ), _graph ) );
}

void Character::moveHorizontal( std::list< CharacterPtr > enemys ) {
	int ratio_x = _ratio_x + _move_speed;
	int screen_r = ( SCREEN_WIDTH - CHARA_WIDTH / 2 ) * RATIO;
	int screen_l = ( CHARA_WIDTH / 2 ) * RATIO;

	if ( ratio_x > screen_r || ratio_x < screen_l ) {
		return;
	}
	
	_ratio_x += _move_speed;
}

void Character::moveVertical( ) {
}

void Character::setMoveSpeed( int move_speed ) {
	_move_speed = move_speed;
}

void Character::setRatioX( int ratio_x ) {
	_ratio_x = ratio_x;
}

void Character::setRatioY( int ratio_y ) {
	_ratio_y = ratio_y;
}
void Character::setDead( bool dead ) {
	_dead = dead;
}

int Character::getMoveSpeed( ) const {
	return _move_speed;
}

int Character::getRatioX( ) const {
	return _ratio_x;
}

int Character::getRatioY( ) const {
	return _ratio_y;
}

bool Character::isDead( ) const {
	return _dead;
}