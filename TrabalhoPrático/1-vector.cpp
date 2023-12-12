#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

int welcome();
void addExpense(), showExpenses(), editExpense(), removeExpense(), balance();

vector<double> expenses;
vector<double>::iterator ite;

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
        showExpenses();
        break;
    case 3:
        editExpense();
        break;
    case 4:
        removeExpense();
        break;
    case 5:
        balance();
        break;
    case 0:
        system("cls");
        cout << endl
             << endl
             << "   Saindo...";
        Sleep(400);
        system("taskkill /f /im cmd.exe");
        exit(0);
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
    cout << "5. Visualizar saldo" << endl;
    cout << "0. Sair" << endl;
    cout << ">>----------------------------------------------------------------------------------------<<" << endl
         << endl;
    cout << "   Digite uma opção: ";
    cin >> option;

    return option;
}

void addExpense()
{
    system("cls");

    int opt;
    double expense;

    cout << ">>--------------------------------- ADICIONAR DESPESA ---------------------------------<<" << endl
         << endl;
    cout << "   Informe o tipo da despesa (1. Ganho | 2. Gasto): ";
    cin >> opt;

    if (opt == 1)
    {
        cout << "   Informe o valor: ";
        cin >> expense;
        expenses.push_back(expense);
        main();
    }
    else if (opt == 2)
    {
        cout << "   Informe o valor com um (-) antes do número: ";
        cin >> expense;
        expenses.push_back(expense);
        main();
    }
    else if (opt != 1 && opt != 2)
    {
        system("cls");

        cout << "   !ERROR: Opção inválida." << endl;
        Sleep(1500);
        addExpense();
    }
}

void showExpenses()
{
    system("cls");

    cout << ">>--------------------------------- LISTANDO DESPESAS ---------------------------------<<" << endl
         << endl;

    if (!expenses.empty())
    {
        for (int i = 0; i < expenses.size(); i++)
        {
            cout << i + 1 << ". R$" << expenses[i] << endl;
        }
        system("pause");

        main();
    }
    else
    {
        cout << "   Lista de despesas vazia...";
        Sleep(1500);
        main();
    }
}

void editExpense()
{
    system("cls");

    int position;
    double newExpense;

    cout << ">>--------------------------------- EDITANDO DESPESAS ---------------------------------<<" << endl
         << endl;

    if (!expenses.empty())
    {
        cout << "   Informe a posição da despesa: ";
        cin >> position;
        cout << "   Informe o novo valor: ";
        cin >> newExpense;

        position--;

        cout << "   Alterando o valor da despesa..." << endl;
        Sleep(1500);

        expenses[position] = newExpense;

        main();
    }
    else
    {
        cout << "   Lista de despesas vazia...";
        Sleep(1500);
        main();
    }
}

void removeExpense()
{
    system("cls");

    int position, amount;

    cout << ">>--------------------------------- REMOVENDO DESPESAS ---------------------------------<<" << endl
         << endl;

    if (!expenses.empty())
    {
        cout << "   Informe a posição da despesa: ";
        cin >> position;
        cout << "   Informe quantas posições deseja remover: ";
        cin >> amount;

        position--;

        if (amount == 1)
        {
            cout << "   Removendo despesa..." << endl;
            Sleep(1500);
        }
        else if (amount > 1)
        {
            cout << "   Removendo despesas..." << endl;
            Sleep(1500);
        }

        ite = expenses.begin() + position;
        expenses.erase(ite, ite + amount);

        main();
    }
    else
    {
        cout << "   Lista de despesas vazia...";
        Sleep(1500);
        main();
    }
}

void balance()
{
    system("cls");

    double balance;

    cout << ">>--------------------------------- SALDO ---------------------------------<<" << endl
         << endl;

    if (!expenses.empty())
    {
        cout << "   Verificando saldo..." << endl
             << endl;
        Sleep(1500);

        for (int i = 0; i < expenses.size(); i++)
            balance += expenses[i];

        cout << "   Saldo atual: R$" << balance << endl
             << endl;

        system("pause");
        main();
    }
    else
    {
        cout << "   Lista de despesas vazia...";
        Sleep(1500);
        main();
    }
}