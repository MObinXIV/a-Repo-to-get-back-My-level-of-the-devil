#include<bits/stdc++.h>
#include "logger.hpp"
#include <thread>
using namespace std;
void user1Logs(){
   Logger*log1 = Logger::getInstance();
   log1->log("this is a message from user.1");
}
void user2Logs(){
   Logger*log2= Logger::getInstance();
   log2->log("this is a message from user.2");
}
int main()
{   
   
   thread t1(user1Logs);
   thread t2(user2Logs);
   t1.join();
   t2.join();

}
/*
1- Singleton 
2- Factory method ✅ 
3- Observer 
4- Startegy
5- Decorator
6- Builder 
7- Adapter 
8- Facade 
*/   