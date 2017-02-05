#pragma once

class Phase {
public:
	enum NEXT {
		NEXT_CONTINEU,
		NEXT_TITLE,
		NEXT_STAGE,
		NEXT_RESULT,
	};
public:
	Phase( );
	virtual ~Phase( );
	virtual NEXT update( ) = 0;
};
