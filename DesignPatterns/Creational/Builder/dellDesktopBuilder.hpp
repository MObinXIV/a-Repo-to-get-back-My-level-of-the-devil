#ifndef DELLDESKTOPBUILDER_H
#define DELLDESKTOPBUILDER_H
#include<iostream>
#include "desktopBuilder.hpp"
using namespace std; 

class DellDesktopBuilder:public DesktopBuilder{
    void buildMonitor(){
        desktop->setMonitor("Dell Monitor");
    }

    void buildKeyBoard(){
        desktop->setSpeaker("Dell KeyBoard");
    }

   void buildSpeaker(){
    desktop->setKeyBoard("Dell Speaker");
   }

   void buildRam()
   {
    desktop->setRam("Dell Ram");

   }
   void buildProcessor(){
    desktop->setPreprocessor("CoreI7");
   }
   void buildMotherBoard(){
    desktop->setMotherBoard("dellMotherBoard");
   }

   void buildMouse()
   {
        desktop ->setMouse("dellMOuse");
   }
   
};
#endif // 