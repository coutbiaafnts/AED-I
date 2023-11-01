#include <iostream>
#include <string>

using namespace std;

// define a estrutura item, que contém um valor de idade, um nome e um ponteiro para o próximo elemento da pilha
struct Item
{
    int idade;
    string nome;
    Item *proximo;
};

// topo é um ponteiro que rastreia o último item da pilha, iniciado como NULL para representar "pilha vazia"
Item *topo = NULL;

// funções declaradas antes da main para que possam ser utilizadas no código principal com mais organização
void empilhar();
void desempilhar();
bool verificarSeTemAlgumaCoisa();
void mostrar();
int menu();

// a função main é o ponto de partida do programa com um loop Do While, onde é exibido um menu de opções para o usuário escolher e executar o que deseja. O loop se repete até que o usuário escolha sair do programa com a opção (0)
int main()
{
    int opcao;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            empilhar();
            break;
        case 2:
            desempilhar();
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

// solicita um nome e uma idade para um novo elemento, coloca esse elemento no topo da pilha e atualiza o "topo"
void empilhar()
{
    
    Item *temp = new Item; // cria um ponteiro para um novo objeto na memória heap
    cout << "Nome: ";
    cin >> temp->nome; // o valor é inserido no campo nome do objeto temp
    cout << "Idade: ";
    cin >> temp->idade; // o valor é inserido no campo idade do objeto temp
    temp->proximo = topo; // atualiza o campo próximo do temp, aponta o elemento que era o topo anteriormente criando uma ligação entre o novo elemento e o anterior
    topo = temp; // após atualizar o campo próximo, atualiza o ponteiro "topo" para apontar o novo elemento, tornando ele o topo da pilha
    temp = NULL; // define como NULL para não vazar memória já que o temp ja foi alocado dinamicamente.
}

// remove o último elemento da pilha após verificar se existem elementos
void desempilhar()
{
    if (verificarSeTemAlgumaCoisa())
    {
        Item *temp = topo; // o ponteiro temp recebe o topo
        topo = topo->proximo; // o elemento anterior é atribuído ao topo, sobrescrevendo
        cout << "Removido: ";
        cout << temp->nome << " " << temp->idade << endl; // imprime o elemento que foi removido
        delete temp; // deleto o temp, liberando espaço na memória
    }
    else
    {
        cout << "Nada!" << endl;
    }
}

// com base no ponteiro "topo" verifica se há algum elemento na pilha, retornando um valor booliano
bool verificarSeTemAlgumaCoisa()
{
    if (topo != NULL)
    {
        return true;
    }
    return false;
}

// exibe o último elemento da pilha enquanto o ponteiro temp for diferente de NULL
void mostrar()
{
    Item *temp = topo;
    while (temp != NULL)
    {
        cout << temp->nome << " " << temp->idade << endl;
        temp = temp->proximo;
    }
}

// exibe uma série de opções ao usuário e retorna a opção escolhida
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