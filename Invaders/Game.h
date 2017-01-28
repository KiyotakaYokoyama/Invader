#pragma once

#include "Task.h"
#include "smart_ptr.h"
#include <string>

PTR( Game );
PTR( Writer );
PTR( CharacterMgr );
PTR( BulletMgr );
PTR( Hecato );

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
	WriterPtr _drawer;
	CharacterMgrPtr _characterMgr;
	BulletMgrPtr _bulletMgr;
	HecatoPtr _hecato;
};

