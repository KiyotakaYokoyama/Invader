#pragma once

#include "smart_ptr.h"
#include <list>
#include "Writer.h"

PTR( Character );

class Character : public std::enable_shared_from_this< Character > {
public:
	Character( GRAPHIC graph, int x, int y );
	virtual ~Character( );
	void update( std::list< CharacterPtr > enemys );
	void draw( WriterConstPtr drawer );
	void setShooting( bool shoot );
	void hit( );
	bool isShooting( );
	int getRatioX( );
	int getRatioY( );
	GRAPHIC getGraphic( );
	virtual void initEnemy( int x, int y );
	virtual void hitLeft( );
	virtual void hitRight( );
protected:
	void setMoveSpeed( int move_speed );
	void setRatioX( int ratio_x );
	void setRatioY( int ratio_y );
	int getMoveSpeed( );
	bool isOverlapped( CharacterPtr target, int x, int y );
private:
	void action( );
	void moveVertical( );
	virtual void moveHorizontal( std::list< CharacterPtr > enemys );
	virtual void actionMove( );
	virtual void actionShoot( );
	virtual void hitEnemy( std::list< CharacterPtr > enemys ) = 0;
private:
	int _ratio_x;
	int _ratio_y;
	int _move_speed;
	bool _shooting;
	GRAPHIC _graph;
};
