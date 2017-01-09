#pragma once

#include "smart_ptr.h"
#include "Defin.h"

PTR( InvadersDrawer );

class InvadersDrawer {
public:
	InvadersDrawer( );
	virtual ~InvadersDrawer( );
	void draw( GRAPHIC graphic, int screen_x, int screen_y ) const;
};
