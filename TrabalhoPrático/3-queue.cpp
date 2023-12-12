#include <iostream>
#include <windows.h>
#include <queue>

using namespace std;

queue<string> musicPlaylist;

int menu();
void playlist(), addMusic(), firstMusic(), lastMusic(), markAsReproduced(), sizeQueue();

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
      addMusic();
      break;
   case 2:
      firstMusic();
      break;
   case 3:
      lastMusic();
      break;
   case 4:
      markAsReproduced();
      break;
   case 5:
      sizeQueue();
      break;
   case 6:
      playlist();
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

   cout << ">>--------------------------------- PLAYER DE MÚSICA ---------------------------------<<" << endl;
   cout << "1. Adicionar música à fila" << endl;
   cout << "2. Primeira música" << endl;
   cout << "3. Última música" << endl;
   cout << "4. Marcar como reproduzida" << endl;
   cout << "5. Número de músicas na fila" << endl;
   cout << "6. Carregar músicas" << endl;
   cout << "0. Sair" << endl;
   cout << ">>------------------------------------------------------------------------------------<<" << endl
        << endl;
   cout << "   Digite uma opção: ";
   cin >> option;

   return option;
}

void playlist()
{
   system("cls");
   musicPlaylist.push("Happiness is a butterfly - (Lana Del Rey)");
   musicPlaylist.push("Freaks - (Surf Curse)");
   musicPlaylist.push("Sparks fly - (Taylor Swift)");
   musicPlaylist.push("Pela luz dos olhos teus - (Miúcha, Tom Jobim)");
   musicPlaylist.push("Quando bate aquela saudade - (Rubel)");

   cout << "   Músicas carregadas com sucesso!" << endl << endl;
   system("pause");
   main();
}

void addMusic()
{
   system("cls");
   string music;

   cout << ">>--------------------------------- ADICIONANDO MÚSICA ---------------------------------<<" << endl;
   cout << "   Informe a música: ";
   cin.ignore();
   getline(cin, music);

   musicPlaylist.push(music);

   cout << endl
        << "   Adicionando música..." << endl;
   Sleep(1500);
   cout << "   Música adicionada com sucesso!" << endl << endl;
   system("pause");

   main();
}

void markAsReproduced()
{
   system("cls");
   cout << ">>--------------------------------- MÚSICA REPRODUZIDA ---------------------------------<<" << endl;
   cout << "   Marcando " << musicPlaylist.front() << " como reproduzida..." << endl;

   Sleep(1500);

   musicPlaylist.pop();
   cout << "   Marcação completa!" << endl<< endl;

   system("pause");
   main();
}

void firstMusic()
{
   system("cls");
   cout << ">>--------------------------------- PRIMEIRA MÚSICA DA FILA ---------------------------------<<" << endl;
   if (!musicPlaylist.empty())
   {
      cout << "   A primeira música a ser reproduzida é: " << musicPlaylist.front() << endl
           << endl;
   }
   else
   {
      cout << "   Fila de reprodução vazia!" << endl
           << endl;
   }

   system("pause");
   main();
}

void lastMusic()
{
   system("cls");
   cout << ">>--------------------------------- ÚLTIMA MÚSICA DA FILA ---------------------------------<<" << endl;
   if (!musicPlaylist.empty())
   {
      cout << "   A última música a ser reproduzida é: " << musicPlaylist.back() << endl
           << endl;
   }
   else
   {
      cout << "   Fila de reprodução vazia!" << endl
           << endl;
   }

   system("pause");
   main();
}

void sizeQueue()
{
   system("cls");
   cout << ">>--------------------------------- TAMANHO DA FILA ---------------------------------<<" << endl;

   if (musicPlaylist.size() < 1)
   {
      cout << "   Fila de reprodução vazia!" << endl
           << endl;
   }
   else if (musicPlaylist.size() == 1)
   {

      cout << "   A fila tem atualmente " << musicPlaylist.size() << " música!" << endl
           << endl;
   }
   else
   {
      cout << "   A fila tem atualmente " << musicPlaylist.size() << " músicas!" << endl
           << endl;
   }
   system("pause");
   main();
}