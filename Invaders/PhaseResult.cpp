#include "PhaseResult.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "defin.h"

PhaseResult::PhaseResult( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_RESULT, "result/result.png" );
}

PhaseResult::~PhaseResult( ) {
}

Phase::NEXT PhaseResult::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );
	
	if ( keyboard->isPushKey( "Z" ) ) {
		return NEXT_TITLE;
	}
	
	DrawerPtr drawer = Drawer::getTask( );
	drawer->setSprite( Drawer::Sprite( Drawer::Transform( 0, 0, 0, 0, 1000, 1000, SCREEN_WIDTH, SCREEN_HEIGHT ), GRAPHIC_RESULT ) );

	return NEXT_CONTINEU;
}