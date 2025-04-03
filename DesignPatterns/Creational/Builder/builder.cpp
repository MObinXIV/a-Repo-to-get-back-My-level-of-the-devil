//Builder design pattern
#include<bits/stdc++.h> 
#include "dellDesktopBuilder.hpp"
#include "hpDescktopBuilder.hpp"
#include "desktopDirector.hpp"
 using namespace std;
 
 

 int main() 
 {    
    HPDesktopBuilder*hp= new HPDesktopBuilder();
    DellDesktopBuilder *dell = new DellDesktopBuilder();

    DesktopDirector*d1 = new DesktopDirector(hp);
    DesktopDirector*d2 = new DesktopDirector(dell);
    Desktop*desktop1= d1->buildDesktop();

     Desktop *desktop2=d2 ->buildDesktop();
     desktop1->showSpecs();

     desktop1->showSpecs();
     delete hp;
     delete dell;
 
     delete d1;
 
     delete d2;

     delete desktop1;
     delete desktop2;

 }
