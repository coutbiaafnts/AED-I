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

  ifstream read; // criando a varável para o arquivo em modo de leitura
  string line;   // armazena a linha lida

  read.open("fileRead.txt"); // criando o arquivo de fato

  if (read.is_open()) // verifica se o arquivo está aberto
  {
    while (getline(read, line)) // lê a linha do arquivo e armazena na variável pré existente no programa ( getline opera linha por linha e se chega ao final ele retorna false )
    {
      cout << line << endl; // exibe a linha do arquivo no prompt ( cout )
    }
    read.close(); // fecha o arquivo ( Sempre fechar )
  }
  else // se não estiver aberto
  {
    cout << "Error: Não foi possível abrir o arquivo." << endl;
  }

  cout << endl
       << endl;
  return 0;
}