#pragma once

#include "smart_ptr.h"
#include "InvadersDrawer.h"

PTR( Bullet );

class Bullet {
public:
	Bullet( int x, int y );
	virtual ~Bullet( );
	void initBullet( int x, int y, bool dir_down );
	void update( );
	void draw( InvadersDrawerConstPtr drawer );
	bool isDead( );
private:
	int _ratio_x;
	int _ratio_y;
	bool _dir_down;
};
