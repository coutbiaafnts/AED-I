#include <iostream>
#include <windows.h>

using namespace std;

struct car // criando a estrutura
{
  string name;      // propriedade da estrutura
  string color;     // propriedade da estrutura
  int power;        // propriedade da estrutura
  int maxVelocity;  // propriedade da estrutura
  int velocity = 0; // propriedade da estrutura

  void insert(string stName, string stColor, int stPower, int stMazVelocity) // insere os valores para cada propriedade da estrutura
  {
    name = stName;
    color = stColor;
    power = stPower;
    maxVelocity = stMazVelocity;
  };

  void show() // imprime os valores para cada propriedade da estrutura
  {
    cout << endl
         << endl
         << "Informações do carro 1: " << endl;
    cout << "Nome: " << name << endl;
    cout << "Cor: " << color << endl;
    cout << "Potência: " << power << endl;
    cout << "Velocidade Atual: " << velocity << endl;
    cout << "Velocidade Máxima: " << maxVelocity << endl
         << endl;
  };

  void changeVelocity(int chandeVelocity) // muda a velocidade atual do carro
  {
    velocity = chandeVelocity;

    if (velocity > maxVelocity) // impede que a velocidade máxima seja ultrapassada
    {
      velocity = maxVelocity;
    }
    else if (velocity < 0) // impede que a velocidade mínima seja batida
    {
      velocity = 0;
    };
  };
};

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int amountCar; // variável que determina o tamanho do vetor

  // usuário insere o valor desejado
  cout << "Insira quantos carros deseja cadastrar: ";
  cin >> amountCar;

  car cars[amountCar]; // criando um vetor para armazenar as propriedades de cada carro com base na estrutura ( car )

  

  cout << endl
       << endl;
  return 0;
}