#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_NOMES = 100;

struct Fila
{
    string nomes[MAX_NOMES];
    // int ini = -1; //Usaremos somente na Fila dinâmica
    int fim = -1;
};

Fila fila;

void inserir(string nome);
void remover();
void mostrar();
bool verificarSeTemAlgumaCoisa();
int menu();

int main()
{
    int opcao;
    string nome;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            cout << "Digite um nome: ";
            cin >> nome;
            inserir(nome);
            break;
        case 2:
            remover();
            break;
        case 3:
            mostrar();
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Selecione uma opção válida!" << endl;
            break;
        }
    } while (opcao != 0);
    return 0;
}

void inserir(string nome)
{
    if (fila.fim < MAX_NOMES - 1)
    {
        fila.fim = fila.fim + 1;
        fila.nomes[fila.fim] = nome;
    }
}

void remover()
{
    if (verificarSeTemAlgumaCoisa())
    {
        cout << "Removido: " << fila.nomes[0] << endl;
        for (int i = 0; i < fila.fim; i++)
        {
            fila.nomes[i] = fila.nomes[i+1];
        }
        fila.fim = fila.fim - 1;
    }
}

void mostrar()
{
    cout << "++++ FILA ++++ " << endl
         << endl;
    for (int i = 0; i <= fila.fim; i++)
    {
        cout << fila.nomes[i] << ' ';
    }
    cout << endl << endl;
}

bool verificarSeTemAlgumaCoisa()
{
    if (fila.fim > -1)
    {
        return true;
    }
    return false;
}

int menu()
{
    int opcao;
    cout << "++++ Opções ++++ " << endl;
    cout << "1. Inserir" << endl;
    cout << "2. Remover" << endl;
    cout << "3. Mostrar" << endl;
    cout << "0. Sair" << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}