#include "Game.h"
#include "Drawer.h"
#include "Sound.h"
#include "PhaseTitle.h"
#include "PhaseStage.h"
#include "PhaseResult.h"

Game::Game( ) :
_next( Phase::NEXT_TITLE ) {
#if _DEBUG
	_next = Phase::NEXT_STAGE;
#endif
}

Game::~Game( ) {
}

void Game::initialize( ) {
	changeScene( );
	SoundPtr sound = Sound::getTask( );
	sound->playBGM( "vigilante.WAV" );
}

void Game::update( ) {
	_next = _phase->update( );
	changeScene( );
}

void Game::changeScene( ) {
	if ( _next == Phase::NEXT_CONTINEU ) {
		return;
	}

	_phase.reset( );
	
	DrawerPtr drawer = Drawer::getTask( );
	drawer->unloadAllGraph( );

	switch( _next ) {
	case Phase::NEXT_TITLE:
		_phase = PhasePtr( new PhaseTitle );
		break;
	case Phase::NEXT_STAGE:
		_phase = PhasePtr( new PhaseStage );		
		break;
	case Phase::NEXT_RESULT:
		_phase = PhasePtr( new PhaseResult );
		break;
	}
}