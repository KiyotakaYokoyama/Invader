#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Defin.h"
#include "Drawer.h"

Character::Character( GRAPHIC graph, int x, int y ) {
	_graph = graph;
	_ratio_x = x;
	_ratio_y = y;
}

Character::~Character( ) {
}

void Character::update( std::list< CharacterPtr > enemys ) {
	action( );
	moveHorizontal( enemys );
	moveVertical( );
}

void Character::draw( WriterConstPtr drawer ) {
	int sx = _ratio_x / RATIO;
	int sy = _ratio_y / RATIO;

	drawer->draw( _graph, sx, sy );

	DrawerPtr draw = Drawer::getTask( );
	draw->drawString( sx, sy, "Åõ" );
}

void Character::action( ) {
	actionMove( );
	actionShoot( );
}

void Character::actionMove( ) {
}

void Character::actionShoot( ) {
}

void Character::hitLeft( ) {
	_ratio_x += RATIO;
	_move_speed = 0;
}

void Character::hitRight( ) {
	_ratio_x += -RATIO;
	_move_speed = 0;
}

void Character::moveHorizontal( std::list< CharacterPtr > enemys ) {

	int x = ( _ratio_x + RATIO ) / RATIO;
	if ( x > SCREEN_WIDTH - CHARA_WIDTH / 2 ) {
		hitRight( );
		return;
	} else if( x < CHARA_WIDTH / 2 ) {
		hitLeft( );
		return;
	}
	
	/*
	std::list< CharacterPtr >::iterator ite = enemys.begin( );
	while ( ite != enemys.end( ) ) {
		if ( (*ite) == shared_from_this( ) ) {
			ite++;
			continue;
		}

		CharacterPtr target = (*ite);
		// âEÇ…Ç‘Ç¬Ç©Ç¡ÇΩ
		int ratio_x = _ratio_x + ( CHARA_WIDTH / 2 * RATIO );
		if ( isOverlapped( target, ratio_x, _ratio_y - ( CHARA_HEIGHT * RATIO ) ) ||
			 isOverlapped( target, ratio_x, _ratio_y * RATIO ) ) {
			hitRight( );
			return;
		}
		// ç∂Ç…Ç‘Ç¬Ç©Ç¡ÇΩ
		ratio_x = _ratio_x - ( CHARA_WIDTH / 2 * RATIO );
		if ( isOverlapped( target, ratio_x, _ratio_y - ( CHARA_HEIGHT * RATIO ) ) ||
			 isOverlapped( target, ratio_x, _ratio_y * RATIO ) ) {
			hitLeft( );
			return;
		}
		ite++;
	}
	*/
	_ratio_x += _move_speed;
}

bool Character::isOverlapped( CharacterPtr target, int x, int y ) {
	int tx1 = target->getRatioX( ) - ( CHARA_WIDTH / 2 * RATIO );
	int tx2 = target->getRatioX( ) + ( CHARA_WIDTH / 2 * RATIO );
	int ty1 = target->getRatioY( ) - ( CHARA_HEIGHT * RATIO );
	int ty2 = target->getRatioY( );
	return x > tx1 && x < tx2 && y > ty1 && y < ty2;
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

void Character::setShooting( bool shoot ) {
	_shooting = shoot;
}

void Character::initEnemy( int x, int y ) {
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