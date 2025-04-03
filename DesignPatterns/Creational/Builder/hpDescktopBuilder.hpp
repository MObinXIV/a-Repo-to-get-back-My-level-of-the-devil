#ifndef HPDESCKTOP_H
#define HPDESCKTOP_H
#include<iostream>
#include "desktopBuilder.hpp"
using namespace std; 

class HPDesktopBuilder : public DesktopBuilder
{
   void buildMonitor()
   {
    desktop->setMonitor("HP Monitor");
   }

   void buildKeyBoard()
   {
    desktop->setSpeaker("HP KeyBoard");
   }

   void buildSpeaker()
   {
    desktop->setKeyBoard("HP Speaker");
   }

   void buildRam()
   {
    desktop->setRam("HP Ram");
   }
   void buildProcessor()
   {
    desktop->setPreprocessor("CoreI7");
   }
   void buildMotherBoard()
   {
    desktop->setMotherBoard("HpMotherBoard");
   }

   void buildMouse()
   {
    desktop->setMouse("HpMOuse");
   }
};


#endif // !