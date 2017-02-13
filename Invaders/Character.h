#pragma once

#include "smart_ptr.h"
#include "Defin.h"
#include <list>

PTR( Character );

class Character : public std::enable_shared_from_this< Character > {
public:
	Character( GRAPHIC graph, int x, int y );
	virtual ~Character( );
	void update( std::list< CharacterPtr > enemys );
	void draw( );
	void initPos( int x, int y );
	void setShooting( bool shoot );
	void setDead( bool dead );
	bool isShooting( ) const;
	int getRatioX( ) const;
	int getRatioY( ) const;
	int getMoveSpeed( ) const;
	bool isDead( ) const;
	GRAPHIC getGraphic( ) const;
	virtual void hitBullet( ) { };
	virtual void toApproach( ) { };
protected:
	void setMoveSpeed( int move_speed );
	void setRatioX( int ratio_x );
	void setRatioY( int ratio_y );
	bool isOverlapped( CharacterPtr target, int x, int y );
private:
	void moveVertical( );
	void moveHorizontal( std::list< CharacterPtr > enemys );
	virtual void action( ) = 0;
	virtual void hitEnemy( std::list< CharacterPtr > enemys ) = 0;
private:
	int _ratio_x;
	int _ratio_y;
	int _move_speed;
	bool _shooting;
	bool _dead;
	GRAPHIC _graph;
};
