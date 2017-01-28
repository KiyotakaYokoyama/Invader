#include "Hecato.h"
#include "CharacterMgr.h"
#include "BulletMgr.h"

Hecato::Hecato( ) {
}

Hecato::~Hecato( ) {
}

void Hecato::update( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {
	shot( char_mgr, blt_mgr );
	landing( );
}

void Hecato::shot( CharacterMgrPtr char_mgr, BulletMgrPtr blt_mgr ) {
	int num = blt_mgr->getDeadBulletNum( );
	if ( num < 0 ) {
		return;
	}

	CharacterPtr chara = char_mgr->getPlayer( );
	if ( chara->isShooting( ) ) {
		chara->setShooting( false );
		blt_mgr->shotBullet( num, chara->getRatioX( ) + CHARA_WIDTH / 2, chara->getRatioY( ) );
		return;
	}
	
	for ( int i = 0; i < char_mgr->getEnemySize( ) - 1; i++ ) {
		chara = char_mgr->getEnemys( i );
		if ( chara->isShooting( ) ) {
			chara->setShooting( false );
			blt_mgr->shotBullet( num, chara->getRatioX( ) + CHARA_WIDTH / 2, chara->getRatioY( ), true );
			return;
		}
	}
}

void Hecato::landing( ) {
	//’e‚Æ‚Ì‚ ‚½‚è”»’è
}