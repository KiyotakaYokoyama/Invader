#include "Writer.h"
#include "Drawer.h"
#include "defin.h"

Writer::Writer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_PLAYER, "player_1.jpg" );
	drawer->loadGraph( GRAPHIC_ENEMY, "enemy_1.jpg" );
	drawer->loadGraph( GRAPHIC_BULLET, "bullet.jpg" );
}

Writer::~Writer( ) {
}

void Writer::draw( GRAPHIC graphic, int screen_x, int screen_y ) const {
	DrawerPtr drawer = Drawer::getTask( );
	int tx = screen_x;
	int ty = screen_y;

	Drawer::Transform trans( screen_x, screen_y );
	Drawer::Sprite sprite( trans, graphic, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}