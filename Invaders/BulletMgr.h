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
	void update( CharacterMgrPtr c_mgr );
	void draw( InvadersDrawerConstPtr drawer );
private:
	std::list< BulletPtr > _bullets;
};
