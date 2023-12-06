#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <stack>

using namespace std;
using namespace chrono;

int main() {
   steady_clock::time_point startTime = steady_clock::now();
   srand(time(NULL));

   UINT CPAGE_UTF8 = 65001;
   SetConsoleOutputCP(CPAGE_UTF8);

   HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(colors, 14);

   

   steady_clock::time_point endTime = steady_clock::now();
   duration<double> time = duration_cast<duration<double>>(endTime - startTime);
   cout << endl << "-----------------------------------------------------------" << endl << "Tempo executando: (" << time.count() << ") segundos" << endl;
   return 0;
}