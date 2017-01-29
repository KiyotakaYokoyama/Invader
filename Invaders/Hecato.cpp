#include "Hecato.h"
#include "CharacterMgr.h"
#include "BulletMgr.h"

Hecato::Hecato( ) {
}

Hecato::~Hecato( ) {
}

void Hecato::update( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {
	shot( char_mgr, blt_mgr );
	landing( char_mgr, blt_mgr );
}

void Hecato::shot( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {/*
	int num = blt_mgr->getDeadBulletNum( );
	if ( num < 0 ) {
		return;
	}

	CharacterPtr chara = char_mgr->getPlayer( );
	if ( chara->isShooting( ) ) {
		chara->setShooting( false );
		blt_mgr->shotBullet( num, chara->getRatioX( ), chara->getRatioY( ) - CHARA_HEIGHT * RATIO );
		return;
	}
	
	for ( int i = 0; i < char_mgr->getEnemySize( ) - 1; i++ ) {
		chara = char_mgr->getEnemys( i );
		if ( chara->isShooting( ) ) {
			chara->setShooting( false );
			blt_mgr->shotBullet( num, chara->getRatioX( ), chara->getRatioY( ) - CHARA_HEIGHT * RATIO, true );
			return;
		}
	}*/
}

void Hecato::landing( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {
	//’e‚Æ‚Ì‚ ‚½‚è”»’è
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
				(*enemy_ite)->hit( );
				(*bullet_ite)->hit( );
			}
			enemy_ite++;
		}
		enemy_ite = enemy_list.begin( );
		bullet_ite++;
	}
}

bool Hecato::isOverlapped( CharacterPtr target, int x, int y ) {
	int tx1 = target->getRatioX( ) - ( CHARA_WIDTH * RATIO / 2 );
	int tx2 = target->getRatioX( ) + ( CHARA_WIDTH * RATIO / 2 );
	int ty1 = target->getRatioY( ) - ( CHARA_HEIGHT * RATIO );
	int ty2 = target->getRatioY( );
	return x > tx1 && x < tx2 && y > ty1 && y < ty2;
}