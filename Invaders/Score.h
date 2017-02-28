#pragma once

class Score {
public:
	Score( );
	virtual ~Score( );

	void reset( );
	void add( int score );
	int getScore( ) const;
private:
	int _score;
};

