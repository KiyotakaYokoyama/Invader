#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Bullet );

class BulletMgr {
public:
	BulletMgr( );
	virtual ~BulletMgr( );
	void update( );
	void draw( );
	void shotBullet( int num, int x, int y, bool dir_down = false );
	int getDeadBulletNum( );
	std::list<BulletPtr> getBullets( );
private:
	std::list< BulletPtr > _bullets;
};
