#ifndef scalanie_hpp
#define scalanie_hpp
#include "tablica.hpp"
template<class typ1>
class sortowanie_scalanie //klasa przeznaczona do przeprowadzenia sortowania przez scalanie
{
 //wksazniki na dynamiczne tablice tab2 jest tablica pomocnicza
 typ1 *tab1;
 typ1 *tab2;
 //rozmiar tablic
 int rozmiar;


 public:
 //konstruktor bezparametryczny
 sortowanie_scalanie()
 {
  tab1=tab2=NULL;
 }


 //dekonstruktor zwlaniajacy zarezerwowane miejsce przez operator new
 ~sortowanie_scalanie()
 {
  delete [] tab1;
  delete [] tab2;
 }


 //metoda sortowania przez scalenie
 // przyjmuje dwa argumenty typu int, ktore symbolizuja pierwszy i ostatni elemnt tablicy
 void sort_scal(int lewy, int prawy)
 {
  if(prawy<=lewy) return;

  int srodek=(prawy+lewy)/2;

  sort_scal(lewy,srodek);
  sort_scal(srodek+1,prawy);
  scal(lewy, srodek, prawy);
 }


 private:
 //scalanie ze soba tablic
 void scal(int lewy, int srodek, int prawy)
 {
  int i=lewy, j=srodek+1;

  for(int i=lewy; i<=prawy; i++)
  tab2[i]=tab1[i];

  for(int s=lewy; s<=prawy; s++)
   if(i<=srodek)
    if(j<=prawy)
     if(tab2[j]<tab2[i]) tab1[s]=tab2[j++];
     else tab1[s]=tab2[i++];
    else tab1[s]=tab2[i++];
   else tab1[s]=tab2[j++];
}


 public:
 void uzupelnij_tablice_dosortowania(int tab[])
 {
  for(int i=0; i<rozmiar; i++)
  tab1[i]=tab[i];
 }

 void uzupelnij_tablice_posortowana(int tab[])
 {
  for(int i=0; i<rozmiar; i++)
  tab[i]=tab1[i];
 }

 void zwolnij_pamiec()
 {
  delete [] tab1;
  delete [] tab2;
  rozmiar=0;
  tab1=NULL;
  tab2=NULL;
 }
 void ustaw_pamiec(int roz)
 {
  tab1=new typ1 [roz];
  tab2=new typ1 [roz];
  rozmiar=roz;
 }


};

#endif
