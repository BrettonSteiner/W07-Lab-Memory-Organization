#include <iostream>
using namespace std;

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
   // add number to stack
   long number = 123456;

   // add number to heap
   int * pointer = new int;

   // display the address values
   cout << "Code:  " << (void*)main << endl;
   cout << "Stack: " << (void*)(&number) << endl;
   cout << "Heap:  " << pointer << endl;

   delete pointer;

   return 0;
}