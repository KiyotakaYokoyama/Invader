#pragma once

static const int RATIO = 10;
static const int MOVE_SPEED = 50;
static const int SCREEN_WIDTH = 960;
static const int SCREEN_HEIGHT = 720;
static const int CHARA_WIDTH = 75;
static const int CHARA_HEIGHT = 75;
static const int BULLET_SIZE = 30;

static const enum GRAPHIC {
	GRAPHIC_NONE,
	GRAPHIC_TITLE,
	GRAPHIC_RESULT,
	GRAPHIC_PLAYER,
	GRAPHIC_ENEMY,
	GRAPHIC_BULLET,
	GRAPHIC_BG,
	MAX_GRAPHIC
};