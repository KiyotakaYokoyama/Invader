#pragma once

#include "smart_ptr.h"
#include "Defin.h"

PTR( Writer );

class Writer {
public:
	Writer( );
	virtual ~Writer( );
	void draw( GRAPHIC graphic, int screen_x, int screen_y ) const;
};
