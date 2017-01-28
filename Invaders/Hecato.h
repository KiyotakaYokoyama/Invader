#pragma once

#include "smart_ptr.h"

PTR( CharacterMgr );
PTR( BulletMgr );

class Hecato {
public:
	Hecato( );
	virtual ~Hecato( );
	void update( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
private:
	void shot( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr );
	void landing( );
};
