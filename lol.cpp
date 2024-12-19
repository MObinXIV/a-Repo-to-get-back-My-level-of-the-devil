#include<iostream>
using namespace std;
int main()
{
   cout<<"hello world"<<endl;
}

/*>>
the linker:

Resolves external references: If your code uses functions or data defined in other files (like libraries), the linker finds those definitions and connects them correctly.
Allocates memory: It assigns memory addresses to different parts of the program (code, data, etc.).
Creates the final executable: It combines all the object files into a single executable file that can be run on the computer.
This process ensures that all the different parts of your program work together correctly and that the program can run independently.
*/