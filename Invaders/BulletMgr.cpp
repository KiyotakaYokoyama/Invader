#include "BulletMgr.h"
#include "Character.h"

static const int MAX_BULLET_NUM = 100;

BulletMgr::BulletMgr( ) {
	int pos = -10;
	for ( int i = 0; i < MAX_BULLET_NUM; i++ ) {
		_bullets.push_back( BulletPtr( new Bullet( pos, pos ) ) );
	}
}

BulletMgr::~BulletMgr( ) {
}

void BulletMgr::update( CharacterMgrPtr c_mgr ) {
	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	while ( ite != _bullets.end( ) ) {
		BulletPtr bullet = (*ite);

		if ( bullet->isDead( ) ) {
			CharacterPtr chara = c_mgr->getPlayer( );
			if ( chara->isShooting( ) ) {
				chara->setShooting( false );
				bullet->initBullet( chara->getRatioX( ) + CHARA_WIDTH / 2, chara->getRatioY( ) );
				break;
			}

			for ( int i = 0; i < c_mgr->getEnemySize( ) - 1; i++ ) {
				chara = c_mgr->getEnemys( i );
				if ( chara->isShooting( ) ) {
					chara->setShooting( false );
					bullet->initBullet( chara->getRatioX( ) + CHARA_WIDTH / 2, chara->getRatioY( ), true );
					break;
				}
			}
		} else {
			bullet->update( );
		}

		ite++;
	}
}

void BulletMgr::draw( WriterConstPtr drawer ) {
	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	while ( ite != _bullets.end( ) ) {
		(*ite)->draw( drawer );
		ite++;
	}
}