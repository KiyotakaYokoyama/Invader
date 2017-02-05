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

void Character::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	int sx = _ratio_x / RATIO;
	int sy = _ratio_y / RATIO;

	drawer->setSprite( Drawer::Sprite( Drawer::Transform( sx - CHARA_WIDTH / 2, sy - CHARA_HEIGHT ), _graph ) );
	
	//drawer->drawString( sx, sy, "'" );

	//drawer->drawString( sx-CHARA_WIDTH/2, sy-CHARA_HEIGHT, "„¬" );
	//drawer->drawString( sx-CHARA_WIDTH/2, sy, "„¯" );
	//drawer->drawString( sx+CHARA_WIDTH/2, sy-CHARA_HEIGHT, "„­" );
	//drawer->drawString( sx+CHARA_WIDTH/2, sy, "„®" );

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
}

void Character::hitRight( ) {
}

void Character::moveHorizontal( std::list< CharacterPtr > enemys ) {
	int ratio_x = _ratio_x + _move_speed;
	int screen_r = ( SCREEN_WIDTH - CHARA_WIDTH / 2 ) * RATIO;
	int screen_l = ( CHARA_WIDTH / 2 ) * RATIO;

	if ( ratio_x > screen_r ) {
		hitRight( );
		return;
	} else if( ratio_x < screen_l ) {
		hitLeft( );
		return;
	}
	hitEnemy( enemys );
	
	_ratio_x += _move_speed;
}

bool Character::isOverlapped( CharacterPtr target, int x, int y ) {
	int tx1 = target->getRatioX( ) - ( CHARA_WIDTH * RATIO / 2 );
	int tx2 = target->getRatioX( ) + ( CHARA_WIDTH * RATIO / 2 );
	int ty1 = target->getRatioY( ) - ( CHARA_HEIGHT * RATIO );
	int ty2 = target->getRatioY( );
	return x >= tx1 && x <= tx2 && y >= ty1 && y <= ty2;
}

void Character::moveVertical( ) {
}

void Character::hit( ) {	
	_ratio_x = -100;
	_ratio_y = -100;
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