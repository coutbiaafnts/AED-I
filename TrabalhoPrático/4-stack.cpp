#include <iostream>
#include <windows.h>
#include <stack>

using namespace std;

stack<string> changes;
string actualText;

int menu();
void addText(), undoText(), showText();

int main()
{
   UINT CPAGE_UTF8 = 65001;
   SetConsoleOutputCP(CPAGE_UTF8);

   HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(colors, 11);
   system("cls");

   int optionMenu;

   optionMenu = menu();

   switch (optionMenu)
   {
   case 1:
      addText();
      break;
   case 2:
      undoText();
      break;
   case 3:
      showText();
      break;
   case 0:
      system("cls");
      cout << endl
           << endl
           << "   Saindo...";
      Sleep(400);
      system("taskkill /f /im cmd.exe");
      exit(0);
   default:
      cout << endl
           << "!ERROR: Opção inválida." << endl;
      Sleep(1500);
      main();
   }

   return 0;
}

int menu()
{
   int option;

   cout << ">>--------------------------------- EDITOR DE TEXTO ---------------------------------<<" << endl;
   cout << "1. Adicionar texto" << endl;
   cout << "2. Desfazer alteração" << endl;
   cout << "3. Exibir texto atual" << endl;
   cout << "0. Sair" << endl;
   cout << ">>-----------------------------------------------------------------------------------<<" << endl
        << endl;
   cout << "   Digite uma opção: ";
   cin >> option;

   return option;
}

void addText()
{
   system("cls");
   string newText;

   cout << ">>--------------------------------- ADICIONANDO TEXTO ---------------------------------<<" << endl;
   cin.ignore();
   getline(cin, newText);
   actualText += newText;
   changes.push(newText);

   cout << "   Texto adicionado com sucesso!" << endl
        << endl;
   system("pause");
   main();
}

void undoText()
{
   system("cls");

   cout << ">>--------------------------------- DESFAZENDO ÚLTIMA ALTERAÇÃO ---------------------------------<<" << endl;
   string lastModification;

   if (!changes.empty())
   {
      lastModification = changes.top();
      changes.pop();
      actualText.erase(actualText.length() - lastModification.length());
   }

   Sleep(1500);

   cout << "   Alteração desfeita com sucesso!" << endl
        << endl;
   system("pause");
   main();
}

void showText()
{
   system("cls");
   cout << ">>--------------------------------- TEXTO ATUAL ---------------------------------<<" << endl
        << endl;

   cout << actualText << endl;

   system("pause");
   main();
}