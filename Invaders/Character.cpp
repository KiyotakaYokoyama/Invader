#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Defin.h"

Character::Character( GRAPHIC graph, int x, int y ) {
	_graph = graph;
	_ratio_x = x;
	_ratio_y = y;
}

Character::~Character( ) {
}

void Character::update( ) {
	action( );
	moveHorizontal( );
	moveVertical( );
}

void Character::draw( InvadersDrawerConstPtr drawer ) {
	int x = _ratio_x / IVD_RATIO;
	int y = _ratio_y / IVD_RATIO;

	drawer->draw( _graph, x, y );
}

void Character::action( ) {
	actionMove( );
	actionShoot( );
}

void Character::actionMove( ) {
}

void Character::actionShoot( ) {
}

void Character::moveHorizontal( ) {
	_ratio_x += _move_speed;
}

void Character::moveVertical( ) {
}

void Character::setMoveSpeed( int move_speed ) {
	_move_speed = move_speed;
}

void Character::setShooting( bool shoot ) {
	_shooting = shoot;
}

void Character::toApproach( ) {
	_ratio_y += CHARACTER_HEIGHT;
}

int Character::getMoveSpeed( ) {
	return _move_speed;
}

int Character::getRatioX( ) {
	return _ratio_x;
}

int Character::getRatioY( ) {
	return _ratio_y;
}

bool Character::isShooting( ) {
	return _shooting;
}

GRAPHIC Character::getGraphic( ) {
	return _graph;
}