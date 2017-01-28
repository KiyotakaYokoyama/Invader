#include "Game.h"
#include "Writer.h"
#include "CharacterMgr.h"
#include "BulletMgr.h"
#include "Hecato.h"

Game::Game( ) {
}

Game::~Game( ) {
}

void Game::initialize( ) {
	_drawer = WriterPtr( new Writer );
	_characterMgr = CharacterMgrPtr( new CharacterMgr );
	_bulletMgr = BulletMgrPtr( new BulletMgr );
	_hecato = HecatoPtr( new Hecato );
}

void Game::update( ) {
	updateobj( );
	drawobj( );
}

void Game::updateobj( ) {
	_characterMgr->update( );
	_bulletMgr->update( );
	_hecato->update( _characterMgr, _bulletMgr );
}

void Game::drawobj( ) {
	_characterMgr->draw( _drawer );
	_bulletMgr->draw( _drawer );
}