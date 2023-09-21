#include <iostream>
#include <windows.h>
#include <fstream>

struct population
{
  float wage;
  int age;
  int numbOfKids;
  char sex;
};

float medianWage, biggestWage, percentWomanWage;
int medianKids;

const int amountPopulation = 2;

void calculateReport(), showReport(), saveReport(), showRecord(), saveData(), separator(), loadData();

using namespace std;

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int option;

  do
  {
    cout << "(1) - Inserir dados manualmente" << endl
         << "(2) - Carregar dados de um arquivo" << endl
         << "(0) - Sair" << endl;
  } while (option != 0);

  

  cout << endl
       << endl;
  return 0;
}
