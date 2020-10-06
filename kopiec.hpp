#ifndef kopiec_hpp
#define kopiec_hpp


template<class typ>
class kopiec //klasa sortowania przez kopcowanie
{
//wskaznik na tablice dynamiczna
typ *tab;
//zmienna zawierajaca rozmiar tablicy
int rozmiar;
public:

kopiec()
{
 tab=NULL;
 rozmiar=0;
}


~kopiec()
{
 delete [] tab;
}


//metoda zajecia pamieci na tablice dynamiczna przez operator new
//argument typu int o nazwie roz sluzy do ustalenia rozmiaru tablicy
void zajmij_pamiec(int roz)
{
 tab=new typ [roz];
 rozmiar=roz;
}


//metoda zwalniania pamieci zajetej przez operator new
void zwolnij_pamiec()
{
 delete [] tab;
 tab=NULL;
 rozmiar=0;
}


void uzupelnij_tablice(typ tab1[])
{
 for(int i=0; i<rozmiar; i++)
 tab[i]=tab1[i];
}


void oddaj_tablice(typ tab1[])
{
 for(int i=0; i<rozmiar; i++)
 tab1[i]=tab[i];
}

private:
/*
Metody w polu private sa glownym algorytmem sortowania przez kopcowanie
w celu uproszczenia rozwazan nad algorytmem trzymalem sie standardowego sposobu
numerowania poszczegolnych indeksow. W jezyku c++ tablice sa numerowane od 0 stad
w ponizyszch metoda w nawiasach kwadratowych (odwolanie do wartosci z tablicy) znajduje
sie operacja odejmowania 1

 ######zbuduj_kopiec########
w metodzie tej j oznaczalewy listek
natomiast k to przodek
operacja dzielenia calkowitego przez 2 (div 2) pozwala na okreslenie wsp przodka (numeryzacja standardowa)


 ######rozloz_kopiec########
w metodzie tej k oznacza lewy listek
nastomiast j oznacza przodka
*/
//metoda budowania kopca
void zbuduj_kopiec()
{
 int i,chwilowa,N=rozmiar,k,j;

 for(i = 2; i <= N; i++)
 {
  j=i;
  k=j/2;
  chwilowa=tab[i-1];
  while((k>0)&&(tab[k-1]<chwilowa))
  {
  tab[j-1] = tab[k-1];
   j=k;
   k=j/2;
  }
  tab[j-1]=chwilowa;
 }
}


//metoda rozkladania kopca
void rozloz_kopiec()
{
 int i,j,k, wieszky;

 for(i=rozmiar;i>1;i--)
 {
  swap(tab[0], tab[i-1]);
  j=1;
  k=2;
  while(k < i)
  {
   if((k+1<i) && (tab[k]>tab[k-1]))
    wieszky=k+1;
   else
    wieszky=k;
   if(tab[wieszky-1]<=tab[j-1])
    break;
   swap(tab[j-1], tab[wieszky-1]);
   j=wieszky;
   k=j+j;
    }
  }
}


public:
//metoda sortowania
void sortuj()
{
 zbuduj_kopiec();
 rozloz_kopiec();
}
};
#endif
