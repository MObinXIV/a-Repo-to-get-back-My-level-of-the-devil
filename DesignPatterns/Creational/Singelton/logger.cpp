#include <iostream>
#include "logger.hpp"
using namespace std; 
int Logger::ctr =0;
Logger*Logger::loggerInstance = nullptr;

mutex Logger :: mtx;
Logger::Logger(){
    ctr++;
    cout<<"new instance created.No of instances is "<<ctr<<endl;
}

void Logger::log(string msg){
    cout<<msg<<endl;
} 

Logger* Logger:: getInstance(){

    if(loggerInstance==nullptr){
    mtx.lock();
    // check if it's the first time 
    if(loggerInstance==nullptr)
    {
        loggerInstance=new Logger();
    }
    mtx.unlock();}
    // if it's already created I return it 
    return loggerInstance;
}