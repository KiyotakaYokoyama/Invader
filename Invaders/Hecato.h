#pragma once

#include "smart_ptr.h"

PTR( Character );
PTR( CharacterMgr );
PTR( BulletMgr );

class Hecato {
public:
	Hecato( );
	virtual ~Hecato( );
	void update( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
private:
	void shot( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
	void landing( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
	bool isOverlapped( CharacterPtr target, int x, int y );
};
