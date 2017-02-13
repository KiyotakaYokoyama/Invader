#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Bullet );
PTR( Player );
PTR( Character );
PTR( EnemyMgr );

class BulletMgr {
public:
	BulletMgr( );
	virtual ~BulletMgr( );
	void update( PlayerPtr player, EnemyMgrPtr char_mgr );
	void draw( );
	void moveBullet( );
	void shot( BulletPtr bullet );
	std::list<BulletPtr> getBullets( );
private:
	void landing( PlayerPtr player );
	void landing( EnemyMgrPtr char_mgr );
	bool isOverlapped( CharacterPtr target, int x, int y );
private:
	std::list< BulletPtr > _bullets;
};
