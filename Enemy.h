#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Enemy );

class Enemy : public Character {
public:
	Enemy( int x, int y );
	virtual ~Enemy( );
private:
	void actionMove( );
	void actionShoot( );
};
