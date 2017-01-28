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
	virtual void initEnemy( int x, int y );
	bool isShooting( );
	int getRatioX( );
	int getRatioY( );
	GRAPHIC getGraphic( );
protected:
	void setMoveSpeed( int move_speed );
	void setRatioX( int ratio_x );
	void setRatioY( int ratio_y );
	int getMoveSpeed( );
private:
	void moveHorizontal( std::list< CharacterPtr > enemys );
	void moveVertical( );
	bool isOverlapped( CharacterPtr target, int x, int y );
	void action( );
	virtual void actionMove( );
	virtual void actionShoot( );
	virtual void hitLeft( );
	virtual void hitRight( );
private:
	int _ratio_x;
	int _ratio_y;
	int _move_speed;
	bool _shooting;
	GRAPHIC _graph;
};
