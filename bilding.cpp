#include "bilding.h"
#include "elevator.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <pthread.h>


class MutexLock
{
    public:
    
    MutexLock(pthread_mutex_t * mutex): m(mutex)
    {
        pthread_mutex_lock(m);
        cout << "lock mutex" << endl;
    }
  /*  MutexLock(int e)
    {};
   */ ~MutexLock()
    {
     pthread_mutex_unlock(m);
     cout <<"unlock mutex"<<endl;
    };
    private:
       pthread_mutex_t *m;
}; 



Bilding::Bilding(int l, int n, float height) : allLevel(l),numberElevator(n),heightFloor(height)
{

   cout << "Constructor bilding... " << endl;
   if (n >=10)
		n = 10;
   for (int i = 0; i < n ; i++)
   {
		elevators.push_back(Elevator(1.0));		
	
   }
   for (int i = 0; i < l ; i++)
   {
      levels.push_back(new level(0x0F&rand()));
   }
   cout << "Size elevators =" << n <<endl;
   cout << "Size levels = " << levels.size() << endl;
   call = new direction[n];
};

Bilding::Bilding(): allLevel(10),numberElevator(2),heightFloor(2.5) {};

Bilding::~Bilding()
{
	
   delete [] call;
   cout << "destruction bilding" <<endl;
}

void Bilding::getInfo(void)
{
   cout<< "Level = " << allLevel << ", elevators = " << numberElevator <<endl;
}
/*
void Bilding::callElevator(int floor,direction dir)
{
   if (floor > allLevel)
   {
      cerr << "callElevator call error floor"<< endl;
      return;
   }
   call[floor] = dir;   
      
}
*/
void Bilding::updateTimeLevel(time_t time)
{
		cout << "Bilding updateTime, time = " << time << endl;
		list<level *>::iterator iter;
		for (iter = levels.begin(); iter != levels.end(); iter++)
			(*(*iter)).updateTime(time);
		for (iter = levels.begin(); iter != levels.end(); iter++)
		{			
			(*(*iter)).showButton();			
		}
		cout << endl;
	
}

extern pthread_mutex_t mutexElevator;
void Bilding::updateTimeElevators(timeval *time)
{
    MutexLock m(&mutexElevator);
//   pthread_mutex_lock(&mutexElevator);
   for (int i = 0 ; i < numberElevator ; i++)
     elevators[i].processTime(time);
   //cout << time->tv_usec<<" - " << time->tv_sec<<endl;
  // pthread_mutex_unlock(&mutexElevator);	
}

void Bilding::getFloorStateDirection(const int floorNum,bool &stateUp,bool &stateDown)
{
	list<level *>::iterator iter;
	iter = find_if(levels.begin(),levels.end(),LevelSearch(floorNum));
	if (iter != levels.end())
	{
		(*iter)->getStateButton(stateUp,stateDown);
	}

};

void Bilding::showAllFloorStateDirection()
{
	bool up, down;
	for (int i = 0; i < allLevel; i++)
	{
		getFloorStateDirection(i,up, down);
		cout << "Level (" << i <<") = " << up << "/" << down <<endl;		
	}
};
