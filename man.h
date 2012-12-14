#if !defined(MAN_H)
#define MAN_H
#include <time.h>
#include "level.h"

enum manState
{
	MAN_STATE_RELAX,			// man is doing nothing	
	MAN_STATE_WAIT_ELEVATOR,	// man is waiting	
	
};
class level;
class man
{
    private:
        unsigned int baseWishFloor;
        int id;
		manState state;
		float probability;
		level *myLevel;
    public:
        man(unsigned int floor,int id, level * lev);
		void updateTime(time_t time);
};

#endif