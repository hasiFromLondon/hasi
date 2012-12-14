#include "level.h"

#include <iostream>
using namespace std;
level::level(int ple)
{
  floor = numLevel;
  if (ple > LEVEL_PEOPLE_MAX)
      ple = LEVEL_PEOPLE_MAX;
  if (ple < 0 )
      ple = 0;
  people = ple;    
  for (int i = 0; i < people ; i++)
  //for (int i = 0; i < 50 ; i++)
	listMen.push_back(man(i,1000,this));
	
  cout << "construction level (floor) = " << floor << " with people = " << listMen.size() << endl;    
  numLevel++;
  buttonUpPressed = false;
  buttonDownPressed = false;
  
//  updateTime(10);
}
void level::showButton(void)
{
	
	cout << floor << "/" << (buttonUpPressed?1:0) << ":" << (buttonDownPressed?1:0 ) << "__";
	
}
int level::getFloor(void) const
{
	//cout << "Floor = "<<floor << endl;
	return floor;
}

/*void level::test(void) const
{
		cout << "level Test= " <<  endl;
}*/
void level::updateTime(time_t time)
{
		int size = listMen.size() ;
		
		cout << "Level updateTime, time = " << time << ", men = " << size << " floor = " << floor << endl;
	
		list<man>::iterator iter;
		for (iter = listMen.begin(); iter != listMen.end(); iter++)
		{
			iter->updateTime(time);
		}
		
		
}
void level::pressButton(direction dir)
{
	if (dir == DIRECTION_UP)
	{
		
		buttonUpPressed = true;
	}
	if (dir == DIRECTION_DOWN)	
	{
		if (floor != 0)
			buttonDownPressed = true;
	}
}

void level::getStateButton(bool &stateUp, bool &stateDown)
{
	stateUp = buttonUpPressed;
	stateDown = buttonDownPressed;
}
const int level::LEVEL_PEOPLE_MAX;

int level::numLevel = 0;
