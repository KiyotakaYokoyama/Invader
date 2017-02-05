#include "PhaseResult.h"
#include "Drawer.h"
#include "Device.h"
#include "defin.h"

PhaseResult::PhaseResult( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_RESULT, "result/result.png" );
}

PhaseResult::~PhaseResult( ) {
}

Phase::NEXT PhaseResult::update( ) {
	DevicePtr device = Device::getTask( );
	
	if ( device->getPush( ) != 0 ) {
		return NEXT_TITLE;
	}
	
	DrawerPtr drawer = Drawer::getTask( );
	drawer->setSprite( Drawer::Sprite( Drawer::Transform( 0, 0, 0, 0, 200, 200, SCREEN_WIDTH, SCREEN_HEIGHT ), GRAPHIC_RESULT ) );

	return NEXT_CONTINEU;
}