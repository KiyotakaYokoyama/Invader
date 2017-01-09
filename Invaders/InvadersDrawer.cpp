#include "InvadersDrawer.h"
#include "Drawer.h"

InvadersDrawer::InvadersDrawer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_PLAYER, "player.jpg" );
	drawer->loadGraph( GRAPHIC_ENEMY, "enemy.jpg" );
	drawer->loadGraph( GRAPHIC_BULLET, "bullet.jpg" );
}

InvadersDrawer::~InvadersDrawer( ) {
}

void InvadersDrawer::draw( GRAPHIC graphic, int screen_x, int screen_y ) const {
	DrawerPtr drawer = Drawer::getTask( );
	int tx = screen_x;
	int ty = screen_y;

	Drawer::Transform trans( screen_x, screen_y );
	Drawer::Sprite sprite( trans, graphic, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}