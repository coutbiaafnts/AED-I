#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

int welcome();
void addExpense(), listExpense(), editExpense(), removeExpense();

vector<int> expenses;
vector<int>::iterator numb;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 11);

    system("cls");

    int optionMenu;

    optionMenu = welcome();

    switch (optionMenu)
    {
    case 1:
        addExpense();
        break;
    case 2:
        listExpense();
        main();
    case 3:
        editExpense();
        main();
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
    cout << "5. Sair" << endl;
    cout << ">>----------------------------------------------------------------------------------------<<" << endl
         << endl;
    cout << "Digite uma opção: ";
    cin >> option;

    return option;
}

void addExpense()
{
    system("cls");
    int opt, expense;

    cout << ">>--------------------------------- ADICIONAR DESPESA ---------------------------------<<" << endl
         << endl;
    cout << "Informe o tipo da despesa (1. Ganho | 2. Gasto): ";
    cin >> opt;

    if (opt == 1)
    {
        cout << "Informe o valor: ";
        cin >> expense;
        expenses.push_back(expense);
        main();
    }
    else if (opt == 2)
    {
        cout << "Informe o valor com um (-) antes do número: ";
        cin >> expense;
        expenses.push_back(expense);
        main();
    }
    else if (opt != 1 && opt != 2)
    {
        system("cls");
        cout << "!ERROR: Opção inválida." << endl;
        Sleep(1500);
        addExpense();
    }
}

void listExpense()
{
    system("cls");
    cout << ">>--------------------------------- LISTANDO DESPESAS ---------------------------------<<" << endl
         << endl;
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << i + 1 << ". : R$" << expenses[i] << endl;
    }
    system("pause");
}

void editExpense()
{
    system("cls");

    int number;

    cout << ">>--------------------------------- EDITANDO DESPESAS ---------------------------------<<" << endl
         << endl;
    cout << "Informe a posição da despesa: ";
    cin >> number;

    numb = expenses.begin();
    expenses.insert(numb, number);
}