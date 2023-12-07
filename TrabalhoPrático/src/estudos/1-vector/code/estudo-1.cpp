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

    // cria os vetores sem um tamanho definido
    vector<int> numb_1;
    vector<int> numb_2;

    int size_1, size_2;

    // insere o elemento na última posição do vetor em questão "push.back()"
    numb_1.push_back(1);
    numb_1.push_back(2);
    numb_1.push_back(3);
    numb_1.push_back(4);

    numb_2.push_back(5);
    numb_2.push_back(6);
    numb_2.push_back(7);
    numb_2.push_back(8);

    // troca os elementos de um vetor para o outro
    numb_1.swap(numb_2);

    cout << "Tamanho original dos vetores..." << endl;
    cout << "Tamanho atual do 1º vetor: " << numb_1.size() << endl;
    cout << "Tamanho atual do 2º vetor: " << numb_2.size() << endl;

    // inserindo elementos em determinada posição sem usar iterator
    numb_1.insert(numb_1.end(), 123);       // insere na última posição
    numb_1.insert(numb_1.begin(), 456);     // insere na primeira posição
    numb_1.insert(numb_1.begin() + 1, 678); // insere na segunda posição
    numb_1.insert(numb_1.end() - 1, 910);   // insere na penúltima posição

    cout << endl << "Tamanho após algumas inserções..." << endl;
    cout << "Tamanho atual do 1º vetor: " << numb_1.size() << endl;
    cout << "Tamanho atual do 2º vetor: " << numb_2.size() << endl;

    // removendo elementos em determinada posição sem usar iterator
    numb_1.erase(numb_1.end() - 2); // vai remover o 910 (comente essa linha para ver o 910 impresso)

    cout << endl << "Tamanho após uma remoção..." << endl;
    cout << "Tamanho atual do 1º vetor: " << numb_1.size() << endl;
    cout << "Tamanho atual do 2º vetor: " << numb_2.size() << endl;

    // cada variável recebe o tamanho (número total de itens) do respectivo vetor
    size_1 = numb_1.size();
    size_2 = numb_2.size();

    // método para imprimir(retornar) o primeiro elemento do vetor
    cout << endl << "Primeiro elemento do vetor 1: " << numb_1.front() << endl;
    // método para imprimir(retornar) o último elemento do vetor
    cout << "Último elemento do vetor 1..: " << numb_1.back() << endl;
    // método para imprimir(retornar) o elemento do meio do vetor
    cout << "Elemento do meio do vetor 1.: " << numb_1.at(size_1 / 2) << endl
         << endl;

    // imprime todos os elementos do vetor
    cout << endl
         << ">>----------- VETOR 1 -----------<<" << endl;
    for (int i = 0; i < size_1; i++)
        cout << i + 1 << "º item: " << numb_1[i] << endl;

    // imprime todos os elementos do vetor
    cout << endl
         << ">>----------- VETOR 2 -----------<<" << endl;
    for (int i = 0; i < size_2; i++)
        cout << i + 1 << "º item: " << numb_2[i] << endl;

    // remove os elemento do vetor
    while (!numb_1.empty()) {
        numb_1.pop_back(); // remove o último elemento do vetor 
    }

    // outro método para limpar o vetor
    numb_2.clear();

    cout << endl << "Tamanho após limpeza dos elementos..." << endl;
    cout << "Tamanho atual do 1º vetor: " << numb_1.size() << endl;
    cout << "Tamanho atual do 2º vetor: " << numb_2.size() << endl;

    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - startTime);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}