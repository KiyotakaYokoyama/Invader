#include "PhaseTitle.h"
#include "Keyboard.h"
#include "Drawer.h"
#include "Defin.h"


PhaseTitle::PhaseTitle( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPHIC_TITLE, "title/title.png" );
}

PhaseTitle::~PhaseTitle( ) {
}

Phase::NEXT PhaseTitle::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->isPushKey( "Z" ) ) {
		return NEXT_STAGE;
	}

	DrawerPtr drawer = Drawer::getTask( );
	drawer->setSprite( Drawer::Sprite( Drawer::Transform( 0, 0, 0, 0, 200, 200, SCREEN_WIDTH, SCREEN_HEIGHT ), GRAPHIC_TITLE ) );
	return NEXT_CONTINEU;
}