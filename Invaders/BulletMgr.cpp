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

void BulletMgr::update( ) {
	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	while ( ite != _bullets.end( ) ) {
		if ( !(*ite)->isDead( ) ) {
			(*ite)->update( );
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

void BulletMgr::shotBullet( int num, int x, int y, bool dir_down ) {
	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	for ( int i = 0; i < num; i++ ) {
		ite++;
	}
	(*ite)->initBullet( x, y, dir_down );
}

int BulletMgr::getDeadBulletNum( ) {
	int result = -1;

	std::list< BulletPtr >::iterator ite = _bullets.begin( );
	while ( ite != _bullets.end( ) ) {
		if ( !(*ite)->isDead( ) ) {
			break;
		}
		result++;
		ite++;
	}

	return result;
}