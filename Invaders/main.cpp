#include "Application.h"
#include "Game.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Device.h"
#include "defin.h"

void main( ) {
	TaskPtr game = GamePtr( new Game );
	TaskPtr drawer = DrawerPtr( new Drawer( "Resource" ) );
	TaskPtr keyboard = KeyboardPtr( new Keyboard );
	TaskPtr device = DevicePtr( new Device );

	ApplicationPtr app = Application::getInstance( );
	app->setWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );

	app->addTask( Game::getTag( ), game );
	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Keyboard::getTag( ), keyboard );
	app->addTask( Device::getTag( ), device );
}