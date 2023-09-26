#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int vetor[10];
  for (int i = 0; i < 10; i++) // percorre e manipula o vetor
  {
    cout << "Digite o º" << i + 1 << " valor: ";
    cin >> vetor[i];
  }

  int matriz[10][10];
  for (int i = 0; i < 10; i++) // percorre e manipula a matriz por linha
  {
    for (int j = 0; j < 9; j++)
    {
      cout << "Digite o º" << j + 1 << " valor da " << i + 1 << "ª linha: ";
      cin >> matriz[i][j];
    }
  }

  for (int i = 0; i < 9; i++) // percorre e manipula a matriz por coluna
  {
    for (int j = 0; j < 10; j++)
    {
      cout << "Digite o º" << i + 1 << " valor da " << j + 1 << "ª coluna: ";
      cin >> matriz[j][i];
    }
  }

  cout << endl
       << endl;
  return 0;
}