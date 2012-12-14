#if !defined(BILDING_H)
#define BILDING_H

#include "elevator.h"
#include "level.h"
#include <time.h>
#include <vector>
#include <list>
using namespace std;


class Bilding
{
    private:        
        vector<Elevator> elevators;
        list<level *> levels;        
        int allLevel;
        int numberElevator;
        direction *call;
        float heightFloor;
		void getFloorStateDirection(int, bool &stateUp, bool &stateDown);
		
    public:
        Bilding(int l,int numberElevator,float);
        Bilding();
        ~Bilding();
        void getInfo(void);
        //void callElevator(int floor,direction dir);
		void updateTimeLevel(time_t time);
		void updateTimeElevators(timeval *time);
		void showAllFloorStateDirection();
};
#endif