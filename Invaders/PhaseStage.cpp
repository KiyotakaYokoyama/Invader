#include "PhaseStage.h"
#include "Player.h"
#include "CharacterMgr.h"
#include "BulletMgr.h"
#include "Hecato.h"
#include "defin.h"
#include "Drawer.h"

static const int PLAYER_START_POS_X = SCREEN_WIDTH * RATIO / 2;
static const int PLAYER_START_POS_Y = SCREEN_HEIGHT * RATIO;
static const int WAIT_SCREEN_TIME = 60;

PhaseStage::PhaseStage( ) :
_state( STATE_NORMAL ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_PLAYER, "stage/player.png" );
	drawer->loadGraph( GRAPHIC_ENEMY, "stage/enemy.png" );
	drawer->loadGraph( GRAPHIC_BULLET, "stage/bullet.png" );

	_player = PlayerPtr( new Player( PLAYER_START_POS_X, PLAYER_START_POS_Y ) );
	_characterMgr = CharacterMgrPtr( new CharacterMgr );
	_bulletMgr = BulletMgrPtr( new BulletMgr );
	_hecato = HecatoPtr( new Hecato );
}

PhaseStage::~PhaseStage( ) {
}

Phase::NEXT PhaseStage::update( ) {
	Phase::NEXT result = NEXT_CONTINEU;

	switch( _state ) {
	case STATE_NORMAL:
		act( );
		if ( _player->isDead( ) ) {
			_state = STATE_WAIT;
		}
		break;
	case STATE_WAIT:
		wait( );
		if ( _wait_count > WAIT_SCREEN_TIME ) {
			result = NEXT_RESULT;
		}
	}

	draw( );
	return result;
}

void PhaseStage::act( ) {
	_characterMgr->update( );
	_player->update( _characterMgr->getEnemys( ) );
	_bulletMgr->update( );
	_hecato->update( _characterMgr, _bulletMgr );
}

void PhaseStage::wait( ) {
	_wait_count++;
}

void PhaseStage::draw( ) {
	_characterMgr->draw( );
	_player->draw( );
	_bulletMgr->draw( );
}