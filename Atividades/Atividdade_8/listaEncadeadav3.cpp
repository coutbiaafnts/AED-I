#include <iostream>
#include <string>

using namespace std;

// estrutura do item
struct Item
{
    int idade;
    string nome;
    Item *proximo; // variável que aponta para o próximo item
};

// estrutura da lista encadeada
struct Lista
{
    Item *primeiro = NULL; // criando ponteiro como nulo (primeiro item)
    Item *ultimo = NULL; // criando ponteiro como nulo (último item)
};

// cria um ponteiro L do tipo lista, como nulo
Lista *L = NULL;

// cria uma lista vazia utilizando ponteiro 
void criarLista()
{
    L->primeiro = new Item; // cria um item como primeiro
    L->ultimo = L->primeiro; // o ponteiro último recebe o ponteiro primeiro
    L->primeiro->proximo = NULL; // cria o próximo item como nulo
}

// retorna 0 ou 1, sendo 0 para primeiro diferente do último e 1 para primeiro igual ao último
int vazia()
{
    return (L->primeiro == L->ultimo);
}

// insere um item na lista na última posição
void inserirUltima()
{
    Item *x = new Item; // cria um item x

    cout << "Digite um nome: ";
    cin >> x->nome; // recebe o nome
    cout << "Digite a idade: ";
    cin >> x->idade; // recebe a idade

    L->ultimo->proximo = x; // aponta para o último item e faz com que o próximo receba x
    L->ultimo = x; // x passa a ser o último
    L->ultimo->proximo = NULL; // o próximo item é definido como nulo
}

// mostra os itens da lista
void mostrar()
{
    Item *aux; // cria um item auxiliar
    aux = L->primeiro->proximo; // atribui o próximo para a variável auxiliar
    while (aux != NULL) // enquanto o próximo não for nulo, exibe os valores
    {
        cout << "Nome: " << aux->nome << " "
             << "Idade: " << aux->idade << endl;
        aux = aux->proximo; // aux recebe o próximo item
    }
}

// insere um item na primeira posição
void inserirPrimeira()
{
    Item *x = new Item; // cria um item x

    cout << "Digite um nome: ";
    cin >> x->nome; // recebe o nome
    cout << "Digite a idade: ";
    cin >> x->idade; // recebe a idade

    if (!vazia()) //  se a lista não estiver vazia 
    {
        x->proximo = L->primeiro->proximo; // o próximo do item x, recebe o primeiro item da lista
        L->primeiro->proximo = x; // o primeiro item da lista recebe o item x 
    }
    else // se a lista estiver vazia 
    {
        L->ultimo->proximo = x; // o próximo item depois do último recebe x
        L->ultimo = x; // o último item recebe x
        L->ultimo->proximo = NULL; //  o próximo item depois do último recebe nulo
    }
}

// insere um item em uma determinada posição informada pela usuário
void inserirPosicao(int n)
{
    int i = 0;
    Item *aux = L->primeiro; // variável auxiliar que receber o primeiro item da lista
    while (i < (n - 1) && aux != NULL) // enquanto i for menor que o a posição inserida - 1 e aux não for nulo
    {
        i++; // i acrescenta de um em um
        aux = aux->proximo; // aux recebe o próximo item
    }

    Item *x = new Item; // cria um item x para receber o novo item
    cout << "Digite um nome: ";
    cin >> x->nome; // recebe o nome
    cout << "Digite a idade: ";
    cin >> x->idade; // recebe a idade

    x->proximo = aux->proximo; // o próximo item de x recebe o próximo item da lista
    aux->proximo = x; // o próximo item da lista recebe o novo item
}

