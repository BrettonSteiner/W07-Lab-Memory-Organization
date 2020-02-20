#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char * passMessage = ":)";
const char * failMessage = ":(";

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
   char text[8] = "*MAIN**";
   long number = 123456;
   void (*pointerFunction)() = fail;
   const char * message = failMessage;

   // display the initial values of the local variables
   cout << "main() : " << (void *)main << endl;
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   // call the other functions
   one(number + 111111);     // 234567

   // display the new values of the local variables
   cout << "main() - after\n";
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   return 0;
}

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char * p)
{
   string output;
   for (int i = 0; i < 8; i++)
       output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number)               // 234567
{
   char text[8] = "**ONE**";

   cout << "one() : " << (void *)one << endl;
   cout << "\tmessage: " << (void *)failMessage << endl;
   cout << "\tfail():  " << (void *)fail        << endl;

   two(number + 111111);    // 345678
}

/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number)              // 345678
{
   // start your display of the stack from this point
   long bow = number + 111111;     // 456789
   char text[8] = "**TWO**";
   long * pLong = NULL;
   char * pChar = NULL;

   // header for our table. Use these setw() offsets in your table
   cout << '[' << setw(2) << 'i' << ']'
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

   for (long i = 24; i >= -4; i--)
   {
      ////////////////////////////////////////////////
      // Insert code here to display the callstack
      void* offset = (void*)(&bow) + i * 8;
      cout << '[' << setw(2) << i << ']'
           << setw(15) << offset
           << setw(20) << hex << *(int*)offset
           << setw(20) << dec << *(int*)offset
           << setw(18) << displayCharArray((char*)offset)
           << endl;
      //
      ////////////////////////////////////////////////
   }

   ////////////////////////////////////////////////
   // Insert code here to change the variables in main()
                                                                                
   // change text in main() to "*main**"
   *(char*)((void*)(&bow) + 153) = 'm';
   *(char*)((void*)(&bow) + 154) = 'a';
   *(char*)((void*)(&bow) + 155) = 'i';
   *(char*)((void*)(&bow) + 156) = 'n';

   // change number in main() to 654321
   *(long*)((void*)(&bow) + 22 * 8) = 654321;
   
   // change pointerFunction in main() to point to pass
   void (*func)() = (void (*)())((void*)(&bow) + 24 * 8);
   func = pass;

   // change message in main() to point to passMessage
   const char* message = (const char*)((void*)(&bow) + 19 * 8);
   message = passMessage;

   //
   ////////////////////////////////////////////////
}
