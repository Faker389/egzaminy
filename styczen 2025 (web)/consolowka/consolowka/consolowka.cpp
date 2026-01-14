#include <ctime>
#include <iostream>
using std::endl;
using std::cout;
class Klasa {
private:
    int len;
    int tab[];
public:
    Klasa(int len):len(len) {
        for (int x = 0;x < len;x++) {
            tab[x] = rand() % 1000 + 1;
        }
    }
    /*
    **********************************************
    nazwa metody: showElements
    opis metody: wyœwietla wszystkie elementy z tablicy liczb ca³kowitych
    parametry: brak
    zwracany typ i opis: brak
    autor: Ja
    ***********************************************
    */
    void showElements() {
        for (int x = 0;x < this->len;x++) {
            cout << x << ":" << this->tab[x] << endl;
        }
    }
    /*
    **********************************************
    nazwa metody: findIndexOf
    opis metody: przeszukuje tablice liczb ca³kowitych czy któryœ element jest równy przekazanemu parametrowi
    parametry: number - poszukiwana liczba ca³kowita
    zwracany typ i opis: zwraca wartoœæ typu int je¿eli znajdzie tak¹ liczbe równ¹ przekazanemu parametrowi zwraca jej index w przeciwnym wypadku zwraca -1
    autor: Ja
    ***********************************************
    */
    int findIndexOf(int number) {
        for (int x = 0;x < this->len;x++) {
            if (this->tab[x] == number) return x;
        }
        return -1;
    }
    /*
    **********************************************
    nazwa metody: showOddElements
     opis metody: zlicza i wyœwietla ile liczb nieparzystych znajduje sie w tablicy
     parametry: brak
     zwracany typ i opis: brak
     autor: Ja
     ***********************************************
    */
    void showOddElements() {
        int oddCount = 0;
        cout << "Liczby nieparzyste: \n";
        for (int x = 0;x < this->len;x++) {
            if (this->tab[x] % 2 != 0) {
                oddCount++;
                cout << this->tab[x]<<endl;
            }
        }
        cout << "Razem nieparzystych: " << oddCount << endl;
    }
    /*
    **********************************************
    nazwa metody: sredniaArytmetyczna
    opis metody: Oblicza œredni¹ arytmetyczna z wartoœci z tablicy i j¹ wyœwietla
    parametry: brak
    zwracany typ i opis: zwracany typ : int - zwraca œredni¹ arytmetyczna wszystkich elementów z tablicy
    autor: Ja
    ***********************************************
    */
    int sredniaArytmetyczna() {
        int sum = 0;
        for (int x = 0;x < this->len;x++) {
            sum+=this->tab[x];
        }
        int srednia = sum / this->len;
        cout << "Srednia wszystkich elementow : " << srednia << endl;
        return srednia;
    }
};
int main()
{
    srand(time(NULL));
    Klasa *obj = new Klasa(30);
    obj->showElements();
    obj->findIndexOf(32);
    obj->showOddElements();
    obj->sredniaArytmetyczna();
}
