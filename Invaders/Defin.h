#pragma once

static const int IVD_RATIO = 10;
static const int MOVE_SPEED = 50;
static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;

static const int CHARACTER_HEIGHT = 20;

static const enum GRAPHIC {
	GRAPHIC_NONE,
	GRAPHIC_PLAYER,
	GRAPHIC_ENEMY,
	GRAPHIC_BULLET,
	MAX_GRAPHIC
};