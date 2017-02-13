#pragma once

class Bullet {
public:
	Bullet( int x, int y, bool dir_down );
	virtual ~Bullet( );
	void update( );
	void draw( );
	int getRatioX( ) const;
	int getRatioY( ) const;
	bool dirDown( ) const;
	bool outofScreen( ) const;
private:
	int _ratio_x;
	int _ratio_y;
	bool _dir_down;
};
