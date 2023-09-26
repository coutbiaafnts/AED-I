#include <iostream>
#include <windows.h>

using namespace std;

struct car // criando a estrutura
{
  string name;     // propriedade da estrutura
  string color;    // propriedade da estrutura
  int power;       // propriedade da estrutura
  int maxVelocity; // propriedade da estrutura
};

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  car car1; // criando uma variável para armazenar propriedades com base na estrutura ( car )

  // atribui um valor à propriedade da estrutura
  car1.name = "Tower";
  car1.color = "Red";
  car1.power = 450;
  car1.maxVelocity = 350;

  // imprime os valores atribuídos a cada propriedade da estrutura
  cout << "Informações do carro 1: " << endl;
  cout << "Nome:------------- " << car1.name << endl;
  cout << "Cor:-------------- " << car1.color << endl;
  cout << "Potência:--------- " << car1.power << endl;
  cout << "Velocidade Máxima: " << car1.maxVelocity << endl;

  cout << endl
       << endl;
  return 0;
}