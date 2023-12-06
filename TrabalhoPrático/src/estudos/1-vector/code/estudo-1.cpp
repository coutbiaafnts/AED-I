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
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    int size1;

    // cria um vetor sem tamanho definido
    vector<int> numb1;

    // cria um vetor com tamanho definido
    vector<int> numb2(5);

    // a variável recebe o tamanho do vetor no momento
    size1 = numb1.size();

    cout << "Tamanho atual do vetor numb1: " << size1 << endl
         << endl;

    numb1.push_back(1);
    numb1.push_back(2);
    numb1.push_back(3);
    numb1.push_back(4);

    size1 = numb1.size();
    cout << "Tamanho atual do vetor numb1: " << size1 << endl << endl;

    for (int i = 0; i < size1; i++)
        cout << i + 1 << " item do vetor: " << numb1[i] << endl;

    

    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - startTime);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}