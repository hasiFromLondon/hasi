/*********************************************
* My first programm on cpp ))
* yep!!!
*
*********************************************/

#include <string>
#include <iostream>
#include "bilding.h"
#include "time.h"
#include <unistd.h>
#include <stdlib.h> 
//#include <Windows.h>
//#include <dos.h>
#include <pthread.h>
#include <sys/time.h>
using namespace std;


void *myThread(void *);
Bilding *ptrBild;
pthread_mutex_t mutexElevator = PTHREAD_MUTEX_INITIALIZER; 

int main (int argc,char * argv[])
{

    cout << "arg =" << argc << endl;
    ptrBild = new Bilding(20,4,3.0);    
    ptrBild->getInfo();
 //   bild.callElevator(10,DIRECTION_UP);
 //   bild.callElevator(99,DIRECTION_DOWN);
    cout << "Hello\n";
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&thread,&attr,&myThread,NULL);
    	
	for (int i = 0 ; i < 100 ; i++)
	{
		ptrBild->updateTimeLevel(time(NULL));
		ptrBild->showAllFloorStateDirection();
		sleep(1);
	}
    return 9;
}

void *myThread(void*)
{
    for (;;)
    {
        //sleep(1);
        struct timeval timeMs;
        gettimeofday(&timeMs,NULL);
//        cout << timeMs.tv_usec;
        ptrBild->updateTimeElevators(&timeMs);
  //      cout << "bbla" << endl;
        
    }
    
}