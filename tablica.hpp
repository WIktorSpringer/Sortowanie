#ifndef sort_tablica_hpp
#define sort_tablica_hpp
#include <iostream>

using namespace std;
// Poniżej klasa służaca do stworzenia obiektu o nazwie tablica
template <class typ>
class tablice_do_sortowania
{
 public:
 //wskaznik typu wybieralne sluzacy do przetrzymywania dynamicznej tablicy
 typ *tablica;

 // rozmiar tablicy
 int rozmiar;



 //Konstruktor bezparametryczny
 tablice_do_sortowania()
 {
  tablica=NULL;
  rozmiar=0;
 }



 // dekonstrukto zwalniajacy zarezerwowana pamiec operatorem new
 ~tablice_do_sortowania()
 {
  delete [] tablica;
 }




// metoda wypisujaca tablice
 void wypisz()
 {
  for(int i=0; i<rozmiar; i++)
  {
   cout << tablica[i] << " ";
  }

  cout << endl;
 }



//uzupelnienie tablicy w wartosci losowe w zakresie do 1000
 void uzupelnij_losowo()
 {
  for(int i=0; i<rozmiar; i++)
  {
   tablica[i]=rand() % 1000;
  }
 }


 //uzupelnienie tabliy w wartosci posortowane do pewnego procenta wielkosci tablicy
 // metoda przyjmuje argument typu double sluzacy do okreslenia liczby posortowanych elementow
 void uzupelnij_procent(double procent)
 {
  int ilosc_elemntow_posortowanych;
  ilosc_elemntow_posortowanych=procent*rozmiar;

  for(int i=0; i<rozmiar; i++)
  {
   if(i<ilosc_elemntow_posortowanych)
   {
    tablica[i]=i;
   }

   else
   {
    tablica[i]=rand() % 1000;
   }
  }
 }




 //uzupelnienie w odwrotnej kolejnosci
 void uzupelnij_odwrotna_kolejnosc()
 {
  for(int i=0; i<rozmiar; i++)
  {
   tablica[i]=rozmiar-i;
  }
 }


 //sprawdzenie poprawnosci posortowanej tablicy
 bool sprawdz_popr()
 {
  int zl=0;

  for(int i=0; i<rozmiar-1; i++)
  {
   if(tablica[i]<tablica[i+1] || tablica[i]==tablica[i+1] )
   {
    ++zl;
   }
  }

  if(zl==rozmiar-1)
  return true;

  else
  return false;
}




// wczytanie wartosci do tablicy podanej w argumencie metody
 void uzupelnij_tablica(typ tab[])
 {
  for(int i=0; i<rozmiar; i++)
  tablica[i]=tab[i];
 }




//zarezerwowanie pamieci do stworzenia tablicy
// metoda przyjmuje argument typu int o nazwie roz sluzacy do okreslenia rozmiaru tablicy
 void zajmij_pamiec(int roz)
 {
  rozmiar=roz;
  tablica=new typ [roz];
 }




 // zwolnienie zarezerwowanego miejsca
 void zwolnij_miejsce()
 {
  rozmiar=0;
  delete [] tablica;
  tablica=NULL;
 }


};


#endif
