#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Player );

class Player : public  Character {
public:
	Player( int x, int y );
	virtual ~Player( );
private:
	void action( );
	void actionMove( );
	void actionShoot( );
	void hitEnemy( std::list< CharacterPtr > enemys );
private:
	int _shoot_count;
};
