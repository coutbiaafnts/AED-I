#include <iostream>
#include <windows.h>

using namespace std;

int teste(int a); // cabeçalho da função
int somaDeValores(int a, int b, int c);

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int a = 9, b = 8, c = 98;

  somaDeValores(a, b, c);

  // cout << somaDeValores(9,8,98);

  cout << endl
       << endl;
  return 0;
}

// int teste(int a){
//     // execução
// };

int somaDeValores(int a, int b, int c)
{
  // primeiro método
  // int soma = a + b + c;
  // return soma;

  // segundo método
  return a + b + c;
};