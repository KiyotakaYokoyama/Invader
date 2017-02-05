#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Enemy );

class Enemy : public Character {
public:
	Enemy( int x, int y );
	virtual ~Enemy( );
	void initEnemy( int x, int y );
private:
	void actionMove( );
	void actionShoot( );
	void toApproach( );
	void hitLeft( );
	void hitRight( );
	void hitEnemy( std::list< CharacterPtr > enemys );
};
