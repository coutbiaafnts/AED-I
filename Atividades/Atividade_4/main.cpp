#include <iostream>
#include <string>

using namespace std;

const int MAX_LIVROS = 100; // constante que determina o número máximo de livros que serão armazenados

// estrutura que define as propriedades do livro
struct Livro
{
    int codigo;  // código o livro
    string nome; // nome do livro
};

// estrutura que define as propriedades da lista de livros
struct ListaDeLivros
{
    int quantidade = 0;       // armazena quantos livros estão cadastrados
    Livro livros[MAX_LIVROS]; // vetor do tipo Livro para armazenar os livros na lista
};

ListaDeLivros lista; // determina uma variável do tipo listaDeLivros

// chama as funções no início do código para organização
void inserirInicio(Livro li);
void inserirFim(Livro li);
void inserirEmUmaPosicao(Livro li, int posicao);
void removerInicio();
void removerFim();
void removerDeUmaPosicao(int posicao);
void mostrarLista();
Livro leDoTeclado();
int menu();

// função principal onde temos um menu para que o usuário escolha as opções e assim o programa flua
int main()
{
    int opcao, posicao; // variáveis responsáveis por obter as opções do menu e a posição do livro na lista
    Livro livro;        // determina um tipo de livro

    // executa o menu enquanto a opção for diferente
    do
    {
        opcao = menu(); // executa a função menu recebendo o valor da variável opção

        // executa o menu com base na opção
        switch (opcao)
        {
        case 1:
            livro = leDoTeclado(); // executa a função para ler as propriedades do livro pelo teclado
            inserirInicio(livro);  //
            break;
        case 2:
            livro = leDoTeclado(); // executa a função para ler as propriedades do livro pelo teclado
            cout << "Em qual posicao? ";
            cin >> posicao;                      // le a posição
            inserirEmUmaPosicao(livro, posicao); // executa a função
            break;
        case 3:
            livro = leDoTeclado(); // recebe o livro
            inserirFim(livro);     // insere no fim o livro cadastrado
            break;
        case 4:
            removerInicio(); // remove o livro do início
            break;
        case 5:
            cout << "Em qual posicao? ";
            cin >> posicao;               // lê a posição
            removerDeUmaPosicao(posicao); // remove o livro da posição
            break;
        case 6:
            removerFim(); // remove o livro do fim
            break;
        case 7:
            mostrarLista(); // mostra a lista de livros
            break;
        case 0:
            cout << "Saindo..." << endl; // sai do menu
            break;
        default:
            cout << "Opção inválida!" << endl; // se a opção for inválida
            break;
        }
    } while (opcao != 0);
}

// função para inserir um novo livro na primeira posição recebendo li (estrutura Livro)
void inserirInicio(Livro li)
{
    if (lista.quantidade < MAX_LIVROS) // se a quantidade de livros for menor que o máximo de livros permitidos ele:
    {
        for (int i = lista.quantidade; i > 0; i--) // percorre a lista de trás para frente
        {
            lista.livros[i] = lista.livros[i - 1]; // passa todos os livros uma posição para frente deixando a primeira posição vazia
        }
        lista.livros[0] = li;                    // atribui o novo livro à primeira posição
        lista.quantidade = lista.quantidade + 1; // adiciona um livro na contagem de livros
    }
}

// função para inserir um novo livro na primeira posição
void inserirFim(Livro li)
{
    if (lista.quantidade < MAX_LIVROS) // se a quantidade de livros for menor que o máximo de livros permitidos ele:
    {
        lista.livros[lista.quantidade] = li;     // insere o novo livro na última posição (a quantidade de livros já indica a última)
        lista.quantidade = lista.quantidade + 1; // adiciona um livro na contagem de livros
    }
}

// função para inserir um novo livro em uma determinada posição
void inserirEmUmaPosicao(Livro li, int posicao)
{
    if (lista.quantidade < MAX_LIVROS) // se a quantidade de livros for menor que o máximo de livros permitidos ele:
    {
        for (int i = lista.quantidade; i > posicao; i--) // percorre a lista de trás para frente até encontrar a posição
        {
            lista.livros[i] = lista.livros[i - 1]; // passa todos os livros uma posição para frente
        }
        lista.livros[posicao] = li;              // atribui o novo livro na posição
        lista.quantidade = lista.quantidade + 1; // adiciona um livro na contagem de livros
    }
}

// função para remover o primeiro livro da lista
void removerInicio()
{
    if (lista.quantidade > 0) // se a quantidade de livros for maior que zero:
    {
        cout << "Removendo ";
        cout << lista.livros[0].codigo << ' ';     // imprime o código do livro que vai ser excluído
        cout << lista.livros[0].nome << endl;      // imprime o nome do livro que vai ser excluído
        for (int i = 0; i < lista.quantidade; i++) // percorre a lista em ordem crescente
        {
            lista.livros[i] = lista.livros[i + 1]; // passa todos os livros uma posição para trás
        }
        lista.quantidade = lista.quantidade - 1; // remove um livro na contagem de livros
    }
}

// função para remover o último livro da lista
void removerFim()
{
    if (lista.quantidade > 0) // se a quantidade de livros for maior que zero:
    {
        cout << "Removendo ";
        cout << lista.livros[lista.quantidade - 1].codigo << ' '; // imprime o código do livro que vai ser excluído
        cout << lista.livros[lista.quantidade - 1].nome << endl;  // imprime o nome do livro que vai ser excluídos
        lista.quantidade = lista.quantidade - 1;                  // remove um livro na contagem de livros
    }
}

// função para remover o livro de uma determinada posição da lista
void removerDeUmaPosicao(int posicao)
{
    if (lista.quantidade > 0 && posicao < lista.quantidade) // se a quantidade for maior que zero e a posição for menor que o valor da quantidade de livros cadastrados
    {
        cout << "Removendo ";
        cout << lista.livros[posicao].codigo << ' ';     // imprime o código do livro que vai ser excluído
        cout << lista.livros[posicao].nome << endl;      // imprime o nome do livro que vai ser excluído
        for (int i = posicao; i < lista.quantidade; i++) // percorre a lista em ordem crescente
        {
            lista.livros[i] = lista.livros[i + 1]; // passa todos os livros uma posição para trás
        }
        lista.quantidade = lista.quantidade - 1; // remove um livro na contagem de livros
    }
}

// função para imprimir a lista de livros
void mostrarLista()
{
    cout << endl;
    cout << "++++++ CONTEÚDO DA LISTA ++++++ " << endl;
    for (int i = 0; i < lista.quantidade; i++)
    {
        cout << lista.livros[i].codigo << ' ';
        cout << lista.livros[i].nome << endl;
    }
    cout << endl;
}

// executa a leitura das propriedades do livro pelo teclado
Livro leDoTeclado()
{
    Livro livro;
    cout << "Código: ";
    cin >> livro.codigo;
    cout << "Nome: ";
    cin >> livro.nome;
    return livro;
}

// responsável por exibir o menu e retornar a opção escolhida pelo usuário
int menu()
{
    int opcao;
    cout << "+++++ OPERAÇÕES +++++ " << endl;
    cout << "1 - Inserir no início." << endl;
    cout << "2 - Inserir em uma posição." << endl;
    cout << "3 - Inserir no final." << endl;
    cout << "4 - Remover no início." << endl;
    cout << "5 - Remover em uma posição." << endl;
    cout << "6 - Remover no final." << endl;
    cout << "7 - Mostrar lista." << endl;
    cout << "0 - Sair." << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}