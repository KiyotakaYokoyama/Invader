#pragma once

#include "Task.h"
#include "smart_ptr.h"
#include "InvadersDrawer.h"
#include "CharacterMgr.h"
#include "BulletMgr.h"
#include <string>

PTR( Game );

class Game : public Task {
public:
	Game( );
	virtual ~Game( );
	static std::string getTag( ) { return "GAME"; }
	static GamePtr getTask( );
	void initialize( );
	void update( );
private:
	void updateobj( );
	void drawobj( );
private:
	InvadersDrawerPtr _drawer;
	CharacterMgrPtr _characterMgr;
	BulletMgrPtr _bulletMgr;
};

