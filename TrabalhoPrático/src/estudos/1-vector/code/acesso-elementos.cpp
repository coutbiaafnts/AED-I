#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

int main()
{
    steady_clock::time_point startTime = steady_clock::now();
    srand(time(NULL));

    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 14);

    vector<int> vetor_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Determinada posição (3) do vetor: " << vetor_1.at(2) << endl;
    cout << "Última posição do vetor: " << vetor_1.back() << endl;
    cout << "Primeira posição do vetor: " << vetor_1.front() << endl;

    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - startTime);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}