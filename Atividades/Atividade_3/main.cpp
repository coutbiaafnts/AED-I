#include <iostream>
#include <windows.h>
#include <fstream> // inclusão da biblioteca para arquivos

using namespace std;

struct population // declara o tipo population
{
  float wage; // declara o tipo de cada membro
  int age;
  int numbOfKids;
  char sex;
};

float sumWage, medianWage, biggestWage, percentWomanWage; // variáveis para realizar os cálculos necessários
int sumKids, medianKids;                                  // variáveis para realizar os cálculos necessários

const int amountPopulation = 10; // constante que guarda o número de habitantes da cidade, utilizada durante o código para determinar repetições e cálculos de média

population person[amountPopulation]; // armazena os dados no struct

ofstream write; // (tipo) ofstream escrita (variável acesso à funções de  manipulação de arquivo);
ifstream read;  // (tipo) ifstream leitura (variável acesso à funções de  manipulação de arquivo);

void separator() // divisor de organização
{
  cout << endl
       << endl
       << ">>----------------------------------------------------------------<<" << endl
       << endl;
}

void insertData() // usuário insere manualmente os dados dos habitantes através de uma estrutura de repetição
{
  for (int i = 0; i < amountPopulation; i++)
  {
    cout << "Digite o salário do " << i + 1 << "º habitante: ";
    cin >> person[i].wage;

    cout << "Digite a idade do " << i + 1 << "º habitante: ";
    cin >> person[i].age;

    cout << "Digite o número de filhos do " << i + 1 << "º habitante: ";
    cin >> person[i].numbOfKids;

    cout << "Digite o sexo do " << i + 1 << "º habitante: ";
    cin >> person[i].sex;

    separator();
    system("cls");
  }
}

void calculateReport() // realiza os cálculos
{
  for (int i = 0; i < amountPopulation; i++)
  {
    sumWage += person[i].wage;        // soma o salário de todos os habitantes
    sumKids += person[i].numbOfKids;  // soma o número de filhos de todos os habitantes
    if (person[i].wage > biggestWage) // verifica e atribui o maior salário à variável biggestWage
    {
      biggestWage = person[i].wage;
    }

    tolower(person[i].sex); // converte o caractere em MAIÚSCULO

    if (person[i].sex == 'F' && person[i].wage > 1000) // verifica se o habitante da posição é uma mulher e se recebe mais de R$1000,00, se sim incrementa 1 à contagem
    {
      percentWomanWage++;
    }

    medianWage = sumWage / amountPopulation;                        // calcula a média de salário
    medianKids = sumKids / amountPopulation;                        // calcula a média de filhos
    percentWomanWage = (percentWomanWage * 100) / amountPopulation; // calcula o percentual de mulheres que ganham mais de R$1000,00
  }
}

void showReport() // mostra o relatório ao usuário
{
  cout << "Média salarial dos habitantes da cidade: R$" << medianWage << endl;
  cout << "Média de filhos dos habitantes da cidade: " << medianKids << endl;
  cout << "O maior salário registrado na cidade: R$" << biggestWage << endl;
  cout << "Percentual de mulheres com salário superior a R$1000,00: " << percentWomanWage << "%" << endl;
}

void saveReport() // salva o relatório no .txt
{
  write.open("Report.txt");
  write.clear();
  write << "Média salarial dos habitantes da cidade: R$" << medianWage << endl;
  write << "Média de filhos dos habitantes da cidade: " << medianKids << endl;
  write << "O maior salário registrado na cidade: R$" << biggestWage << endl;
  write << "Percentual de mulheres com salário superior a R$1000,00: " << percentWomanWage << "%" << endl;
  write.close();
}

void saveData() // salva os dados no .txt
{
  write.open("DataList.txt");
  write.clear();
  for (int i = 0; i < amountPopulation; i++)
  {
    write << person[i].wage << endl;
    write << person[i].age << endl;
    write << person[i].numbOfKids << endl;
    write << person[i].sex << endl;
  }
  write.close();
}

void loadData() // carrega os dados do arquivo
{
  read.open("DataList.txt"); // abre o arquivo ou cria um, se não existir
  if (read.fail())           // se falhar a leitura do arquivo
  {
    cout << "ERROR!";
    system("pause");
    read.clear(); // fecha o arquivo
  }

  while (!read.eof())
  {
    for (int i = 0; i < amountPopulation; i++)
    {
      read >> person[i].wage;
      read >> person[i].age;
      read >> person[i].numbOfKids;
      read >> person[i].sex;
    }
  }
  read.close(); // fecha depois de carregar todos os arquivos
}

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int option = -1, saveOption = -1;

  do // responsável pelo menu, onde o usuário insere a opção desejada
  {
    separator();
    cout << "* |\t(1) - Inserir dados manualmente" << endl // mostra o menu ao usuário para que insira a opção desejada
         << "* |\t(2) - Carregar dados de um arquivo" << endl
         << "* |\t(0) - Sair" << endl
         << "* |\tDigite uma opção: ";
    cin >> option;
    system("cls");

    switch (option) // cada caso responde à opção do menu (Option)
    {
    case 0: //
      cout << "Saindo...";
      Sleep(1000);
      system("cls");
      break;

    case 1:
      insertData();      // insere os dados manualmente
      calculateReport(); // realiza os códigos para gerar o relatório
      separator();
      showReport(); // mostra o relatório
      separator();

      do
      {
        cout << "* |\tDeseja salvar as informações?" << endl // imprime menu de salvar ou não os dados e relatório nos .txt
             << "* |\t(1) - Sim" << endl
             << "* |\t(2) - Não" << endl
             << "* |\tDigite uma opção: ";
        cin >> saveOption;

        system("cls");

        if (saveOption == 1) // salva
        {
          saveReport();
          cout << "Relatório salvo!";
          saveData();
          cout << "Dados salvos!";
        }
        else if (saveOption == 2) // encerra o programa
        {
          cout << "Encerrando programa...";
          Sleep(2000);
          break;
        }
        else if (saveOption != 1 && saveOption != 2)
        {
          cout << "ERROR! Opção inválida...";
          system("pause");
        }

      } while (saveOption != 2);

      break;

    default: // tratamento para valores inválidos no menu
      system("cls");
      cout << "ERROR! Opção inválida...";
      system("pause");
      break;
    }
  } while (option != 0);

  cout << endl
       << endl;
  return 0; // fim do programa
}
