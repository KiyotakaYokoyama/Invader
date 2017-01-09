#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Player );

class Player : public  Character {
public:
	Player( int x, int y );
	virtual ~Player( );
private:
	void actionMove( );
	void actionShoot( );
private:
	int _shoot_count;
};
