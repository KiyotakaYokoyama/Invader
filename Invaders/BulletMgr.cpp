#include "BulletMgr.h"
#include "Bullet.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "Sound.h"

BulletMgr::BulletMgr( ) {
}

BulletMgr::~BulletMgr( ) {
}

void BulletMgr::update( PlayerPtr player, EnemyMgrPtr char_mgr ) {
	moveBullet( );
	landing( player );
	landing( char_mgr );
}

void BulletMgr::draw( ) {
	if ( _bullets.empty( ) ) {
		return;
	}

	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	while ( ite != _bullets.end( ) ) {
		(*ite)->draw( );
		ite++;
	}
}

void BulletMgr::moveBullet( ) {
	if ( _bullets.empty( ) ) {
		return;
	}

	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	while ( ite != _bullets.end( ) ) {
		if ( (*ite)->outofScreen( ) ) {
			ite = _bullets.erase( ite );
		} else {
			(*ite)->update( );
			ite++;
		}
	}
}

void BulletMgr::shot( BulletPtr bullet ) {
	_bullets.push_back( bullet );
}

void BulletMgr::landing( EnemyMgrPtr char_mgr ) {
	//弾とのあたり判定
	std::list< CharacterPtr > enemy_list = char_mgr->getEnemys( );
	std::list< CharacterPtr >::iterator enemy_ite = enemy_list.begin( );
	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	
	while ( ite != _bullets.end( ) ) {
		while ( enemy_ite != enemy_list.end( ) ) {
			int bullet_x = (*ite)->getRatioX( );
			int bullet_y = (*ite)->getRatioY( );
			if ( isOverlapped( (*enemy_ite), bullet_x + BULLET_SIZE / 2, bullet_y + BULLET_SIZE ) ||
				 isOverlapped( (*enemy_ite), bullet_x + BULLET_SIZE / 2, bullet_y				   ) ||
				 isOverlapped( (*enemy_ite), bullet_x - BULLET_SIZE / 2, bullet_y + BULLET_SIZE ) ||
				 isOverlapped( (*enemy_ite), bullet_x - BULLET_SIZE / 2, bullet_y ) ) {
				//キャラクターに当てる
				if ( !(*ite)->dirDown( ) ) {
					(*enemy_ite)->hitBullet( );

					SoundPtr sound = Sound::getTask( );
					sound->playSE( "bomb3.wav" );

					ite = _bullets.erase( ite );
					break;
				}
			}
			enemy_ite++;
		}

		if ( ite == _bullets.end( ) || _bullets.empty( ) ) {
			break;
		}

		enemy_ite = enemy_list.begin( );
		ite++;
	}
}

void BulletMgr::landing( PlayerPtr player ) {
	std::list< BulletPtr >::iterator ite = _bullets.begin( );

	while ( ite != _bullets.end( ) ) {
		int bullet_x = (*ite)->getRatioX( );
		int bullet_y = (*ite)->getRatioY( );
		if ( isOverlapped( player, bullet_x + BULLET_SIZE / 2, bullet_y + BULLET_SIZE ) ||
			 isOverlapped( player, bullet_x + BULLET_SIZE / 2, bullet_y				 ) ||
			 isOverlapped( player, bullet_x - BULLET_SIZE / 2, bullet_y + BULLET_SIZE ) ||
			 isOverlapped( player, bullet_x - BULLET_SIZE / 2, bullet_y ) ) {
			if ( (*ite)->dirDown( ) ) {
				player->setDead( true );
				ite = _bullets.erase( ite );

				SoundPtr sound = Sound::getTask( );
				sound->playSE( "bomb3.wav" );
			}
		}

		if ( _bullets.empty( ) ) {
			break;
		}

		ite++;
	}
}

bool BulletMgr::isOverlapped( CharacterPtr target, int x, int y ) {
	int tx1 = target->getRatioX( ) - ( CHARA_WIDTH * RATIO / 2 );
	int tx2 = target->getRatioX( ) + ( CHARA_WIDTH * RATIO / 2 );
	int ty1 = target->getRatioY( ) - ( CHARA_HEIGHT * RATIO );
	int ty2 = target->getRatioY( );
	return x > tx1 && x < tx2 && y > ty1 && y < ty2;
}

std::list<BulletPtr> BulletMgr::getBullets( ) {
	return _bullets;
}