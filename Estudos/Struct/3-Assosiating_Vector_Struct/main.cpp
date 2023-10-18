#include <iostream>
#include <windows.h>

using namespace std;

struct cars // criando a estrutura
{
  string name;      // propriedade da estrutura
  string color;     // propriedade da estrutura
  int power;        // propriedade da estrutura
  int maxVelocity;  // propriedade da estrutura
  int velocity = 0; // propriedade da estrutura
};

const int amountCar = 2; // variável que determina o tamanho do vetor
cars car[amountCar];     // criando um vetor para armazenar as propriedades de cada carro com base na estrutura ( car )
void insert(), show();   // funções para o programa

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  char change;

  insert();
  show();

  cout << endl
       << endl;
  return 0;
}

void insert()
{
  // // usuário insere o valor desejado
  // cout << "Insira quantos carros deseja cadastrar: ";
  // cin >> amountCar;

  for (int i = 0; i < amountCar; i++)
  {
    cout << "Nome do carro: ";
    cin >> car[i].name;

    cout << "Cor do carro: ";
    cin >> car[i].color;

    cout << "Potência do carro: ";
    cin >> car[i].power;

    cout << "Velocidade máxima do carro: ";
    cin >> car[i].maxVelocity;

    cout << "Velocidade atual do carro: ";
    cin >> car[i].velocity;
    cout << endl
         << endl;
  };
};

void show() // imprime os valores para cada propriedade da estrutura
{
  for (int i = 0; i < amountCar; i++)
  {
    cout << endl
         << endl
         << "Informações do " << i + 1 << "º carro" << endl;
    cout << "Nome: " << car[i].name << endl;
    cout << "Cor: " << car[i].color << endl;
    cout << "Potência: " << car[i].power << endl;
    cout << "Velocidade Atual: " << car[i].maxVelocity << endl;
    cout << "Velocidade Máxima: " << car[i].velocity << endl
         << endl;
  };
};