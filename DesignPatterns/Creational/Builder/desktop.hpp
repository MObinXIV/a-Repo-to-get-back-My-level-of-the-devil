#ifndef DESKTOP_H
#define DESKTOP_H 
#include <iostream>
using namespace std;
class Desktop{
    string monitor;
     string keyBoard;
     string mouse;
     string speaker;
     string ram;
     string preprocessor;
     string motherBoard;
 
     public:
 
     void setMonitor(string monitor){
         this->monitor=monitor;
     }
 
     void setKeyBoard (string keyBoard){
 
         this->keyBoard=keyBoard;
     }
 
     void setMouse (string mouse){
         this->mouse=mouse;
     }
 
     void setSpeaker(string speaker){
         this->speaker=speaker;
     }
 
     void setRam(string ram){
         this->ram=ram;
     }
 
     void setPreprocessor(string preprocessor){
         this->preprocessor=preprocessor;
     }
 
     void setMotherBoard(string motherBoard){
         this->motherBoard=motherBoard;
     }
 
     void showSpecs(){
         cout<<"---------------------------------------------"<<endl;
 
         cout<<"Monitor "<<monitor<<endl;
         cout<<"keyboard "<<keyBoard<<endl;
 
         cout<<"Mouse "<<mouse<<endl;
 
         cout<<"Speaker "<<speaker<<endl;
 
         cout<<"Ram "<<ram<<endl;
 
         cout<<"preprocessor "<<preprocessor<<endl;
 
         cout<< "MotherBoard "<<motherBoard<<endl;
         cout << "---------------------------------------------" << endl;
     }
  };
#endif // !