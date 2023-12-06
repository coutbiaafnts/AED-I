#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

int welcome();

int main()
{
    steady_clock::time_point startTime = steady_clock::now();
    srand(time(NULL));

    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 14);

    system("cls");

    int optionMenu;

    optionMenu = welcome();

    switch (optionMenu)
    {
    case 1:
        // Adicionar despesa
        break;
    case 2:
        // Listar despesas
        break;
    case 3:
        // Editar despesa
        break;
    case 4:
        // Remover despesa
        break;
    case 5:
        return 0;
    default:
        cout << endl
             << "!ERROR: Opção inválida." << endl;
        Sleep(1500);
        main();
    }

    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - startTime);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}

int welcome()
{
    int option;

    cout << ">>--------------------------------- REGISTRO DE DESPESAS ---------------------------------<<" << endl;

    cout << "1. Adicionar despesa" << endl;
    cout << "2. Listar despesas" << endl;
    cout << "3. Editar despesa" << endl;
    cout << "4. Remover despesa" << endl;
    cout << "5. Sair" << endl
         << endl;
    cout << "Digite uma opção: ";
    cin >> option;

    return option;
}