#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iostream>
#include"board.h"

//Deklaracje funkcji---------------------------------------- 
void wyswietlPlansze(char tab[17][17]);                     //Rysowanie planszy
void wyczyscTerminal();                                     //Czyszczenie terminala
void wykonajRuch(int x, int y, char tab[17][17]);           //Sprawdzanie możliwości wykonania ruchu i wykonanie go
bool sprawdzPlansze(char tab[17][17]);                      //Sprawdzanie czy plansza jest cała pokryta kółkami
bool sprawdzRuch(int x, int y, char tab[17][17]);           //Sprawdzanie możliwości wykonania ruchu
void stworzPlansze(char tab[17][17]);                       //Tworzenie planszy
//----------------------------------------------------------


int main(void)
{
  game::Board board = game::Board(8,'/');
  std::cout << board;
//  int liczbaRuchow = 0, wiersz = 0, kolumna = 0;            //Definicje zmiennych, odpowiednio linczik ruchów, indeksy wiersza i kolumny
//  char plansza[17][17];                                     //Definicja planszy
  
//  stworzPlansze(plansza);                                   //Tworzenie planszy
//  wyswietlPlansze(plansza);                                 

  //while(sprawdzPlansze(plansza))
//{   
//  printf("Wykonane ruchy: %d", liczbaRuchow);               //Wyswietlenie wykonanych liczby ruchow
//  printf("\nWiersz: ");                                     
//  scanf("%d", &wiersz);                                     //Wczytywanie indeksu wiersza  
//  printf("Kolumna: ");
//  scanf("%d", &kolumna);                                    //Wczytywanie indeksu kolumny
//  printf("\n");
//  if(sprawdzRuch(wiersz, kolumna, plansza))                 //Sprawdzenie czy ruch możliwy
//  {
//    wyczyscTerminal();
//    wykonajRuch(wiersz,kolumna,plansza);
//    wyswietlPlansze(plansza);
//    liczbaRuchow += 1;
//  }
//  else printf("Ruch niemożliwy, spróbuj ponownie!\n");
//}
//  printf("Koniec gry! \n Wykonane ruchu : %d", liczbaRuchow);     //końcowy komunikat
  return 0;
}



void wyswietlPlansze(char tab[17][17]){
  int i = 0, k = 0;
  for(i=0; i<17; i++){
      for(k=0;k<17;k++)
	{
	  printf("%c  ",tab[i][k]);
	}
      printf("\n");
    } 
}

void wyczyscTerminal(){
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
}

bool  sprawdzPlansze(char tab[17][17]){
  bool kontynuuj = false;
  int i=0, k=0;
  for(i=0;i<=7;i++)
    {
      for(k=0;k<=7;k++)
	{
	  if(tab[2*i+1][2*k+1] == 'X') {kontynuuj = true; break;}
	}
    }
  return kontynuuj;
}

void wykonajRuch(int x, int y, char tab[17][17]){
      if(tab[2*x-1][2*y-1] == (char)88) tab[2*x-1][2*y-1] = (char)79;              //sprawdzanie pola centralnego
      if(x-1>=1) {if(tab[2*x-3][2*y-1] == (char)88) tab[2*x-3][2*y-1] = (char)79;} //sprawdzanie pola na lewo
      if(y-1>=1) {if(tab[2*x-1][2*y-3] == (char)88) tab[2*x-1][2*y-3] = (char)79;} //sprawdzanie pola od góry
      if(y+1<=8) {if(tab[2*x-1][2*y+1] == (char)88) tab[2*x-1][2*y+1] = (char)79;} //sprawdzanie pola od dołu
      if(x+1<=8) {if(tab[2*x+1][2*y-1] == (char)88) tab[2*x+1][2*y-1] = (char)79;} //sprawdzanie pola na prawo
}

bool sprawdzRuch(int x, int y, char tab[17][17]){
   if((x<=8 && x>=1)&&(y<=8 && y>=1)&&tab[2*x-1][2*y-1] ==(char)88) return true;
   else return false;
}

void stworzPlansze(char tab[17][17]){
 int i = 0, k = 0;                                         //iteratory
  for(i=0 ; i < 17; i++)                                  //Rysowanie planszy
    {
      for(k=0; k<17; k++)
	{
	  if(k%2 == 1 && i%2 == 1) tab[i][k] = (char)88;
	    else tab[i][k] = (char)92;
	}
    }   
}
