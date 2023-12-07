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
    vector<int>::iterator it; // declarando um iterator (tipo de iterador/cursor de acesso aleatório que pode ler ou modificar qualquer elemento em um vetor)
    vector<int> vetor_2;

    // atribuir elementos a um vetor ou substitui se já tiver elementos
    vetor_2.assign(10, 0); // (quantidade de elementos, elemento que quero atribuir)

    cout << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    // atribuindo os elementos do vetor_1 ao vetor_2
    vetor_2.assign(vetor_1.begin(), vetor_1.end()); // (início do vetor_1 ao final do mesmo)

    cout << endl
         << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    cout << endl
         << "Removendo o último elemento do vetor 2..." << endl;
    vetor_2.pop_back();
    cout << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    cout << endl
         << "Adicionando o valor 10 à ultima posição do vetor..." << endl;
    vetor_2.push_back(10);
    cout << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    // inserir um elemento utilizando iterator
    it = vetor_2.begin();
    vetor_2.insert(it, 99);

    cout << endl
         << "Adicionando o valor 99 à primeira posição do vetor..." << endl;
    cout << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    // inserindo determinada quantidade de elementos
    it = vetor_2.begin();
    vetor_2.insert(it, 5, 99);
    cout << endl
         << "Adicionando o valor 99, 5 vezes na primeira posição do vetor..." << endl;
    cout << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    // removendo determinada quantidade de elementos
    it = vetor_2.begin();
    vetor_2.erase(vetor_2.begin(), vetor_2.begin() + 6);
    cout << endl
         << "Removendo o valor 99, 6 vezes na primeira posição do vetor..." << endl;
    cout << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    cout << endl
         << "Atribuindo novos valores ao vetor..." << endl;
    vetor_2 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    // trocando os elementos entre os vetores
    cout << endl
         << "Trocando os elementos..." << endl;
    vetor_2 = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vetor_2.swap(vetor_1);
    cout << "Estado atual do vetor 1:" << endl;
    for (int i = 0; i < vetor_1.size(); i++)
        cout << vetor_1.at(i) << " ";
    cout << endl << "Estado atual do vetor 2:" << endl;
    for (int i = 0; i < vetor_2.size(); i++)
        cout << vetor_2.at(i) << " ";

    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - startTime);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}