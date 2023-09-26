#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int teste();

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  ofstream arquivo("teste.txt");

  // txt << programa (of)
  // txt >> programa (if)

  arquivo << "Oi";

  arquivo.close();

  cout << endl
       << endl;
  teste();
  return 0;
}

int teste()
{

  ifstream arquivo("teste.txt");
  string test;
  arquivo >> test;
  cout << test << endl;
  arquivo.close();
}