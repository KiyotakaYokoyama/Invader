#include "Hecato.h"
#include "Player.h"
#include "Character.h"
#include "CharacterMgr.h"
#include "Bullet.h"
#include "BulletMgr.h"

Hecato::Hecato( ) {
}

Hecato::~Hecato( ) {
}

void Hecato::update( PlayerPtr player, CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {
	shot( player, char_mgr, blt_mgr );
	landing( char_mgr, blt_mgr );
	landing( player, blt_mgr );
}

void Hecato::shot( PlayerPtr player, CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {
	int num = blt_mgr->getDeadBulletNum( );
	if ( num < 0 ) {
		return;
	}

	if ( player->isShooting( ) ) {
		player->setShooting( false );
		blt_mgr->shotBullet( num, player->getRatioX( ), player->getRatioY( ) - CHARA_HEIGHT * RATIO - 30 );
		return;
	}

	for ( int i = 0; i < char_mgr->getEnemySize( ); i++ ) {
		CharacterPtr chara = char_mgr->getEnemys( i );
		if ( chara->isShooting( ) ) {
			chara->setShooting( false );
			blt_mgr->shotBullet( num, chara->getRatioX( ), chara->getRatioY( ), true );
			return;
		}
	}
}

void Hecato::landing( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {
	//弾とのあたり判定
	std::list< CharacterPtr > enemy_list = char_mgr->getEnemys( );
	std::list< CharacterPtr >::iterator enemy_ite = enemy_list.begin( );
	std::list< BulletPtr > bullet_list = blt_mgr->getBullets( );
	std::list< BulletPtr >::iterator bullet_ite = bullet_list.begin( );
	
	while ( bullet_ite != bullet_list.end( ) ) {
		while ( enemy_ite != enemy_list.end( ) ) {
			int bullet_x = (*bullet_ite)->getRatioX( );
			int bullet_y = (*bullet_ite)->getRatioY( );
			if ( isOverlapped( (*enemy_ite), bullet_x + BULLET_WIDTH / 2, bullet_y + BULLET_HEIGHT ) ||
				 isOverlapped( (*enemy_ite), bullet_x + BULLET_WIDTH / 2, bullet_y				   ) ||
				 isOverlapped( (*enemy_ite), bullet_x - BULLET_WIDTH / 2, bullet_y + BULLET_HEIGHT ) ||
				 isOverlapped( (*enemy_ite), bullet_x - BULLET_WIDTH / 2, bullet_y ) ) {
				//キャラクターに当てる
				(*enemy_ite)->hitBullet( );
				(*bullet_ite)->hit( );
			}
			enemy_ite++;
		}
		enemy_ite = enemy_list.begin( );
		bullet_ite++;
	}
}

void Hecato::landing( PlayerPtr player, BulletMgrPtr blt_mgr ) {
	std::list< BulletPtr > bullet_list = blt_mgr->getBullets( );
	std::list< BulletPtr >::iterator ite = bullet_list.begin( );

	while ( ite != bullet_list.end( ) ) {
		int bullet_x = (*ite)->getRatioX( );
		int bullet_y = (*ite)->getRatioY( );
		if ( isOverlapped( player, bullet_x + BULLET_WIDTH / 2, bullet_y + BULLET_HEIGHT ) ||
			 isOverlapped( player, bullet_x + BULLET_WIDTH / 2, bullet_y				 ) ||
			 isOverlapped( player, bullet_x - BULLET_WIDTH / 2, bullet_y + BULLET_HEIGHT ) ||
			 isOverlapped( player, bullet_x - BULLET_WIDTH / 2, bullet_y ) ) {
			player->setDead( true );
			(*ite)->hit( );
		}
		ite++;
	}
}


bool Hecato::isOverlapped( CharacterPtr target, int x, int y ) {
	int tx1 = target->getRatioX( ) - ( CHARA_WIDTH * RATIO / 2 );
	int tx2 = target->getRatioX( ) + ( CHARA_WIDTH * RATIO / 2 );
	int ty1 = target->getRatioY( ) - ( CHARA_HEIGHT * RATIO );
	int ty2 = target->getRatioY( );
	return x > tx1 && x < tx2 && y > ty1 && y < ty2;
}