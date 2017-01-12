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
		_ratio_x += BULLET_SPEED;
	} else {
		_ratio_x += -BULLET_SPEED;
	}
}

void Bullet::draw( WriterConstPtr drawer ) {

}

bool Bullet::isDead( ) {
	bool result = false;

	if ( _ratio_x < 0 || _ratio_x > SCREEN_WIDTH ||
		 _ratio_y < 0 || _ratio_y > SCREEN_HEIGHT ) {
		result = true;
	}

	return result;
}