#include "Bullet.h"
#include "Defin.h"
#include "Drawer.h"

static const int BULLET_SPEED = 100;

Bullet::Bullet( int x, int y, bool dir_down ) :
_ratio_x( x ),
_ratio_y( y ),
_dir_down( dir_down ) {
}

Bullet::~Bullet( ) {
}

void Bullet::update( ) {
	if ( _dir_down ) {
		_ratio_y += BULLET_SPEED;
	} else {
		_ratio_y += -BULLET_SPEED;
	}
}

void Bullet::draw( ) {
	if ( _ratio_y < 0 ) {
		return;
	}
	DrawerPtr drawer = Drawer::getTask( );
	int sx = ( _ratio_x / RATIO ) - BULLET_SIZE / 2;
	int sy = ( _ratio_y / RATIO ) - BULLET_SIZE;	
	int sx2 = ( _ratio_x / RATIO ) + BULLET_SIZE / 2;
	int sy2 = ( _ratio_y / RATIO );

	drawer->setSprite( Drawer::Sprite(
		Drawer::Transform( sx, sy, 0, 0, 600, 600, sx2, sy2 ),
			GRAPHIC_BULLET ) );
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

bool Bullet::outofScreen( ) const {
	bool result = false;
	if ( _ratio_x < 0 || _ratio_x > SCREEN_WIDTH * RATIO ||
        _ratio_y < 0 || _ratio_y > SCREEN_HEIGHT * RATIO ) {
		result = true;
	}
	return result;
}