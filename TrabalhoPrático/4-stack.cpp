#include <iostream>
#include <windows.h>
#include <time.h> 
#include <chrono>
#include <stack> 

using namespace std;
using namespace chrono;

int main() {
    steady_clock::time_point startTime = steady_clock::now();
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));



    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - startTime);
    cout << endl << "-----------------------------------------------------------" << endl << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}