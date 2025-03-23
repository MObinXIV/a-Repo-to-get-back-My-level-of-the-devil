#ifndef logger_h
#define logger_h
#include <string>
#include <mutex>
using namespace std;

class Logger{
    private:
    static int ctr;
    static Logger*loggerInstance;
    static mutex mtx;
    Logger();
    //restrict the user from using any constructor
    Logger(const Logger&)=delete;
    // from using operators 
    Logger operator*(const Logger&)=delete;
    ~Logger() {}
    public:
    // functoin to give the constructor
    static Logger*getInstance();
    void log(string msg);
};
#endif // !logger_h
