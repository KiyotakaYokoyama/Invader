#pragma once

#include "smart_ptr.h"
#include "Writer.h"

PTR( Bullet );

class Bullet {
public:
	Bullet( int x, int y );
	virtual ~Bullet( );
	void initBullet( int x, int y, bool dir_down = false );
	void update( );
	void draw( WriterConstPtr drawer );
	bool isDead( );
private:
	int _ratio_x;
	int _ratio_y;
	bool _dir_down;
};
