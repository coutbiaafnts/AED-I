#include <iostream>
#include <windows.h>

using namespace std;

void separator();

int question01(), question02(), question03(), question04(), question05(), question06(), question07(), question08();

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  system("cls");

  int question08();
  int option;
  int confirmation;

  option = question08();

  switch (option)
  {
  case 1:
    question01();
    cout << endl;
    system("pause");
    main();

  case 2:
    question02();
    cout << endl;
    system("pause");
    main();

  case 3:
    question03();
    cout << endl;
    system("pause");
    main();

  case 4:
    question04();
    cout << endl;
    system("pause");
    main();

  case 5:
    question05();
    cout << endl;
    system("pause");
    main();

  case 6:
    question06();
    cout << endl;
    system("pause");
    main();

  case 7:
    question07();
    cout << endl;
    system("pause");
    main();

  case 0:
    do
    {
      cout << "Realmente deseja sair? (1 - Sim / 0 - Não) ";
      cin >> confirmation;

      if (confirmation == 1)
      {
        system("cls");
        separator();
        cout << "Obrigada por utilizar o sistema de matriz!";
        return 0;
      }
      else if (confirmation == 0)
      {
        question08();
      }
      else if (confirmation != 1 && confirmation != 0)
      {
        system("cls");
        cout << "Opção inválida!...";
        question08();
      }
    } while (confirmation != 1);

  default:
    cout << "Opção Inválida!\n";
    system("pause");
    main();
  }

  return 0;
}

void separator()
{
  cout << "\n\n----------------------------------------------------------------\n\n";
}

int question01()
{
  cout << "\n\tMega Sena";
  separator();

  int apostas_gab[2][10], pts = 0;

  // preenchendo o gabarito
  cout << "Informe os números sorteados:\n\n";
  for (int j = 0; j < 6; j++)
  {
    cout << "Diga o " << j + 1 << "º número sorteado: ";
    cin >> apostas_gab[0][j];
  }

  // preenchendo a aposta
  cout << "\n\nInforme os números que você apostou:\n\n";
  for (int j = 0; j < 10; j++)
  {
    cout << "Diga o " << j + 1 << "º número que apostou: ";
    cin >> apostas_gab[1][j];
  }

  // verificando acertos e calculando pontuação
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (apostas_gab[0][i] == apostas_gab[1][j])
      {
        pts++;
      }
    }
  }

  separator();

  cout << "Verificamos que você fez " << pts << " pontos!";
}

int question02()
{
  cout << "\n\tChuva";
  separator();

  int numRegions;

  cout << "Digite o número de regiões: ";
  cin >> numRegions;

  int map01[numRegions][numRegions], map02[numRegions][numRegions], sumPeriod[numRegions][numRegions];

  cout << "\nPreencha o primeiro mapa!\n";
  for (int i = 0; i < numRegions; i++)
  {
    for (int j = 0; j < numRegions; j++)
    {
      cin >> map01[i][j];
    }
  }

  cout << "\nPreencha o segundo mapa!\n";
  for (int i = 0; i < numRegions; i++)
  {
    for (int j = 0; j < numRegions; j++)
    {
      cin >> map02[i][j];
    }
  }

  // soma os períodos
  for (int i = 0; i < numRegions; i++)
  {
    for (int j = 0; j < numRegions; j++)
    {
      sumPeriod[i][j] = map01[i][j] + map02[i][j];
    }
  }

  separator();
  cout << "Soma dos períodos:\n";

  // imprime a matriz com os resultados
  for (int i = 0; i < numRegions; i++)
  {
    for (int j = 0; j < numRegions; j++)
    {
      cout << sumPeriod[i][j] << " ";
    }
    cout << "\n";
  }
}

int question03()
{
  cout << "\n\tSomar coluna matriz";
  separator();

  int mat[3][3], column0 = 0, column1 = 0, column2 = 0;

  // preenche a matriz
  for (int i = 0; i < 3; i++)
  {
    cout << "\nPreencha a " << i + 1 << "ª linha da matriz:\n";
    for (int j = 0; j < 3; j++)
    {
      cout << "Digite o " << j + 1 << "º valor: ";
      cin >> mat[i][j];

      // soma os valores das colunas
      if (j == 0)
      {
        column0 += mat[i][j];
      }
      else if (j == 1)
      {
        column1 += mat[i][j];
      }
      else if (j == 2)
      {
        column2 += mat[i][j];
      }
    }
  }

  separator();

  cout << "Coluna 0: " << column0 << "\n";
  cout << "Coluna 1: " << column1 << "\n";
  cout << "Coluna 2: " << column2;
}

int question04()
{
  cout << "\n\tSomar linha matriz";
  separator();

  int mat[3][3], line0 = 0, line1 = 0, line2 = 0;

  // preenche a matriz
  for (int i = 0; i < 3; i++)
  {
    cout << "\nPreencha a " << i + 1 << "ª linha da matriz:\n";
    for (int j = 0; j < 3; j++)
    {
      cout << "Digite o " << j + 1 << "º valor: ";
      cin >> mat[i][j];

      // soma os valores das linhas
      if (i == 0)
      {
        line0 += mat[i][j];
      }
      else if (i == 1)
      {
        line1 += mat[i][j];
      }
      else if (i == 2)
      {
        line2 += mat[i][j];
      }
    }
  }

  separator();

  cout << "Linha 0: " << line0 << "\n";
  cout << "Linha 1: " << line1 << "\n";
  cout << "Linha 2: " << line2;
}

