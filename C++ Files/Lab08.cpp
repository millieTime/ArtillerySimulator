///*************************************************************
// * 1. Name:
// *      The Key
// * 2. Assignment Name:
// *      Lab 08: M777 Howitzer
// * 3. Assignment Description:
// *      Simulate firing the M777 howitzer 15mm artillery piece
// * 4. What was the hardest part? Be as specific as possible.
// *      ??
// * 5. How long did it take for you to complete the assignment?
// *      ??
// *****************************************************************/


#include "test.h"       // for TESTRUNNER
using namespace std;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();

   return 0;
}