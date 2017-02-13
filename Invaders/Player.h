#pragma once

#include "smart_ptr.h"
#include "Character.h"

PTR( Player );
PTR( BulletMgr );

class Player : public  Character {
public:
	Player( int x, int y, BulletMgrPtr bullet_mgr  );
	virtual ~Player( );
private:
	void action( );
	void actionMove( );
	void actionShoot( );
	void hitEnemy( std::list< CharacterPtr > enemys );
private:
	int _shoot_count;
	BulletMgrPtr _bullet_mgr;
};
