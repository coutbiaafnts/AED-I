#include <iostream>
#include <string>

using namespace std;

const int MAX_NOMES = 100;

struct Pilha
{
    string nomes[MAX_NOMES];
    int topo = -1;
};

Pilha pilha;

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
    if (pilha.topo < MAX_NOMES - 1)
    {
        pilha.topo = pilha.topo + 1;
        pilha.nomes[pilha.topo] = nome;
    }
}

void remover()
{
    if (verificarSeTemAlgumaCoisa())
    {
        cout << "Removido: " << pilha.nomes[pilha.topo] << endl;
        pilha.topo = pilha.topo - 1;
    }
}

void mostrar()
{
    cout << "++++ PILHA ++++ " << endl
         << endl;
    for (int i = 0; i <= pilha.topo; i++)
    {
        cout << pilha.nomes[i] << ' ';
    }
    cout << endl << endl;
}

bool verificarSeTemAlgumaCoisa()
{
    if (pilha.topo > -1)
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