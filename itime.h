#if !defined(ITIME_H)
#define ITIME_H

#include <sys/time.h>
#include <iostream>
class Itime
{
    public:
        Itime(std::string s):str(s) 
        {
            std::cout << "Start chronometry: " << str << endl;
            gettimeofday(&timeBegin,NULL);
        };
        ~Itime()
        {
            struct timeval timeEnd;
            gettimeofday(&timeEnd,NULL);
            int s = timeEnd.tv_sec - timeBegin.tv_sec;
            int ms = (timeEnd.tv_usec > timeBegin.tv_usec)?(timeEnd.tv_usec - timeBegin.tv_usec):(s -= 1,timeEnd.tv_usec - timeBegin.tv_usec + 1000000);
            std::cout << "Stop chronometry: " << str << ": " << s << "." << ms << endl;    
        };
    private:
        std::string str;
        struct timeval timeBegin;                                                                                                                                                       
}; 
                                                              
#endif
                                                                                                                                                                