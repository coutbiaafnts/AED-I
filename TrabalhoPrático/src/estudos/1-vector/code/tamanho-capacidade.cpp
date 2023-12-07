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

    // outro método para declarar um vetor
    vector<int> vetor_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Tamanho atual do vetor: " << vetor_1.size() << endl;
    cout << "Tamanho máximo que o vetor pode ter: " << vetor_1.max_size() << endl
         << endl;

    // método que redefine o tamanho do vetor (dentro dos parênteses vai o novo tamanho desejado)
    vetor_1.resize(5);
    cout << "Redefinindo o tamanho do vetor para 5..." << endl;
    cout << "Tamanho atual do vetor: " << vetor_1.size() << endl
         << endl;

    cout << "Capacidade do vetor: " << vetor_1.capacity() << endl; // retorna o maior tamanho que o vetor já teve

    // método para alterar a capacidade de acordo com o tamanho atual do vetor
    vetor_1.shrink_to_fit();
    cout << "Nova capacidade do vetor: " << vetor_1.capacity() << endl;

    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - startTime);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}