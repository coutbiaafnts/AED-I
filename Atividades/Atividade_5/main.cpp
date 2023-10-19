#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>

using namespace std;

ofstream write;
ifstream read;

const int maxBooks = 100;

struct Book
{
    int code;
    string name;
    string edit;
    int yearOfPublication;
};

struct listOfBooks
{
    int countBooks = 0;
    Book books[maxBooks];
};

listOfBooks list;

int menu();
int menuEdit();

void insertStart(Book newBook);
void insertEnd(Book newBook);
void insertInPosition(Book newBook, int position);

void removeStart();
void removeEnd();
void removeInPosition(int position);

void editBook(int code);
void changePosition(int p1, int p2);

void showList();

Book readKeyboard();

void importList();
void exportList();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int option, position, code, p1, p2;

    Book book;

    do
    {
        system("cls");

        option = menu();

        switch (option)
        {
        case 0:
            // 00 - Sair do programa
            cout << "Saindo...";
            break;

        case 1:
            // 01 - Inserir livro no início.
            book = readKeyboard();
            cout << "Inserindo livro...\n";
            insertStart(book);
            break;

        case 2:
            // 02 - Inserir livro no fim.
            book = readKeyboard();
            cout << "Inserindo livro...\n";
            insertEnd(book);
            break;

        case 3:
            // 03 - Inserir livro em uma posição.
            book = readKeyboard();
            cout << "Digite a posição: ";
            cin >> position;
            cout << "Inserindo livro...\n";
            insertInPosition(book, position);
            break;
        case 4:
            // 04 - Remover livro do início.
            cout << "Removendo livro...\n";
            removeStart();
            break;
        case 5:
            cout << "Removendo livro...\n";
            removeEnd();
            // 05 - Remover livro do fim.
            break;
        case 6:
            cout << "Posição do livro: ";
            cin >> position;
            cout << "Removendo livro...\n";
            removeInPosition(position);
            // 06 - Remover livro de uma posição.
            break;
        case 7:
            // 07 - Atualizar dados de um livro.
            showList();

            cout << "Código do livro: ";
            cin >> code;
            editBook(code);
            break;
        case 8:
            // 08 - Trocar posição de um livro.
            cout << "Digite a posição do primeiro livro: ";
            cin >> p1;
            cout << "Digite a posição do segundo livro: ";
            cin >> p2;
            changePosition(p1, p2);
            break;
        case 9:
            // 09 - Importar lista de livros.
            importList();
            break;
        case 10:
            // 10 - Exportar lista de livros.
            exportList();
            break;
        case 11:
            // 11 - Mostrar lista de livros.
            showList();
            break;
        default:
            cout << "Opção inválida!\n";
            Sleep(1000);
            break;
        }
    } while (option != 0);

    cout << endl
         << endl;
    return 0;
}

int menu()
{
    int option;

    cout << ">>------------------- MENU ------------------<<\n\n";
    cout << "01 - Inserir livro no início\n";
    cout << "02 - Inserir livro no fim\n";
    cout << "03 - Inserir livro em uma posição\n";
    cout << "04 - Remover livro do início\n";
    cout << "05 - Remover livro do fim\n";
    cout << "06 - Remover livro de uma posição\n";
    cout << "07 - Atualizar dados de um livro\n";
    cout << "08 - Trocar posição de um livro\n";
    cout << "09 - Importar lista de livros\n";
    cout << "10 - Exportar lista de livros\n";
    cout << "11 - Mostrar lista de livros\n";
    cout << "00 - SAIR\n";
    cout << "\n\n>>-------------------------------------------<<\n\n";
    cout << "Digite: ";
    cin >> option;

    system("cls");

    return option;
}

int menuEdit()
{
    int option;

    cout << ">>------------------- EDITAR ------------------<<\n\n";
    cout << "01 - Editar código\n";
    cout << "02 - Editar nome\n";
    cout << "03 - Editar editora\n";
    cout << "04 - Editar ano de publicação\n";
    cout << "00 - SAIR\n";
    cout << "\n\n>>-------------------------------------------<<\n\n";
    cout << "Digite: ";
    cin >> option;

    system("cls");
    return option;
}

void insertStart(Book newBook)
{
    if (list.countBooks < maxBooks)
    {
        for (int i = list.countBooks; i > 0; i--)
            list.books[i] = list.books[i - 1];
        list.books[0] = newBook;
        list.countBooks = list.countBooks + 1;
        cout << "Livro inserido com sucesso!";
        Sleep(1000);
    }
}

void insertEnd(Book newBook)
{
    if (list.countBooks < maxBooks)
    {
        list.books[list.countBooks] = newBook;
        list.countBooks = list.countBooks + 1;
        cout << "Livro inserido com sucesso!";
        Sleep(1000);
    }
}

