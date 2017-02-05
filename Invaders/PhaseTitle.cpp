#include "PhaseTitle.h"
#include "Device.h"
#include "Drawer.h"
#include "Defin.h"


PhaseTitle::PhaseTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_TITLE, "title/title.png" );
}

PhaseTitle::~PhaseTitle( ) {
}

Phase::NEXT PhaseTitle::update( ) {
	DevicePtr device = Device::getTask( );

	if ( device->getPush( ) != 0 ) {
		return NEXT_STAGE;
	}

	DrawerPtr drawer = Drawer::getTask( );
	drawer->setSprite( Drawer::Sprite( Drawer::Transform( 0, 0, 0, 0, 200, 200, SCREEN_WIDTH, SCREEN_HEIGHT ), GRAPHIC_TITLE ) );
	return NEXT_CONTINEU;
}