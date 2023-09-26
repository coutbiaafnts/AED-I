#include <iostream>
#include <windows.h>
#include <fstream>

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

  ofstream file; // criando a varável para o arquivo
  // file.open("file.txt"); // criando o arquivo de fato ( sobrescrevendo )
  file.open("file.txt", ios::app); // criando o arquivo de fato ( posiciona o cursor no final do arquivo e insere o conteúdo em seguida ( não sobrescreve ) )

  file << "Texto teste 3" << endl; // armazenando no arquivo

  file.close(); // fecha o arquivo e libera o espaço na memória ( sempre fechar o arquivo )

  cout << endl
       << endl;
  return 0;
}