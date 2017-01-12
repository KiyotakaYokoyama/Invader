#include "Bullet.h"
#include "Defin.h"

static const int BULLET_SPEED = 20;

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

void Bullet::draw( WriterConstPtr drawer ) {
	int x = _ratio_x / RATIO;
	int y = _ratio_y / RATIO;

	drawer->draw( GRAPHIC_BULLET, x, y, _dir_down );
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