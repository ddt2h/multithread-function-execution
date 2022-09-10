# multithread-function-execution
A class that lets you execute a function every given interval of time in a cycle inside a new thread
Example:

#include "Execution.h"

void task()
{
  //do something
}
int main()
{
   ExecuteEvery ex;
   ex.startExecution(task, 100); //execute task every 100 milliseconds
   
   while (true)
   {
   //so the main thread doesn't end
   }
}
