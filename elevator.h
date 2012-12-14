#if !defined(ELEVATOR_H)
#define ELEVATOR_H
#include <stdlib.h>
class Elevator 
{
    enum elevator_state
    {
      STATE_STOP,
      STATE_DOWN,
      STATE_UP,
    };
    enum elevatorDoorsState
    {
      DOORS_OPEN,
      DOORS_CLOSE,      
    };
    private:
      float speed;
      elevator_state moveState;
	  elevatorDoorsState doorsState;
      int numElevator;
      float elevation;
      static int countElev;
	  bool buttonUpPressed;
	  bool buttonDownPressed;
	  
    public:
      Elevator(float sp);
      void processTime(timeval *);
      float getCurrentFloor();
};
#endif