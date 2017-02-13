#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Bullet );
PTR( Player );
PTR( Character );
PTR( CharacterMgr );

class BulletMgr {
public:
	BulletMgr( );
	virtual ~BulletMgr( );
	void update( PlayerPtr player, CharacterMgrPtr char_mgr );
	void draw( );
	void moveBullet( );
	void shot( BulletPtr bullet );
	std::list<BulletPtr> getBullets( );
private:
	void landing( PlayerPtr player );
	void landing( CharacterMgrPtr char_mgr );
	bool isOverlapped( CharacterPtr target, int x, int y );
private:
	std::list< BulletPtr > _bullets;
};
