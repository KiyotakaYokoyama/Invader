#include "Application.h"
#include "Game.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Defin.h"

void main( ) {
	TaskPtr game = GamePtr( new Game( ) );
	TaskPtr drawer = DrawerPtr( new Drawer( "Resource" ) );
	TaskPtr keyboard = KeyboardPtr( new Keyboard( ) );

	ApplicationPtr app = Application::getInstance( );
	app->setWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	app->addTask( Game::getTag( ), game );
	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Keyboard::getTag( ), keyboard );
}