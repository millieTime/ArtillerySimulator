
#include "test.h"       // for TESTRUNNER
using namespace std;
//#include "ground.h"
#include "position.h"
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
//   Position pos;
//   pos.setMetersX(10.0);
//   pos.setMetersY(10.0);
//   Ground g(pos);
//   g.reset(pos);

   return 0;
}
