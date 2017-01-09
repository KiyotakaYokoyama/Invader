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
			for ( int i = 0; i < c_mgr->getCharacterSize( ); i++ ) {
				CharacterPtr chara = c_mgr->getCharacter( i );
				if ( chara->isShooting( ) ) {
					bool dir_down = true;
					if ( chara->getGraphic( ) == GRAPHIC_PLAYER ) {
						dir_down = false;
					}
					bullet->initBullet( chara->getRatioX( ), chara->getRatioY( ), dir_down );
					break;
				}
			}
		} else {
			bullet->update( );
		}

		ite++;
	}
}

void BulletMgr::draw( InvadersDrawerConstPtr drawer ) {
	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	while ( ite != _bullets.end( ) ) {
		(*ite)->draw( drawer );
		ite++;
	}
}