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

  car car1; // criando uma variável para armazenar propriedades com base na estrutura ( car )

  // atribui um valor à propriedade da estrutura
  car1.insert("Tower", "Red", 450, 350);

  // imprime os valores atribuídos a cada propriedade da estrutura
  car1.show();

  // muda a velocidade
  car1.changeVelocity(150);

  // imprime os valores atuais atribuídos a cada propriedade da estrutura
  car1.show();

  cout << endl
       << endl;
  return 0;
}