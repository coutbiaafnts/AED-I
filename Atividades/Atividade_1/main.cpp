#include <iostream>
#include <windows.h>

using namespace std;

// chama todas as funções antes da main para que o código fique mais organizado e de fácil entendimento
int menu(), question1(), question2(), question3(), question4(), question5(), question6(), question7();
void separator();

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  // limpa o terminal sempre que retorna à main
  system("cls");

  // imprimi o menu no terminal
  int menu();
  int option;

  // recebe a opção inserida pelo usuário no menu
  option = menu();

  // responsável por imprimir a questão relacionada à opção inserida pelo usuário ou encerra o programa (-1)
  switch (option)
  {
  case 1:
    question1();
    cout << endl;
    system("pause");
    main();

  case 2:
    question2();
    cout << endl;
    system("pause");
    main();

  case 3:
    question3();
    cout << endl;
    system("pause");
    main();

  case 4:
    question4();
    cout << endl;
    system("pause");
    main();

  case 5:
    question5();
    cout << endl;
    system("pause");
    main();

  case 6:
    question6();
    cout << endl;
    system("pause");
    main();

  case 7:
    question7();
    cout << endl;
    system("pause");
    main();

  case -1:
    break;

  default:
    cout << "Opção Inválida!\n";
    system("pause");
    main();
  }

  cout << endl
       << endl;

  return 0;
}

int menu()
{
  system("cls");

  // variável para receber a opção que o usuário selecionou
  int op;

  separator();

  cout << "Escolha uma questão de 1 a 7 ou digite (-1) para encerrar o programa: ";
  cin >> op;

  system("cls");
  return op;
}

int question1()
{
  cout << "Inteiros de 1 a 50!";

  separator();

  int intNum[50];

  // imprime os números de 1 a 50 de acordo com o "for"
  for (int i = 0; i < 50; i++)
  {
    intNum[i] = i + 1;
    cout << intNum[i] << " | ";
  }
}

int question2()
{
  cout << "Inteiros de 100 a 1 em ordem decrescente!";

  separator();

  int intNum[100];

  // imprime os números de 100 a 1, obedecendo a ordem do "for"
  for (int i = 100; i > 0; i--)
  {
    intNum[i] = i;
    cout << intNum[i] << " | ";
  }
}

int question3()
{
  cout << "100 primeiros números ímpares!";

  separator();

  int impNum[100], j = 0;

  // imprime os 100 primeiros números ímpares a partir do "if" que define se é ímpar ou não
  for (int i = 0; i < 200; i++)
  {
    if (i % 2 != 0)
    {
      impNum[j] = i;
      cout << impNum[j] << " | ";
      j++;
    }
  }
}

int question4()
{
  cout << "Informe 10 números e te mostrarei a metade de cada um!";

  separator();

  int partNum[10];

  // recebe os valores do usuário
  for (int i = 0; i < 10; i++)
  {
    cout << "Informe o " << i + 1 << "º valor: ";
    cin >> partNum[i];

    // calcula a metade de cada valor e armazena no vetor
    partNum[i] = partNum[i] / 2;
  }

  separator();

  // imprime a metade dos valores
  cout << "Metade de cada valor: ";
  for (int i = 0; i < 10; i++)
  {
    cout << partNum[i] << " | ";
  }
}

int question5()
{
  cout << "Informe 10 números e te mostrarei o quadrado de cada um!";

  separator();

  int squaredNum[10];

  // recebe os valores do usuário e calcula o quadrado
  for (int i = 0; i < 10; i++)
  {
    cout << "Informe o " << i + 1 << "º valor: ";
    cin >> squaredNum[i];

    // calcula o quadrado
    squaredNum[i] = squaredNum[i] * squaredNum[i];
  }

  separator();

  // imprime os valores ao quadrado
  cout << "Quadrado do valores: ";
  for (int i = 0; i < 10; i++)
  {
    cout << squaredNum[i] << " | ";
  }
}

int question6()
{
  cout << "Informe a altura de 10 atletas e te mostrarei quais deles tem altura maior que a média!";

  separator();

  float heightAth[10], aveHeight = 0;

  // recebe a altura de cada atleta
  for (int i = 0; i < 10; i++)
  {
    cout << "Informe a altura do " << i + 1 << "º atleta: ";
    cin >> heightAth[i];

    // soma todas as alturas
    aveHeight = aveHeight + heightAth[i];
  }

  // calcula a média
  aveHeight = aveHeight / 10;

  separator();

  // imprime as altura acima da média
  cout << "Altura dos atletas que seu maiores que a média: ";
  for (int i = 0; i < 10; i++)
  {
    if (heightAth[i] > aveHeight)
    {
      cout << heightAth[i] << " | ";
    }
  }
}

int question7()
{
  cout << "Informe 10 números e te mostrarei o quadrado de cada um!";

  separator();

  int numAth[10], auxNumAth = 0;
  float tempAth[10], auxTempAth = 0;

  // recebe os números dos atletas e seus respectivos tempos
  for (int i = 0; i < 10; i++)
  {
    cout << "Informe o número do " << i + 1 << "º atleta: ";
    cin >> numAth[i];
    cout << "Informe o tempo do " << i + 1 << "º atleta: ";
    cin >> tempAth[i];
    cout << "\n\n";
  }

  separator();

  cout << "Veja os tempos em ordem crescente:\n\n\n";

  // altera a ordem dos tempos e dos números dos atletas para que fiquem na ordem menor tempo ao maior
  for (int current = 0; current < 10; current++)
  {
    for (int successor = current + 1; successor < 10; successor++)
    {
      if (tempAth[successor] < tempAth[current])
      {
        auxTempAth = tempAth[successor];
        auxNumAth = numAth[successor];
        tempAth[successor] = tempAth[current];
        numAth[successor] = numAth[current];
        tempAth[current] = auxTempAth;
        numAth[current] = auxNumAth;
      }
    }
  }

  for (int i = 0; i < 10; i++)
  {
    // imprime o número e o tempo do atleta na ordem pedida
    cout << "Número do atleta: " << numAth[i];
    cout << " | Tempo do atleta: " << tempAth[i];

    separator();
  }
}

void separator()
{
  cout << "\n\n----------------------------------------------------------------\n\n";
}