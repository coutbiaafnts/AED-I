#include <iostream>
#include <windows.h>
#include <list>

using namespace std;

struct task
{
    string title;
    string text;
    int priority;
};

list<task> tasksList;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 11);

    int menu();
    void addTask(), showTasks();

    system("cls");

    int optionMenu;

    optionMenu = menu();

    switch (optionMenu)
    {
    case 1:
        addTask();
        break;
    case 2:
        showTasks();
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
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

int menu()
{
    int option;

    cout << ">>--------------------------------- LISTA DE TAREFAS ---------------------------------<<" << endl;
    cout << "1. Adicionar tarefa" << endl;
    cout << "2. Listar tarefas" << endl;
    cout << "3. Organizar por prioridade" << endl;
    cout << "4. Deletar tarefa" << endl;
    cout << "0. Sair" << endl;
    cout << ">>----------------------------------------------------------------------------------------<<" << endl
         << endl;
    cout << "   Digite uma opção: ";
    cin >> option;

    return option;
}

void addTask()
{
    system("cls");
    task newTask;
    
    cout << ">>--------------------------------- ADICIONANDO TAREFA ---------------------------------<<" << endl;
    cout << "   Insira o título: ";
    cin.ignore();
    getline(cin, newTask.title);
    cout << "   Insira a tarefa: ";
    getline(cin, newTask.text);
    cout << "   Insira a prioridade de (1) a (5): ";
    cin >> newTask.priority;

    tasksList.push_back(newTask);

    Sleep(1500);
    cout << "   Tarefa adicionada com sucesso!";
}

void showTasks(){
    system("cls");
    cout << ">>--------------------------------- LISTANDO TAREFAS ---------------------------------<<" << endl;

    
}