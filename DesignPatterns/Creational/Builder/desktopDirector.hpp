#ifndef DISKTOPDIRECTOR
#define DISKTOPDIRECTOR
#include <iostream>
#include "desktopBuilder.hpp"

class DesktopDirector
{

        private:
         DesktopBuilder* deskBuilder; // use a builder

         public:
         // assign builder in constructor
             DesktopDirector(DesktopBuilder *deskBuilder){
                this->deskBuilder=deskBuilder;
             }

    // build the product
             Desktop* buildDesktop(){
                deskBuilder->buildMonitor();
                deskBuilder->buildKeyBoard();
                deskBuilder->buildMouse();
                deskBuilder->buildMotherBoard();
                deskBuilder->buildProcessor();
                deskBuilder->buildRam();
                deskBuilder->buildSpeaker();

                return deskBuilder->getDesktop();
             }
};

#endif // !