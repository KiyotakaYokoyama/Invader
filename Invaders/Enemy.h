#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Enemy );
PTR( BulletMgr );

class Enemy : public Character {
public:
	Enemy( int x, int y, BulletMgrPtr bullet_mgr );
	virtual ~Enemy( );
	void toApproach( );
private:
	void action( );
	void actionMove( );
	void actionShoot( );
	void hitBullet( );
private:
	int _move_speed;
	BulletMgrPtr _bullet_mgr;
};
