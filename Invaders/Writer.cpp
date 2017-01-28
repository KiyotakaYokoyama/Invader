#include "Writer.h"
#include "Drawer.h"
#include "defin.h"

Writer::Writer( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_PLAYER, "player.png" );
	drawer->loadGraph( GRAPHIC_ENEMY, "enemy.png" );
	drawer->loadGraph( GRAPHIC_BULLET, "bullet.png" );
}

Writer::~Writer( ) {
}

void Writer::draw( GRAPHIC graphic, int screen_x, int screen_y, bool dir_down ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( screen_x, screen_y );
	Drawer::Sprite sprite( trans, graphic, Drawer::BLEND_NONE, 1.0 );
	drawer->setSprite( sprite );
}