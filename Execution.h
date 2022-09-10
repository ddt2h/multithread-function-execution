#include <thread>
#include <chrono>

class ExecuteEvery
{
private:
    static void loopInnerFunc(void (*func)(), int interval_millis)
    {
        for (;;)
        {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval_millis));
        }
    }
public:
    std::thread t1;
    ExecuteEvery()
    {
        
    }
    
    void startExecution(void (*func)(), int interval_millis)
    {
        t1 = std::thread(loopInnerFunc, func, interval_millis);
        t1.detach();
    }
    void endExecution()
    {
        t1.join();
        delete &t1;
    }

};