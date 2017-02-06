#include "Bullet.h"
#include "Defin.h"
#include "Drawer.h"

static const int BULLET_SPEED = 100;

Bullet::Bullet( int x, int y ) {
}

Bullet::~Bullet( ) {
}

void Bullet::initBullet( int x, int y, bool dir_down ) {
	_ratio_x = x;
	_ratio_y = y;
	_dir_down = dir_down;
}

void Bullet::update( ) {
	if ( _dir_down ) {
		_ratio_y += BULLET_SPEED;
	} else {
		_ratio_y += -BULLET_SPEED;
	}
}

void Bullet::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	int sx = _ratio_x / RATIO;
	int sy = _ratio_y / RATIO;

	drawer->setSprite( Drawer::Sprite( Drawer::Transform( sx - BULLET_WIDTH / 2, sy - BULLET_HEIGHT ), GRAPHIC_BULLET ) );
}

void Bullet::hit( ) {
	_ratio_x = -100;
	_ratio_y = -100;
}

int Bullet::getRatioX( ) const {
	return _ratio_x;
}

int Bullet::getRatioY( ) const {
	return _ratio_y;
}

bool Bullet::dirDown( ) const {
	return _dir_down;
}

bool Bullet::isDead( ) {
	bool result = false;

	if ( _ratio_x < 0 || _ratio_x > SCREEN_WIDTH * RATIO ||
		 _ratio_y < 0 || _ratio_y > SCREEN_HEIGHT * RATIO ) {
		_ratio_x = -100;
		_ratio_y = -100;
		result = true;
	}

	return result;
}