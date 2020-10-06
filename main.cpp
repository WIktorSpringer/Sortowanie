#include <iostream>
#include <cstdlib>
#include "scalanie.hpp"
#include "tablica.hpp"
#include <ctime>
#include "quick.hpp"
#include "kopiec.hpp"
#include "introspektywne.hpp"
using namespace std;

// funkcja wyswietlajaca menu
void menu()
{
 cout <<"####################### MENU #######################" << endl;
 cout << "1--> wprowadz tablice"<<endl;
 cout << "2--> zwolnij miejsce (!uwaga wczesniej trzeba wybrac opcje wprowadz tablice!)"<<endl;
 cout << "3--> wyswietl tablice"<<endl;
 cout << "4--> sortowanie przez scalenie" <<endl;
 cout << "5--> sortowanie szybkie (quick)" <<endl;
 cout << "6--> sortowanie kopiec" <<endl;
 cout << "7--> sortowanie introspektywne" <<endl;
 cout << "8-> sprawdz poprawnosc posortowanych tablic" <<endl;
 cout << "9--> KONIEC DZIAŁANIA PROGRAMU"<< endl;
 cout << "##################################################"<<endl;
 }




int main()
{

int rozmiar=0, opcja=1, opcja2=0, opcja3=0;
int licz=0;
bool powtarzaj=true, spraw_alok=false, powtarzaj2=true;
bool tak_nie;
double procent=0.0;
sortowanie_scalanie<int> obiekt;
tablice_do_sortowania<int> tablice[100];
tablice_do_sortowania<int> tablice_po[100];
quick<int> sort_szybki;
kopiec<int> kopiec1;
introspektywne<int> intro;
clock_t time_req;

//petla wykonywania dzialan z menu
while(powtarzaj)
{
 menu();
 cin >> opcja;
 switch(opcja)
  {
/*#########case 1##########
jest opcja ktora odpowaiada za stworzenie 100 tablic wybieralnego
rozmiaru. w casie tym ustala sie rozmiar tablicy oraz wybiera się
sposób uzupełnienia tablic. case ten również odpowiada za uzupełnie
danych w psozczegolnych klasach i zalokowanie odpowiedniej pamieci przez
metody tych klas. Wczesniej sprawdzane jest czy doszlo do zwolnienia miejsca
*/
   case 1:
   if(spraw_alok==false)
   {
   cout << "wprowadz rozmiar tablicy: ";
   cin >> rozmiar;
   cout << endl;

   for(int i=0; i<100; i++)
   {
    tablice[i].zajmij_pamiec(rozmiar);
    tablice_po[i].zajmij_pamiec(rozmiar);
   }
   obiekt.ustaw_pamiec(rozmiar);
   sort_szybki.zajmij_pamiec(rozmiar);
   kopiec1.zajmij_pamiec(rozmiar);
   intro.zajmij_pamiec(rozmiar);
   spraw_alok=true;

   cout<< "wybierz opcje uzupelnienie:" <<endl;
   cout<< "1--> uzupelniene losowe" << endl;
   cout<< "2--> uzupelnienie procentowe" << endl;
   cout<< "3--> uzupelnienie w odwrotnej kolejnosci" << endl;
   cout<< "opcja: ";
   cin >> opcja2;
   cout<< endl;

   switch(opcja2)
    {
     case 1:
     for(int i=0; i<100; i++)
     tablice[i].uzupelnij_losowo();
     break;

     case 2:
     cout<< "wybierz procent uzupelnienia (90%=0.90): ";
     cin >> procent;
     cout << endl;

     for(int i=0; i<100; i++)
     tablice[i].uzupelnij_procent(procent);
     break;

     case 3:
     for(int i=0; i<100; i++)
     tablice[i].uzupelnij_odwrotna_kolejnosc();
     break;

     default:
     cout<< "bledny wybor! wybierz opcje: ";
     break;
    }
    }
    else
    cout<< "najpierw zwolnij miejsce!"<< endl;
   break;

/*#####case 2##########
case ten odpowiada za zwolnienie pamieci, zajetej wczesniej przez
operator new w metodach typu "zajmij pamiec" w posczegolnych klasach
wczesniej sprawdzany jest warunek czy nastapila alokacja pamieci poprzez
wywolanie case 1
*/
   case 2:
   if(spraw_alok==true)
   {
    for(int i=0; i<100; i++)
    {
    tablice[i].zwolnij_miejsce();
    tablice_po[i].zwolnij_miejsce();
    }
    obiekt.zwolnij_pamiec();
    sort_szybki.zwolnij_pamiec();
    kopiec1.zwolnij_pamiec();
    intro.zwolnij_pamiec();
    spraw_alok=false;

   }

   else
   cout <<"Najpierw stworz tablice!" <<endl;
   break;
/*###### case 3 ######
odpowiada za wypisanie wartosci aktualnych 100 tablic
*/
   case 3:
   powtarzaj2=true;
   while(powtarzaj2)
   {
   cout<< "wybierz opcje:" << endl << "1--> wyswietl tablice, która została poddana sortowaniu" << endl
   << "2--> wyswietl tablice posortowana" << endl;
   cin >> opcja3;
   switch(opcja3)
   {
    case 1:
    for(int i=0; i<100; i++)
    tablice[i].wypisz();
    powtarzaj2=false;
    break;

    case 2:
    for(int i=0; i<100; i++)
    tablice_po[i].wypisz();
    powtarzaj2=false;
    break;

    default:
    cout<< "bledna opcja, wybierz jeszcze raz:"<<endl;
    break;
   }
   }
   break;

/*###### case 4 ######
proces sortowania za pomoca metody scalania
oraz wypisanie czasu trawania tej operacji
*/
   case 4:
   time_req = clock();
   for(int i=0; i<100; i++)
   {
   obiekt.uzupelnij_tablice_dosortowania(tablice[i].tablica);
   obiekt.sort_scal(0,rozmiar-1);
   obiekt.uzupelnij_tablice_posortowana(tablice_po[i].tablica);
   }
   time_req = clock() - time_req;
   cout << "Using pow function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

   break;
/*###### case 5 ######
proces sortowania za pomoca metody sortowania szybkiego
oraz wypisanie czasu trawania tej operacji
*/
   case 5:
   time_req = clock();
   for(int i=0; i<100; i++)
   {
    sort_szybki.uzupelnij_tablice(tablice[i].tablica);
    sort_szybki.sort_quick(0,rozmiar-1);
    sort_szybki.oddaj_tablice(tablice_po[i].tablica);
   }
   time_req = clock() - time_req;
   cout << "Using pow function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
   break;
/*###### case 6 ######
proces sortowania za pomoca metody kopcowania
oraz wypisanie czasu trawania tej operacji
*/
   case 6:
   time_req = clock();
   for(int i=0; i<100; i++)
   {
    kopiec1.uzupelnij_tablice(tablice[i].tablica);
    kopiec1.sortuj();
    kopiec1.oddaj_tablice(tablice_po[i].tablica);
   }
   time_req = clock() - time_req;
   cout << "Using pow function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
   break;

/*###### case 4 ######
proces sortowania za pomoca metody i
oraz wypisanie czasu trawania tej operacji
*/
   case 7:
   time_req = clock();
   for(int i=0; i<100; i++)
   {
    intro.uzupelnij_tablice(tablice[i].tablica);
    intro.sortuj();
    intro.oddaj_tablice(tablice_po[i].tablica);
   }
   time_req = clock() - time_req;
   cout << "Using pow function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
   break;

/*###### case 8 ######
sprawdzenie poprawnosci posortowanych tablic
*/
   case 8:

   for(int i=0; i<100; i++)
    {
     tak_nie=tablice_po[i].sprawdz_popr();
     if(tak_nie==true)
     ++licz;
    }
    if(licz==100)
    cout << "poprawnie posortowane"<<endl;
    else
    cout << "zle posortowane"<< endl;
    licz=0;
   break;

/*###### case 9######
Koniec dzialania programu wyjscie z petli
*/
   case 9:
   powtarzaj=false;
   break;

   default:
   cout << "bledny wybor" << endl;
   break;
  }
 }

    return 0;
}
