#if !defined(LEVEL_H)
#define LEVEL_H
#include <list>
#include <vector>
#include "man.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

enum direction
{
    DIRECTION_UP,
    DIRECTION_DOWN
};

class man;
class level
{
    private:
        static const int LEVEL_PEOPLE_MAX = 20;
        int floor;
        static int numLevel;
        int people;		// people live aldays
        list<man> listMen;
		bool buttonUpPressed;
		bool buttonDownPressed;
	//	level(level &l);
    public:
        level(int ple);		
        void updateTime(time_t time);
		void pressButton(direction dir);
	//	void test(void) const;
		int getFloor(void) const ;
		void showButton(void);
		void getStateButton(bool &stateUp, bool &stateDown);
};

class LevelSearch
{
	private:
		int num;
	public:
		LevelSearch(int n): num(n){};
		bool operator() (const level *l) 
		{
			if (l->getFloor() == num)
				return true;
			else
				return false;
				
		};
};
#endif