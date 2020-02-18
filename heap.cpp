#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************
 * MAIN : Just one function...
 **********************************************/
int main()
{
   // allocate multiple blocks of memory
   long * first  = new long(1234567);
   char * second = new char[16];
   long * third  = new long[2];
       
   // header for our table. Use these setw() offsets in your table
   cout << "[" << setw(2) << 'i' << ']'
        << setw(15) << "address"
        << setw(20) << "hexadecimal"
        << setw(20) << "decimal"
        << setw(18) << "characters"
        << endl;
   cout << "----+"
        << "---------------+"
        << "-------------------+"
        << "-------------------+"
        << "-----------------+\n";
   for (int i = 20; i >= -4; i--)
   {
      ////////////////////////////////////////////////
      // Insert code here to display the heap

      //
      ////////////////////////////////////////////////
    }
    return 0;
}
