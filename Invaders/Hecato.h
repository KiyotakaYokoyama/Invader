#pragma once

#include "smart_ptr.h"

PTR( Character );
PTR( Player );
PTR( CharacterMgr );
PTR( BulletMgr );

class Hecato {
public:
	Hecato( );
	virtual ~Hecato( );
	void update( PlayerPtr player, CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
private:
	void shot( PlayerPtr player, CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
	void landing( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
	void landing( PlayerPtr player, BulletMgrPtr blt_mgr );
	bool isOverlapped( CharacterPtr target, int x, int y );
};
