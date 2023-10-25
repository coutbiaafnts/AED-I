#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

const int MAX_ORDERS = 100;

// estrutura de pedido
struct Order
{
    string customerName;
    string description;
    int tableNumb;
};

// estrutura da fila de pedidos
struct OrdersRow
{
    int end = -1;
    Order ordersList[MAX_ORDERS];
};

OrdersRow orders;

int menu();

void insertOrder(Order newOrder);
void markAsDone();
void showOrders();
void showNextOrder();

bool checkOrders();

Order readKeyboard();

void importOrders();
void exportOrders();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    Order order;

    int option;
    do
    {
        option = menu();

        switch (option)
        {
        case 0:
            // sai do programa
            cout << "Saindo...";
            Sleep(3500);
            exit(0);

        case 1:
            // lê as informações do pedido
            order = readKeyboard();
            cout << "Anotando pedido...\n";
            // insere no vetor
            insertOrder(order);
            cout << "Pedido anotado com sucesso!\n";
            Sleep(3500);
            break;

        case 2:
            // marca o primeiro pedido da fila como concluído
            markAsDone();
            break;

        case 3:
            showOrders();
            break;

        case 4:
            showNextOrder();
            break;

        case 5:
            exportOrders();
            break;

        case 6:
            importOrders();
            break;

        default:
            cout << "Opção inválida! Tente novamente...";
            Sleep(3500);
            break;
        }
        system("cls");
    } while (option != 0);

    return 0;
}

// exibe menu para navegação no sistema e retorna a opção
int menu()
{
    int option;

    cout << ">>------------------- MENU ------------------<<\n\n";
    cout << "01 - Fazer pedido\n";
    cout << "02 - Marcar pedido como concluído\n";
    cout << "03 - Mostrar pedidos\n";
    cout << "04 - Mostrar próximo pedido\n";
    cout << "05 - Salvar pedidos\n";
    cout << "04 - Importar pedidos\n";
    cout << "00 - SAIR\n";
    cout << "\n\n>>---------------------------------------<<\n\n";
    cout << "Digite: ";
    cin >> option;

    return option;
}

// verifica se existem pedidos na fila
bool checkOrders()
{
    // se o fim da fila por maior que (-1), ou seja, conteúdo existente
    if (orders.end > -1)
        return true;
    return false;
}

Order readKeyboard()
{
    Order order;

    cout << ">>------------------- ANOTANDO PEDIDO ------------------<<\n\n";
    cin.ignore();
    cout << "Nome do cliente: ";
    getline(cin, order.customerName);
    cout << "Descrição do pedido: ";
    getline(cin, order.description);
    cout << "Número da mesa: ";
    cin >> order.tableNumb;

    return order;
}

// insere o pedido na fila
void insertOrder(Order newOrder)
{
    // se o fim da fila for menor que o tamanho máximo do vetor ele anota o pedido
    if (orders.end < MAX_ORDERS - 1)
    {
        orders.end++;
        // insere o novo pedido no fim da fila
        orders.ordersList[orders.end] = newOrder;
    }
}

void markAsDone()
{
    int option, table = orders.ordersList[0].tableNumb;
    
    // verifica se existem pedidos anotados
    if (checkOrders())
    {

        // verifica se realmente quer marcar como concluído
        cout << "Digite (1) para marcar o pedido da mesa " << table << " como concluído!";
        if (option == 1)
        {
            // reorganiza a fila sobrescrevendo os pedidos do início
            for (int i = 0; i < orders.end; i++)
                orders.ordersList[i] = orders.ordersList[i + 1];
            orders.end--;
            cout << " Pedido da mesa " << table << " marcado como concluído!\n";
        }
    }
}

void showOrders()
{
    cout << "\n>>------------------- PEDIDOS ------------------<<\n\n";
    for (int i = 0; i <= orders.end; i++)
    {
        cout << "Nome do cliente: " << orders.ordersList[i].customerName << "\n";
        cout << "Descrição do pedido: " << orders.ordersList[i].description << "\n";
        cout << "Número da mesa: " << orders.ordersList[i].tableNumb << "\n\n";
    }
    cout << "\n>>----------------------------------------------<<\n\n";

    system("pause");
}

void showNextOrder()
{
    cout << "\n>>------------------- PRÓXIMO PEDIDO ------------------<<\n\n";
    cout << "Nome do cliente: " << orders.ordersList[1].customerName << "\n";
    cout << "Descrição do pedido: " << orders.ordersList[1].description << "\n";
    cout << "Número da mesa: " << orders.ordersList[1].tableNumb << "\n\n";
    cout << "\n>>-----------------------------------------------------<<\n\n";

    system("pause");
}

void importOrders()
{
    ifstream read;

    read.open("pedidos.txt");

    if (read.fail())
        cerr << "\aError: Não foi possível abrir o arquivo\n";
    else
    {
        for (int i = 0; i <= orders.end; i++)
        {
            getline(read >> ::ws, orders.ordersList[i].customerName);
            cout << orders.ordersList[i].customerName;
            getline(read >> ::ws, orders.ordersList[i].description);
            cout << orders.ordersList[i].description;
            read >> orders.ordersList[i].tableNumb;
            cout << orders.ordersList[i].tableNumb << "\n";
        }

        cout << "Importação realizada!";
        Sleep(3500);
        read.close();
    }
}

void exportOrders()
{
    ofstream write;

    write.open("pedidos.txt");

    if (!write.is_open())
        cerr << "\aError: Não foi possível abrir o arquivo\n";
    else
    {
        for (int i = 0; i <= orders.end; i++)
        {
            write << orders.ordersList[i].customerName << endl;
            write << orders.ordersList[i].description << endl;
            write << orders.ordersList[i].tableNumb << endl;
        }
        cout << "Exportação realizada!";
        Sleep(3500);
        write.close();
    }
}