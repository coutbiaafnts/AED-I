#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  struct pessoa {
    char nome[35]; // 1B
    char sx; // 1B
    int idade; // 4B
    float salario;  // 4B
  };

  pessoa p[5]; // ((35 + 1 + 4 + 4) * 5) =  240

  // cout << sizeof(char) << endl;
  // cout << sizeof(string) << endl;
  // cout << sizeof(int) << endl;
  // cout << sizeof(float) << endl;
  // cout << sizeof(double) << endl;
  // cout << sizeof(long double) << endl;
  // cout << sizeof(bool) << endl;

  cout << endl
       << endl;
  return 0;
}