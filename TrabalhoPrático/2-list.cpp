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

int menu();
void addTask(), showTasks(), sortTasks(), deleteTask(), taskDone();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 11);

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
        sortTasks();
        break;
    case 4:
        deleteTask();
        break;
    case 5:
        taskDone();
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
    cout << "5. Marcar tarefa como concluída" << endl;
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
    Sleep(1500);
    main();
}

void showTasks()
{
    system("cls");
    cout << ">>--------------------------------- LISTANDO TAREFAS ---------------------------------<<" << endl
         << endl;

    if (!tasksList.empty())
    {
        for (auto task : tasksList)
        {
            cout << "   Título: " << task.title << endl;
            cout << "   Tarefa: " << task.text << endl;
            cout << "   Prioridade: " << task.priority << endl
                 << endl;
        }
    }
    else
    {
        cout << "   Nenhuma tarefa foi inserida!" << endl
             << endl;
    }

    cout << ">>--------------------------------<<" << endl;
    system("pause");
    main();
}

bool verifyPriority(task a, task b)
{
    return a.priority < b.priority;
}

void sortTasks()
{
    system("cls");
    cout << ">>--------------------------------- ORGANIZANDO TAREFAS ---------------------------------<<" << endl;

    if (!tasksList.empty())
    {
        cout << "   Em processamento..." << endl;
        tasksList.sort(verifyPriority);
        cout << endl
             << endl;
        Sleep(1500);
        cout << "   Tarefas organizadas com sucesso!" << endl;
        Sleep(1500);
    }
    else
    {
        cout << "   Nenhuma tarefa foi inserida!" << endl
             << endl;
        Sleep(1500);
    }

    main();
}

void deleteTask()
{
    system("cls");
    int position;
    cout << ">>--------------------------------- DELETANDO TAREFA ---------------------------------<<" << endl;
    if (!tasksList.empty())
    {
        cout << "   Informe a posição da despesa: ";
        cin >> position;

        auto it = tasksList.begin();
        advance(it, position - 1);

        if (it != tasksList.end())
        {
            tasksList.erase(it);
        }

        cout << "   Em processamento..." << endl;
        Sleep(1500);
        cout << "   Tarefa deletada com sucesso..." << endl;

    }
    else
    {
        cout << "   Nenhuma tarefa foi inserida!" << endl
             << endl;
        Sleep(1500);
    }

    main();
}

void taskDone(){
    system("cls");
    cout << ">>--------------------------------- CONCLUINDO TAREFA ---------------------------------<<" << endl;
    if (!tasksList.empty()){
        cout << "   Marcando a 1ª tarefa como concluída..." << endl;
        tasksList.pop_front();
        cout << "   Concluída!" << endl;
        Sleep(1500);
    }
    else
    {
        cout << "   Nenhuma tarefa foi inserida!" << endl
             << endl;
        Sleep(1500);
    }
    main();
}