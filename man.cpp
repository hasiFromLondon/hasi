
#include "man.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

man::man(unsigned int floor,int id, level * lev): baseWishFloor(floor),id(id),probability(0.99)
{
   cout << "construction man of floor ="<< floor << endl; 
   state = MAN_STATE_RELAX;
   myLevel = lev;
};

void man::updateTime(time_t time)
{
	//cout << "Man updateTime, time = " << time << endl;
	//cout << "Im on floor " << myLevel->getFloor() << endl;
	if (state == MAN_STATE_RELAX)
		if (rand()/32768.0 > probability)
		{
			cout << "Im on floor " << myLevel->getFloor() << " and i want down "<< endl;	
			myLevel->pressButton(DIRECTION_DOWN);	
			state = MAN_STATE_WAIT_ELEVATOR;
		}
	if (state == MAN_STATE_WAIT_ELEVATOR)	
	{
	
	}
	//myLevel->test();	
}