// remove o primeiro item da lista
void removerPrimeira()
{
    if (!vazia()) // se a lista não estiver vazia
    {
        Item *aux = L->primeiro->proximo; // cria uma variável atribuindo o primeiro item da lista 
        cout << endl
             << "+++ REMOVENDO +++" << endl;
        cout << aux->nome << " " << aux->idade << endl
             << endl; // mostra os valores do item a ser removido
        L->primeiro->proximo = aux->proximo; // atribui o item depois de aux ao primeiro item da lista
        if (aux == L->ultimo) // se aux for o último item da lista 
        {
            L->ultimo = L->primeiro; // último recebe o item cabeça
        }
        delete aux; // deleta o o valor de aux
    }
    else // se não 
    {
        cout << endl
             << "Vazia" << endl; // imprime vazia
    }
}


// remove o último item da lista
void removerUltima()
{
    if (!vazia()) // se a lista não estiver vazia 
    {
        Item *aux = L->primeiro; // cria uma variável que recebe o item cabeça
        while (aux->proximo != L->ultimo) // enquanto o próximo item não for o último
        {
            aux = aux->proximo; // aux recebe o próximo item
        }
        cout << endl
             << "+++ REMOVENDO +++" << endl;
        cout << aux->proximo->nome << " " << aux->proximo->idade << endl 
             << endl; // imprime o item a ser removido
        aux->proximo = NULL; // o próximo item recebe nulo 
        delete L->ultimo; // deleta o último item da lista
        L->ultimo = aux; // o último recebe aux
    }
    else // se não
    {
        cout << endl
             << "Vazia" << endl; // imprime vazia
    }
}

// remove o item de uma posição determinada pelo usuário
void removerPosicao(int posicao)
{
    if (!vazia()) // se a lista não estiver vazia
    {
        int i = 1;
        Item *aux1 = L->primeiro, *aux2 = L->primeiro->proximo; // duas variáveis, uma aponta recebe o item cabeça e a outro o primeiro item da lista
        while (i < posicao && aux2 != NULL) // enquanto i for menor que a posição inserida e o primeiro item da lista não for nulo
        {
            i++;  // i acrescenta de um em um
            aux1 = aux2; // o item cabeça recebe o primeiro item da lista não for nulo
            aux2 = aux2->proximo; // o primeiro item da lista recebe o próximo
        }
        if (aux2 == NULL) // se o primeiro item da lista for nulo
        {
            cout << "Nada para remover" << endl;
        }
        else // se não 
        {
            cout << endl
                 << "+++ REMOVENDO +++" << endl;
            cout << aux2->nome << " " << aux2->idade << endl
                 << endl; // exibe o item a ser removido
            if (aux2 == L->ultimo) // se o primeiro item da lista for o último
            {
                L->ultimo = aux1; // último recebe o item cabeça
            }
            aux1->proximo = aux2->proximo; // o item cabeça recebe o próximo item
            delete aux2; // deleta os valores de aux2
        } 
    }
}

// exibe o menu e retorna a opção inserida
int menu()
{
    int opcao;
    cout << "++++ Opcoes ++++ " << endl;
    cout << "1. Inserir no inicio" << endl;
    cout << "2. Inserir no final" << endl;
    cout << "3. Inserir em uma posicao" << endl;
    cout << "4. Mostrar" << endl;
    cout << "5. Remover primeira" << endl;
    cout << "6. Remover ultima" << endl;
    cout << "7. Remover de uma posicao" << endl;

    cout << "0. Sair" << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}

// executa o programa com base nas funções criadas e o opção informada pelo usuário
int main()
{
    int opcao, p; // cria variáveis úteis para executar o menu e receber posições da lista, informa pelo usuário
    L = new Lista; // cria uma lista

    criarLista();
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            inserirPrimeira();
            break;
        case 2:
            inserirUltima();
            break;
        case 3:
            cout << "Digite a posicao: "; 
            cin >> p;
            inserirPosicao(p);
            break;
        case 4:
            mostrar();
            break;
        case 5:
            removerPrimeira();
            break;
        case 6:
            removerUltima();
            break;
        case 7:
            cout << "Digite a posicao: ";
            cin >> p;
            removerPosicao(p);
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