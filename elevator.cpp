#include "elevator.h"
#include <iostream>
using namespace std;

Elevator::Elevator(float sp):speed(sp),elevation(0.0)
{
    Elevator::countElev++;    
    numElevator = countElev;
    cout << "Evevator construction, num =" << numElevator<<endl;   
	doorsState = DOORS_CLOSE;
	moveState = STATE_STOP;
	
}
void Elevator::processTime(timeval *time)
{
	switch (moveState)
	{
		case STATE_STOP:
			
			break;	
		case STATE_DOWN:
			break;
		case STATE_UP:
			break;						
	}
    cout << time->tv_usec << endl;
}

int Elevator::countElev = 0;