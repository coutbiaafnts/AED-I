#include <iostream>
#include <windows.h>

using namespace std;

const int MAX_ORDERS = 100;

// estrutura de pedido
struct Order
{
    string name;
    string description;
    int tableNumb;
};

// estrutura da fila de pedidos
struct ordersList
{
    Order ordersList[MAX_ORDERS];
    int end = -1;
};

Order orders;

Order readKeyboard();

int menu();
void insertOrder(Order name);
void markAsDone();
void showOrders();
bool checkOrders();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int option = menu();

    do
    {
        switch (option)
        {
        case 1:

            break;

        default:

            break;
        }
    } while (option != 0);

    return 0;
}

int menu()
{
    int option;

    cout << ">>------------------- MENU ------------------<<\n\n";
    cout << "01 - Fazer pedido\n";
    cout << "02 - Marcar pedido como concluído\n";
    cout << "00 - SAIR\n";
    cout << "\n\n>>-------------------------------------------<<\n\n";
    cout << "Digite: ";
    cin >> option;

    system("cls");

    return option;
}