#pragma once

#include "smart_ptr.h"
#include <list>
#include "Writer.h"

PTR( Character );

class Character : public std::enable_shared_from_this< Character >{
public:
	Character( GRAPHIC graph, int x, int y );
	virtual ~Character( );
	void update( );
	void draw( WriterConstPtr drawer );
	bool isShooting( );
	int getRatioX( );
	int getRatioY( );
	GRAPHIC getGraphic( );
protected:
	void setMoveSpeed( int move_speed );
	void setShooting( bool shoot );
	void toApproach( );
	int getMoveSpeed( );
private:
	void moveHorizontal( );
	void moveVertical( );
	void action( );
	virtual void actionMove( );
	virtual void actionShoot( );
private:
	int _ratio_x;
	int _ratio_y;
	int _move_speed;
	bool _shooting;
	GRAPHIC _graph;
};
