#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  // tipos ->> ofstream, ifstream, fstream

  // ofstream ->> ( saída/escrita (<<) ) sai do programa e vai para o arquivo
  // ifstream ->> ( entrada/leitura (>>) ) sai do arquivo e vai para o programa
  // fstream ->> ( entrada/saída ) não precisa definir um tipo para entrada ou saída

  fstream write_read; // criando a variável para o arquivo sem determinar o modo
  char option = 's';
  string name, line;

  // write_read.open("fileWriteRead.txt", ios::out); // cria o arquivo de fato e abre em modo de escrita ( sobrescrevendo )
  write_read.open("fileWriteRead.txt", ios::out | ios::app); // cria o arquivo de fato e abre em modo de escrita ( sem sobrescrever )

  while ((option == 's') || (option == 'S')) // repete os comandos até que o usuário escolha não inserir um novo nome
  {
    cout << "Digite um nome: ";
    cin >> name;
    write_read << name << endl; // salva o nome no arquivo
    cout << "Digitar um novo nome? [s/n]" << endl;
    cin >> option;
    system("cls");
  }

  write_read.close();

  write_read.open("fileWriteRead.txt", ios::in); // cria o arquivo de fato e abre em modo de leitura

  cout << "Nomes digitados:" << endl;

  if (write_read.is_open()) // verifica se o arquivo está aberto
  {
    while (getline(write_read, line)) // lê a linha do arquivo e armazena na variável pré existente no programa ( getline opera linha por linha e se chega ao final ele retorna false )
    {
      cout << line << endl; // exibe a linha do arquivo no prompt ( cout )
    }
    write_read.close();
  }
  else
  {
    cout << "Error: Não foi possível abrir o arquivo." << endl;
  }
  cout << endl
       << endl;
  return 0;
}