void insertInPosition(Book newBook, int position)
{
    if (list.countBooks < maxBooks)
    {
        for (int i = list.countBooks; i > 0; i--)
            list.books[i] = list.books[i - 1];
        list.books[position] = newBook;
        list.countBooks = list.countBooks + 1;
        cout << "Livro inserido com sucesso!";
        Sleep(1000);
    }
}

void removeStart()
{
    if (list.countBooks < maxBooks)
    {
        cout << "Removendo o livro: ";
        cout << list.books[0].code << " ";
        cout << list.books[0].name << endl;
        Sleep(1000);

        for (int i = 0; i < list.countBooks; i++)
            list.books[i] = list.books[i + 1];
        list.countBooks = list.countBooks - 1;
        cout << "Livro removido com sucesso!";
        Sleep(1000);
    }
}

void removeEnd()
{
    if (list.countBooks > 0)
    {
        cout << "Removendo o livro: ";
        cout << list.books[list.countBooks - 1].code << " ";
        cout << list.books[list.countBooks - 1].name << endl;
        list.countBooks = list.countBooks - 1;
        cout << "Livro removido com sucesso!";
        Sleep(1000);
    }
}

void removeInPosition(int position)
{
    if (list.countBooks > 0 && position < list.countBooks)
    {
        cout << "Removendo o livro: ";
        cout << list.books[position].code << " ";
        cout << list.books[position].name << endl;

        for (int i = position; i < list.countBooks; i++)
            list.books[i] = list.books[i - 1];

        list.countBooks = list.countBooks - 1;
        cout << "Livro removido com sucesso!";
        Sleep(1000);
    }
}

void showList()
{
    int option;

    do
    {
        cout << "\n>>------------------- LISTA ------------------<<\n\n";
        for (int i = 0; i < list.countBooks; i++)
        {
            cout << list.books[i].code << " - ";
            cout << list.books[i].name << endl;
        }
        cout << "\n>>--------------------------------------------<<\n\n";

        cout << "Digite (1) para voltar ao menu: ";
        cin >> option;
    } while (option != 1);
}

Book readKeyboard()
{
    Book book;

    cout << ">>------------------- LIVRO ------------------<<\n\n";
    cout << "Código: ";
    cin >> book.code;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, book.name);
    cout << "Editora: ";
    getline(cin, book.edit);
    cout << "Ano de publicação: ";
    cin >> book.yearOfPublication;

    return book;
}

void editBook(int code)
{
    int option;

    for (int i = 0; i < list.countBooks; i++)
    {
        if (list.books[i].code == code)
        {
            option = menuEdit();

            do
            {
                switch (option)
                {
                case 0:
                    // sair
                    cout << "Saindo...";
                    Sleep(1000);
                    break;
                case 1:
                    // editar código
                    cout << "Digite o código: ";
                    cin >> list.books[i].code;
                    break;
                case 2:
                    // editar editora
                    cout << "Digite o nome: ";
                    cin >> list.books[i].name;
                    break;
                case 3:
                    // editar ano de publicação
                    cout << "Digite o ano de publicação: ";
                    cin >> list.books[i].yearOfPublication;
                    break;
                default:
                    cout << "Opção inválida!\n";
                    Sleep(1000);
                    system("cls");
                    break;
                }
            } while (option != 0);
        }
    }
}

void changePosition(int p1, int p2)
{
    Book aux;
    aux = list.books[p1];
    list.books[p1] = list.books[p2];
    list.books[p2] = aux;
}

void importList()
{
    read.open("booksList.txt");

    if (read.fail())
        cout << "Não foi possível abrir o arquivo...\n";
    else
    {
        read >> list.countBooks;
        for (int i = 0; i < list.countBooks; i++)
        {
            read >> list.books[i].code;
            read.ignore();
            getline(read, list.books[i].name);
            read.ignore();
            getline(read, list.books[i].edit);
            read.ignore();
            read >> list.books[i].yearOfPublication;
        }

        cout << "Importação realizada!";
        Sleep(1000);
        read.close();
    }
}

void exportList()
{
    write.open("booksList.txt");

    if (!write.is_open())
        cout << "Não foi possível abrir o arquivo...\n";
    else
    {
        write.clear();

        write << list.countBooks;
        for (int i = 0; i < list.countBooks; i++)
        {
            write << list.books[i].code << endl;
            write << list.books[i].name << endl;
            write << list.books[i].edit << endl;
            write << list.books[i].yearOfPublication << endl;
        }

        cout << "Exportação realizada!";
        Sleep(1000);
        write.close();
    }
}