int question05()
{
  cout << "\n\tSomar diagonal";
  separator();

  int mat[3][3], diagPrin = 0, diagSec = 0;

  // preenche a matriz
  for (int i = 0; i < 3; i++)
  {
    cout << "\nPreencha a " << i + 1 << "ª linha da matriz:\n";
    for (int j = 0; j < 3; j++)
    {
      cout << "Digite o " << j + 1 << "º valor: ";
      cin >> mat[i][j];
    }

    // soma diagonal principal
    diagPrin += mat[i][i];
    // soma diagonal secundária
    diagSec += mat[i][((3 - 1) - i)];
  }

  separator();

  cout << "Diagonal Principal: " << diagPrin << "\n";
  cout << "Diagonal Secundária: " << diagSec << "\n";
}

int question06()
{
  cout << "\n\tQuadrado mágico";
  separator();

  int matriz[3][3];
  int line0 = 0, line1 = 0, line2 = 0;
  int column0 = 0, column1 = 0, column2 = 0;

  int diagPrin = 0, diagSec = 0;

  for (int i = 0; i < 3; i++)
  {
    cout << "\nPreencha a " << i + 1 << "ª linha da matriz:\n";
    for (int j = 0; j < 3; j++)
    {
      cout << "Digite o " << j + 1 << "º valor: ";
      cin >> matriz[i][j];

      // soma linha
      if (i == 0)
      {
        line0 += matriz[i][j];
      }
      else if (i == 1)
      {
        line1 += matriz[i][j];
      }
      else if (i == 2)
      {
        line2 += matriz[i][j];
      }

      // soma coluna
      if (j == 0)
      {
        column0 += matriz[i][j];
      }
      else if (j == 1)
      {
        column1 += matriz[i][j];
      }
      else if (j == 2)
      {
        column2 += matriz[i][j];
      }
    }

    // soma diagonal principal
    diagPrin += matriz[i][i];
    // soma diagonal secundária
    diagSec += matriz[i][((3 - 1) - i)];
  }

  separator();

  if (line0 == line1 && line2 == line1 && column0 == column1 && column1 == column2 && diagPrin == column2 && diagSec == diagPrin)
  {
    cout << "A matriz forma um quadrado mágico\n\n";
  }
  else
  {
    cout << "A matriz não forma um quadrado mágico\n\n";
  }
}

int question07()
{
  system("cls");

  cout << "\n\tQuadrado mágico";
  separator();

  // uma matriz para cada número
  char numb0[5][4] = {
      {'X', 'X', 'X', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'}};

  char numb1[5][4] = {
      {' ', ' ', 'X', ' '},
      {' ', 'X', 'X', ' '},
      {' ', ' ', 'X', ' '},
      {' ', ' ', 'X', ' '},
      {' ', ' ', 'X', ' '}};

  char numb2[5][4] = {
      {'X', 'X', 'X', 'X'},
      {' ', ' ', ' ', 'X'},
      {' ', ' ', 'X', ' '},
      {' ', 'X', ' ', ' '},
      {'X', 'X', 'X', 'X'}};

  char numb3[5][4] = {
      {'X', 'X', 'X', 'X'},
      {' ', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'},
      {' ', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'}};

  char numb4[5][4] = {
      {'X', ' ', ' ', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'},
      {' ', ' ', ' ', 'X'},
      {' ', ' ', ' ', 'X'}};

  char numb5[5][4] = {
      {'X', 'X', 'X', 'X'},
      {'X', ' ', ' ', ' '},
      {'X', 'X', 'X', 'X'},
      {' ', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'}};

  char numb6[5][4] = {
      {'X', 'X', 'X', 'X'},
      {'X', ' ', ' ', ' '},
      {'X', 'X', 'X', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'}};

  char numb7[5][4] = {
      {'X', 'X', 'X', 'X'},
      {' ', ' ', ' ', 'X'},
      {' ', ' ', ' ', 'X'},
      {' ', ' ', ' ', 'X'},
      {' ', ' ', ' ', 'X'}};

  char numb8[5][4] = {
      {'X', 'X', 'X', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'}};

  char numb9[5][4] = {
      {'X', 'X', 'X', 'X'},
      {'X', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'},
      {' ', ' ', ' ', 'X'},
      {'X', 'X', 'X', 'X'}};

  int number;

  cout << "Digite um número de (0) a (9): ";
  cin >> number;

  cout << "\n\nNúmero na matriz:\n\n";

  // imprime a matriz referente ao número inserido pelo usuário
  switch (number)
  {
  case 0:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb0[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 1:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb1[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 2:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb2[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 3:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb3[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 4:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb4[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 5:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb5[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 6:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb6[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 7:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb7[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 8:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb8[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  case 9:
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        cout << numb9[i][j] << " ";
      }
      cout << "\n";
    }
    break;

  default:
    cout << "Opção Inválida!\n";
    system("pause");
    question07();
  }
}

int question08()
{
  system("cls");

  // variável para receber a opção que o usuário selecionou
  int op;

  separator();

  cout << "1 - Mega Sena\n";
  cout << "2 - Chuva\n";
  cout << "3 - Somar coluna matriz\n";
  cout << "4 - Somar linha matriz\n";
  cout << "5 - Somar diagonal\n";
  cout << "6 - Quadrado mágico\n";
  cout << "7 - Números (0 a 9)\n";
  cout << "0 - Sair\n";

  separator();

  cout << "Digite uma opção: ";
  cin >> op;

  system("cls");
  return op;
}