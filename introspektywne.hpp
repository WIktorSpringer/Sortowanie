#ifndef introspektywne_hpp
#define introspektywne_hpp
#include <cmath>
#include <algorithm>
template<class typ>
class introspektywne
{
 //wskaznik na tablice dynamiczna
 typ *tab;
 // zmienna typu int liczaca ilosc wywolan funkcji
 int ilosc_wywolan;
 // zmienna trzymajaca rozmiar tablicy
 int rozmiar;
 int L, P;
 public:



 introspektywne()
 {
  tab=NULL;
  rozmiar=0;
  ilosc_wywolan=0;
 }
 ~introspektywne()
 {
  delete [] tab;
 }


 //metoda sluzaca do zajecia pamieci przez operator new
 // zmienna typu int o nazwie roz sluzy do ustalenia rozmiaru tablicy
 void zajmij_pamiec(int roz)
 {
  tab=new typ [roz];
  rozmiar=roz;
  ilosc_wywolan=(int)floor(2*log(rozmiar)/M_LN2);

 }

 // metoda zwalniajaca zajeta pamiec przez operator new
 void zwolnij_pamiec()
 {
  delete [] tab;
  tab=NULL;
  rozmiar=0;
  ilosc_wywolan=0;
 }



 void uzupelnij_tablice(int tab1[])
 {
  for(int i=0; i<rozmiar; i++)
  {
   tab[i]=tab1[i];
  }
 }



 void oddaj_tablice(int tab1[])
 {
  for(int i=0; i<rozmiar; i++)
  {
   tab1[i]=tab[i];
  }
 }

 private:
 //metoda sortowania szybkiego z uwzglednieniem zmiany zmiennej ilosc_wywolan
 void sort_quick(int lewy, int prawy)
{
 if(ilosc_wywolan==0)
 {
 make_heap(&tab[lewy], &tab[prawy+1]);
 sort_heap(&tab[lewy], &tab[prawy+1]);
 return;
 }
 if(prawy <= lewy) return;
 int pivot=tab[(lewy+prawy)/2];
 bool dzialaj=true;
 int i=lewy, s=prawy;

 while(dzialaj)
 {
 while(pivot>tab[i])
 i++;

 while(pivot<tab[s])
 s--;

 if(i<=s)
 {
 swap(tab[i],tab[s]);
 i++;
 s--;
 }
 else
 dzialaj=false;
 }

 if(lewy<s)
 {
  --ilosc_wywolan;
  sort_quick(lewy,s);
 }

 if(prawy>i)
 {
  --ilosc_wywolan;
  sort_quick(i,prawy);
 }

}



public:
// metoda sortowania introspektywnego
void sortuj()
{
 if(ilosc_wywolan>0) sort_quick(0, rozmiar-1);

  ilosc_wywolan=(int)floor(2*log(rozmiar)/M_LN2);

}





};



#endif
