#include "PhaseStage.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "BulletMgr.h"
#include "defin.h"
#include "Drawer.h"
#include "Sound.h"

static const int PLAYER_START_POS_X = SCREEN_WIDTH * RATIO / 2;
static const int PLAYER_START_POS_Y = SCREEN_HEIGHT * RATIO;
static const int WAIT_SCREEN_TIME = 60;
static const int GAMEOVER_LINE = SCREEN_HEIGHT - CHARA_HEIGHT;

PhaseStage::PhaseStage( ScorePtr score ) :
_state( STATE_NORMAL ),
_score( score ){
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_PLAYER, "stage/player.png" );
	drawer->loadGraph( GRAPHIC_ENEMY, "stage/enemy.png" );
	drawer->loadGraph( GRAPHIC_BULLET, "stage/bullet.png" );
	drawer->loadGraph( GRAPHIC_BG, "stage/bg.png" );
	
	SoundPtr sound = Sound::getTask( );
	sound->loadSE( "bomb3.wav" );
	sound->loadSE( "shoot.wav" );

	_bullet_mgr = BulletMgrPtr( new BulletMgr );
	_player = PlayerPtr( new Player( PLAYER_START_POS_X, PLAYER_START_POS_Y, _bullet_mgr ) );
	_enemy_mgr = EnemyMgrPtr( new EnemyMgr( _bullet_mgr ) );
}

PhaseStage::~PhaseStage( ) {
}

Phase::NEXT PhaseStage::update( ) {
	Phase::NEXT result = NEXT_CONTINEU;

	switch( _state ) {
	case STATE_NORMAL:
		act( );
		gameover( );
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
	_enemy_mgr->update( _score );
	_player->update( _enemy_mgr->getEnemys( ) );
	_bullet_mgr->update( _player, _enemy_mgr );
}

void PhaseStage::gameover( ) {
	auto enemys = _enemy_mgr->getEnemys( );
	auto ite = enemys.begin( );

	while( ite != enemys.end( ) ) {
		if ( (*ite)->getRatioY( ) > GAMEOVER_LINE * RATIO ) {
			_player->setDead( true );
			break;
		}
		ite++;
	}

	if ( _player->isDead( ) ) {
		_state = STATE_WAIT;
	}
}

void PhaseStage::wait( ) {
	_wait_count++;
}

void PhaseStage::draw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	
	drawer->setSprite( Drawer::Sprite(
		Drawer::Transform( 0, 0, 0, 0, 1500, 1500, SCREEN_WIDTH, SCREEN_WIDTH ), GRAPHIC_BG ) );

	_enemy_mgr->draw( );
	_player->draw( );
	_bullet_mgr->draw( );

#if _DEBUG
	debugDraw( );
#endif
}

void PhaseStage::debugDraw( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "bulletsize %d", _bullet_mgr->getBullets( ).size( ) );
}
