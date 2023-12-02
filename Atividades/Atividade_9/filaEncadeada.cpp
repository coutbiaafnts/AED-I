#include <iostream>
#include <windows.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

struct Item
{
    string name;
    int age;
    Item *next;
};

struct Row
{
    Item *first;
    Item *last;
};

Row *row = NULL;

int menu();
void insertItem(), removeItem(), showItems(), createRow();
bool emptyRow();

int main()
{
    steady_clock::time_point firstTime = steady_clock::now();
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    int option;

    row = new Row;

    do
    {
        option = menu();

        switch (option)
        {
        case 1:
            insertItem();
            break;
        case 2:
            removeItem();
            break;
        case 3:
            showItems();
            break;
        default:
            cout << "Opção inválida!...";
            Sleep(3000);
            break;
        }

    } while (option != 0);

    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time = duration_cast<duration<double>>(endTime - firstTime);
    cout << endl
         << "-----------------------------------------------------------" << endl
         << "Tempo executando: (" << time.count() << ") segundos" << endl;
    return 0;
}

// exibe o menu e retorna a opção inserida
int menu()
{
    int option;
    cout << ">>--------- MENU ---------<<" << endl;
    cout << "1 - Inserir item" << endl;
    cout << "2 - Remover item" << endl;
    cout << "3 - Mostrar itens da fila" << endl
         << endl;

    cout << "0. Sair" << endl;
    cout << "Digite: ";
    cin >> option;
    return option;
}

void createRow()
{
    row->first = NULL;
    row->last = NULL;
}

bool emptyRow()
{
    return (row->first == NULL);
}

void insertItem()
{
    Item *newItem = new Item;

    cout << "Insira o nome: ";
    cin >> newItem->name;
    cout << "Insira a idade: ";
    cin >> newItem->age;

    newItem->next = NULL;

    if (emptyRow())
    {
        row->first = newItem;
    }
    else
    {
        row->last->next = newItem;
    }

    row->last = newItem;
    newItem->next = NULL;
}

void showItems()
{
    Item *aux;

    aux = row->first;

    while (aux != NULL)
    {
        cout << "Nome: " << aux->name << endl;
        cout << "Idade: " << aux->age << endl;

        aux = aux->next;
    }
}

void removeItem()
{
    if (!emptyRow())
    {
        Item *aux = row->first;
        cout << ">>--------- REMOVENDO ---------<<" << endl
             << endl;
        cout << "Nome: " << aux->name << endl;
        cout << "Idade: " << aux->age << endl;

        row->first = aux->next;
        if (row->first == NULL)
        {
            row->last = NULL;
        }
        delete aux;
    }
    else
    {
        cout << "Fila vazia!" << endl;
    }
}