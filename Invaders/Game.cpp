#include "Game.h"

Game::Game( ) {
}

Game::~Game( ) {
}

void Game::initialize( ) {
	_drawer = WriterPtr( new Writer( ) );
	_characterMgr = CharacterMgrPtr( new CharacterMgr( ) );
	_bulletMgr = BulletMgrPtr( new BulletMgr( ) );
}

void Game::update( ) {
	updateobj( );
	drawobj( );
}

void Game::updateobj( ) {
	_characterMgr->update( );
	_bulletMgr->update( _characterMgr );
}

void Game::drawobj( ) {
	_characterMgr->draw( _drawer );
	_bulletMgr->draw( _drawer );
}