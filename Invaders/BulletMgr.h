#pragma once

#include "smart_ptr.h"
#include <list>
#include "Bullet.h"
#include "CharacterMgr.h"

PTR( BulletMgr );
PTR( InvadersDrawer );

class BulletMgr {
public:
	BulletMgr( );
	virtual ~BulletMgr( );
	void update( );
	void draw( WriterConstPtr drawer );
	void shotBullet( int num, int x, int y, bool dir_down = false );
	int getDeadBulletNum( );
private:
	std::list< BulletPtr > _bullets;
};
