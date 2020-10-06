#ifndef quick_hpp
#define quick_hpp


template<class typ>
class quick //klasa przeznaczona do sortowania szybkiego
{
//wskaznik na tablice dynamiczna
typ *tab;
//zmienna int przechowywujaca rozmiar tablicy
int rozmiar;
public:


quick()
{
 tab=NULL;
 rozmiar=0;
}

~quick()
{
 delete [] tab;
}

//metoda zarezerwujaca miejsce na tablice dynamiczna
void zajmij_pamiec(int roz)
{
 tab= new typ [roz];
 rozmiar =roz;
}


//metoda zwalnaiajaca pamiec zajeta przez operator new
void zwolnij_pamiec()
{
 delete [] tab;
 tab=NULL;
 rozmiar=0;
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

//metoda sortowania szybkiego
void sort_quick(int lewy, int prawy)
{
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
 sort_quick(lewy,s);

 if(prawy>i)
 sort_quick(i,prawy);
}


};
#endif
