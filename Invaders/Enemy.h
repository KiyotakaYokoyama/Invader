#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Enemy );

class Enemy : public Character {
public:
	Enemy( int x, int y );
	virtual ~Enemy( );
	void toApproach( );
private:
	void action( );
	void actionMove( );
	void actionShoot( );
	void hitBullet( );
	void hitEnemy( std::list< CharacterPtr > enemys );
private:
	int _move_speed;
};
